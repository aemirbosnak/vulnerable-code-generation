//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdbool.h>

#define BAUDRATE B115200
#define DEVICE "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;

    // Open the serial port
    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        fprintf(stderr, "Error opening serial port: %s\n", strerror(errno));
        return 1;
    }

    // Get the current options
    if (tcgetattr(fd, &options)!= 0) {
        fprintf(stderr, "Error getting serial port options: %s\n", strerror(errno));
        return 1;
    }

    // Set the baud rate
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    // Set the options
    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        fprintf(stderr, "Error setting serial port options: %s\n", strerror(errno));
        return 1;
    }

    // Main loop
    while (true) {
        // Read input from the user
        char input[100];
        fgets(input, 100, stdin);

        // Remove the newline character
        input[strcspn(input, "\n")] = '\0';

        // Send the command to the drone
        if (write(fd, input, strlen(input))!= strlen(input)) {
            fprintf(stderr, "Error writing to serial port: %s\n", strerror(errno));
            return 1;
        }
    }

    return 0;
}