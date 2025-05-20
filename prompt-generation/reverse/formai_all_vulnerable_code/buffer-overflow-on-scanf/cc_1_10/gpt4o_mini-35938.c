//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_SENSORS 10
#define TEMP_UPDATE_INTERVAL 2 // seconds

typedef struct {
    int id;
    float current_temp;
    float lower_limit;
    float upper_limit;
} Sensor;

void initialize_sensors(Sensor sensors[], int count);
float read_temperature(void);
void display_temperature(Sensor sensors[], int count);
void check_limits(Sensor sensors[], int count);
void sleep_for_interval(int seconds);
void run_monitor(Sensor sensors[], int count);

int main(void) {
    Sensor sensors[MAX_SENSORS];

    int sensor_count;
    printf("Enter the number of sensors (max %d): ", MAX_SENSORS);
    scanf("%d", &sensor_count);

    if (sensor_count < 1 || sensor_count > MAX_SENSORS) {
        fprintf(stderr, "Number of sensors must be between 1 and %d\n", MAX_SENSORS);
        return EXIT_FAILURE;
    }

    initialize_sensors(sensors, sensor_count);
    run_monitor(sensors, sensor_count);

    return EXIT_SUCCESS;
}

void initialize_sensors(Sensor sensors[], int count) {
    for (int i = 0; i < count; i++) {
        sensors[i].id = i + 1;
        printf("Enter lower limit for Sensor %d: ", sensors[i].id);
        scanf("%f", &sensors[i].lower_limit);
        printf("Enter upper limit for Sensor %d: ", sensors[i].id);
        scanf("%f", &sensors[i].upper_limit);
        sensors[i].current_temp = read_temperature();
    }
    printf("\nSensors Initialized Successfully!\n");
}

float read_temperature(void) {
    float temp;
    // Simulating temperature reading from a sensor
    temp = (float)(rand() % 150); // Random temperature between 0 and 150
    return temp;
}

void display_temperature(Sensor sensors[], int count) {
    printf("\nCurrent Temperature Readings:\n");
    for (int i = 0; i < count; i++) {
        printf("Sensor %d: %.2f°C\n", sensors[i].id, sensors[i].current_temp);
    }
}

void check_limits(Sensor sensors[], int count) {
    for (int i = 0; i < count; i++) {
        if (sensors[i].current_temp < sensors[i].lower_limit) {
            printf("Warning: Sensor %d is below the lower limit! Current Temperature: %.2f°C\n", sensors[i].id, sensors[i].current_temp);
        } else if (sensors[i].current_temp > sensors[i].upper_limit) {
            printf("Warning: Sensor %d is above the upper limit! Current Temperature: %.2f°C\n", sensors[i].id, sensors[i].current_temp);
        }
    }
}

void sleep_for_interval(int seconds) {
    sleep(seconds);
}

void run_monitor(Sensor sensors[], int count) {
    while (1) {
        for (int i = 0; i < count; i++) {
            sensors[i].current_temp = read_temperature();
        }

        display_temperature(sensors, count);
        check_limits(sensors, count);

        sleep_for_interval(TEMP_UPDATE_INTERVAL);
    }
}