//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_TEMP_RECORDS 100
#define TEMP_SENSOR_PATH "/sys/class/thermal/thermal_zone0/temp"
#define SLEEP_INTERVAL 5 // interval to check temp in seconds

typedef struct {
    time_t timestamp;
    float temperature;
} TemperatureRecord;

TemperatureRecord temp_records[MAX_TEMP_RECORDS];
int record_count = 0;

// Function to read temperature from the sensor
float read_temperature() {
    float temp;
    FILE *fp = fopen(TEMP_SENSOR_PATH, "r");
    if (fp == NULL) {
        perror("Error opening temperature sensor file");
        return -1;
    }
    fscanf(fp, "%f", &temp);
    fclose(fp);
    return temp / 1000.0; // Convert from millidegree Celsius to Celsius
}

// Function to log the temperature
void log_temperature(float temperature) {
    if (record_count < MAX_TEMP_RECORDS) {
        temp_records[record_count].timestamp = time(NULL);
        temp_records[record_count].temperature = temperature;
        record_count++;
        printf("Logged Temperature: %.2f °C at %s", temperature, ctime(&temp_records[record_count - 1].timestamp));
    } else {
        printf("Maximum records reached! Cannot log more temperatures.\n");
    }
}

// Function to display all recorded temperatures
void display_temperature_records() {
    printf("\nTemperature Records:\n");
    for (int i = 0; i < record_count; i++) {
        printf("Record %d: %.2f °C at %s", i + 1, temp_records[i].temperature, ctime(&temp_records[i].timestamp));
    }
}

// Main function to run the temperature monitoring
int main() {
    float temperature;

    printf("Temperature Monitor Initialized...\n");
    printf("Press Ctrl+C to stop the monitoring.\n");

    // Monitor temperature in a loop
    while (1) {
        temperature = read_temperature();
        if (temperature != -1) {
            log_temperature(temperature);
        } else {
            printf("Error reading temperature!\n");
        }
        
        sleep(SLEEP_INTERVAL);
    }
    
    // This code will never reach here due to infinite loop
    display_temperature_records();

    return 0;
}