//MISTRAL-7B DATASET v1.0 Category: Smart home light control ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>

#define I2C_ADDR 0x20
#define LED_ON  0x01
#define LED_OFF 0x00

int main() {
    int file, i2c_data;
    char buffer[2];
    char filename[10] = "/dev/i2c-1";

    if ((file = open(filename, O_RDWR)) < 0) {
        perror("Failed to open I2C bus");
        exit(1);
    }

    if (ioctl(file, I2C_SLAVE, I2C_ADDR) < 0) {
        perror("Failed to select device");
        exit(1);
    }

    while (1) {
        printf("Enter a command (ON/OFF): ");
        scanf("%s", buffer);

        if (strlen(buffer) > 1) {
            printf("Invalid command. Use ON or OFF.\n");
            continue;
        }

        if (strcmp(buffer, "ON") == 0) {
            i2c_data = LED_ON;
        } else if (strcmp(buffer, "OFF") == 0) {
            i2c_data = LED_OFF;
        } else {
            printf("Invalid command. Use ON or OFF.\n");
            continue;
        }

        buffer[0] = i2c_data;
        if (write(file, buffer, 1) != 1) {
            perror("Failed to write to device");
            exit(1);
        }

        printf("Light %s\n", buffer[0] == LED_ON ? "turned on" : "turned off");
        sleep(1);
    }

    if (close(file) < 0) {
        perror("Failed to close I2C bus");
        exit(1);
    }

    return 0;
}