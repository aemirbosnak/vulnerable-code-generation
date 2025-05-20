//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator

    int total_calories_burned = 0;

    printf("Welcome to your fitness tracker!\n");

    while (1) {
        printf("\nWhat activity did you do? (Enter 'q' to quit)\n");
        printf("1. Running\n");
        printf("2. Walking\n");

        char activity;
        scanf(" %c", &activity);

        if (activity == 'q') {
            break;
        }

        printf("How many minutes did you do this activity?\n");

        int minutes;
        scanf("%d", &minutes);

        int calories_burned;

        switch (activity) {
            case '1':
                calories_burned = minutes * (rand() % (15 - 10 + 1) + 10); // Burn between 10-15 calories/minute
                printf("You burned %d calories running!\n", calories_burned);
                break;
            case '2':
                calories_burned = minutes * (rand() % (8 - 5 + 1) + 5); // Burn between 5-8 calories/minute
                printf("You burned %d calories walking!\n", calories_burned);
                break;
            default:
                printf("Invalid activity!\n");
                continue;
        }

        total_calories_burned += calories_burned;
    }

    printf("\nGood job today! You burned a total of %d calories.", total_calories_burned);

    return 0;
}