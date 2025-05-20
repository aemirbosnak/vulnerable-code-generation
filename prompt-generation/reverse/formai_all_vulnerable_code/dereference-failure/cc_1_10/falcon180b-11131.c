//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
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
    if (tcgetattr(fd, &options)!= 0) {
        printf("Error tcgetattr: %s\n", strerror(errno));
        exit(2);
    }

    // Set the baud rate
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    // Set the data format
    options.c_cflag = CS8 | CREAD | CLOCAL;

    // Set the input mode
    options.c_iflag = IGNBRK;

    // Set the output mode
    options.c_oflag = 0;

    // Set the control mode
    options.c_cflag |= CREAD | CLOCAL;

    // Set the local mode
    options.c_lflag = 0;

    // Set the new options for the port
    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        printf("Error tcsetattr: %s\n", strerror(errno));
        exit(3);
    }

    // Loop to send commands to the drone
    while (1) {
        // Get user input
        char input[100];
        printf("Enter command: ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Send command to drone
        if (write(fd, input, strlen(input))!= strlen(input)) {
            printf("Error writing to port: %s\n", strerror(errno));
            exit(4);
        }
    }

    return 0;
}