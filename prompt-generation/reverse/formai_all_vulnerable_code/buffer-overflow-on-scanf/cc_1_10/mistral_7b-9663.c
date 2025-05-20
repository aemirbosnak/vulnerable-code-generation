//MISTRAL-7B DATASET v1.0 Category: Smart home light control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>

#define I2C_ADDR 0x3F
#define LED_ON 0x01
#define LED_OFF 0x00

int main() {
    int fd, i2c_data;
    char buf[2];

    fd = open("/dev/i2c-1", O_RDWR);
    if (fd < 0) {
        perror("Failed to open i2c bus");
        exit(1);
    }

    if (ioctl(fd, I2C_SLAVE, I2C_ADDR) < 0) {
        perror("Failed to acquire bus access and/or talk to slave.");
        exit(1);
    }

    while (1) {
        printf("Enter light control command (on or off): ");
        scanf("%s", buf);

        if (strlen(buf) > 0) {
            if (strcasecmp(buf, "on") == 0) {
                i2c_data = LED_ON;
            } else if (strcasecmp(buf, "off") == 0) {
                i2c_data = LED_OFF;
            } else {
                printf("Invalid command.\n");
                continue;
            }

            buf[0] = (i2c_data & 0x01) << 1; // Set MSB to 1 for write operation
            write(fd, buf, 1);
            printf("Light %s.\n", buf);
        }

        usleep(500000); // Delay for 0.5 seconds before next iteration
    }

    close(fd);
    return 0;
}