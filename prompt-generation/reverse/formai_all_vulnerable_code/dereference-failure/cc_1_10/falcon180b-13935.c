//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#define I2C_SLAVE "i2c-1"
#define LIGHT_ON 0x01
#define LIGHT_OFF 0x00

int main(int argc, char **argv) {
    int file;
    char *devpath = "/dev/i2c-1";
    int addr = 0x20;
    unsigned char data = 0x00;

    if (argc < 3) {
        printf("Usage: %s <i2c_device_address> <on|off>\n", argv[0]);
        return 1;
    }

    file = open(devpath, O_RDWR);
    if (file < 0) {
        printf("Error opening i2c device.\n");
        return 1;
    }

    if (ioctl(file, I2C_SLAVE, addr) < 0) {
        printf("Error setting i2c slave address.\n");
        return 1;
    }

    if (strcmp(argv[1], "on") == 0) {
        data = LIGHT_ON;
    } else if (strcmp(argv[1], "off") == 0) {
        data = LIGHT_OFF;
    } else {
        printf("Invalid command.\n");
        return 1;
    }

    if (write(file, &data, 1)!= 1) {
        printf("Error writing to i2c device.\n");
        return 1;
    }

    printf("Light set to %s.\n", argv[1]);
    close(file);
    return 0;
}