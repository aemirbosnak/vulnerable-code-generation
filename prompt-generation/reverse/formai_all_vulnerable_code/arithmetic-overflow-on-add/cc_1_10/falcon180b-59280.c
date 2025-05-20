//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <sys/time.h>

#define BAUDRATE B115200
#define DEVICE "/dev/ttyUSB0"

int main()
{
    int fd;
    struct termios options;
    fd_set readfds;
    char buf[1024];
    int ret;

    fd = open(DEVICE, O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    memset(&options, 0, sizeof(options));
    options.c_cflag = BAUDRATE | CS8 | CREAD | CLOCAL;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    ret = tcsetattr(fd, TCSANOW, &options);
    if (ret < 0) {
        perror("tcsetattr");
        return 1;
    }

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    while (1) {
        ret = select(fd + 1, &readfds, NULL, NULL, NULL);
        if (ret < 0) {
            if (errno == EINTR)
                continue;
            perror("select");
            return 1;
        }

        if (FD_ISSET(fd, &readfds)) {
            ret = read(fd, buf, sizeof(buf));
            if (ret < 0) {
                perror("read");
                return 1;
            }

            buf[ret] = '\0';
            printf("Received data: %s\n", buf);
        }
    }

    return 0;
}