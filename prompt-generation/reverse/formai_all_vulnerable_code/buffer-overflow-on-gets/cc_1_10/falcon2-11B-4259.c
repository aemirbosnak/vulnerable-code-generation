//Falcon2-11B DATASET v1.0 Category: Time Travel Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char destination[MAX_LENGTH];
    char current[MAX_LENGTH];
    char future[MAX_LENGTH];
    char past[MAX_LENGTH];

    printf("Welcome to the C Time Travel Simulator!\n");
    printf("Please enter your destination:\n");
    gets(destination);

    printf("Please enter your current location:\n");
    gets(current);

    printf("Please enter your desired future location:\n");
    gets(future);

    printf("Please enter your desired past location:\n");
    gets(past);

    // Calculate the time difference
    int timeDifference = strlen(destination) - strlen(current);

    // Travel to the past
    int timeTraveled = timeDifference;
    while (timeTraveled >= 0) {
        printf("You have traveled back in time %d seconds\n", timeTraveled);
        timeTraveled -= 1;
    }
    printf("You have arrived in the past!\n");

    // Travel to the future
    timeTraveled = timeDifference;
    while (timeTraveled < strlen(destination)) {
        printf("You have traveled forward in time %d seconds\n", timeTraveled);
        timeTraveled += 1;
    }
    printf("You have arrived in the future!\n");

    // Return to the present
    timeTraveled = timeDifference;
    while (timeTraveled >= 0) {
        printf("You have traveled back to the present %d seconds\n", timeTraveled);
        timeTraveled -= 1;
    }
    printf("You have arrived back in the present!\n");

    return 0;
}