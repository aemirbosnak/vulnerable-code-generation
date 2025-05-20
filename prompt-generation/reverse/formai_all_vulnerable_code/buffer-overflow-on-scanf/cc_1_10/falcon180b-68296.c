//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SENSORS 10
#define MAX_SAMPLES 100

struct sensor {
    char name[20];
    float temperature;
    float humidity;
    int sample_count;
};

void print_sensor_data(struct sensor *sensor) {
    printf("Sensor name: %s\n", sensor->name);
    printf("Temperature: %.2f\n", sensor->temperature);
    printf("Humidity: %.2f\n", sensor->humidity);
    printf("Sample count: %d\n", sensor->sample_count);
}

void add_sample(struct sensor *sensor) {
    sensor->sample_count++;
    if (sensor->sample_count > MAX_SAMPLES) {
        sensor->sample_count = MAX_SAMPLES;
    }
}

int main() {
    struct sensor sensors[MAX_SENSORS];
    int num_sensors = 0;

    char name[20];
    float temperature;
    float humidity;

    srand(time(NULL));

    while (num_sensors < MAX_SENSORS) {
        printf("Enter sensor name (leave blank to finish): ");
        scanf("%s", name);

        if (name[0] == '\0') {
            break;
        }

        num_sensors++;
        strcpy(sensors[num_sensors - 1].name, name);
        sensors[num_sensors - 1].temperature = rand() % 101;
        sensors[num_sensors - 1].humidity = rand() % 101;
        sensors[num_sensors - 1].sample_count = 0;
    }

    int choice;
    while (1) {
        printf("\n1. Print sensor data\n2. Add sample\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < num_sensors; i++) {
                    print_sensor_data(&sensors[i]);
                }
                break;
            case 2:
                printf("Enter sensor name: ");
                scanf("%s", name);

                for (int i = 0; i < num_sensors; i++) {
                    if (strcmp(sensors[i].name, name) == 0) {
                        add_sample(&sensors[i]);
                        break;
                    }
                }

                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}