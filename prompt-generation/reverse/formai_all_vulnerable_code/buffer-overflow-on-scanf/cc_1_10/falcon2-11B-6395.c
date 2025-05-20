//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SQUATS 50
#define MAX_JUMPS 30
#define MAX_PUSHUPS 20
#define MAX_CALORIES 200

typedef struct {
    int squats;
    int jumps;
    int pushups;
    int calories;
} fitness_stats;

int main() {
    srand(time(NULL)); // Initialize random number generator
    fitness_stats stats;
    int i;

    printf("Welcome to the Fitness Tracker!\n");
    printf("-----------------------------\n");
    printf("| 1. Log Squats\n");
    printf("| 2. Log Jumps\n");
    printf("| 3. Log Pushups\n");
    printf("| 4. Log Calories\n");
    printf("| 5. View Stats\n");
    printf("| 6. Exit\n");
    printf("-----------------------------\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &i);

        switch (i) {
            case 1:
                printf("Enter number of squats: ");
                scanf("%d", &stats.squats);
                break;
            case 2:
                printf("Enter number of jumps: ");
                scanf("%d", &stats.jumps);
                break;
            case 3:
                printf("Enter number of pushups: ");
                scanf("%d", &stats.pushups);
                break;
            case 4:
                printf("Enter number of calories burned: ");
                scanf("%d", &stats.calories);
                break;
            case 5:
                printf("Total Squats: %d\n", stats.squats);
                printf("Total Jumps: %d\n", stats.jumps);
                printf("Total Pushups: %d\n", stats.pushups);
                printf("Total Calories: %d\n", stats.calories);
                break;
            case 6:
                exit(0); // Exit program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}