//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <math.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"
#define PI 3.14159265358979323846

typedef struct {
    int throttle;
    int roll;
    int pitch;
    int yaw;
} DroneData;

void init_termios(speed_t baudrate) {
    struct termios options;
    tcgetattr(0, &options);
    cfsetispeed(&options, baudrate);
    cfsetospeed(&options, baudrate);
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~(PARENB | PARODD | CSTOPB);
    options.c_cflag |= CS8;
    options.c_iflag |= (IGNBRK | IGNPAR);
    options.c_oflag = 0;
    tcsetattr(0, TCSANOW, &options);
}

void send_data(int fd, DroneData data) {
    char buffer[10];
    sprintf(buffer, "%d,%d,%d,%d\n", data.throttle, data.roll, data.pitch, data.yaw);
    write(fd, buffer, strlen(buffer));
}

int main() {
    int fd;
    DroneData data;

    fd = open(DEVICE, O_RDWR);
    if (fd < 0) {
        printf("Error opening device\n");
        return 1;
    }

    init_termios(BAUDRATE);

    while (1) {
        printf("Enter drone data (throttle, roll, pitch, yaw): ");
        scanf("%d,%d,%d,%d", &data.throttle, &data.roll, &data.pitch, &data.yaw);
        send_data(fd, data);
        usleep(100000);
    }

    close(fd);
    return 0;
}