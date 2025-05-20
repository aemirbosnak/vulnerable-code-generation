//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;
    int year = 2021;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You are currently in the year %d.\n", year);
    printf("What would you like to do?\n");
    printf("1. Travel to the past\n");
    printf("2. Travel to the future\n");
    printf("3. Quit\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the year you would like to travel to:\n");
            int targetYear;
            scanf("%d", &targetYear);
            if (targetYear < year) {
                printf("You cannot travel to the past.\n");
            } else {
                printf("You have traveled to the year %d.\n", targetYear);
                year = targetYear;
            }
            break;
        case 2:
            printf("Enter the year you would like to travel to:\n");
            int targetYear2;
            scanf("%d", &targetYear2);
            if (targetYear2 > year) {
                printf("You cannot travel to the future.\n");
            } else {
                printf("You have traveled to the year %d.\n", targetYear2);
                year = targetYear2;
            }
            break;
        case 3:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}