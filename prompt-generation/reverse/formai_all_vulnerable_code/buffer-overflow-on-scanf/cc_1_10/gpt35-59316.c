//FormAI DATASET v1.0 Category: Temperature monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    float currentTemperature = 0, maxTemperature = -273, minTemperature = 1000, totalTemperature = 0;
    int numReadings = 0, choice = 1;
    time_t now;
    char *timeStr;

    printf("Welcome to the Temperature Monitor!\n");
    printf("-----------------------------------\n\n");

    while(choice != 0) {

        printf("1. Enter a temperature reading\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 0:
                break;
            case 1:
                printf("\nEnter the current temperature reading in Celsius: ");
                scanf("%f", &currentTemperature);

                if(currentTemperature < -273) {
                    printf("\nError: The lowest possible temperature is -273 Celsius.\n\n");
                    break;
                }

                numReadings++;
                totalTemperature += currentTemperature;

                if(currentTemperature > maxTemperature) {
                    maxTemperature = currentTemperature;
                }

                if(currentTemperature < minTemperature) {
                    minTemperature = currentTemperature;
                }

                // Get the current time and format it
                now = time(NULL);
                timeStr = ctime(&now);

                printf("\nTemperature reading saved at %s", timeStr);
                printf("Current temperature: %.2f°C\n", currentTemperature);
                printf("Highest temperature recorded: %.2f°C\n", maxTemperature);
                printf("Lowest temperature recorded: %.2f°C\n", minTemperature);
                printf("Average temperature recorded: %.2f°C\n\n", totalTemperature/numReadings);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
                break;
        }

    }

    printf("Thank you for using the Temperature Monitor!\n");

    return 0;
}