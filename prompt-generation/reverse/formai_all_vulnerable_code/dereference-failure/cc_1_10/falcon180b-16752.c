//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

#define BAUDRATE B115200
#define SERIAL_DEVICE "/dev/ttyS0"

typedef struct {
    double x;
    double y;
    double z;
} Vector3D;

void initSerial(int fd) {
    struct termios options;
    tcgetattr(fd, &options);
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~(CSIZE | PARENB);
    options.c_cflag |= CS8;
    options.c_cflag &= ~CRTSCTS;
    tcsetattr(fd, TCSANOW, &options);
}

void sendData(int fd, char* data, int size) {
    write(fd, data, size);
}

void sendInt(int fd, int value) {
    char buffer[4];
    sprintf(buffer, "%d", value);
    sendData(fd, buffer, strlen(buffer));
}

void sendFloat(int fd, float value) {
    char buffer[6];
    sprintf(buffer, "%f", value);
    sendData(fd, buffer, strlen(buffer));
}

void sendVector3D(int fd, Vector3D vector) {
    sendFloat(fd, vector.x);
    sendFloat(fd, vector.y);
    sendFloat(fd, vector.z);
}

int main() {
    int fd = open(SERIAL_DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        printf("Error opening serial device\n");
        exit(1);
    }

    initSerial(fd);

    while (1) {
        Vector3D position;
        position.x = 0;
        position.y = 0;
        position.z = 0;

        sendVector3D(fd, position);

        usleep(100000); // 100ms
    }

    close(fd);
    return 0;
}