//MISTRAL-7B DATASET v1.0 Category: Smart home light control ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>

#define LED_STRIP_ADDR 0x3F // Replace with the I2C address of your RGB LED strip controller
#define BUFFER_SIZE 32

int main() {
    int file;
    char buffer[BUFFER_SIZE];
    short r, g, b;

    if ((file = open("/dev/i2c-1", O_RDWR)) < 0) {
        perror("Failed to open I2C bus");
        return 1;
    }

    if (ioctl(file, I2C_SLAVE, LED_STRIP_ADDR) < 0) {
        perror("Failed to open RGB LED strip controller");
        close(file);
        return 1;
    }

    printf("RGB LED Strip Controller connected at address %#x\n", LED_STRIP_ADDR);

    while (1) {
        printf("Enter RGB values (R G B): ");
        scanf("%hhd%hhd%hhd", &r, &g, &b);

        buffer[0] = 0x01; // Set mode to single color
        buffer[1] = r >> 2; // Red high byte
        buffer[2] = r & 0x1F; // Red low byte
        buffer[3] = g >> 2; // Green high byte
        buffer[4] = g & 0x1F; // Green low byte
        buffer[5] = b >> 2; // Blue high byte
        buffer[6] = b & 0x1F; // Blue low byte

        if (write(file, buffer, 7) != 7) {
            perror("Failed to write to RGB LED strip controller");
            close(file);
            return 1;
        }

        printf("RGB: %hhd %hhd %hhd\n", r, g, b);
        sleep(1);
    }

    close(file);
    return 0;
}