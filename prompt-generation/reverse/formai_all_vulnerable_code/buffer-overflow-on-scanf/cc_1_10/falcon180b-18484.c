//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <sys/ioctl.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyS0"

int main() {
    int fd;
    struct termios options;

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd == -1) {
        printf("Error opening %s\n", DEVICE);
        exit(1);
    }

    memset(&options, 0, sizeof(struct termios));

    options.c_cflag = BAUDRATE | CS8 | CREAD | CLOCAL;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 5;

    tcsetattr(fd, TCSANOW, &options);

    while (1) {
        char c;
        read(fd, &c, 1);

        if (c == 'f') {
            char command[100];
            printf("Enter command: ");
            scanf("%s", command);
            write(fd, command, strlen(command));
            printf("Command sent: %s\n", command);
        } else if (c == 'b') {
            char response[100];
            read(fd, response, 100);
            printf("Response received: %s\n", response);
        } else {
            printf("Invalid command\n");
        }
    }

    close(fd);
    return 0;
}