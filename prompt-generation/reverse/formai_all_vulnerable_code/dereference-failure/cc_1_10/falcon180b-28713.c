//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define DEBUG 0

#if DEBUG
#define LOG(fmt,...) fprintf(stdout, fmt, ##__VA_ARGS__)
#else
#define LOG(fmt,...) {}
#endif

#define TEMP_SENSOR_FILE "/sys/class/thermal/thermal_zone0/temp"
#define TEMP_THRESHOLD 80
#define TEMP_CHECK_INTERVAL 5  // in seconds

int main() {
    int fd, temp;
    char temp_buf[10];

    fd = open(TEMP_SENSOR_FILE, O_RDONLY);
    if (fd == -1) {
        LOG("Failed to open temperature sensor file: %s\n", strerror(errno));
        return 1;
    }

    while (1) {
        if (read(fd, temp_buf, sizeof(temp_buf))!= sizeof(temp_buf)) {
            LOG("Failed to read temperature sensor: %s\n", strerror(errno));
            close(fd);
            return 1;
        }

        temp = atoi(temp_buf);
        if (temp > TEMP_THRESHOLD) {
            LOG("Temperature is too high: %d°C\n", temp);
        }

        close(fd);
        fd = open(TEMP_SENSOR_FILE, O_RDONLY);
        if (fd == -1) {
            LOG("Failed to reopen temperature sensor file: %s\n", strerror(errno));
            return 1;
        }

        sleep(TEMP_CHECK_INTERVAL);
    }

    return 0;
}