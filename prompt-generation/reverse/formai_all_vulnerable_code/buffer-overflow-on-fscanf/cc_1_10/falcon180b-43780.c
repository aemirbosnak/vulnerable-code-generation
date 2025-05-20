//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define TEMP_SENSOR_FILE "/sys/class/thermal/thermal_zone0/temp"
#define TEMP_THRESHOLD 70
#define ALERT_FILE "/tmp/temperature_alert"

void log_temperature(int temperature) {
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm_now);

    FILE *fp = fopen("temperature.log", "a");
    if (fp == NULL) {
        printf("Error opening log file\n");
        exit(1);
    }

    fprintf(fp, "%s: Temperature = %dC\n", timestamp, temperature);
    fclose(fp);
}

void send_alert(int temperature) {
    FILE *fp = fopen(ALERT_FILE, "w");
    if (fp == NULL) {
        printf("Error opening alert file\n");
        exit(1);
    }

    fprintf(fp, "Temperature threshold exceeded: %dC", temperature);
    fclose(fp);
}

int read_temperature() {
    FILE *fp = fopen(TEMP_SENSOR_FILE, "r");
    if (fp == NULL) {
        printf("Error opening temperature sensor file\n");
        exit(1);
    }

    int temperature;
    fscanf(fp, "%d", &temperature);
    fclose(fp);

    return temperature;
}

int main() {
    while (1) {
        int temperature = read_temperature();
        log_temperature(temperature);

        if (temperature >= TEMP_THRESHOLD) {
            send_alert(temperature);
        }

        sleep(5);
    }

    return 0;
}