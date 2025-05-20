//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP_READINGS 100
#define MAX_TEMP_THRESHOLDS 10

typedef struct {
    double threshold;
    int action;
} TempThreshold;

typedef struct {
    double temperature;
    time_t timestamp;
} TempReading;

void print_temp_readings(TempReading *readings, int num_readings) {
    printf("Temperature Readings:\n");
    for (int i = 0; i < num_readings; i++) {
        printf("%.2f degrees at %s", readings[i].temperature, ctime(&readings[i].timestamp));
    }
}

int main() {
    int num_temp_readings = 0;
    TempReading readings[MAX_TEMP_READINGS];
    TempThreshold thresholds[MAX_TEMP_THRESHOLDS];
    int num_thresholds = 0;

    double current_temp;
    char input[50];
    while (1) {
        printf("Enter current temperature (in Celsius): ");
        scanf("%lf", &current_temp);

        // Add temperature reading to array
        if (num_temp_readings >= MAX_TEMP_READINGS) {
            printf("Error: Temperature reading array is full.\n");
            continue;
        }
        readings[num_temp_readings].temperature = current_temp;
        readings[num_temp_readings].timestamp = time(NULL);
        num_temp_readings++;

        // Add threshold to array
        printf("Enter threshold (in Celsius) and action (0=none, 1=alert, 2=shutdown): ");
        scanf("%lf %d", &thresholds[num_thresholds].threshold, &thresholds[num_thresholds].action);
        num_thresholds++;
    }

    return 0;
}