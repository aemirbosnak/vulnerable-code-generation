//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_SENSORS 10

struct sensor {
    char name[20];
    double temperature;
    double threshold;
    int state;
};

int main() {
    int i, j, nsensors, choice;
    double t;
    char input[50];
    struct sensor sensors[MAX_SENSORS];

    printf("Welcome to the Temperature Monitor!\n");
    printf("How many sensors do you want to monitor? (max %d): ", MAX_SENSORS);
    scanf("%d", &nsensors);

    for (i = 0; i < nsensors; i++) {
        printf("Enter the name of sensor %d: ", i+1);
        scanf("%s", sensors[i].name);
        sensors[i].temperature = 0.0;
        sensors[i].threshold = 0.0;
        sensors[i].state = FALSE;
    }

    while (TRUE) {
        printf("\n");
        for (i = 0; i < nsensors; i++) {
            printf("%s: %.2f°C\n", sensors[i].name, sensors[i].temperature);
        }
        printf("\n");

        printf("Enter your choice:\n");
        printf("1. Set threshold for a sensor\n");
        printf("2. Check temperature of a sensor\n");
        printf("3. Check state of a sensor\n");
        printf("4. Exit\n");
        scanf("%s", input);

        switch (atoi(input)) {
        case 1:
            printf("Enter the name of the sensor: ");
            scanf("%s", input);
            for (j = 0; j < nsensors; j++) {
                if (strcmp(sensors[j].name, input) == 0) {
                    printf("Enter the threshold temperature: ");
                    scanf("%lf", &sensors[j].threshold);
                    printf("Threshold set successfully!\n");
                    break;
                }
            }
            break;
        case 2:
            printf("Enter the name of the sensor: ");
            scanf("%s", input);
            for (j = 0; j < nsensors; j++) {
                if (strcmp(sensors[j].name, input) == 0) {
                    printf("Current temperature: %.2f°C\n", sensors[j].temperature);
                    break;
                }
            }
            break;
        case 3:
            printf("Enter the name of the sensor: ");
            scanf("%s", input);
            for (j = 0; j < nsensors; j++) {
                if (strcmp(sensors[j].name, input) == 0) {
                    if (sensors[j].temperature >= sensors[j].threshold) {
                        printf("The sensor is currently in a warning state.\n");
                    } else {
                        printf("The sensor is currently in a normal state.\n");
                    }
                    break;
                }
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}