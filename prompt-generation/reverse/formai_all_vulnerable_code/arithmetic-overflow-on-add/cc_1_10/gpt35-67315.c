//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    time_t t = time(NULL); // acquiring current time
    struct tm tm = *localtime(&t); // converting time to readable format
    int year, month, day, hour, minute, second;
    
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter a date and time to travel to:\n");

    // prompting user to enter desired date and time
    printf("Year (yyyy): ");
    scanf("%d", &year);
    printf("Month (mm): ");
    scanf("%d", &month);
    printf("Day (dd): ");
    scanf("%d", &day);
    printf("Hour (hh): ");
    scanf("%d", &hour);
    printf("Minute (mm): ");
    scanf("%d", &minute);
    printf("Second (ss): ");
    scanf("%d", &second);

    // converting user input to time format
    struct tm travel_time = {0};
    travel_time.tm_year = year - 1900;
    travel_time.tm_mon = month - 1;
    travel_time.tm_mday = day;
    travel_time.tm_hour = hour;
    travel_time.tm_min = minute;
    travel_time.tm_sec = second;

    // calculating time remaining to travel
    double time_remaining = difftime(mktime(&travel_time), t);

    // handling negative time remaining values (i.e. travel time already passed)
    if (time_remaining < 0) {
        printf("You have traveled back in time!\n");
        time_remaining *= -1;
    }

    // displaying time remaining to travel
    printf("Time remaining to travel: %f seconds\n", time_remaining);

    // simulating travel time
    printf("Traveling...\n");
    while (difftime(time(NULL), t) < time_remaining) {}

    // displaying arrival time
    printf("You have arrived at your destination on ");
    printf("%d-%02d-%02d %02d:%02d:%02d\n",
           travel_time.tm_year + 1900, travel_time.tm_mon + 1, travel_time.tm_mday,
           travel_time.tm_hour, travel_time.tm_min, travel_time.tm_sec);

    return 0;
}