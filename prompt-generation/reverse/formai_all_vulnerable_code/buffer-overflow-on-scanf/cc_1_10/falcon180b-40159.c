//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int temp = 0;
    int humidity = 0;
    int windSpeed = 0;
    char weather[100];
    char location[100];
    int count = 0;

    printf("Welcome to the Weather Simulation Program!\n\n");
    printf("Please enter a location: ");
    scanf("%s", location);

    srand(time(NULL));
    temp = rand() % 101;
    humidity = rand() % 101;
    windSpeed = rand() % 101;

    printf("\nCurrent weather conditions in %s:\n", location);
    printf("Temperature: %d degrees Fahrenheit\n", temp);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind Speed: %d mph\n\n", windSpeed);

    while(1) {
        printf("\nEnter 1 to update weather conditions\n");
        printf("Enter 2 to change location\n");
        printf("Enter 3 to exit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            temp = rand() % 101;
            humidity = rand() % 101;
            windSpeed = rand() % 101;
            printf("\nWeather conditions have been updated!\n");
        }
        else if(choice == 2) {
            printf("\nEnter a new location: ");
            scanf("%s", location);
            printf("\nWeather conditions for %s:\n", location);
            printf("Temperature: %d degrees Fahrenheit\n", temp);
            printf("Humidity: %d%%\n", humidity);
            printf("Wind Speed: %d mph\n\n", windSpeed);
        }
        else if(choice == 3) {
            printf("\nThank you for using the Weather Simulation Program!\n");
            break;
        }
        else {
            printf("\nInvalid choice. Please try again.\n");
        }

        count++;
        if(count == 10) {
            printf("\nThe program will now exit.\n");
            break;
        }
    }

    return 0;
}