//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: Cryptic
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/types.h>
#include <linux/types.h>

#define I2C_SLAVE_ADDR 0x50
#define I2C_DATA_SIZE 4
#define I2C_READ 0x00
#define I2C_WRITE 0x01

int main()
{
    int i2c_fd;
    int status;
    int data[I2C_DATA_SIZE];
    char command[I2C_DATA_SIZE];

    if ((i2c_fd = open("/dev/i2c-1", O_RDWR)) < 0) {
        printf("Error opening i2c-1\n");
        return 1;
    }

    ioctl(i2c_fd, I2C_SLAVE, I2C_SLAVE_ADDR);

    printf("Enter command (0x00 = read, 0x01 = write): ");
    scanf("%s", command);

    if (strncmp(command, "0x00", 3) == 0) {
        printf("Reading data...\n");
        status = read(i2c_fd, data, I2C_DATA_SIZE);
        if (status < 0) {
            printf("Error reading data\n");
            return 1;
        }
        printf("Data read: %02X %02X %02X %02X\n", data[0], data[1], data[2], data[3]);
    } else if (strncmp(command, "0x01", 3) == 0) {
        printf("Writing data...\n");
        status = write(i2c_fd, data, I2C_DATA_SIZE);
        if (status < 0) {
            printf("Error writing data\n");
            return 1;
        }
        printf("Data written: %02X %02X %02X %02X\n", data[0], data[1], data[2], data[3]);
    } else {
        printf("Invalid command\n");
    }

    close(i2c_fd);

    return 0;
}