//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

int main() {
    int choice;
    float temperature;
    char celsius_fahrenheit[10];
    time_t start_time, end_time;

    printf("Welcome to the Temperature Monitor!\n");
    printf("Please choose a temperature scale:\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    scanf("%d", &choice);

    if (choice == 1) {
        strcpy(celsius_fahrenheit, "Celsius");
    } else if (choice == 2) {
        strcpy(celsius_fahrenheit, "Fahrenheit");
    } else {
        printf("Invalid choice. Exiting program.\n");
        return 0;
    }

    while (TRUE) {
        printf("\nEnter current temperature: ");
        scanf("%f", &temperature);

        if (temperature < -273.15) {
            printf("Temperature cannot be below absolute zero (-273.15°%s).\n", celsius_fahrenheit);
        } else if (choice == 1) {
            printf("Current temperature: %.2f°%s\n", temperature, celsius_fahrenheit);
        } else if (choice == 2) {
            temperature = (temperature * 9.0 / 5.0) + 32.0;
            printf("Current temperature: %.2f°%s\n", temperature, celsius_fahrenheit);
        }

        printf("Do you want to continue monitoring? (Y/N): ");
        scanf(" %c", &choice);

        if (choice!= 'Y' && choice!= 'y') {
            break;
        }
    }

    end_time = time(NULL);
    printf("\nTemperature monitoring ended at %s", ctime(&end_time));

    return 0;
}