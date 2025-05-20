//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int configChoice;
    int year;
    char response;

    srand(time(NULL));

    printf("Welcome to Time Travel Simulator!\n");
    printf("Choose a configuration from the following options:\n");
    printf("1. Travel to a random year\n");
    printf("2. Travel to a specific year\n");
    printf("Choice: ");
    scanf("%d", &configChoice);

    if (configChoice == 1) {
        // Generate random year between 1800 and 2200
        year = rand() % 400 + 1800;
        printf("You will be traveling to the year: %d\n", year);
    }
    else if (configChoice == 2) {
        printf("Enter the year you want to travel to: ");
        scanf("%d", &year);
        printf("You will be traveling to the year: %d\n", year);
    }
    else {
        printf("Invalid choice.\n");
        return 0;
    }

    printf("Are you ready to begin your time travel journey? (y/n): ");
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        printf("3... 2... 1... Time travel initiated!\n");

        // Simulate travel time
        for (int i = 3; i >= 0; i--) {
            printf("%d...\n", i);
            sleep(1);
        }

        printf("Welcome to the year %d!\n", year);
    }
    else {
        printf("Time travel aborted.\n");
        return 0;
    }

    return 0;
}