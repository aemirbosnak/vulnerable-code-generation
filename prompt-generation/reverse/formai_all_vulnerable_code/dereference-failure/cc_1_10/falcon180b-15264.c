//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
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
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    // Get the current options for the port
    if (tcgetattr(fd, &options)!= 0) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    // Set the baud rate
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    // Set the input mode
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag |= CREAD | CLOCAL;

    // Set the output mode
    options.c_oflag = 0;

    // Set the control mode
    options.c_cflag |= CREAD | CLOCAL;
    options.c_lflag = 0;

    // Set the local mode
    options.c_lflag = 0;

    // Set the line discipline
    options.c_line = 0;

    // Set the control characters
    options.c_cc[VTIME] = 5;
    options.c_cc[VMIN] = 1;

    // Set the new options for the port
    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    // Loop to send commands to the drone
    while (1) {
        // Take off
        printf("Taking off...\n");
        char takeoff_command[] = "AT*REF=1,1\r";
        write(fd, takeoff_command, strlen(takeoff_command));

        // Move forward
        printf("Moving forward...\n");
        char forward_command[] = "AT*REF=1,2,0\r";
        write(fd, forward_command, strlen(forward_command));

        // Turn left
        printf("Turning left...\n");
        char left_command[] = "AT*REF=1,2,1\r";
        write(fd, left_command, strlen(left_command));

        // Turn right
        printf("Turning right...\n");
        char right_command[] = "AT*REF=1,2,2\r";
        write(fd, right_command, strlen(right_command));

        // Land
        printf("Landing...\n");
        char land_command[] = "AT*REF=1,1\r";
        write(fd, land_command, strlen(land_command));

        // Wait for 1 second
        sleep(1);
    }

    // Close the serial port
    close(fd);
    return 0;
}