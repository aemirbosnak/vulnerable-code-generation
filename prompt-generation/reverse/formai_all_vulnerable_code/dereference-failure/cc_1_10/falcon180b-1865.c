//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>

#define BUFFER_LENGTH 100

// SPI device name
#define SPI_DEVICE "/dev/spidev0.0"

// GPIO pin for light control
#define GPIO_PIN 4

// SPI mode and speed
#define SPI_MODE 0
#define SPI_SPEED 1000000

// Function to initialize SPI
void init_spi() {
    int fd;
    struct spi_ioc_transfer tr = {0};

    fd = open(SPI_DEVICE, O_RDWR);
    if (fd < 0) {
        printf("Failed to open SPI device\n");
        exit(1);
    }

    tr.tx_buf = (unsigned long) malloc(BUFFER_LENGTH);
    tr.rx_buf = (unsigned long) malloc(BUFFER_LENGTH);
    tr.len = BUFFER_LENGTH;
    tr.speed_hz = SPI_SPEED;
    tr.bits_per_word = 8;
    tr.delay_usecs = 0;
    tr.cs_change = 0;

    if (ioctl(fd, SPI_IOC_MESSAGE(1), &tr) < 0) {
        printf("Failed to initialize SPI\n");
        exit(1);
    }

    close(fd);
}

// Function to set light on/off
void set_light(int on) {
    int fd;
    unsigned char data;

    fd = open(SPI_DEVICE, O_RDWR);
    if (fd < 0) {
        printf("Failed to open SPI device\n");
        exit(1);
    }

    data = on? 1 : 0;
    ioctl(fd, SPI_IOC_MESSAGE(1), &data);

    close(fd);
}

// Function to get light status
int get_light() {
    int fd;
    unsigned char data;
    int status;

    fd = open(SPI_DEVICE, O_RDWR);
    if (fd < 0) {
        printf("Failed to open SPI device\n");
        exit(1);
    }

    ioctl(fd, SPI_IOC_MESSAGE(1), &data);

    status = data & 0x01;

    close(fd);

    return status;
}

// Main function
int main() {
    init_spi();

    set_light(0);

    while (1) {
        if (get_light() == 0) {
            set_light(1);
        } else {
            set_light(0);
        }
        sleep(1);
    }

    return 0;
}