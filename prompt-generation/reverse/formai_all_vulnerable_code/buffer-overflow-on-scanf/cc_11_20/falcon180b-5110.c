//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

#define BAUDRATE B9600
#define SERIAL_DEVICE "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;

    // Open the serial port
    fd = open(SERIAL_DEVICE, O_RDWR);
    if (fd == -1) {
        printf("Error: Could not open serial port\n");
        return 1;
    }

    // Configure the serial port
    memset(&options, 0, sizeof(options));
    options.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        printf("Error: Could not configure serial port\n");
        close(fd);
        return 1;
    }

    // Send commands to the drone
    char command[100];
    strcpy(command, "AT\r");
    write(fd, command, strlen(command));

    while (1) {
        char input[100];
        printf("Enter a command: ");
        scanf("%s", input);

        if (strcmp(input, "takeoff") == 0) {
            strcpy(command, "AT*REF=0,0,0,0,0\r");
        } else if (strcmp(input, "land") == 0) {
            strcpy(command, "AT*REF=1,0,0,0,0\r");
        } else if (strcmp(input, "left") == 0) {
            strcpy(command, "AT*REF=0,0,0,1,0\r");
        } else if (strcmp(input, "right") == 0) {
            strcpy(command, "AT*REF=0,0,0,-1,0\r");
        } else if (strcmp(input, "forward") == 0) {
            strcpy(command, "AT*REF=0,0,1,0,0\r");
        } else if (strcmp(input, "backward") == 0) {
            strcpy(command, "AT*REF=0,0,-1,0,0\r");
        } else if (strcmp(input, "up") == 0) {
            strcpy(command, "AT*REF=0,1,0,0,0\r");
        } else if (strcmp(input, "down") == 0) {
            strcpy(command, "AT*REF=0,-1,0,0,0\r");
        }

        write(fd, command, strlen(command));
    }

    close(fd);
    return 0;
}