//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUD_RATE 9600
#define SERIAL_PORT "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;

    fd = open(SERIAL_PORT, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        perror("Error opening serial port");
        exit(1);
    }

    if (tcgetattr(fd, &options)!= 0) {
        perror("Error getting attributes");
        exit(1);
    }

    options.c_cflag = BAUD_RATE | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        perror("Error setting attributes");
        exit(1);
    }

    char command[10];
    char response[10];
    int length;

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        length = strlen(command);
        if (write(fd, command, length)!= length) {
            perror("Error writing to serial port");
            exit(1);
        }

        if (read(fd, response, length)!= length) {
            perror("Error reading from serial port");
            exit(1);
        }

        printf("Response: %s\n", response);
    }

    close(fd);
    return 0;
}