//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <string.h>

#define TEMPERATURE_SENSOR_PATH "/sys/class/thermal/thermal_zone0/temp"
#define MAX_TEMP_LIMIT 80000
#define TEMPERATURE_CHECK_INTERVAL 2 // in seconds
#define LOG_FILE "temperature_log.txt"

pthread_mutex_t lock;
int alert_triggered = 0;

void *temperature_monitor(void *arg) {
    while (1) {
        FILE *fp = fopen(TEMPERATURE_SENSOR_PATH, "r");
        if (fp == NULL) {
            perror("Error opening temperature sensor file");
            continue; // Retry next check
        }

        int temp;
        fscanf(fp, "%d", &temp);
        fclose(fp);

        // Convert milliCelsius to Celsius
        float celsius_temp = temp / 1000.0;

        // Lock for thread safety
        pthread_mutex_lock(&lock);
        printf("Current Temperature: %.2f °C\n", celsius_temp);

        if (celsius_temp > MAX_TEMP_LIMIT / 1000.0) {
            if (!alert_triggered) {
                printf("ALERT: Temperature exceeds safe limits!\n");
                alert_triggered = 1;
                // Log the alert
                FILE *log_fp = fopen(LOG_FILE, "a");
                if (log_fp != NULL) {
                    fprintf(log_fp, "ALERT: Temperature reached %.2f °C\n", celsius_temp);
                    fclose(log_fp);
                }
            }
        } else {
            alert_triggered = 0; // Reset alert if temperature is safe
        }
        
        pthread_mutex_unlock(&lock);
        sleep(TEMPERATURE_CHECK_INTERVAL);
    }
}

int main() {
    pthread_t monitor_thread;

    // Initialize mutex
    if (pthread_mutex_init(&lock, NULL) != 0) {
        fprintf(stderr, "Error initializing mutex\n");
        return EXIT_FAILURE;
    }

    // Create a dedicated thread for monitoring temperature
    if (pthread_create(&monitor_thread, NULL, temperature_monitor, NULL) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return EXIT_FAILURE;
    }

    // Join the thread (we won't actually reach this point in this loop)
    pthread_join(monitor_thread, NULL);

    // Clean up mutex (not reached in this loop but good practice)
    pthread_mutex_destroy(&lock);

    return EXIT_SUCCESS;
}