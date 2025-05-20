//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SENSORS 10
#define SENSOR_NAME_LENGTH 20

struct sensor {
    char name[SENSOR_NAME_LENGTH];
    double temperature;
};

void read_sensors(struct sensor sensors[], int num_sensors) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("sensors.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open sensors file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= num_sensors) {
            printf("Warning: Maximum number of sensors reached.\n");
            break;
        }

        sscanf(line, "%s %lf", sensors[i].name, &sensors[i].temperature);
        i++;
    }

    fclose(fp);
}

void display_sensors(struct sensor sensors[], int num_sensors) {
    int i;

    for (i = 0; i < num_sensors; i++) {
        printf("Sensor %d: %s - %.2lf°C\n", i + 1, sensors[i].name, sensors[i].temperature);
    }
}

int main() {
    int num_sensors;
    struct sensor sensors[MAX_SENSORS];

    printf("Enter the number of sensors to monitor: ");
    scanf("%d", &num_sensors);

    read_sensors(sensors, num_sensors);
    display_sensors(sensors, num_sensors);

    return 0;
}