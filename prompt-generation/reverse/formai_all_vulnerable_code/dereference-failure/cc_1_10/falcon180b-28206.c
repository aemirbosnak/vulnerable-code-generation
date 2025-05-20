//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;

    fd = open(DEVICE, O_RDWR | O_NOCTTY);

    if (fd < 0) {
        printf("Error opening %s: %s\n", DEVICE, strerror(errno));
        return 1;
    }

    if (tcgetattr(fd, &options) < 0) {
        printf("Error tcgetattr: %s\n", strerror(errno));
        return 1;
    }

    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~(CSIZE | PARENB);
    options.c_cflag |= CS8;
    options.c_cflag |= CREAD;
    options.c_cflag &= ~CRTSCTS;

    options.c_iflag |= (IGNBRK | IGNPAR);
    options.c_oflag = 0;

    if (tcsetattr(fd, TCSANOW, &options) < 0) {
        printf("Error tcsetattr: %s\n", strerror(errno));
        return 1;
    }

    printf("Press any key to send 'Hello, World!'...\n");
    fflush(stdout);

    getchar();

    write(fd, "Hello, World!\r\n", 13);

    close(fd);

    return 0;
}