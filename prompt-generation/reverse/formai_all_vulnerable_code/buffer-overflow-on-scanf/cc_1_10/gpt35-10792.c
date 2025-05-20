//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("\nWelcome to Time Travel Simulator!\n");

    int i, max_year = 9999, min_year = 0, current_year;
    int max_month = 12, min_month = 1, current_month;
    int max_day = 31, min_day = 1, current_day;
    int max_hour = 23, min_hour = 1, current_hour;
    int max_min = 59, min_min = 0, current_min;

    srand(time(NULL)); //initializing random function

    printf("\nEnter the current year: ");
    scanf("%d", &current_year);

    printf("\nEnter the current month: ");
    scanf("%d", &current_month);

    printf("\nEnter the current day: ");
    scanf("%d", &current_day);

    printf("\nEnter the current hour: ");
    scanf("%d", &current_hour);

    printf("\nEnter the current minute: ");
    scanf("%d", &current_min);

    // Time Travel begins here

    printf("\nCongratulations! You have successfully landed in the time machine.\n");

    printf("\nSetting the Year...\n");
    for (i = 0; i < 10; i++) {
        int new_year = (rand() % (max_year - min_year + 1)) + min_year;
        printf("Year: %d\n", new_year);
    }

    printf("\nSetting the Month...\n");
    for (i = 0; i < 10; i++) {
        int new_month = (rand() % (max_month - min_month + 1)) + min_month;
        printf("Month: %d\n", new_month);
    }

    printf("\nSetting the Day...\n");
    for (i = 0; i < 10; i++) {
        int new_day = (rand() % (max_day - min_day + 1)) + min_day;
        printf("Day: %d\n", new_day);
    }

    printf("\nSetting the Hour...\n");
    for (i = 0; i < 10; i++) {
        int new_hour = (rand() % (max_hour - min_hour + 1)) + min_hour;
        printf("Hour: %d\n", new_hour);
    }

    printf("\nSetting the Minute...\n");
    for (i = 0; i < 10; i++) {
        int new_min = (rand() % (max_min - min_min + 1)) + min_min;
        printf("Minute: %d\n", new_min);
    }

    printf("\nTime Travel successful! You have been transported to a new time and space.\n");

    return 0;
}