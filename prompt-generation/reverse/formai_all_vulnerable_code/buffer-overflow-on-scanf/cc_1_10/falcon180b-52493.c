//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Defining the global variables */
int temperature;
int humidity;
int windSpeed;
int cloudCoverage;

void weatherSimulation() {

    /* Initializing the weather variables */
    temperature = rand() % 80 + 10;
    humidity = rand() % 50 + 20;
    windSpeed = rand() % 30 + 5;
    cloudCoverage = rand() % 50 + 10;

    printf("Current Weather:\n");
    printf("Temperature: %d\n", temperature);
    printf("Humidity: %d\n", humidity);
    printf("Wind Speed: %d\n", windSpeed);
    printf("Cloud Coverage: %d\n", cloudCoverage);
}

int main() {

    srand(time(NULL));

    int choice;
    do {
        printf("Enter 1 to simulate weather\n");
        printf("Enter 2 to exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                weatherSimulation();
                break;
            case 2:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while(choice!= 2);

    return 0;
}