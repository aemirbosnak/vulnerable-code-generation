//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define TEMP_SENSOR_PATH "/sys/class/thermal/thermal_zone0/temp"
#define HIGH_THRESHOLD 75000 // Celsius * 1000
#define LOW_THRESHOLD 10000  // Celsius * 1000
#define SLEEP_INTERVAL 5 // seconds

volatile sig_atomic_t stop_monitoring = 0;

void handle_sigint(int sig) {
    stop_monitoring = 1;
}

int read_temperature() {
    FILE *file = fopen(TEMP_SENSOR_PATH, "r");
    if (file == NULL) {
        perror("Could not open temperature sensor file");
        return -1;
    }
    int temp;
    fscanf(file, "%d", &temp);
    fclose(file);
    return temp;
}

void monitor_temperature() {
    while (!stop_monitoring) {
        int current_temp = read_temperature();
        if (current_temp == -1) {
            printf("Failed to read temperature.\n");
            break;
        }

        current_temp /= 1000; // Convert to Celsius
        printf("Current Temperature: %d°C\n", current_temp);

        if (current_temp > HIGH_THRESHOLD / 1000) {
            printf("WARNING: HIGH TEMPERATURE ALERT! (%d°C)\n", current_temp);
        } else if (current_temp < LOW_THRESHOLD / 1000) {
            printf("WARNING: LOW TEMPERATURE ALERT! (%d°C)\n", current_temp);
        }

        sleep(SLEEP_INTERVAL);
    }
}

int main() {
    struct sigaction act;
    act.sa_handler = handle_sigint;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    
    if (sigaction(SIGINT, &act, NULL) == -1) {
        perror("Failed to set signal handler");
        return EXIT_FAILURE;
    }

    printf("Temperature Monitor Started. Press Ctrl+C to stop.\n");
    monitor_temperature();
    
    printf("Temperature Monitor Stopped.\n");
    return EXIT_SUCCESS;
}