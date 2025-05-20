//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>

#define BAUDRATE B9600

int main() {
    int fd;
    struct termios options;

    fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY);

    if (fd < 0) {
        printf("Error opening port\n");
        return 1;
    }

    tcgetattr(fd, &options);

    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~(CSIZE);
    options.c_cflag |= CS8;
    options.c_cflag &= ~(PARENB);
    options.c_cflag &= ~(CSTOPB);
    options.c_cflag &= ~(CRTSCTS);

    options.c_iflag &= ~(IXON);
    options.c_iflag &= ~(IXOFF);
    options.c_iflag &= ~(IXANY);

    options.c_oflag &= ~(OPOST);
    options.c_lflag &= ~(ICANON);
    options.c_lflag &= ~(ECHO);
    options.c_lflag &= ~(ECHOE);
    options.c_lflag &= ~(ECHONL);

    tcsetattr(fd, TCSANOW, &options);

    char str[100];
    sprintf(str, "AT+CREG=2\r");
    write(fd, str, strlen(str));

    close(fd);

    return 0;
}