//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Ken Thompson
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
        printf("Error opening %s\n", DEVICE);
        exit(1);
    }

    memset(&options, 0, sizeof(options));
    options.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    tcsetattr(fd, TCSANOW, &options);

    while (1) {
        char command[100];
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "up") == 0) {
            char up_command[10] = {0x55, 0xAA, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
            write(fd, up_command, sizeof(up_command));
        } else if (strcmp(command, "down") == 0) {
            char down_command[10] = {0x55, 0xAA, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
            write(fd, down_command, sizeof(down_command));
        } else if (strcmp(command, "left") == 0) {
            char left_command[10] = {0x55, 0xAA, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
            write(fd, left_command, sizeof(left_command));
        } else if (strcmp(command, "right") == 0) {
            char right_command[10] = {0x55, 0xAA, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
            write(fd, right_command, sizeof(right_command));
        } else if (strcmp(command, "stop") == 0) {
            char stop_command[10] = {0x55, 0xAA, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
            write(fd, stop_command, sizeof(stop_command));
        } else {
            printf("Invalid command\n");
        }
    }

    close(fd);
    return 0;
}