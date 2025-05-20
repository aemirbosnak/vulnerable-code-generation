//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SENSORS 10
#define MAX_READINGS 100

typedef struct {
    char name[50];
    float readings[MAX_READINGS];
    int reading_count;
} TemperatureSensor;

void initialize_sensor(TemperatureSensor *sensor, const char *name) {
    strncpy(sensor->name, name, sizeof(sensor->name) - 1);
    sensor->name[sizeof(sensor->name) - 1] = '\0';
    sensor->reading_count = 0;
}

void add_reading(TemperatureSensor *sensor, float temperature) {
    if (sensor->reading_count < MAX_READINGS) {
        sensor->readings[sensor->reading_count++] = temperature;
    } else {
        printf("Max readings reached for sensor: %s\n", sensor->name);
    }
}

float calculate_average(TemperatureSensor *sensor) {
    if (sensor->reading_count == 0) return 0.0;
    float sum = 0.0;
    for (int i = 0; i < sensor->reading_count; i++) {
        sum += sensor->readings[i];
    }
    return sum / sensor->reading_count;
}

void display_sensor_info(const TemperatureSensor *sensor) {
    printf("Sensor: %s\n", sensor->name);
    printf("Readings Count: %d\n", sensor->reading_count);
    printf("Average Temperature: %.2f\n", calculate_average(sensor));
    for (int i = 0; i < sensor->reading_count; i++) {
        printf("Reading %d: %.2f\n", i + 1, sensor->readings[i]);
    }
    printf("\n");
}

void monitor_temperature(TemperatureSensor *sensors, int sensor_count) {
    while (1) {
        for (int i = 0; i < sensor_count; i++) {
            // Simulate temperature reading; this would be replaced by actual sensor reading code
            float simulated_temp = (float)(rand() % 5000) / 100; // Simulating temperature 0.00 to 50.00
            add_reading(&sensors[i], simulated_temp);
            display_sensor_info(&sensors[i]);
        }
        sleep(5); // Pause for 5 seconds before next reading
    }
}

int main() {
    TemperatureSensor sensors[MAX_SENSORS];
    int sensor_count;

    printf("Enter the number of sensors (max %d): ", MAX_SENSORS);
    scanf("%d", &sensor_count);

    if (sensor_count <= 0 || sensor_count > MAX_SENSORS) {
        printf("Invalid number of sensors. Please re-run the program.\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < sensor_count; i++) {
        char sensor_name[50];
        printf("Enter name for sensor %d: ", i + 1);
        scanf("%s", sensor_name);
        initialize_sensor(&sensors[i], sensor_name);
    }

    monitor_temperature(sensors, sensor_count);

    return EXIT_SUCCESS;
}