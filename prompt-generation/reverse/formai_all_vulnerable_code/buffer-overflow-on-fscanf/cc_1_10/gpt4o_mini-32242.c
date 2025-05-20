//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define TEMP_SENSOR "/sys/class/thermal/thermal_zone0/temp"
#define MAX_TEMP 75000      // Maximum temperature reading in millidegree Celsius
#define MIN_TEMP -10000     // Minimum temperature reading in millidegree Celsius
#define TEMP_UPDATE_INTERVAL 5 // Interval in seconds

void whisper_temperature(float temp) {
    if (temp < MIN_TEMP || temp > MAX_TEMP) {
        printf("⚠️   Out of bounds!  — Temperature unreadable ⚠️   \n");
    } else if (temp < 20000) {
        printf("❄️   Ice Age! —  Temperature: %.2f°C\n", temp / 1000.0);
    } else if (temp < 30000) {
        printf("🌡️   Chilly vibes! —  Temperature: %.2f°C\n", temp / 1000.0);
    } else if (temp < 35000) {
        printf("☀️   Pleasant! —  Temperature: %.2f°C\n", temp / 1000.0);
    } else if (temp < 40000) {
        printf("🔥   Warm embrace! —  Temperature: %.2f°C\n", temp / 1000.0);
    } else {
        printf("🌡️   Hot tamale! —  Temperature: %.2f°C\n", temp / 1000.0);
    }
}

int temp_read() {
    FILE *fp;
    int value;

    fp = fopen(TEMP_SENSOR, "r");
    if (fp == NULL) {
        perror("Can't read temperature");
        return -1;
    }
    fscanf(fp, "%d", &value);
    fclose(fp);
    return value;
}

void watch_forever() {
    while (1) {
        int current_temp = temp_read();
        if (current_temp != -1) {
            whisper_temperature(current_temp);
        }
        sleep(TEMP_UPDATE_INTERVAL);
    }
}

int main() {
    printf("🌡️   Welcome to the C Temperature Monitor! 🌡️   \n");
    printf("📊   Monitoring system temperature...\n");
    
    watch_forever();

    return 0;
}