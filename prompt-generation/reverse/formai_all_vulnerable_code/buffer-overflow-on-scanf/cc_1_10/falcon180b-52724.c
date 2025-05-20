//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <math.h>

#define BAUDRATE B9600
#define DEV "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;
    char buf[100];

    fd = open(DEV, O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd == -1) {
        perror("open");
        exit(1);
    }

    if (tcgetattr(fd, &options)!= 0) {
        perror("tcgetattr");
        exit(1);
    }

    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~(PARENB | CSTOPB | CSIZE);

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        perror("tcsetattr");
        exit(1);
    }

    while (1) {
        printf("Enter command (f:forward, b:backward, l:left, r:right, s:stop): ");
        scanf("%s", buf);

        switch (buf[0]) {
            case 'f':
                printf("Moving forward...\n");
                break;
            case 'b':
                printf("Moving backward...\n");
                break;
            case 'l':
                printf("Moving left...\n");
                break;
            case 'r':
                printf("Moving right...\n");
                break;
            case's':
                printf("Stopping...\n");
                break;
            default:
                printf("Invalid command.\n");
        }
    }

    close(fd);
    return 0;
}