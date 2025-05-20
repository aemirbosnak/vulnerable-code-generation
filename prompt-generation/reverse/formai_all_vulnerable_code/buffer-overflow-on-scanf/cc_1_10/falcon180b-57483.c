//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int temperature;
} Sensor;

int main() {
    int numSensors;
    Sensor sensors[100];
    char choice;

    printf("Welcome to the Sherlock Holmes Temperature Monitoring System!\n");
    printf("How many sensors do you wish to monitor? ");
    scanf("%d", &numSensors);

    for (int i = 0; i < numSensors; i++) {
        printf("Enter the name of sensor %d: ", i+1);
        scanf("%s", sensors[i].name);
        sensors[i].temperature = 0;
    }

    while (1) {
        printf("\n");
        printf("1. Display temperatures\n");
        printf("2. Update temperature\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                for (int i = 0; i < numSensors; i++) {
                    printf("%s: %d degrees Celsius\n", sensors[i].name, sensors[i].temperature);
                }
                break;
            case '2':
                printf("Enter the name of the sensor whose temperature you wish to update: ");
                scanf("%s", sensors[0].name);
                printf("Enter the new temperature: ");
                scanf("%d", &sensors[0].temperature);
                break;
            case '3':
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}