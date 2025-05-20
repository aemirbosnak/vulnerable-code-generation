//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVEL 10

typedef struct {
    int time;
    int destination;
} TimeTravel;

int main() {
    int i, j, n;
    TimeTravel time_travel[MAX_TIME_TRAVEL];
    char input[80];

    // Initialize the time travel log
    for (i = 0; i < MAX_TIME_TRAVEL; i++) {
        time_travel[i].time = 0;
        time_travel[i].destination = 0;
    }

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter your name:\n");
    scanf("%s", input);
    printf("Hello, %s! You are now a time traveler!\n", input);

    // Main time travel loop
    while (1) {
        printf("\nWhere and when would you like to travel? ");
        scanf("%d %d", &n, &time_travel[n].destination);
        time_travel[n].time = time(NULL);
        printf("You have traveled to the year %d!\n", time_travel[n].destination);

        // Check for paradoxes
        for (i = 0; i < n; i++) {
            if (time_travel[i].destination == time_travel[n].destination &&
                time_travel[i].time > time_travel[n].time) {
                printf("Paradox detected! You cannot travel to a time before you have already been there.\n");
                exit(0);
            }
        }

        // Allow the user to explore the new time period
        printf("\nWhat would you like to do?\n");
        printf("1. Explore\n");
        printf("2. Return to the present\n");
        scanf("%d", &j);

        if (j == 1) {
            // Simulate exploring the new time period
            printf("\nYou explore the year %d for a while...\n", time_travel[n].destination);
        } else if (j == 2) {
            // Return to the present
            printf("\nYou return to the present.\n");
        } else {
            printf("Invalid option.\n");
        }
    }

    return 0;
}