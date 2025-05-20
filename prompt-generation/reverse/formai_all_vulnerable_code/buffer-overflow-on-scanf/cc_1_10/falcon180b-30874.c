//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SENSORS 10

typedef struct {
    char name[20];
    float temperature;
    float humidity;
    time_t last_updated;
} Sensor;

int main() {
    int num_sensors = 0;
    Sensor sensors[MAX_SENSORS];

    while (num_sensors < MAX_SENSORS) {
        printf("Enter the name of a sensor (or type 'done' to finish): ");
        char input[20];
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        strcpy(sensors[num_sensors].name, input);
        sensors[num_sensors].temperature = 0;
        sensors[num_sensors].humidity = 0;
        sensors[num_sensors].last_updated = 0;
        num_sensors++;
    }

    while (1) {
        printf("Temperature Monitor\n");
        printf("===================\n");
        for (int i = 0; i < num_sensors; i++) {
            printf("%s: %.2f°C %.2f%% humidity\n", sensors[i].name, sensors[i].temperature, sensors[i].humidity);
        }
        printf("\nPress enter to update temperatures...\n");
        getchar();

        for (int i = 0; i < num_sensors; i++) {
            sensors[i].temperature = rand() % 41 + 20;
            sensors[i].humidity = rand() % 101;
            sensors[i].last_updated = time(NULL);
        }

        printf("\nTemperatures updated!\n");
        printf("Press enter to continue...\n");
        getchar();
    }

    return 0;
}