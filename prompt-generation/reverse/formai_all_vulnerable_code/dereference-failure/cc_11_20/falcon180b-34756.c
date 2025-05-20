//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: minimalist
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

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    memset(&options, 0, sizeof(options));

    options.c_cflag = BAUDRATE | CS8 | CREAD | CLOCAL;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    while (1) {
        char command = getchar();
        switch (command) {
            case 'f':
                write(fd, "forward\r\n", 8);
                break;
            case 'b':
                write(fd, "backward\r\n", 9);
                break;
            case 'l':
                write(fd, "left\r\n", 6);
                break;
            case 'r':
                write(fd, "right\r\n", 7);
                break;
            case 'u':
                write(fd, "up\r\n", 5);
                break;
            case 'd':
                write(fd, "down\r\n", 6);
                break;
            case's':
                write(fd, "stop\r\n", 6);
                break;
            case 'q':
                close(fd);
                return 0;
            default:
                printf("Invalid command\n");
        }
    }

    close(fd);
    return 0;
}