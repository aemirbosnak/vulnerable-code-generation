//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <termios.h>
#include <errno.h>

#define DEV_PATH "/dev/ttyUSB0"
#define BAUD_RATE 9600
#define TIMEOUT 1000

#define LIGHT_ON "LIGHT_ON\r"
#define LIGHT_OFF "LIGHT_OFF\r"

#define MAX_COMMAND_LENGTH 50

int main() {
    int fd;
    struct termios options;

    // Open serial port
    fd = open(DEV_PATH, O_RDWR | O_NOCTTY);
    if (fd == -1) {
        printf("Error opening serial port: %s\n", strerror(errno));
        exit(1);
    }

    // Set serial port options
    memset(&options, 0, sizeof(options));
    options.c_cflag = BAUD_RATE | CS8 | CREAD | CLOCAL;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        printf("Error setting serial port options: %s\n", strerror(errno));
        exit(1);
    }

    // Main loop
    char command[MAX_COMMAND_LENGTH];
    while (1) {
        printf("Enter command (LIGHT_ON/LIGHT_OFF): ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, LIGHT_ON) == 0) {
            if (write(fd, LIGHT_ON, strlen(LIGHT_ON))!= strlen(LIGHT_ON)) {
                printf("Error writing to serial port: %s\n", strerror(errno));
                exit(1);
            }
        } else if (strcmp(command, LIGHT_OFF) == 0) {
            if (write(fd, LIGHT_OFF, strlen(LIGHT_OFF))!= strlen(LIGHT_OFF)) {
                printf("Error writing to serial port: %s\n", strerror(errno));
                exit(1);
            }
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}