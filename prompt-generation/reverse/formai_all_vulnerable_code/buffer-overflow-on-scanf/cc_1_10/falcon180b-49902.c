//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENSORS 10
#define SENSOR_NAME_LEN 20

struct sensor {
    char name[SENSOR_NAME_LEN];
    float temperature;
};

void read_sensors(struct sensor sensors[], int num_sensors) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("sensors.txt", "r");

    if (fp == NULL) {
        printf("Error opening sensors.txt\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        sscanf(line, "%s %f", sensors[i].name, &sensors[i].temperature);
        i++;
    }

    fclose(fp);
}

void display_sensors(struct sensor sensors[], int num_sensors) {
    int i;

    for (i = 0; i < num_sensors; i++) {
        printf("Sensor %d: %s - %.2f C\n", i + 1, sensors[i].name, sensors[i].temperature);
    }
}

int main() {
    struct sensor sensors[MAX_SENSORS];
    int num_sensors;

    printf("Enter number of sensors (max %d): ", MAX_SENSORS);
    scanf("%d", &num_sensors);

    read_sensors(sensors, num_sensors);
    display_sensors(sensors, num_sensors);

    return 0;
}