//MISTRAL-7B DATASET v1.0 Category: Smart home light control ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>

// I2C address of the RGB LED
#define LED_I2C_ADDR 0x20

// Register addresses for RGB LED
#define LED_REG_MODE 0x00
#define LED_REG_RED 0x01
#define LED_REG_GREEN 0x02
#define LED_REG_BLUE 0x03

int main(void) {
    int fd, i;
    char buf[2];
    int mode = 1; // 1 for RGB, 2 for color cycling

    // Open I2C bus
    if ((fd = open("/dev/i2c-1", O_RDWR)) < 0) {
        perror("Failed to open I2C bus");
        exit(1);
    }

    // Attach slave I2C address
    if (ioctl(fd, I2C_SLAVE, LED_I2C_ADDR) < 0) {
        perror("Failed to attach I2C slave address");
        exit(1);
    }

    while (1) {
        switch (mode) {
            case 1: // RGB control
                printf("Enter RGB values (0-255 for each color): ");
                scanf("%d%d%d", &buf[0], &buf[1], &buf[2]);

                if (write(fd, &buf, 3) != 3) {
                    perror("Failed to write to RGB LED");
                    exit(1);
                }

                usleep(500000); // Delay to allow LED to update

                printf("RGB values set to: %d, %d, %d\n", buf[0], buf[1], buf[2]);
                break;

            case 2: // Color cycling
                for (i = 0; i < 360; i += 5) {
                    buf[0] = (i / 360.0f) * 255.0f;
                    buf[1] = (i % 120) * 255.0f / 120.0f;
                    buf[2] = 255.0f - (buf[0] + buf[1]);

                    if (write(fd, &buf, 3) != 3) {
                        perror("Failed to write to RGB LED");
                        exit(1);
                    }

                    usleep(50000); // Delay to allow LED to update
                }

                mode = 1;
                break;
        }

        printf("Press 1 for RGB, 2 for color cycling: ");
        scanf("%d", &mode);
    }

    // Close I2C bus
    close(fd);

    return 0;
}