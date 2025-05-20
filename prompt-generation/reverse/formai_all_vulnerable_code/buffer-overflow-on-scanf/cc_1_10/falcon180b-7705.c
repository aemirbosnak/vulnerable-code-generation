//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP_SENSORS 10
#define TEMP_SENSOR_ERROR 0.5

struct temp_sensor {
    char name[30];
    float temp;
};

int main() {
    int num_sensors;
    struct temp_sensor sensors[MAX_TEMP_SENSORS];
    float avg_temp = 0;
    float max_temp = -999;
    float min_temp = 999;

    printf("Enter number of temperature sensors: ");
    scanf("%d", &num_sensors);

    for (int i = 0; i < num_sensors; i++) {
        printf("Enter name of temperature sensor %d: ", i + 1);
        scanf("%s", sensors[i].name);
        sensors[i].temp = 0;
    }

    while (1) {
        for (int i = 0; i < num_sensors; i++) {
            sensors[i].temp = rand() % 50 + 10; // Simulate random temperature readings
            avg_temp += sensors[i].temp;

            if (sensors[i].temp > max_temp) {
                max_temp = sensors[i].temp;
            }

            if (sensors[i].temp < min_temp) {
                min_temp = sensors[i].temp;
            }
        }

        avg_temp /= num_sensors;

        printf("\n");
        printf("Current temperature readings:\n");
        for (int i = 0; i < num_sensors; i++) {
            printf("%s: %.2f°C\n", sensors[i].name, sensors[i].temp);
        }

        printf("\nAverage temperature: %.2f°C\n", avg_temp);
        printf("Maximum temperature: %.2f°C\n", max_temp);
        printf("Minimum temperature: %.2f°C\n", min_temp);

        sleep(5); // Update temperature readings every 5 seconds
    }

    return 0;
}