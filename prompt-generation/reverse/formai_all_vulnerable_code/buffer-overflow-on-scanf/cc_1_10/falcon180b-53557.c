//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_SENSORS 10
#define MAX_LOOP_COUNT 1000

struct sensor {
    char name[20];
    float temperature;
    float threshold;
    int state;
};

void init_sensor(struct sensor *sensor) {
    strcpy(sensor->name, "Sensor 1");
    sensor->temperature = 0;
    sensor->threshold = 25;
    sensor->state = 0;
}

int main() {
    struct sensor sensors[MAX_SENSORS] = { { 0 } };
    int sensor_count = 0;
    int loop_count = 0;

    while (1) {
        if (sensor_count < MAX_SENSORS) {
            printf("Enter sensor name (max 20 characters): ");
            scanf("%s", sensors[sensor_count].name);
            init_sensor(&sensors[sensor_count]);
            sensor_count++;
        } else {
            printf("Maximum sensors reached.\n");
        }

        if (sensor_count > 0) {
            printf("\n");
            printf("Sensor\tName\tTemperature\tThreshold\tState\n");
            for (int i = 0; i < sensor_count; i++) {
                printf("%d\t%s\t%.2f\t%.2f\t", i+1, sensors[i].name, sensors[i].temperature, sensors[i].threshold);
                if (sensors[i].temperature >= sensors[i].threshold) {
                    printf("Overheated\n");
                } else {
                    printf("Normal\n");
                }
            }
        }

        loop_count++;
        if (loop_count == MAX_LOOP_COUNT) {
            loop_count = 0;
            for (int i = 0; i < sensor_count; i++) {
                sensors[i].temperature += 1;
            }
        }

        sleep(1);
    }

    return 0;
}