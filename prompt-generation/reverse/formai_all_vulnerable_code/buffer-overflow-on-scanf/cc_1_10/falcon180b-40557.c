//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_SENSORS 10

typedef struct {
    char name[20];
    double current_temperature;
    double min_temperature;
    double max_temperature;
    double average_temperature;
} Sensor;

int main() {
    int num_sensors = 0;
    Sensor sensors[MAX_SENSORS];

    printf("Enter the number of sensors: ");
    scanf("%d", &num_sensors);

    for(int i=0; i<num_sensors; i++) {
        printf("Enter the name of sensor %d: ", i+1);
        scanf("%s", sensors[i].name);
        sensors[i].current_temperature = 0.0;
        sensors[i].min_temperature = 1000.0;
        sensors[i].max_temperature = -1000.0;
        sensors[i].average_temperature = 0.0;
    }

    while(1) {
        for(int i=0; i<num_sensors; i++) {
            printf("Enter the temperature for sensor %s: ", sensors[i].name);
            scanf("%lf", &sensors[i].current_temperature);

            if(sensors[i].current_temperature < sensors[i].min_temperature) {
                sensors[i].min_temperature = sensors[i].current_temperature;
            }

            if(sensors[i].current_temperature > sensors[i].max_temperature) {
                sensors[i].max_temperature = sensors[i].current_temperature;
            }

            sensors[i].average_temperature += sensors[i].current_temperature;
        }

        printf("\n");
        for(int i=0; i<num_sensors; i++) {
            printf("Sensor %s:\n", sensors[i].name);
            printf("Current temperature: %.2lf\n", sensors[i].current_temperature);
            printf("Min temperature: %.2lf\n", sensors[i].min_temperature);
            printf("Max temperature: %.2lf\n", sensors[i].max_temperature);
            printf("Average temperature: %.2lf\n\n", sensors[i].average_temperature/((double)num_sensors*i));
        }

        sleep(5);
    }

    return 0;
}