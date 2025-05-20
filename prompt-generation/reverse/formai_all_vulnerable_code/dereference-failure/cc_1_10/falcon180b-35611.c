//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <sys/time.h>

#define BAUDRATE B9600
#define MODEMDEVICE "/dev/ttyS0"

int main() {
    int fd;
    struct termios options;
    fd_set readfds;

    fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY);

    if (fd < 0) {
        printf("Error opening %s: %s\n", MODEMDEVICE, strerror(errno));
        exit(1);
    }

    if (tcgetattr(fd, &options) < 0) {
        printf("Error getting attributes: %s\n", strerror(errno));
        exit(1);
    }

    cfmakeraw(&options);
    cfsetospeed(&options, BAUDRATE);
    cfsetispeed(&options, BAUDRATE);

    if (tcsetattr(fd, TCSANOW, &options) < 0) {
        printf("Error setting attributes: %s\n", strerror(errno));
        exit(1);
    }

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    while (1) {
        int ret = select(fd + 1, &readfds, NULL, NULL, NULL);

        if (ret < 0) {
            printf("Error selecting: %s\n", strerror(errno));
            exit(1);
        }

        if (FD_ISSET(fd, &readfds)) {
            char buf[1024];
            int len;

            len = read(fd, buf, sizeof(buf));

            if (len < 0) {
                printf("Error reading: %s\n", strerror(errno));
                exit(1);
            }

            printf("Received: %s\n", buf);
        }
    }

    close(fd);
    return 0;
}