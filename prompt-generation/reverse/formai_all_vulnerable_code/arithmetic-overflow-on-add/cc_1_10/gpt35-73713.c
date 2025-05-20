//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: genious
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *res, time_traveler;
    char time_str[20], traveler_str[20];

    // get current time
    current_time = time(NULL);
    res = localtime(&current_time);
    strftime(time_str, 20, "%Y-%m-%d %H:%M:%S", res);

    // ask user to input time traveler's year, month and day
    printf("Enter year of time traveler: ");
    scanf("%d", &time_traveler.tm_year);
    time_traveler.tm_year -= 1900;
    printf("Enter month of time traveler: ");
    scanf("%d", &time_traveler.tm_mon);
    time_traveler.tm_mon -= 1;
    printf("Enter day of time traveler: ");
    scanf("%d", &time_traveler.tm_mday);
    time_traveler.tm_hour = 0;
    time_traveler.tm_min = 0;
    time_traveler.tm_sec = 0;

    // compute time difference
    time_traveler.tm_isdst = -1;
    time_t traveler_time = mktime(&time_traveler);
    double seconds_diff = difftime(current_time, traveler_time);

    // check if user wants to travel to the past or future
    int choice;
    printf("Do you want to travel to the past or future? (0 for past, 1 for future): ");
    scanf("%d", &choice);
    printf("\n");

    // travel to the past or future
    if (choice == 0) {
        current_time -= seconds_diff;
        res = localtime(&current_time);
        strftime(traveler_str, 20, "%Y-%m-%d %H:%M:%S", res);
        printf("You have traveled %f seconds back in time.\n", seconds_diff);
        printf("Current time is now %s\n", traveler_str);
        printf("Time traveler arrived at %s\n", time_str);
    } else {
        current_time += seconds_diff;
        res = localtime(&current_time);
        strftime(traveler_str, 20, "%Y-%m-%d %H:%M:%S", res);
        printf("You have traveled %f seconds forward in time.\n", seconds_diff);
        printf("Current time is now %s\n", traveler_str);
        printf("Time traveler arrived at %s\n", time_str);
    }

    return 0;
}