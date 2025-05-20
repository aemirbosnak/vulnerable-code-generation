//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 9999

int main() {
    int year = 2021;
    char input[10];
    int choice;

    do {
        printf("Welcome to the Time Travel Simulator!\n");
        printf("You are currently in the year %d.\n", year);
        printf("What would you like to do?\n");
        printf("1. Travel forward in time\n");
        printf("2. Travel backward in time\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of years you want to travel forward: ");
                scanf("%d", &year);
                if (year > MAX_YEAR) {
                    printf("Error: You cannot travel beyond the year %d.\n", MAX_YEAR);
                    break;
                }
                printf("You have traveled forward in time to the year %d.\n", year);
                break;
            case 2:
                printf("Enter the number of years you want to travel backward: ");
                scanf("%d", &year);
                if (year < 1900) {
                    printf("Error: You cannot travel beyond the year 1900.\n");
                    break;
                }
                printf("You have traveled backward in time to the year %d.\n", year);
                break;
            case 3:
                printf("Thank you for using the Time Travel Simulator!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice!= 3);

    return 0;
}