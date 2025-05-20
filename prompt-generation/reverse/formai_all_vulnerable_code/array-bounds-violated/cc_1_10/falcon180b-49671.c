//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define BAUDRATE B115200
#define DEVICE "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        perror("Error opening port");
        exit(1);
    }

    memset(&options, 0, sizeof(struct termios));
    options.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        perror("Error setting attributes");
        exit(1);
    }

    while (1) {
        char buf[100];
        int n = read(fd, buf, sizeof(buf));
        if (n > 0) {
            buf[n] = 0;
            printf("Received: %s\n", buf);
        } else {
            perror("Error reading from port");
            exit(1);
        }
    }

    close(fd);
    return 0;
}