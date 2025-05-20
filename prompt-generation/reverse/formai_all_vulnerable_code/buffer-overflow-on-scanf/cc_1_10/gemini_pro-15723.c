//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <termios.h>
#include <signal.h>

#define BAUDRATE B115200
#define TIMEOUT 1000 /* in milliseconds */
#define SERIAL_DEVICE "/dev/ttyUSB0"

int serial_port;

void sigint_handler(int sig)
{
	printf("\nCaught SIGINT, closing serial port\n");
	close(serial_port);
	exit(0);
}

int main(int argc, char **argv)
{
	struct termios oldtio, newtio;
	char buf[1024];
	int nbytes;
	int i;
	int control;

	/* Open serial port */
	serial_port = open(SERIAL_DEVICE, O_RDWR | O_NOCTTY);
	if (serial_port < 0) {
		perror("Error opening serial port");
		exit(1);
	}

	/* Set up serial port параметры */
	tcgetattr(serial_port, &oldtio);
	bzero(&newtio, sizeof(newtio));
	newtio.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
	newtio.c_iflag = IGNPAR | ICRNL;
	newtio.c_oflag = 0;
	newtio.c_lflag = 0;
	tcflush(serial_port, TCIFLUSH);
	tcsetattr(serial_port, TCSANOW, &newtio);

	/* Set up signal handler */
	signal(SIGINT, sigint_handler);

	/* Main loop */
	while (1) {
		/* Get input from user */
		printf("Enter control (1-4): ");
		scanf("%d", &control);

		/* Send control to robot */
		write(serial_port, &control, 1);

		/* Read response from robot */
		nbytes = read(serial_port, buf, sizeof(buf));
		if (nbytes < 0) {
			perror("Error reading from serial port");
			close(serial_port);
			exit(1);
		}

		/* Print response from robot */
		for (i = 0; i < nbytes; i++) {
			printf("%c", buf[i]);
		}
	}

	/* Close serial port */
	close(serial_port);

	return 0;
}