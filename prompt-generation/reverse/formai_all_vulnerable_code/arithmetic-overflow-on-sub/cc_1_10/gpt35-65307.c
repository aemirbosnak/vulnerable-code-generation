//FormAI DATASET v1.0 Category: Temperature monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#define TEMP_REG 0x00

int read_i2c_data(int fd, int reg) {
    unsigned char buffer[2];
    buffer[0] = reg;

    if (write(fd, buffer, 1) != 1) {
        printf("Error writing to i2c slave\n");
        return -1;
    }

    if (read(fd, buffer, 2) != 2) {
        printf("Error reading from i2c slave\n");
        return -1;
    }

    int value = ((buffer[0] << 8) | buffer[1]);
    value = value >> 4;

    return value;
}

int main(int argc, char *argv[]) {
    int file;
    char *filename = "/dev/i2c-1";
    int address = 0x48;         // default address
    int reg = TEMP_REG;         // default register
    int value;

    if (argc > 1) {
        address = strtol(argv[1], NULL, 0);
    }

    if ((file = open(filename, O_RDWR)) < 0) {
        printf("Failed to open i2c bus\n");
        exit(1);
    }

    if (ioctl(file, I2C_SLAVE, address) < 0) {
        printf("Failed to acquire bus access and/or talk to slave\n");
        exit(1);
    }

    while (1) {
        value = read_i2c_data(file, reg);

        float temp = value * 0.0625;

        printf("Temperature: %.2f°C\n", temp);

        sleep(1);
    }

    close(file);

    return 0;
}