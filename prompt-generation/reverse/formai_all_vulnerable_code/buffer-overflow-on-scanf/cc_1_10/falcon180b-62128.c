//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUD B9600
#define DEV "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;
    char command[50];
    char response[100];

    fd = open(DEV, O_RDWR);
    if (fd == -1) {
        printf("Failed to open %s\n", DEV);
        exit(1);
    }

    tcgetattr(fd, &options);
    cfsetispeed(&options, BAUD);
    cfsetospeed(&options, BAUD);

    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~(CSIZE | PARENB | CSTOPB);
    options.c_cflag |= CS8;
    options.c_cc[VMIN] = 0;
    options.c_cc[VTIME] = 1;

    tcsetattr(fd, TCSANOW, &options);

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        strcat(command, "\r");
        write(fd, command, strlen(command));

        memset(response, 0, sizeof(response));
        read(fd, response, sizeof(response));

        printf("Response: %s\n", response);
    }

    close(fd);
    return 0;
}