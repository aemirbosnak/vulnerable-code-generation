//MISTRAL-7B DATASET v1.0 Category: Temperature monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <string.h>

#define I2C_ADDR 0x27
#define BUFFER_SIZE 3

struct i2c_data {
    int temp_raw;
    float temp_celsius;
};

void i2c_read_temp_raw(int file, struct i2c_data *data) {
    int ret = ioctl(file, I2C_RDWR, (union ion_union_rw *)data);
    if (ret < 0) {
        perror("Failed to read temperature data");
        exit(EXIT_FAILURE);
    }

    data->temp_raw = ((data->temp_raw << 8) | (data->temp_raw >> 8));
    data->temp_celsius = (data->temp_raw / 16.0);
}

int main() {
    int i2c_file;
    int addr = I2C_ADDR << 1;
    char buf[BUFFER_SIZE];
    struct i2c_data temp_data;

    // Open I2C bus
    if ((i2c_file = open("/dev/i2c-1", O_RDWR)) < 0) {
        perror("Failed to open I2C bus");
        exit(EXIT_FAILURE);
    }

    // Set slave address
    if (ioctl(i2c_file, I2C_SLAVE, addr) < 0) {
        perror("Failed to set slave address");
        exit(EXIT_FAILURE);
    }

    printf("Welcome to the FutureTherm 3000 Temperature Monitoring System!\n");
    printf("=====================================================\n");

    while (1) {
        i2c_read_temp_raw(i2c_file, &temp_data);
        printf("Temperature: %.2f degrees Celsius\n", temp_data.temp_celsius);
        sleep(1);
    }

    // Close I2C bus
    close(i2c_file);

    return 0;
}