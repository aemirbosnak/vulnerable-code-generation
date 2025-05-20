//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <poll.h>

#define DEVICE "/dev/ttyUSB0"
#define BAUDRATE B115200

int main(int argc, char **argv) {
    int fd;
    struct termios options;
    struct pollfd pollfd;
    char buffer[1024];
    int i;

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    tcgetattr(fd, &options);
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    tcsetattr(fd, TCSANOW, &options);

    pollfd.fd = fd;
    pollfd.events = POLLIN;

    while (1) {
        if (poll(&pollfd, 1, 1000) > 0) {
            if (read(fd, buffer, sizeof(buffer)) > 0) {
                printf("%s", buffer);
            }
        }

        if (strcmp(argv[1], "takeoff") == 0) {
            write(fd, "takeoff\n", strlen("takeoff\n"));
        } else if (strcmp(argv[1], "land") == 0) {
            write(fd, "land\n", strlen("land\n"));
        } else if (strcmp(argv[1], "forward") == 0) {
            write(fd, "forward\n", strlen("forward\n"));
        } else if (strcmp(argv[1], "backward") == 0) {
            write(fd, "backward\n", strlen("backward\n"));
        } else if (strcmp(argv[1], "left") == 0) {
            write(fd, "left\n", strlen("left\n"));
        } else if (strcmp(argv[1], "right") == 0) {
            write(fd, "right\n", strlen("right\n"));
        } else if (strcmp(argv[1], "up") == 0) {
            write(fd, "up\n", strlen("up\n"));
        } else if (strcmp(argv[1], "down") == 0) {
            write(fd, "down\n", strlen("down\n"));
        } else if (strcmp(argv[1], "stop") == 0) {
            write(fd, "stop\n", strlen("stop\n"));
        } else if (strcmp(argv[1], "exit") == 0) {
            break;
        }
    }

    close(fd);

    return 0;
}