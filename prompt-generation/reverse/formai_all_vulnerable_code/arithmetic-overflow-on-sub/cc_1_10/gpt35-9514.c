//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Dennis Ritchie
/*
* C Time Travel Simulator
* By [Your Name]
* 
* This program simulates time travel by switching between a current time and a desired time.
* 
*/

#include <stdio.h>
#include <time.h>

int main()
{
    // variables to hold current time and desired time
    time_t current_time, desired_time;
    
    // get current time
    current_time = time(NULL);
    printf("Current time is %s", ctime(&current_time));
    
    // get desired time from user
    printf("Enter the year you would like to travel to: ");
    int year;
    scanf("%d", &year);
    printf("Enter the month you would like to travel to: ");
    int month;
    scanf("%d", &month);
    printf("Enter the day you would like to travel to: ");
    int day;
    scanf("%d", &day);
    printf("Enter the hour you would like to travel to: ");
    int hour;
    scanf("%d", &hour);
    printf("Enter the minute you would like to travel to: ");
    int minute;
    scanf("%d", &minute);
    printf("Enter the second you would like to travel to: ");
    int second;
    scanf("%d", &second);
    
    // construct struct tm for desired time
    struct tm time_struct = {0};
    time_struct.tm_year = year - 1900; // years since 1900
    time_struct.tm_mon = month - 1; // months since January (0-11)
    time_struct.tm_mday = day; // day of the month (1-31)
    time_struct.tm_hour = hour; // hours since midnight (0-23)
    time_struct.tm_min = minute; // minutes after the hour (0-59)
    time_struct.tm_sec = second; // seconds after the minute (0-61)
    
    // convert struct tm to time_t
    desired_time = mktime(&time_struct);
    
    // travel to desired time
    printf("Traveling to %s", ctime(&desired_time));
    sleep(1); // simulate time travel time
    current_time = desired_time;
    
    // print current time
    printf("Current time is now %s", ctime(&current_time));
    
    return 0;
}