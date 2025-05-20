//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>

#define TEMP_SENSOR_FILE "/sys/class/thermal/thermal_zone0/temp"
#define TEMPERATURE_THRESHOLD 75000 // Temperature in millidegree Celsius (75°C)
#define CHECK_INTERVAL 5 // In seconds

volatile sig_atomic_t termination_requested = false;

void handle_signal(int signal) {
    if (signal == SIGINT || signal == SIGTERM) {
        termination_requested = true;
    }
}

double read_temperature() {
    FILE *file = fopen(TEMP_SENSOR_FILE, "r");
    if (file == NULL) {
        perror("Failed to open temperature sensor file");
        return -1;
    }

    int temp_millidegree;
    if (fscanf(file, "%d", &temp_millidegree) != 1) {
        perror("Failed to read temperature");
        fclose(file);
        return -1;
    }
    fclose(file);
    return temp_millidegree / 1000.0; // Convert millidegree Celsius to degree Celsius
}

void *monitor_temperature(void *arg) {
    while (!termination_requested) {
        double temperature = read_temperature();
        if (temperature < 0) {
            fprintf(stderr, "Error reading temperature\n");
            sleep(CHECK_INTERVAL);
            continue;
        }

        printf("Current Temperature: %.2f°C\n", temperature);
        if (temperature > (TEMPERATURE_THRESHOLD / 1000.0)) {
            fprintf(stderr, "Warning: Temperature exceeds threshold! Current: %.2f°C\n", temperature);
        }

        sleep(CHECK_INTERVAL);
    }
    return NULL;
}

int main() {
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    pthread_t monitor_thread;
    if (pthread_create(&monitor_thread, NULL, monitor_temperature, NULL) != 0) {
        perror("Failed to create monitoring thread");
        return EXIT_FAILURE;
    }

    printf("Temperature Monitor started. Press Ctrl+C to stop.\n");

    pthread_join(monitor_thread, NULL);
    printf("Temperature Monitor terminated.\n");
    return EXIT_SUCCESS;
}