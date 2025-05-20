//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int year, month, day, hour, minute, second;
    char input[10];
    printf("Welcome to the Time Travel Simulator!\n");

    // Get the current date and time
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    year = 1900 + t->tm_year;
    month = t->tm_mon + 1;
    day = t->tm_mday;
    hour = t->tm_hour;
    minute = t->tm_min;
    second = t->tm_sec;

    // Display the current date and time
    printf("The current date and time is: %d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second);

    // Ask the user for a date and time to travel to
    printf("Enter the date and time you want to travel to (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", input);

    // Convert the input string to the appropriate date and time format
    struct tm target_time;
    memset(&target_time, 0, sizeof(struct tm));
    target_time.tm_year = atoi(input) - 1900;
    target_time.tm_mon = atoi(input + 4) - 1;
    target_time.tm_mday = atoi(input + 7);
    target_time.tm_hour = atoi(input + 10);
    target_time.tm_min = atoi(input + 13);
    target_time.tm_sec = atoi(input + 16);

    // Calculate the number of seconds between the current time and the target time
    time_t target_time_t = mktime(&target_time);
    int difference = difftime(target_time_t, time(NULL));

    // Travel through time!
    printf("Traveling through time...\n");
    for (int i = 0; i < difference; i++) {
        sleep(1);
        printf(".");
    }

    // Display the new date and time
    printf("\nYou have arrived at your destination!\n");
    t = localtime(&target_time_t);
    year = 1900 + t->tm_year;
    month = t->tm_mon + 1;
    day = t->tm_mday;
    hour = t->tm_hour;
    minute = t->tm_min;
    second = t->tm_sec;
    printf("The current date and time is now: %d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second);

    return 0;
}