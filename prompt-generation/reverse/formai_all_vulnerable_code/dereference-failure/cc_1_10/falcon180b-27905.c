//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <fcntl.h>
#include <errno.h>

#define BAUD B9600
#define DEV "/dev/ttyS0"

int fd;
struct termios oldtio, newtio;

void setup() {
    if ((fd = open(DEV, O_RDWR | O_NOCTTY | O_NDELAY)) == -1) {
        printf("Error opening %s: %s\n", DEV, strerror(errno));
        exit(1);
    }

    if (tcgetattr(fd, &oldtio)!= 0) {
        printf("Error tcgetattr: %s\n", strerror(errno));
        exit(1);
    }

    newtio = oldtio;
    newtio.c_cflag = BAUD | CS8 | CLOCAL | CREAD;
    newtio.c_iflag = IGNPAR;
    newtio.c_oflag = 0;
    newtio.c_lflag = 0;

    if (tcsetattr(fd, TCSANOW, &newtio)!= 0) {
        printf("Error tcsetattr: %s\n", strerror(errno));
        exit(1);
    }

    printf("Setup complete.\n");
}

void loop() {
    char input;

    while (1) {
        if (read(fd, &input, 1)!= 1) {
            printf("Error reading from %s: %s\n", DEV, strerror(errno));
            exit(1);
        }

        switch (input) {
            case 'w':
                printf("Vehicle moving forward.\n");
                break;
            case's':
                printf("Vehicle moving backward.\n");
                break;
            case 'a':
                printf("Vehicle turning left.\n");
                break;
            case 'd':
                printf("Vehicle turning right.\n");
                break;
            case 'q':
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }
}

int main() {
    setup();
    loop();

    return 0;
}