//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SENSORS 10

typedef struct {
    char name[50];
    float temperature;
    float threshold;
    int alarm;
} Sensor;

int main() {
    int num_sensors;
    Sensor sensors[MAX_SENSORS];
    float avg_temp = 0;
    int num_alarms = 0;
    char choice;
    
    printf("Welcome to the Temperature Monitor!\n");
    printf("How many sensors would you like to monitor? (max %d): ", MAX_SENSORS);
    scanf("%d", &num_sensors);
    
    for (int i = 0; i < num_sensors; i++) {
        printf("Enter the name of sensor %d: ", i+1);
        scanf("%s", sensors[i].name);
        printf("Enter the initial temperature of %s: ", sensors[i].name);
        scanf("%f", &sensors[i].temperature);
        printf("Enter the threshold temperature for %s: ", sensors[i].name);
        scanf("%f", &sensors[i].threshold);
        sensors[i].alarm = 0;
    }
    
    while (1) {
        system("clear");
        printf("Current temperatures:\n");
        for (int i = 0; i < num_sensors; i++) {
            printf("%s: %.2fC\n", sensors[i].name, sensors[i].temperature);
            if (sensors[i].temperature >= sensors[i].threshold) {
                sensors[i].alarm = 1;
                num_alarms++;
            } else {
                sensors[i].alarm = 0;
            }
        }
        avg_temp = 0;
        for (int i = 0; i < num_sensors; i++) {
            avg_temp += sensors[i].temperature;
        }
        avg_temp /= num_sensors;
        printf("\nAverage temperature: %.2fC\n", avg_temp);
        printf("Number of alarms: %d\n", num_alarms);
        printf("Press any key to continue...\n");
        getchar();
    }
    
    return 0;
}