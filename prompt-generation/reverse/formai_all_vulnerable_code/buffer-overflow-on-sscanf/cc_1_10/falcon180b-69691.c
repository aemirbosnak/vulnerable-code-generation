//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#define I2C_SLAVE 0x0703

int i2c_dev;
char *i2c_dev_name = "/dev/i2c-0";
int addr = 0x4F;

void init_i2c(void) {
    if ((i2c_dev = open(i2c_dev_name, O_RDWR)) < 0) {
        printf("Failed to open the bus.\n");
        exit(1);
    }
    if (ioctl(i2c_dev, I2C_SLAVE, addr) < 0) {
        printf("Failed to acquire bus access and/or talk to slave.\n");
        exit(1);
    }
}

int read_temp(void) {
    int file;
    char buf[10];
    int value;

    snprintf(buf, sizeof(buf), "0x%02X", 0x00);
    if ((file = open("/sys/bus/i2c/devices/0-004F/temp1_input", O_RDONLY)) < 0) {
        printf("Failed to open file.\n");
        return -1;
    }
    if (read(file, buf, sizeof(buf))!= sizeof(buf)) {
        printf("Failed to read from file.\n");
        close(file);
        return -1;
    }
    close(file);

    sscanf(buf, "%d", &value);
    return value;
}

int main(int argc, char *argv[]) {
    init_i2c();
    while (1) {
        int temp = read_temp();
        if (temp == -1) {
            printf("Error reading temperature.\n");
        } else {
            printf("Temperature: %d°C\n", temp);
        }
        sleep(1);
    }
    return 0;
}