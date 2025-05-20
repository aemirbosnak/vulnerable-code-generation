//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159
#define MAX_SENSOR 100
#define SENSOR_NAME_LENGTH 20
#define SENSOR_VALUE_LENGTH 10
#define SENSOR_DATA_LENGTH 30

typedef struct {
    char name[SENSOR_NAME_LENGTH];
    float value;
    char data[SENSOR_DATA_LENGTH];
} sensor_t;

void sensor_init(sensor_t *sensor, char *name, float value) {
    strcpy(sensor->name, name);
    sensor->value = value;
    sprintf(sensor->data, "%.2f", value);
}

void sensor_update(sensor_t *sensor, float new_value) {
    sensor->value = new_value;
    sprintf(sensor->data, "%.2f", new_value);
}

void sensor_print(sensor_t *sensor) {
    printf("%s: %s\n", sensor->name, sensor->data);
}

int main() {
    int i;
    sensor_t sensors[MAX_SENSOR];
    char input[SENSOR_NAME_LENGTH];
    float value;

    for (i = 0; i < MAX_SENSOR; i++) {
        printf("Enter sensor name: ");
        scanf("%s", input);
        sensor_init(&sensors[i], input, 0.0);
    }

    while (1) {
        printf("\n");
        for (i = 0; i < MAX_SENSOR; i++) {
            printf("%s ", sensors[i].name);
        }
        printf("\n");

        printf("Enter new sensor value for ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        }

        if (strcmp(input, "time") == 0) {
            time_t now = time(NULL);
            struct tm *t = localtime(&now);
            printf("Current time: %s\n", asctime(t));
        } else {
            value = atof(input);
            for (i = 0; i < MAX_SENSOR; i++) {
                if (strcmp(sensors[i].name, input) == 0) {
                    sensor_update(&sensors[i], value);
                    break;
                }
            }
        }
    }

    return 0;
}