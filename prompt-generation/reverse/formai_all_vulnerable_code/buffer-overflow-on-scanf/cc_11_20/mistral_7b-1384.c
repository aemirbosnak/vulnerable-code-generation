//MISTRAL-7B DATASET v1.0 Category: Drone Remote Control ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>

#define I2C_ADDR 0x2A
#define BUFFER_SIZE 256

int main(int argc, char **argv) {
    int fd, i, x, y, z;
    char buffer[BUFFER_SIZE];

    if ((fd = open("/dev/i2c-1", O_RDWR)) < 0) {
        perror("Failed to open i2c bus");
        return 1;
    }

    if (ioctl(fd, I2C_SLAVE, I2C_ADDR) < 0) {
        perror("Failed to connect to drone");
        close(fd);
        return 1;
    }

    while (1) {
        printf("Enter x, y, z values (0-255): ");
        scanf("%d %d %d", &x, &y, &z);

        if (x < 0 || x > 255 || y < 0 || y > 255 || z < 0 || z > 255) {
            printf("Invalid values. Try again.\n");
            continue;
        }

        buffer[0] = (x >> 2) & 0x03;
        buffer[1] = (x >> 0) & 0x3F;
        buffer[2] = (y >> 2) & 0x03;
        buffer[3] = (y >> 0) & 0x3F;
        buffer[4] = (z >> 2) & 0x03;
        buffer[5] = (z >> 0) & 0x3F;

        if (write(fd, buffer, 6) != 6) {
            perror("Failed to send data to drone");
            close(fd);
            return 1;
        }

        usleep(50000); // Delay between commands
    }

    close(fd);
    return 0;
}