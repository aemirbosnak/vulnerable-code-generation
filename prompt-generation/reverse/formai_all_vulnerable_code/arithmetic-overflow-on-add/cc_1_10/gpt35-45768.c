//FormAI DATASET v1.0 Category: Date and time ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // Get current time of system
    time_t current_time;
    struct tm *time_info;
    char timeString[9];

    time(&current_time);
    time_info = localtime(&current_time);

    // Set time format and print current date and time
    strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);
    printf("Current time is: %s\n", timeString);
    strftime(timeString, sizeof(timeString), "%Y-%m-%d", time_info);
    printf("Current date is: %s\n", timeString);

    // Let's construct an arbitrary date and time in the past
    struct tm past_time_info;
    char past_timeString[9];
    char past_dateString[11];

    past_time_info.tm_sec = 23;
    past_time_info.tm_min = 22;
    past_time_info.tm_hour = 12;
    past_time_info.tm_mday = 16;
    past_time_info.tm_mon = 7;
    past_time_info.tm_year = 95;
    past_time_info.tm_isdst = -1;

    // Convert the past date and time to seconds since Epoch
    time_t past_time = mktime(&past_time_info);
    printf("Time in seconds of %d-%d-%d %d:%d:%d: %ld\n", 
            past_time_info.tm_year + 1900,
            past_time_info.tm_mon + 1, past_time_info.tm_mday,
            past_time_info.tm_hour, past_time_info.tm_min,
            past_time_info.tm_sec, past_time);

    // Convert the past time to struct tm format, set the time format and print it
    struct tm *past_time_struct = localtime(&past_time);
    strftime(past_timeString, sizeof(past_timeString), "%H:%M:%S", past_time_struct);
    printf("Time of %d-%d-%d %s: %s\n", 
            past_time_struct->tm_year + 1900,
            past_time_struct->tm_mon + 1, past_time_struct->tm_mday,
            past_timeString, past_timeString);
    strftime(past_dateString, sizeof(past_dateString), "%Y-%m-%d", past_time_struct);
    printf("Date of %s %s: %s\n", 
            past_timeString, past_dateString, past_dateString);

    return 0;
}