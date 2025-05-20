//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define TEMP_SENSOR_FILE "/sys/class/thermal/thermal_zone0/temp" // assuming a thermal sensor on Linux
#define ALERT_THRESHOLD 75000 // temperature threshold in millidegrees Celsius

void get_temperature(float *temp) {
    FILE *fp = fopen(TEMP_SENSOR_FILE, "r");
    if (fp == NULL) {
        perror("Error opening temperature sensor file");
        exit(EXIT_FAILURE);
    }

    int tempValue;
    fscanf(fp, "%d", &tempValue);
    fclose(fp);
    
    *temp = tempValue / 1000.0; // converting from millidegrees
}

void alert_high_temperature(float temp) {
    printf("ALERT: High temperature detected! Current temperature: %.1f°C\n", temp);
}

void log_temperature(float temp) {
    FILE *logFile = fopen("temperature_log.txt", "a");
    if (logFile == NULL) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }
    
    time_t now;
    time(&now);
    fprintf(logFile, "[%s] Temperature: %.1f°C\n", ctime(&now), temp);
    fclose(logFile);
}

void monitor_temperature() {
    float current_temp;
    
    while(1) {
        get_temperature(&current_temp);
        printf("Current Temperature: %.1f°C\n", current_temp);
        
        if (current_temp * 1000 > ALERT_THRESHOLD) {
            alert_high_temperature(current_temp);
        }

        log_temperature(current_temp);
        sleep(5); // wait for 5 seconds before checking again
    }
}

int main() {
    printf("Starting Temperature Monitor...\n");
    monitor_temperature();
    return 0;
}