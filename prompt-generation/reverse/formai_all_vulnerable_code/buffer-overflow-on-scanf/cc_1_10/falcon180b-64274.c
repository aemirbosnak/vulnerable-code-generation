//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>

#define BAUDRATE B9600
#define DEV "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;

    fd = open(DEV, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd < 0) {
        printf("Error opening %s\n", DEV);
        return 1;
    }

    tcgetattr(fd, &options);

    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~(CSIZE | PARENB);
    options.c_cflag |= CS8;
    options.c_cflag |= CREAD;
    options.c_cflag |= CLOCAL;

    options.c_iflag |= IGNPAR;
    options.c_oflag = 0;

    tcsetattr(fd, TCSANOW, &options);

    printf("Enter commands:\n");
    while (1) {
        char command[100];
        scanf("%s", command);

        if (strcmp(command, "on") == 0) {
            write(fd, "1", 1);
        } else if (strcmp(command, "off") == 0) {
            write(fd, "0", 1);
        } else if (strcmp(command, "dim") == 0) {
            write(fd, "2", 1);
        } else if (strcmp(command, "bright") == 0) {
            write(fd, "3", 1);
        } else {
            printf("Invalid command\n");
        }
    }

    close(fd);
    return 0;
}