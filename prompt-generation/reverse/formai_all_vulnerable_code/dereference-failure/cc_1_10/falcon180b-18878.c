//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/select.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;
    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
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
    options.c_cflag &= ~(CSIZE);
    options.c_cflag |= CS8;
    options.c_cflag &= ~(PARENB);
    options.c_cflag &= ~(CSTOPB);
    options.c_cflag |= (CREAD | CLOCAL);
    options.c_iflag |= (IGNBRK);
    options.c_lflag = 0;

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        perror("tcsetattr");
        exit(1);
    }

    while (1) {
        char buf[10];
        int n;
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(fd, &readfds);
        select(fd + 1, &readfds, NULL, NULL, NULL);
        if (FD_ISSET(fd, &readfds)) {
            n = read(fd, buf, 10);
            if (n > 0) {
                buf[n] = '\0';
                printf("Received: %s\n", buf);
            }
        }
    }

    close(fd);
    return 0;
}