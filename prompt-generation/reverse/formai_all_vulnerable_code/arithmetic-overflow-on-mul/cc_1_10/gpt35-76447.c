//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to get valid year from user
int getYear() {
    int year;
    printf("Enter a valid year: ");
    scanf("%d", &year);
    while (year < 1900 || year > 2100) {
        printf("Invalid year! Please enter a year between 1900 and 2100: ");
        scanf("%d", &year);
    }
    return year;
}

int main() {
    //get current time
    time_t current_time;
    struct tm * time_info;
    time(&current_time);
    time_info = localtime(&current_time);

    //get target year from user
    int target_year = getYear();

    //check if time travel is possible
    if (target_year >= time_info->tm_year + 1900) {
        printf("Sorry, time travel into the future is not yet possible...\n");
        return 0;
    }

    //simulate time travel
    printf("A time travel simulation to %d...\n\n", target_year);

    //print current date and time
    printf("CURRENT DATE AND TIME: %s\n", asctime(time_info));

    //calculate time difference
    int year_diff = target_year - (time_info->tm_year + 1900);
    int day_diff = year_diff * 365 + (year_diff / 4) - (year_diff / 100) + (year_diff / 400);
    time_t target_time = current_time - day_diff * 24 * 60 * 60;

    //update time_info with target time
    time_info = localtime(&target_time);

    //print target date and time
    printf("\nTARGET DATE AND TIME: %s\n", asctime(time_info));

    return 0;
}