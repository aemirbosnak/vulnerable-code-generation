//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>

#define I2C_ADDR 0x60
#define I2C_BUS 1

struct i2c_data {
    int client;
    int x;
    int y;
};

int main() {
    struct i2c_data fd;
    int file;
    char buf[2];
    int x, y;

    if ((file = open("/dev/i2c-1", O_RDWR)) < 0) {
        perror("Can't open i2c-1\n");
        exit(1);
    }

    if (ioctl(file, I2C_SLAVE, I2C_ADDR) < 0) {
        perror("Can't talk to slave.\n");
        exit(1);
    }

    fd.client = file;

    while (1) {
        buf[0] = 0x31;
        buf[1] = 0x0A;
        write(file, buf, 2);

        usleep(100000);

        read(file, buf, 2);

        x = buf[0] << 8 | buf[1];
        y = buf[2] << 8 | buf[3];

        printf("X: %d, Y: %d\n", x, y);

        fd.x = x;
        fd.y = y;

        if (x > 100 || x < -100 || y > 100 || y < -100) {
            printf("Out of range!\n");
            fd.client = -1;
            break;
        }

        if (x > fd.x && y > fd.y) {
            printf("Quadrant I\n");
        } else if (x > fd.x && y < fd.y) {
            printf("Quadrant II\n");
        } else if (x < fd.x && y > fd.y) {
            printf("Quadrant III\n");
        } else if (x < fd.x && y < fd.y) {
            printf("Quadrant IV\n");
        } else {
            printf("Origin\n");
        }

        fd.x = x;
        fd.y = y;

        sleep(1);
    }

    if (fd.client >= 0) {
        close(fd.client);
    }

    return 0;
}