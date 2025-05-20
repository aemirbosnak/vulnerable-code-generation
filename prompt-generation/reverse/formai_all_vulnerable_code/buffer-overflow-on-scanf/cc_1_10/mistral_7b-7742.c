//MISTRAL-7B DATASET v1.0 Category: Temperature monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SENSORS 10

typedef struct {
    float temperature;
    char location[20];
    struct sensor *next;
} sensor;

sensor *head = NULL;
float threshold = 50.0;

void addSensor(char *location) {
    sensor *newSensor = (sensor *)malloc(sizeof(sensor));
    if (newSensor == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    printf("Enter temperature for sensor %s: ", location);
    scanf("%f", &newSensor->temperature);
    strcpy(newSensor->location, location);
    newSensor->next = head;
    head = newSensor;
}

void checkTemperature(sensor *sensor) {
    if (sensor == NULL) {
        return;
    }

    if (sensor->temperature > threshold) {
        printf("High temperature (%f) detected at location %s\n", sensor->temperature, sensor->location);
    }

    checkTemperature(sensor->next);
}

int main() {
    int i;

    printf("Enter number of sensors: ");
    scanf("%d", &i);

    for (int j = 0; j < i; j++) {
        char location[20];
        printf("Enter location for sensor %d: ", j + 1);
        scanf("%s", location);
        addSensor(location);
    }

    checkTemperature(head);

    free(head);

    return 0;
}