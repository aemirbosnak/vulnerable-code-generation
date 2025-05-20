//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int year, month, day;
    int current_year, current_month, current_day;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please select an option:\n");
    printf("1. Travel to a specific date\n");
    printf("2. Travel to the future\n");
    printf("3. Travel to the past\n");
    scanf("%d", &choice);

    time_t now = time(0);
    struct tm* current_time = localtime(&now);

    current_year = 1900 + current_time->tm_year;
    current_month = 1 + current_time->tm_mon;
    current_day = current_time->tm_mday;

    switch(choice) {
        case 1:
            printf("Enter the year you want to travel to (YYYY): ");
            scanf("%d", &year);
            printf("Enter the month you want to travel to (1-12): ");
            scanf("%d", &month);
            printf("Enter the day you want to travel to (1-31): ");
            scanf("%d", &day);

            if(year < current_year) {
                printf("You cannot travel to the past!\n");
            } else {
                printf("You have traveled to %d-%d-%d!\n", year, month, day);
            }
            break;
        case 2:
            printf("You have traveled to the year %d!\n", current_year);
            break;
        case 3:
            printf("You have traveled to the year %d!\n", current_year - 1);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}