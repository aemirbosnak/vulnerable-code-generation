//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENSORS 10
#define BUFFER_SIZE 50

typedef struct {
    char name[BUFFER_SIZE];
    float temperature;
} Sensor;

Sensor sensors[MAX_SENSORS];
int sensor_count = 0;

// Function to add a new sensor
void add_sensor(const char *sensor_name) {
    if (sensor_count < MAX_SENSORS) {
        strncpy(sensors[sensor_count].name, sensor_name, BUFFER_SIZE - 1);
        sensors[sensor_count].temperature = 0.0f; // Initial temperature
        sensor_count++;
        printf("Sensor '%s' added.\n", sensor_name);
    } else {
        printf("Cannot add more sensors. Maximum limit reached.\n");
    }
}

// Function to take temperature readings for all sensors
void take_readings() {
    for (int i = 0; i < sensor_count; i++) {
        printf("Enter temperature for sensor '%s': ", sensors[i].name);
        scanf("%f", &sensors[i].temperature);
    }
}

// Function to calculate the average temperature
float calculate_average() {
    float total = 0.0f;
    for (int i = 0; i < sensor_count; i++) {
        total += sensors[i].temperature;
    }
    return sensor_count > 0 ? total / sensor_count : 0.0f;
}

// Function to display the readings
void display_readings() {
    printf("Temperature Readings:\n");
    for (int i = 0; i < sensor_count; i++) {
        printf("- Sensor '%s': %.2f °C\n", sensors[i].name, sensors[i].temperature);
    }
}

int main() {
    int choice;
    char sensor_name[BUFFER_SIZE];

    while (1) {
        printf("\nTemperature Monitor Menu:\n");
        printf("1. Add Sensor\n");
        printf("2. Take Readings\n");
        printf("3. Display Readings\n");
        printf("4. Calculate Average Temperature\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter sensor name: ");
                scanf("%s", sensor_name);
                add_sensor(sensor_name);
                break;
            case 2:
                take_readings();
                break;
            case 3:
                display_readings();
                break;
            case 4:
                {
                    float avg_temp = calculate_average();
                    printf("Average Temperature: %.2f °C\n", avg_temp);
                }
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}