//MISTRAL-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>

#define I2C_ADDR 0x3F
#define BUF_SIZE 10

typedef struct {
    int x;
    int y;
    int speed;
    int left_motor;
    int right_motor;
} control_t;

void send_data(int fd, control_t data) {
    char buf[BUF_SIZE];
    int bytes_written;

    buf[0] = (data.x & 0xFF);
    buf[1] = (data.x >> 8) & 0xFF;
    buf[2] = (data.y & 0xFF);
    buf[3] = (data.y >> 8) & 0xFF;
    buf[4] = data.speed & 0xFF;
    buf[5] = (data.speed >> 8) & 0xFF;
    buf[6] = data.left_motor & 0xFF;
    buf[7] = (data.left_motor >> 8) & 0xFF;
    buf[8] = data.right_motor & 0xFF;
    buf[9] = (data.right_motor >> 8) & 0xFF;

    bytes_written = write(fd, buf, BUF_SIZE);
    if (bytes_written < 0) {
        perror("Error writing to I2C device");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int fd;
    control_t data;

    fd = open("/dev/i2c-1", O_RDWR);
    if (fd < 0) {
        perror("Error opening I2C device");
        exit(EXIT_FAILURE);
    }

    if (ioctl(fd, I2C_SLAVE, I2C_ADDR) < 0) {
        perror("Error setting I2C slave address");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Enter x, y, speed, left_motor and right_motor values: ");
        scanf("%d%d%d%d%d", &data.x, &data.y, &data.speed, &data.left_motor, &data.right_motor);
        send_data(fd, data);
        usleep(100000); // Wait for 0.1 seconds before sending next data
    }

    close(fd);
    return 0;
}