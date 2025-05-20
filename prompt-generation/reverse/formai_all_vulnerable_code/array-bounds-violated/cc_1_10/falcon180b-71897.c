//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

int main(void) {
    int fd;
    struct termios options;

    // Open the serial port
    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd == -1) {
        printf("Error opening %s\n", DEVICE);
        exit(1);
    }

    // Set the serial port options
    tcgetattr(fd, &options);
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag |= CS8;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;
    tcsetattr(fd, TCSANOW, &options);

    // Main loop
    while (1) {
        char buffer[128];
        int bytes_read = read(fd, buffer, sizeof(buffer));

        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';
            printf("%s\n", buffer);
        }
    }

    close(fd);
    return 0;
}