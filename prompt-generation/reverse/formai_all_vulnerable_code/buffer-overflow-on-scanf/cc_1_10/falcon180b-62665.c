//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        perror(DEVICE);
        exit(1);
    }

    memset(&options, 0, sizeof(options));
    options.c_cflag = BAUDRATE | CS8 | CREAD | CLOCAL;
    options.c_iflag = IGNBRK | IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 10;

    tcsetattr(fd, TCSANOW, &options);

    while (1) {
        char command[50];
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "takeoff") == 0) {
            char takeoff_command = 0xA0;
            write(fd, &takeoff_command, 1);
        } else if (strcmp(command, "land") == 0) {
            char land_command = 0xB0;
            write(fd, &land_command, 1);
        } else if (strcmp(command, "left") == 0) {
            char left_command = 0x80;
            write(fd, &left_command, 1);
        } else if (strcmp(command, "right") == 0) {
            char right_command = 0xC0;
            write(fd, &right_command, 1);
        } else if (strcmp(command, "forward") == 0) {
            char forward_command = 0xE0;
            write(fd, &forward_command, 1);
        } else if (strcmp(command, "backward") == 0) {
            char backward_command = 0x60;
            write(fd, &backward_command, 1);
        } else {
            printf("Invalid command\n");
        }
    }

    close(fd);
    return 0;
}