//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>

#define BAUD_RATE 9600
#define DATA_BITS 8
#define PARITY 0
#define STOP_BITS 1

int main() {
    int fd;
    struct termios options;

    // Open the serial port
    fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY);
    if (fd == -1) {
        printf("Error opening serial port\n");
        return 1;
    }

    // Get the current options for the serial port
    tcgetattr(fd, &options);

    // Set the baud rate
    cfsetispeed(&options, BAUD_RATE);
    cfsetospeed(&options, BAUD_RATE);

    // Set the data bits, parity, and stop bits
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= DATA_BITS;
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag |= STOP_BITS;

    // Set the serial port options
    tcsetattr(fd, TCSANOW, &options);

    // Loop to send commands to the drone
    while (1) {
        // Get user input
        char input[100];
        printf("Enter command: ");
        scanf("%s", input);

        // Send the command to the drone
        write(fd, input, strlen(input));
        write(fd, "\r", 1);

        // Read the response from the drone
        char response[100];
        read(fd, response, sizeof(response));

        // Print the response
        printf("Response: %s\n", response);
    }

    close(fd);
    return 0;
}