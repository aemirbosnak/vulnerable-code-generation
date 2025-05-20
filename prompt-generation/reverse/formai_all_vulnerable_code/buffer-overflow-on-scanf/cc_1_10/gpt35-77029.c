//FormAI DATASET v1.0 Category: Weather simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    srand(time(NULL)); // Seed random number generator with current time
    
    printf("Welcome to the Weather Simulator!\n");
    printf("Select the type of weather you want to simulate:\n");
    printf("1. Sunny\n");
    printf("2. Cloudy\n");
    printf("3. Rainy\n");
    printf("4. Blustery\n");
    printf("5. Exit the simulator\n");
    
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {
                printf("\nSimulating sunny weather...\n");
                int temperature = rand() % 20 + 70; // Generate random temperature between 70 and 90 degrees Fahrenheit
                printf("Temperature: %d degrees F\n", temperature);
                printf("Humidity: %d%%\n", rand() % 10 + 50); // Generate random humidity between 50% and 60%
                printf("UV Index: %d\n", rand() % 10 + 1); // Generate random UV index between 1 and 10
                break;
            }
            case 2: {
                printf("\nSimulating cloudy weather...\n");
                int temperature = rand() % 10 + 60; // Generate random temperature between 60 and 70 degrees Fahrenheit
                printf("Temperature: %d degrees F\n", temperature);
                printf("Humidity: %d%%\n", rand() % 20 + 70); // Generate random humidity between 70% and 90%
                printf("Chance of precipitation: %d%%\n", rand() % 30 + 20); // Generate random chance of precipitation between 20% and 50%
                break;
            }
            case 3: {
                printf("\nSimulating rainy weather...\n");
                int temperature = rand() % 10 + 50; // Generate random temperature between 50 and 60 degrees Fahrenheit
                printf("Temperature: %d degrees F\n", temperature);
                printf("Humidity: %d%%\n", rand() % 20 + 80); // Generate random humidity between 80% and 100%
                printf("Chance of thunder: %d%%\n", rand() % 10 + 1); // Generate random chance of thunder between 1% and 10%
                break;
            }
            case 4: {
                printf("\nSimulating blustery weather...\n");
                int temperature = rand() % 10 + 30; // Generate random temperature between 30 and 40 degrees Fahrenheit
                printf("Temperature: %d degrees F\n", temperature);
                printf("Wind speed: %d mph\n", rand() % 20 + 20); // Generate random wind speed between 20 and 40 mph
                printf("Wind direction: %d degrees\n", rand() % 360); // Generate random wind direction between 0 and 359 degrees
                break;
            }
            case 5: {
                printf("\nExiting simulator...\n");
                return 0;
            }
            default: {
                printf("\nInvalid choice! Please enter a number between 1 and 5.\n");
                break;
            }
        }
    }
}