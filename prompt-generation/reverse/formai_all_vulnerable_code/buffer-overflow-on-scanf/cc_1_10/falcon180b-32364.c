//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_SENSORS 10
#define MIN_TEMP -100
#define MAX_TEMP 1000

typedef struct {
    char name[20];
    float temp;
    float threshold;
    int status;
} Sensor;

int main() {
    int numSensors;
    printf("Enter the number of sensors: ");
    scanf("%d", &numSensors);

    Sensor sensors[MAX_SENSORS];

    for (int i = 0; i < numSensors; i++) {
        printf("Enter sensor %d name: ", i+1);
        scanf("%s", sensors[i].name);

        printf("Enter sensor %d threshold temperature: ", i+1);
        scanf("%f", &sensors[i].threshold);

        sensors[i].temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        sensors[i].status = TRUE;
    }

    while (TRUE) {
        system("clear");
        printf("Sherlock Holmes' Temperature Monitor\n\n");

        for (int i = 0; i < numSensors; i++) {
            if (sensors[i].status == FALSE) {
                printf("%s - OFFLINE\n", sensors[i].name);
            } else {
                printf("%s - %.2f°C\n", sensors[i].name, sensors[i].temp);

                if (sensors[i].temp >= sensors[i].threshold) {
                    printf("%s - ALERT! Temperature exceeded threshold.\n", sensors[i].name);
                }
            }
        }

        printf("\nPress any key to continue...\n");
        getchar();
    }

    return 0;
}