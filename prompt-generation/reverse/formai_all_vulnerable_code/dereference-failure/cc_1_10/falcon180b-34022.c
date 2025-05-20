//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

void setup_serial(int fd) {
    struct termios tio;
    memset(&tio, 0, sizeof(tio));

    tio.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    tio.c_iflag = IGNBRK;
    tio.c_oflag = 0;
    tio.c_lflag = 0;
    tio.c_cc[VMIN] = 1;
    tio.c_cc[VTIME] = 0;

    if (tcsetattr(fd, TCSANOW, &tio)!= 0) {
        fprintf(stderr, "Error setting serial attributes: %s\n", strerror(errno));
        exit(1);
    }
}

int main() {
    int fd;
    char buf[1024];

    fd = open(DEVICE, O_RDWR);
    if (fd == -1) {
        fprintf(stderr, "Error opening %s: %s\n", DEVICE, strerror(errno));
        return 1;
    }

    setup_serial(fd);

    while (1) {
        memset(buf, 0, sizeof(buf));
        if (read(fd, buf, sizeof(buf)) == -1) {
            fprintf(stderr, "Error reading from serial: %s\n", strerror(errno));
            exit(1);
        }

        printf("Received: %s\n", buf);
    }

    close(fd);
    return 0;
}