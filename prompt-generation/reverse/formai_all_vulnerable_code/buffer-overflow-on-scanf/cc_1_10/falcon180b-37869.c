//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUDRATE B9600
#define SERIAL_PORT "/dev/ttyUSB0"

void init_serial(int fd) {
    struct termios options;
    tcgetattr(fd, &options);
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~(CSIZE | PARENB);
    options.c_cflag |= CS8;
    options.c_cc[VTIME] = 5;
    options.c_cc[VMIN] = 0;
    tcsetattr(fd, TCSANOW, &options);
}

int main() {
    int fd;
    char serial_port[100] = SERIAL_PORT;

    fd = open(serial_port, O_RDWR | O_NOCTTY | O_SYNC);

    if (fd < 0) {
        perror("Error opening serial port");
        return 1;
    }

    init_serial(fd);

    while (1) {
        char command[100];
        int nbytes;

        printf("Enter command: ");
        scanf("%s", command);

        nbytes = write(fd, command, strlen(command));

        if (nbytes < 0) {
            perror("Error writing to serial port");
            return 1;
        }

        memset(command, 0, sizeof(command));
        nbytes = read(fd, command, sizeof(command));

        if (nbytes > 0) {
            printf("Received response: %s\n", command);
        } else if (nbytes == 0) {
            printf("No data received\n");
        } else {
            perror("Error reading from serial port");
            return 1;
        }
    }

    close(fd);
    return 0;
}