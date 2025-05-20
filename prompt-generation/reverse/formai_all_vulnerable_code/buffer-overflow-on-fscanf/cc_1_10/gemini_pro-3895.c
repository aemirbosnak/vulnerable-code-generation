//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <time.h>
#include <string.h>

#define TEMP_SENSOR_PATH "/sys/class/thermal/thermal_zone0/temp"
#define TEMP_WARNING_THRESHOLD 80000
#define TEMP_CRITICAL_THRESHOLD 90000
#define TEMP_FORMAT "%d\n"

bool read_temperature(int64_t *temp) {
    FILE *fp = fopen(TEMP_SENSOR_PATH, "r");
    if (fp == NULL) {
        return false;
    }

    int ret = fscanf(fp, TEMP_FORMAT, temp);
    fclose(fp);
    return ret == 1;
}

bool is_temperature_warning(int64_t temp) {
    return temp >= TEMP_WARNING_THRESHOLD;
}

bool is_temperature_critical(int64_t temp) {
    return temp >= TEMP_CRITICAL_THRESHOLD;
}

void log_temperature(int64_t temp) {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    char timestamp[32];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm);

    FILE *fp = fopen("temperature.log", "a");
    if (fp == NULL) {
        return;
    }

    fprintf(fp, "%s %" PRId64 "\n", timestamp, temp);
    fclose(fp);
}

int main() {
    int64_t temp;
    while (true) {
        if (!read_temperature(&temp)) {
            fprintf(stderr, "Error reading temperature\n");
            return EXIT_FAILURE;
        }

        log_temperature(temp);

        if (is_temperature_warning(temp)) {
            printf("Warning: Temperature is high (%ld)\n", temp);
        }

        if (is_temperature_critical(temp)) {
            printf("Critical: Temperature is too high (%ld)\n", temp);
            return EXIT_FAILURE;
        }

        sleep(1);
    }

    return EXIT_SUCCESS;
}