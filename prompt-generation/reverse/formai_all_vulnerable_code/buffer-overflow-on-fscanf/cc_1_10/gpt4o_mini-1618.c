//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_SAMPLES 100
#define TEMP_SENSOR_PATH "/sys/class/thermal/thermal_zone0/temp"

typedef struct {
    time_t timestamp;
    float temperature;
} TemperatureData;

void log_temperature(TemperatureData history[], int index, float temperature) {
    if (index < MAX_SAMPLES) {
        history[index].timestamp = time(NULL);
        history[index].temperature = temperature;
    } else {
        printf("Temperature log is full. Increase MAX_SAMPLES to log more data.\n");
    }
}

char *format_timestamp(time_t timestamp) {
    return ctime(&timestamp);
}

float read_temperature() {
    FILE *fp = fopen(TEMP_SENSOR_PATH, "r");
    if (fp == NULL) {
        perror("Error opening temperature sensor file");
        exit(EXIT_FAILURE);
    }

    int temp_milli;
    fscanf(fp, "%d", &temp_milli);
    fclose(fp);
    
    return temp_milli / 1000.0; // Convert from millidegree Celsius to degree Celsius
}

void display_temperature_history(TemperatureData history[], int count) {
    printf("\n--- Temperature History ---\n");
    printf("Timestamp\t\t\tTemperature (°C)\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%.2f\n", format_timestamp(history[i].timestamp), history[i].temperature);
    }
}

void clear_temperature_history(TemperatureData history[], int *count) {
    for (int i = 0; i < *count; i++) {
        history[i].timestamp = 0;
        history[i].temperature = 0.0;
    }
    *count = 0;
}

int main() {
    TemperatureData history[MAX_SAMPLES];
    int history_count = 0;
    
    printf("Welcome to the Temperature Monitor.\n");
    printf("Press Ctrl+C to stop the monitoring.\n");

    while (1) {
        float current_temp = read_temperature();
        log_temperature(history, history_count, current_temp);
        if (history_count < MAX_SAMPLES) {
            history_count++;
        }

        printf("Current Temperature: %.2f°C\n", current_temp);
        sleep(5); // Wait for 5 seconds before the next reading
        
        // Displaying the history every 30 seconds for monitoring
        if (history_count % 6 == 0) {
            display_temperature_history(history, history_count);
        }
    }

    return 0;
}