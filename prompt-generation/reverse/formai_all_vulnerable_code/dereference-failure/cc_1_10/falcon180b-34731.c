//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sys/ioctl.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

int main(void) {
    int fd;
    struct termios options;

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        printf("Error opening %s: %s\n", DEVICE, strerror(errno));
        return 1;
    }

    tcgetattr(fd, &options);

    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~(PARENB | CSTOPB);
    options.c_cflag |= CS8;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;

    tcsetattr(fd, TCSANOW, &options);

    while (1) {
        char buffer[1024];
        int bytes_read;

        memset(buffer, 0, sizeof(buffer));
        bytes_read = read(fd, buffer, sizeof(buffer));

        if (bytes_read > 0) {
            printf("Received: %s\n", buffer);
        }
    }

    close(fd);
    return 0;
}