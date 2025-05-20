//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <math.h>

#define BAUDRATE B115200
#define DEVICE "/dev/ttyUSB0"
#define TIMEOUT 1000 // in ms

int fd;
struct termios oldtio, newtio;
char buffer[256];
int bytes_read;

void init_serial() {
    memset(&oldtio, 0, sizeof(oldtio));
    memset(&newtio, 0, sizeof(newtio));

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        printf("Error opening %s: %s\n", DEVICE, strerror(errno));
        exit(1);
    }

    if (tcgetattr(fd, &oldtio)!= 0) {
        printf("Error tcgetattr: %s\n", strerror(errno));
        exit(1);
    }

    newtio = oldtio;
    newtio.c_cflag = BAUDRATE | CS8 | CREAD | CLOCAL;
    newtio.c_cc[VMIN] = 1;
    newtio.c_cc[VTIME] = 10;

    if (tcsetattr(fd, TCSANOW, &newtio)!= 0) {
        printf("Error tcsetattr: %s\n", strerror(errno));
        exit(1);
    }
}

int main() {
    init_serial();

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        bytes_read = read(fd, buffer, sizeof(buffer));

        if (bytes_read <= 0) {
            printf("Error reading from serial port: %s\n", strerror(errno));
            exit(1);
        }

        printf("Received: %s\n", buffer);
    }

    return 0;
}