//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: portable
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *time_info;
    int choice;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please select an option:\n");
    printf("1. Travel to the Past\n");
    printf("2. Travel to the Future\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    time(&current_time);
    time_info = localtime(&current_time);

    switch(choice) {
        case 1: // Travel to the past
            printf("Enter the year you wish to travel to: ");
            int year;
            scanf("%d", &year);

            if(year > time_info->tm_year + 1900) {
                printf("Sorry, you cannot travel to the future!\n");
            } else {
                time_info->tm_year = year - 1900;
                mktime(time_info); // Adjust other fields based on the new year

                printf("You have traveled to %d\n", year);
                printf("The current date is: %s", asctime(time_info));
            }
            break;

        case 2: // Travel to the future
            printf("Enter the year you wish to travel to: ");
            int future_year;
            scanf("%d", &future_year);

            if(future_year < time_info->tm_year + 1900) {
                printf("Sorry, you cannot travel to the past!\n");
            } else {
                time_info->tm_year = future_year - 1900;
                mktime(time_info); // Adjust other fields based on the new year

                printf("You have traveled to %d\n", future_year);
                printf("The current date is: %s", asctime(time_info));
            }
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}