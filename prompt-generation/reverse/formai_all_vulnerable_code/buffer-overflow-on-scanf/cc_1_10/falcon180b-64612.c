//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#define I2C_DEVICE "/dev/i2c-1"
#define I2C_ADDR 0x20

int main() {
    int fd;
    char buff[10];
    int res;

    fd = open(I2C_DEVICE, O_RDWR);
    if (fd < 0) {
        perror("Error");
        exit(1);
    }

    if (ioctl(fd, I2C_SLAVE, I2C_ADDR) < 0) {
        perror("Error");
        exit(1);
    }

    while (1) {
        printf("Enter 'on' or 'off' to control the light: ");
        scanf("%s", buff);

        if (strcmp(buff, "on") == 0) {
            res = write(fd, "10101010", 8);
            if (res!= 8) {
                perror("Error");
                exit(1);
            }
        } else if (strcmp(buff, "off") == 0) {
            res = write(fd, "10101000", 8);
            if (res!= 8) {
                perror("Error");
                exit(1);
            }
        } else {
            printf("Invalid input\n");
        }
    }

    close(fd);
    return 0;
}