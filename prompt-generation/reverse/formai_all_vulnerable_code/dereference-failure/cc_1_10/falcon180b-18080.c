//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <sys/ioctl.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"
#define SERIAL_TIMEOUT 1000
#define BUFFER_SIZE 64

int main() {
    int fd;
    struct termios options;
    char buffer[BUFFER_SIZE];

    // Open serial port
    fd = open(DEVICE, O_RDWR);
    if (fd == -1) {
        printf("Error opening serial port: %s\n", strerror(errno));
        return 1;
    }

    // Configure serial port
    if (tcgetattr(fd, &options)!= 0) {
        printf("Error getting serial port attributes: %s\n", strerror(errno));
        return 1;
    }

    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    options.c_cflag |= PARENB;
    options.c_cflag &= ~PARODD;
    options.c_cflag |= CSTOPB;

    options.c_iflag = IGNBRK;
    options.c_oflag = 0;

    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        printf("Error setting serial port attributes: %s\n", strerror(errno));
        return 1;
    }

    // Main loop
    while (1) {
        // Send commands
        char command[10];
        strcpy(command, "TAKEOFF\r");
        write(fd, command, strlen(command));
        sleep(1);

        strcpy(command, "LAND\r");
        write(fd, command, strlen(command));
        sleep(1);

        // Read response
        int bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0) {
            printf("Error reading from serial port: %s\n", strerror(errno));
            return 1;
        }

        printf("Received: %s\n", buffer);
    }

    close(fd);
    return 0;
}