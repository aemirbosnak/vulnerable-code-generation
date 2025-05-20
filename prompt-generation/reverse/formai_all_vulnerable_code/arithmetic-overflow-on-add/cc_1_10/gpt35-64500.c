//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, yearDifference;
    struct tm current_time;
    time_t t = time(NULL);
    localtime_r(&t, &current_time);

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You are currently in the year %d.\n", current_time.tm_year + 1900);

    do {
        printf("Where do you want to go?\n");
        printf("1. Forward in time\n");
        printf("2. Backward in time\n");
        printf("3. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("How many years forward do you want to go?: ");
                scanf("%d", &yearDifference);

                current_time.tm_year += yearDifference;
                mktime(&current_time);
                printf("You are now in the year %d.\n", current_time.tm_year + 1900);
                break;

            case 2:
                printf("How many years backward do you want to go?: ");
                scanf("%d", &yearDifference);

                current_time.tm_year -= yearDifference;
                mktime(&current_time);
                printf("You are now in the year %d.\n", current_time.tm_year + 1900);
                break;

            case 3:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }

    } while(choice != 3);

    return 0;
}