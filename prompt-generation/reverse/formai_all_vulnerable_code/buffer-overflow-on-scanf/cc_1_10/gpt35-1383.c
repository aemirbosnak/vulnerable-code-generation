//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pushups = 0;
    int squats = 0;
    int crunches = 0;
    float distance = 0.0;
    int choice = 0;

    printf("Welcome to Fitness Tracker\n");

    do {
        printf("\nSelect an option:\n");
        printf("1. Add Pushups\n");
        printf("2. Add Squats\n");
        printf("3. Add Crunches\n");
        printf("4. Add Distance\n");
        printf("5. View Stats\n");
        printf("6. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                pushups++;
                break;
            case 2:
                squats++;
                break;
            case 3:
                crunches++;
                break;
            case 4:
                printf("Enter Distance(miles): ");
                scanf("%f", &distance);
                break;
            case 5:
                printf("\nFitness Stats:\n");
                printf("Pushups: %d\n", pushups);
                printf("Squats: %d\n", squats);
                printf("Crunches: %d\n", crunches);
                printf("Distance: %f miles\n", distance);
                break;
            case 6:
                printf("Thank you for using Fitness Tracker!");
                break;
            default:
                printf("Invalid Choice!");
        }

    } while (choice != 6);

    return 0;
}