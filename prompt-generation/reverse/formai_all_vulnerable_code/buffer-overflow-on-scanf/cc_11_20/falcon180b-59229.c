//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd == -1) {
        printf("Error opening %s\n", DEVICE);
        exit(1);
    }

    memset(&options, 0, sizeof(options));

    options.c_cflag = BAUDRATE | CS8 | CREAD | CLOCAL;
    options.c_iflag = IGNBRK;

    tcsetattr(fd, TCSANOW, &options);

    char cmd[10];
    while (1) {
        printf("Enter command (0-9, a-z): ");
        scanf("%s", cmd);

        if (cmd[0] >= '0' && cmd[0] <= '9') {
            char c = cmd[0] - '0';
            write(fd, &c, 1);
        } else if (cmd[0] >= 'a' && cmd[0] <= 'z') {
            char c = cmd[0] - 'a' + 10;
            write(fd, &c, 1);
        } else if (cmd[0] =='s') {
            char c ='s';
            write(fd, &c, 1);
        } else if (cmd[0] == 'f') {
            char c = 'f';
            write(fd, &c, 1);
        } else if (cmd[0] == 'b') {
            char c = 'b';
            write(fd, &c, 1);
        } else if (cmd[0] == 'l') {
            char c = 'l';
            write(fd, &c, 1);
        } else if (cmd[0] == 'r') {
            char c = 'r';
            write(fd, &c, 1);
        } else if (cmd[0] == 'u') {
            char c = 'u';
            write(fd, &c, 1);
        } else if (cmd[0] == 'd') {
            char c = 'd';
            write(fd, &c, 1);
        }
    }

    close(fd);
    return 0;
}