//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#define I2C_DEV "/dev/i2c-1"
#define I2C_ADDR 0x50

int main() {
    int i2c_fd = open(I2C_DEV, O_RDWR);
    if (i2c_fd < 0) {
        perror("open");
        return -1;
    }

    if (ioctl(i2c_fd, I2C_SLAVE_FORCE, I2C_ADDR) < 0) {
        perror("ioctl");
        close(i2c_fd);
        return -1;
    }

    unsigned char buf[16];
    int ret;

    while (true) {
        printf("Enter command: ");
        scanf("%s", buf);

        ret = write(i2c_fd, buf, sizeof(buf));
        if (ret < 0) {
            perror("write");
            close(i2c_fd);
            return -1;
        }

        ret = read(i2c_fd, buf, sizeof(buf));
        if (ret < 0) {
            perror("read");
            close(i2c_fd);
            return -1;
        }

        printf("Response: ");
        for (int i = 0; i < ret; i++) {
            printf("%02X ", buf[i]);
        }
        printf("\n");
    }

    close(i2c_fd);
    return 0;
}