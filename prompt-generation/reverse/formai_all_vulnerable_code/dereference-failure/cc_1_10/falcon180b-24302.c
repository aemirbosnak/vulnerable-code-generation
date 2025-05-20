//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#define I2C_SLAVE "0x4a"

int main() {
    // Open the I2C bus
    int file;
    char filename[10] = "/dev/i2c-1";
    if ((file = open(filename, O_RDWR)) < 0) {
        printf("Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    // Set the slave address
    if (ioctl(file, I2C_SLAVE, I2C_SLAVE) < 0) {
        printf("Error setting slave address: %s\n", strerror(errno));
        exit(1);
    }

    // Write to the I2C bus
    char write_buffer[] = "Hello, world!";
    if (write(file, write_buffer, strlen(write_buffer))!= strlen(write_buffer)) {
        printf("Error writing to file: %s\n", strerror(errno));
        exit(1);
    }

    // Read from the I2C bus
    char read_buffer[100];
    if (read(file, read_buffer, sizeof(read_buffer)) < 0) {
        printf("Error reading from file: %s\n", strerror(errno));
        exit(1);
    }

    // Close the I2C bus
    if (close(file) < 0) {
        printf("Error closing file: %s\n", strerror(errno));
        exit(1);
    }

    printf("Read from I2C bus: %s\n", read_buffer);

    return 0;
}