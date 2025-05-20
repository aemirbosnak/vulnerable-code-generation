//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <sys/ioctl.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;

    // Open the serial port
    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        printf("Error opening serial port: %s\n", strerror(errno));
        return 1;
    }

    // Get the current options
    tcgetattr(fd, &options);

    // Set the baud rate
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    // Set the options
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~(PARENB | CSTOPB | CSIZE);
    options.c_cflag |= CS8;
    options.c_iflag &= ~(IXON | IXOFF | IXANY);
    options.c_oflag &= ~OPOST;

    // Set the input mode
    options.c_lflag = 0;

    // Set the control mode
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    // Set the options
    tcsetattr(fd, TCSANOW, &options);

    // Send commands to the drone
    char command[100];
    sprintf(command, "AT+CFUN=1\r");
    write(fd, command, strlen(command));
    usleep(100000);

    sprintf(command, "AT+CIPMUX=1\r");
    write(fd, command, strlen(command));
    usleep(100000);

    sprintf(command, "AT+CIPSERVER=1,80\r");
    write(fd, command, strlen(command));
    usleep(100000);

    sprintf(command, "AT+CIPSTART=1,1\r");
    write(fd, command, strlen(command));
    usleep(100000);

    // Close the serial port
    close(fd);

    return 0;
}