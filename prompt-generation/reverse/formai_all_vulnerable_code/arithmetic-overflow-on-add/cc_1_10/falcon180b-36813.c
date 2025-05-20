//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/select.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;

    fd = open(DEVICE, O_RDWR | O_NOCTTY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    if (tcgetattr(fd, &options)!= 0) {
        perror("tcgetattr");
        return 1;
    }

    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~(CSIZE | PARENB);
    options.c_cflag |= CS8;
    options.c_cflag &= ~HUPCL;
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        perror("tcsetattr");
        return 1;
    }

    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    while (1) {
        int ret = select(fd + 1, &readfds, NULL, NULL, NULL);

        if (ret == -1) {
            perror("select");
            return 1;
        }

        if (FD_ISSET(fd, &readfds)) {
            char buf[1024];
            int n = read(fd, buf, sizeof(buf));

            if (n == -1) {
                perror("read");
                return 1;
            }

            buf[n] = '\0';
            printf("Received: %s\n", buf);
        }
    }

    return 0;
}