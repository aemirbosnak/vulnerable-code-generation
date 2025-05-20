//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int caloriesBurned = 0;
    int stepsTaken = 0;
    int minuteCount = 0;
    time_t t;

    printf("Welcome to your C Fitness Tracker!\n");
    printf("What activity would you like to track?\n");
    printf("1. Running\n");
    printf("2. Walking\n");
    printf("3. Cycling\n");
    printf("4. Swimming\n");
    printf("5. Other\n");

    int choice = 0;
    scanf("%d", &choice);

    printf("Great! Let's start tracking your activity.\n");
    printf("Press enter to start.\n");
    getchar(); // Capture the enter key
    printf("Start time: %s", ctime(&t));

    while (1) {
        caloriesBurned += (10 * choice);
        stepsTaken += (100 * choice);
        minuteCount += 1;

        printf("Minute %d:\n", minuteCount);
        printf("Calories burned: %d\n", caloriesBurned);
        printf("Steps taken: %d\n", stepsTaken);

        printf("Would you like to end your activity? (Y/N)\n");
        char end;
        scanf(" %c", &end);

        if (end == 'Y' || end == 'y') {
            time_t end_t;
            time(&end_t);
            printf("End time: %s", ctime(&end_t));
            printf("Total time: %d minute(s)\n", minuteCount);
            break;
        }
    }

    printf("Thanks for using the C Fitness Tracker!\n");

    return 0;
}