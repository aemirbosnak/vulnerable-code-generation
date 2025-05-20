//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define BAUD B115200
#define DEVICE "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd < 0) {
        printf("Error opening %s: %s\n", DEVICE, strerror(errno));
        return 1;
    }

    if (tcgetattr(fd, &options) < 0) {
        printf("Error tcgetattr: %s\n", strerror(errno));
        return 1;
    }

    cfsetispeed(&options, BAUD);
    cfsetospeed(&options, BAUD);

    options.c_cflag |= CREAD | CLOCAL;
    options.c_cflag &= ~(CSIZE | PARENB);
    options.c_cflag |= CS8;
    options.c_cflag &= ~CRTSCTS;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 5;

    if (tcsetattr(fd, TCSANOW, &options) < 0) {
        printf("Error tcsetattr: %s\n", strerror(errno));
        return 1;
    }

    write(fd, "AT\r", 3);
    usleep(10000);

    while (1) {
        char buf[1024];
        int n = read(fd, buf, sizeof(buf));

        if (n <= 0) {
            printf("Error reading from %s: %s\n", DEVICE, strerror(errno));
            break;
        }

        buf[n] = '\0';
        printf("%s", buf);
    }

    close(fd);
    return 0;
}