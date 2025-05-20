//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUD_RATE 9600
#define DATA_BITS 8
#define PARITY 'N'
#define STOP_BITS 1

#define MOTOR_1 0
#define MOTOR_2 1
#define MOTOR_3 2
#define MOTOR_4 3

#define PWM_MIN 1000
#define PWM_MAX 2000

int fd;
struct termios options;

void setupSerial() {
    fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY);
    if (fd == -1) {
        printf("Error opening serial port\n");
        exit(1);
    }

    tcgetattr(fd, &options);
    cfsetispeed(&options, BAUD_RATE);
    cfsetospeed(&options, BAUD_RATE);
    options.c_cflag |= (PARITY | CLOCAL | CREAD);
    options.c_cflag &= ~CRTSCTS;
    options.c_iflag |= IGNPAR;
    options.c_oflag = 0;
    tcsetattr(fd, TCSANOW, &options);
}

void sendCommand(int motor, int speed) {
    char command[10];
    sprintf(command, "%d%c", speed, motor + 'A');
    write(fd, command, strlen(command));
}

int main() {
    setupSerial();

    while (1) {
        char input[10];
        read(fd, input, 10);

        int motor = input[0] - 'A';
        int speed = input[1] - '0';

        if (motor >= 0 && motor <= 3) {
            sendCommand(motor, speed);
        }
    }

    return 0;
}