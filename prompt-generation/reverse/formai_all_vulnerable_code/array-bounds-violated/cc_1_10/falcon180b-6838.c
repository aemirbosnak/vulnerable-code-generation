//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUDRATE	B9600
#define DEVICE	"/dev/ttyUSB0"

int main(int argc, char *argv[])
{
	int fd;
	struct termios options;
	char buffer[100];
	int len;

	// Open the serial port
	fd = open(DEVICE, O_RDWR);
	if (fd == -1) {
		perror("open");
		exit(1);
	}

	// Get the current options for the serial port
	if (tcgetattr(fd, &options)!= 0) {
		perror("tcgetattr");
		exit(1);
	}

	// Set the baud rate
	cfsetispeed(&options, BAUDRATE);
	cfsetospeed(&options, BAUDRATE);

	// Set the serial port options
	options.c_cflag |= CREAD | CLOCAL;
	options.c_cflag &= ~CSIZE;
	options.c_cflag |= CS8;
	options.c_cflag &= ~PARENB;
	options.c_cflag &= ~CSTOPB;
	options.c_cflag |= CREAD | CLOCAL;
	options.c_iflag = IGNPAR;
	options.c_oflag = 0;
	options.c_lflag = 0;
	options.c_cc[VMIN] = 1;
	options.c_cc[VTIME] = 0;

	// Set the new options for the serial port
	if (tcsetattr(fd, TCSANOW, &options)!= 0) {
		perror("tcsetattr");
		exit(1);
	}

	// Write a command to the drone
	write(fd, "takeoff\r", strlen("takeoff\r"));

	// Read the response from the drone
	len = read(fd, buffer, sizeof(buffer));
	buffer[len] = '\0';
	printf("Response: %s\n", buffer);

	// Close the serial port
	close(fd);

	return 0;
}