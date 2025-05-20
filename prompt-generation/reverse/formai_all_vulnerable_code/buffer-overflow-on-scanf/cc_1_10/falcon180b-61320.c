//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_FITNESS 100
#define MAX_DAYS 30
#define INCREMENT 10

int main() {
    int fitness[MAX_DAYS];
    int days = 0;
    int progress = 0;

    printf("Welcome to the post-apocalyptic fitness tracker!\n");
    printf("You have survived for %d days.\n", days);

    while (days < MAX_DAYS) {
        printf("Day %d:\n", days+1);
        int choice;

        printf("What would you like to do?\n");
        printf("1. Exercise\n");
        printf("2. Rest\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                progress += INCREMENT;
                if (progress > MAX_FITNESS) {
                    printf("You have reached peak fitness!\n");
                } else {
                    printf("You have increased your fitness level by %d.\n", INCREMENT);
                }
                break;
            case 2:
                printf("You have rested for the day.\n");
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        days++;
        fitness[days-1] = progress;
    }

    return 0;
}