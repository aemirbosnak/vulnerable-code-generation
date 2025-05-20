//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sys/ioctl.h>

#define TEMP_SENSOR_DEVICE "/dev/ttyS0"
#define TEMP_SENSOR_BAUDRATE 9600

#define TEMP_OFFSET 30
#define TEMP_SCALE 5

int main(int argc, char *argv[]) {
    int fd;
    struct termios options;
    char buffer[64];
    float temperature;

    fd = open(TEMP_SENSOR_DEVICE, O_RDWR | O_NOCTTY);
    if (fd == -1) {
        printf("Error opening %s: %s\n", TEMP_SENSOR_DEVICE, strerror(errno));
        return 1;
    }

    tcgetattr(fd, &options);
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag |= CREAD | CLOCAL;
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        printf("Error setting attributes for %s: %s\n", TEMP_SENSOR_DEVICE, strerror(errno));
        return 1;
    }

    while (1) {
        if (read(fd, buffer, sizeof(buffer))!= -1) {
            temperature = (float)atoi(buffer) - TEMP_OFFSET;
            temperature *= TEMP_SCALE;
            printf("Current temperature: %.2f°C\n", temperature);
        }
        usleep(500000);
    }

    close(fd);
    return 0;
}