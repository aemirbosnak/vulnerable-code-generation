//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: cheerful
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* Function prototypes */
void travel_time(int year, int month, int day);

int main() {
    int choice, year, month, day;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please choose an option:\n");
    printf("1. Travel back in time\n");
    printf("2. Travel forward in time\n");
    printf("3. Exit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the year you want to travel back to (YYYY): ");
            scanf("%d", &year);
            printf("Enter the month (1-12): ");
            scanf("%d", &month);
            printf("Enter the day (1-31): ");
            scanf("%d", &day);
            travel_time(year, month, day);
            break;
        case 2:
            printf("Enter the year you want to travel forward to (YYYY): ");
            scanf("%d", &year);
            printf("Enter the month (1-12): ");
            scanf("%d", &month);
            printf("Enter the day (1-31): ");
            scanf("%d", &day);
            travel_time(year, month, day);
            break;
        case 3:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

/* Function to travel through time */
void travel_time(int year, int month, int day) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    t->tm_year = year - 1900;
    t->tm_mon = month - 1;
    t->tm_mday = day;

    time_t target_time = mktime(t);

    printf("Traveling through time...\n");
    sleep(3);

    time_t current_time = time(NULL);
    t = localtime(&current_time);

    if(t->tm_year == target_time) {
        printf("You have arrived in %d!\n", target_time + 1900);
    } else {
        printf("Time travel failed. You are still in %d.\n", t->tm_year + 1900);
    }
}