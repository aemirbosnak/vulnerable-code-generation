//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char direction[20];
    int distance, total_distance = 0;

    printf("Welcome to the GPS Navigation Simulation!\n\n");

    while (1) {
        printf("Which direction do you want to go (N/S/E/W)? ");
        scanf("%s", direction);

        printf("How far (in miles)? ");
        scanf("%d", &distance);

        total_distance += distance;

        if (direction[0] == 'N' || direction[0] == 'n') {
            printf("\n*Driving north for %d miles...*\n", distance);
        }
        else if (direction[0] == 'S' || direction[0] == 's') {
            printf("\n*Driving south for %d miles...*\n", distance);
        }
        else if (direction[0] == 'E' || direction[0] == 'e') {
            printf("\n*Driving east for %d miles...*\n", distance);
        }
        else if (direction[0] == 'W' || direction[0] == 'w') {
            printf("\n*Driving west for %d miles...*\n", distance);
        }
        else {
            printf("\nInvalid direction! Please try again.\n");
            continue;
        }

        printf("Total distance traveled: %d miles\n\n", total_distance);

        if (total_distance >= 50) {
            printf("\n*Warning! You are starting to feel car sick from all this driving. It might be time to stop and get some fresh air.*\n");
        }
        if (total_distance >= 100) {
            printf("\n*Are you lost? Because you've been driving for hours...*\n");
        }
        if (total_distance >= 200) {
            printf("\n*Congratulations, you've officially circumnavigated the globe!*\n");
            break;
        }
    }

    printf("\nThanks for using the GPS Navigation Simulation! Have a safe trip!\n");
    return 0;
}