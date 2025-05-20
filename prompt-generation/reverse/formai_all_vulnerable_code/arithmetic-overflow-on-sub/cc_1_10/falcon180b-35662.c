//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    struct tm start_time;
    struct tm end_time;
    int year, month, day, hour, minute, second;

    // Get the current time
    time_t now = time(NULL);

    // Convert the current time to a struct tm
    localtime_r(&now, &start_time);

    // Get the year, month, day, hour, minute, and second from the user
    printf("Enter the year you want to travel to: ");
    scanf("%d", &year);
    printf("Enter the month you want to travel to: ");
    scanf("%d", &month);
    printf("Enter the day you want to travel to: ");
    scanf("%d", &day);
    printf("Enter the hour you want to travel to: ");
    scanf("%d", &hour);
    printf("Enter the minute you want to travel to: ");
    scanf("%d", &minute);
    printf("Enter the second you want to travel to: ");
    scanf("%d", &second);

    // Set the end time to the user's input
    end_time.tm_year = year - 1900;
    end_time.tm_mon = month - 1;
    end_time.tm_mday = day;
    end_time.tm_hour = hour;
    end_time.tm_min = minute;
    end_time.tm_sec = second;

    // Calculate the time difference between the start and end times
    int time_diff = mktime(&end_time) - mktime(&start_time);

    // Convert the time difference to seconds
    time_diff /= 1000;

    // Sleep for the time difference
    sleep(time_diff);

    // Print the current time
    printf("You have traveled to the year %d!\n", end_time.tm_year + 1900);
    printf("The current time is %d:%d:%d.\n", end_time.tm_hour, end_time.tm_min, end_time.tm_sec);

    return 0;
}