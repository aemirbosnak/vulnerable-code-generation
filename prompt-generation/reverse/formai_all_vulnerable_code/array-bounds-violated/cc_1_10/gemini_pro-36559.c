//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <poll.h>
#include <signal.h>
#include <pthread.h>

#define INTERVAL 1000
#define BUFF_SIZE 1024
#define MAX_TRACKING_POINTS 1024
#define MAX_TRACKING_SESSIONS 10

struct tracking_point {
	time_t timestamp;
	double latitude;
	double longitude;
	double altitude;
	double speed;
	double heading;
};

struct tracking_session {
	time_t start_timestamp;
	time_t end_timestamp;
	struct tracking_point *points;
	int num_points;
};

static struct tracking_session sessions[MAX_TRACKING_SESSIONS];
static int num_sessions = 0;

static int fd;

static void init_gps()
{
	struct termios termios;

	fd = open("/dev/ttyACM0", O_RDWR);
	if (fd < 0) {
		perror("open()");
		exit(1);
	}

	tcgetattr(fd, &termios);
	termios.c_cflag |= CS8;
	termios.c_cflag |= CREAD;
	termios.c_cflag |= CLOCAL;
	termios.c_cflag &= ~PARENB;
	termios.c_cflag &= ~CSTOPB;
	termios.c_iflag |= IGNPAR;
	termios.c_iflag &= ~IGNCR;
	termios.c_iflag &= ~ISTRIP;
	termios.c_iflag &= ~ICRNL;
	termios.c_lflag &= ~ICANON;
	termios.c_lflag &= ~ECHO;
	termios.c_lflag &= ~ECHOE;
	termios.c_oflag &= ~OPOST;
	termios.c_oflag &= ~ONLCR;
	termios.c_cc[VTIME] = 0;
	termios.c_cc[VMIN] = 1;
	cfsetispeed(&termios, 9600);
	cfsetospeed(&termios, 9600);
	tcsetattr(fd, TCSANOW, &termios);
}

static void close_gps()
{
	if (fd >= 0) {
		close(fd);
	}
}

static void handle_sigint(int signum)
{
	close_gps();
	exit(0);
}

static void *tracking_thread(void *arg)
{
	char buff[BUFF_SIZE];
	int num_chars;
	while (1) {
		struct timeval timeout = {
			.tv_sec = INTERVAL / 1000,
			.tv_usec = (INTERVAL % 1000) * 1000,
		};
		fd_set fds;
		FD_ZERO(&fds);
		FD_SET(fd, &fds);
		select(fd + 1, &fds, NULL, NULL, &timeout);
		if (FD_ISSET(fd, &fds)) {
			num_chars = read(fd, buff, BUFF_SIZE);
			if (num_chars > 0) {
				buff[num_chars] = '\0';
				printf(buff);
			}
		}
	}
	return NULL;
}

static void start_tracking()
{
	char command[BUFF_SIZE];
	if (num_sessions >= MAX_TRACKING_SESSIONS) {
		fprintf(stderr, "Error: maximum number of tracking sessions reached\n");
		return;
	}
	sessions[num_sessions].num_points = 0;
	sprintf(command, "$PMTK220,1000,1,%u\n", MAX_TRACKING_POINTS);
	write(fd, command, strlen(command));
	sessions[num_sessions].start_timestamp = time(NULL);
	num_sessions++;
}

static void stop_tracking()
{
	char command[BUFF_SIZE];
	sprintf(command, "$PMTK220,0\n");
	write(fd, command, strlen(command));
	sessions[num_sessions - 1].end_timestamp = time(NULL);
}

static void display_sessions()
{
	int i;
	for (i = 0; i < num_sessions; i++) {
		printf("Session %d:\n", i + 1);
		printf("\tStart timestamp: %s", ctime(&sessions[i].start_timestamp));
		printf("\tEnd timestamp: %s", ctime(&sessions[i].end_timestamp));
		printf("\tNumber of points: %d\n", sessions[i].num_points);
	}
}

static void save_sessions()
{
	char filename[BUFF_SIZE];
	FILE *fp;
	int i, j;
	for (i = 0; i < num_sessions; i++) {
		sprintf(filename, "session_%d.txt", i + 1);
		fp = fopen(filename, "w");
		if (fp == NULL) {
			perror("fopen()");
			exit(1);
		}
		fprintf(fp, "Session %d:\n", i + 1);
		fprintf(fp, "Start timestamp: %s", ctime(&sessions[i].start_timestamp));
		fprintf(fp, "End timestamp: %s", ctime(&sessions[i].end_timestamp));
		fprintf(fp, "Number of points: %d\n", sessions[i].num_points);
		for (j = 0; j < sessions[i].num_points; j++) {
			fprintf(fp, "%s", ctime(&sessions[i].points[j].timestamp));
			fprintf(fp, "%f,%f,%f,%f,%f\n",
				sessions[i].points[j].latitude,
				sessions[i].points[j].longitude,
				sessions[i].points[j].altitude,
				sessions[i].points[j].speed,
				sessions[i].points[j].heading);
		}
		fclose(fp);
	}
}

static void delete_sessions()
{
	int i;
	for (i = 0; i < num_sessions; i++) {
		free(sessions[i].points);
	}
}

int main(int argc, char *argv[])
{
	pthread_t thread;
	int rc;
	init_gps();
	signal(SIGINT, handle_sigint);
	rc = pthread_create(&thread, NULL, tracking_thread, NULL);
	if (rc != 0) {
		fprintf(stderr, "Error: could not create tracking thread\n");
		close_gps();
		exit(1);
	}
	while (1) {
		printf("1. Start tracking\n");
		printf("2. Stop tracking\n");
		printf("3. Display sessions\n");
		printf("4. Save sessions\n");
		printf("5. Delete sessions\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		int choice;
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			start_tracking();
			break;
		case 2:
			stop_tracking();
			break;
		case 3:
			display_sessions();
			break;
		case 4:
			save_sessions();
			break;
		case 5:
			delete_sessions();
			break;
		case 6:
			close_gps();
			exit(0);
		default:
			printf("Invalid choice\n");
		}
	}
	return 0;
}