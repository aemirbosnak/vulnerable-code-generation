//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: realistic
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
        printf("Error opening device %s\n", DEVICE);
        return 1;
    }

    tcgetattr(fd, &options);

    options.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;

    tcsetattr(fd, TCSANOW, &options);

    char cmd[100];
    while (1) {
        printf("Enter command: ");
        scanf("%s", cmd);

        if (strcmp(cmd, "takeoff") == 0) {
            char takeoff[] = "AT*REF=1,1\r";
            write(fd, takeoff, strlen(takeoff));
        } else if (strcmp(cmd, "land") == 0) {
            char land[] = "AT*REF=0,0\r";
            write(fd, land, strlen(land));
        } else if (strcmp(cmd, "left") == 0) {
            char left[] = "AT*REF=1,0\r";
            write(fd, left, strlen(left));
        } else if (strcmp(cmd, "right") == 0) {
            char right[] = "AT*REF=0,1\r";
            write(fd, right, strlen(right));
        } else if (strcmp(cmd, "forward") == 0) {
            char forward[] = "AT*REF=1,1\r";
            write(fd, forward, strlen(forward));
        } else if (strcmp(cmd, "backward") == 0) {
            char backward[] = "AT*REF=0,0\r";
            write(fd, backward, strlen(backward));
        } else {
            printf("Invalid command\n");
        }
    }

    close(fd);
    return 0;
}