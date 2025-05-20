//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <errno.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;

    // Open the serial port
    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        printf("Error opening %s: %s\n", DEVICE, strerror(errno));
        exit(1);
    }

    // Get the current options for the port
    tcgetattr(fd, &options);

    // Set the baud rate
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    // Set the data format
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;

    // Enable hardware flow control
    options.c_cflag |= CRTSCTS;

    // Set the input mode
    options.c_iflag = IGNPAR;

    // Set the output mode
    options.c_oflag = 0;

    // Set the control mode
    options.c_lflag = 0;

    // Set the local mode
    options.c_lflag &= ~ICANON;
    options.c_lflag &= ~ECHO;
    options.c_lflag &= ~ISIG;

    // Set the new options for the port
    tcsetattr(fd, TCSANOW, &options);

    // Send a test message
    write(fd, "Hello, world!\n", 13);

    // Close the serial port
    close(fd);

    return 0;
}