//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

int main(int argc, char **argv) {
    int fd;
    struct termios options;

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    if (tcgetattr(fd, &options)!= 0) {
        perror("tcgetattr");
        exit(1);
    }

    options.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        perror("tcsetattr");
        exit(1);
    }

    char cmd[10];

    while (1) {
        printf("Enter command: ");
        scanf("%s", cmd);

        if (strcmp(cmd, "up") == 0) {
            write(fd, "A", 1);
        } else if (strcmp(cmd, "down") == 0) {
            write(fd, "B", 1);
        } else if (strcmp(cmd, "left") == 0) {
            write(fd, "C", 1);
        } else if (strcmp(cmd, "right") == 0) {
            write(fd, "D", 1);
        } else if (strcmp(cmd, "stop") == 0) {
            write(fd, "E", 1);
        } else {
            printf("Invalid command\n");
        }
    }

    close(fd);
    return 0;
}