//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare the weather simulation function
void weatherSimulation(int numDays);

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the number of days from the user
    int numDays;
    printf("Enter the number of days to simulate: ");
    scanf("%d", &numDays);

    // Simulate the weather for the specified number of days
    weatherSimulation(numDays);

    return 0;
}

// Weather simulation function
void weatherSimulation(int numDays) {
    // Declare the weather array
    char weather[numDays];

    // Initialize the weather array with random weather conditions
    for (int i = 0; i < numDays; i++) {
        int randomNum = rand() % 4;
        switch (randomNum) {
            case 0:
                weather[i] = 's';
                break;
            case 1:
                weather[i] = 'r';
                break;
            case 2:
                weather[i] = 'c';
                break;
            case 3:
                weather[i] = 't';
                break;
        }
    }

    // Print the weather forecast for each day
    printf("Weather forecast for the next %d days:\n", numDays);
    for (int i = 0; i < numDays; i++) {
        printf("Day %d: ", i + 1);
        switch (weather[i]) {
            case 's':
                printf("Sunny\n");
                break;
            case 'r':
                printf("Rainy\n");
                break;
            case 'c':
                printf("Cloudy\n");
                break;
            case 't':
                printf("Thunderstorms\n");
                break;
        }
    }
}