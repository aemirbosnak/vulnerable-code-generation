//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265359
#define THETA 0.1
#define WHEEL_BASE 0.25
#define WHEEL_RADIUS 0.05
#define TICKS_PER_REVOLUTION 4096

int fd;
struct termios oldtio, newtio;

void setup() {
    fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        perror("Error opening serial port");
        exit(1);
    }

    if (tcgetattr(fd, &oldtio)!= 0) {
        perror("Error getting serial port attributes");
        exit(1);
    }

    newtio = oldtio;
    newtio.c_cflag = B9600 | CS8 | CREAD | CLOCAL;
    newtio.c_iflag = IGNPAR;
    newtio.c_oflag = 0;
    newtio.c_lflag = 0;
    newtio.c_cc[VMIN] = 1;
    newtio.c_cc[VTIME] = 0;

    if (tcsetattr(fd, TCSANOW, &newtio)!= 0) {
        perror("Error setting serial port attributes");
        exit(1);
    }
}

void move(int left_speed, int right_speed) {
    char command[20];
    sprintf(command, "F%d,%d\r", left_speed, right_speed);
    write(fd, command, strlen(command));
}

void turn(int speed) {
    char command[10];
    sprintf(command, "T%d\r", speed);
    write(fd, command, strlen(command));
}

int main() {
    setup();

    while (1) {
        char c = getchar();
        if (c == 'w') {
            move(100, 100);
        } else if (c =='s') {
            move(-100, -100);
        } else if (c == 'a') {
            turn(-100);
        } else if (c == 'd') {
            turn(100);
        } else if (c == 'q') {
            break;
        }
    }

    tcsetattr(fd, TCSANOW, &oldtio);
    close(fd);

    return 0;
}