//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SENSORS 10

typedef struct {
    char name[20];
    int value;
} sensor_t;

int main() {
    int num_sensors;
    sensor_t sensors[MAX_SENSORS];
    char input[100];
    char *token;
    int i;

    printf("Enter the number of sensors: ");
    scanf("%d", &num_sensors);

    for (i = 0; i < num_sensors; i++) {
        printf("Enter the name of sensor %d: ", i+1);
        scanf("%s", sensors[i].name);
        printf("Enter the initial temperature for %s: ", sensors[i].name);
        scanf("%d", &sensors[i].value);
    }

    while (1) {
        printf("\nTemperature Monitor\n");
        printf("Sensor\t\tInitial Temp\tCurrent Temp\n");

        for (i = 0; i < num_sensors; i++) {
            printf("%s\t\t%d\t\t", sensors[i].name, sensors[i].value);

            if (i == num_sensors - 1) {
                printf("%d\n", sensors[i].value);
            } else {
                printf("%d\t", sensors[i].value);
            }
        }

        printf("\nEnter 'c' to calibrate a sensor or 'q' to quit: ");
        scanf("%s", input);

        if (tolower(input[0]) == 'c') {
            printf("Enter the name of the sensor to calibrate: ");
            scanf("%s", input);

            token = strtok(input, " ");
            while (token!= NULL) {
                if (strcmp(token, "calibrate") == 0) {
                    printf("Enter the new temperature for %s: ", sensors[i].name);
                    scanf("%d", &sensors[i].value);
                    break;
                }
                token = strtok(NULL, " ");
            }
        } else if (tolower(input[0]) == 'q') {
            break;
        }
    }

    return 0;
}