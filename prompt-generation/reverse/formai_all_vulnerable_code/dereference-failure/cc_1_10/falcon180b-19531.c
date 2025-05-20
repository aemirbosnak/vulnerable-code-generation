//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

int main(int argc, char *argv[]) {
    int fd;
    struct termios options;

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        printf("Error opening %s: %s\n", DEVICE, strerror(errno));
        exit(1);
    }

    tcgetattr(fd, &options);
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~(CSIZE | PARENB);
    options.c_cflag |= CS8;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;

    tcsetattr(fd, TCSANOW, &options);

    while (1) {
        char c = getchar();
        if (c == 'w') {
            printf("Sending 'w' command\n");
            write(fd, "w", 1);
        } else if (c =='s') {
            printf("Sending's' command\n");
            write(fd, "s", 1);
        } else if (c == 'a') {
            printf("Sending 'a' command\n");
            write(fd, "a", 1);
        } else if (c == 'd') {
            printf("Sending 'd' command\n");
            write(fd, "d", 1);
        } else {
            printf("Unknown command: %c\n", c);
        }
    }

    close(fd);
    return 0;
}