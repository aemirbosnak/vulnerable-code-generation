//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TEMP_MAX 100
#define TEMP_MIN 0
#define TEMP_INC 0.1

int main() {
    double temperature = TEMP_MIN;
    int choice;

    printf("Welcome to the Temperature Monitor!\n");
    printf("Please select an option:\n");
    printf("1. Increase temperature\n");
    printf("2. Decrease temperature\n");
    printf("3. Display temperature\n");
    printf("4. Exit\n");

    scanf("%d", &choice);

    while (choice!= 4) {
        switch (choice) {
            case 1:
                temperature += TEMP_INC;
                if (temperature > TEMP_MAX) {
                    temperature = TEMP_MAX;
                }
                break;
            case 2:
                temperature -= TEMP_INC;
                if (temperature < TEMP_MIN) {
                    temperature = TEMP_MIN;
                }
                break;
            case 3:
                printf("The current temperature is %.2f\n", temperature);
                break;
            default:
                printf("Invalid choice\n");
        }

        printf("\nPlease select an option:\n");
        printf("1. Increase temperature\n");
        printf("2. Decrease temperature\n");
        printf("3. Display temperature\n");
        printf("4. Exit\n");

        scanf("%d", &choice);
    }

    return 0;
}