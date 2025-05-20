//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Time {
    int hour;
    int minute;
    int second;
};

struct Date {
    int year;
    int month;
    int day;
};

struct DateTime {
    struct Date date;
    struct Time time;
};

// Function that adds or subtracts time from a given datetime struct
void adjustDateTime(struct DateTime *dt, int years, int months, int days, int hours, int minutes, int seconds) {
    time_t t = mktime(&(dt->date));
    t += years * 31557600;
    t += months * 2629800;
    t += days * 86400;
    t += hours * 3600;
    t += minutes * 60;
    t += seconds;
    struct tm *new_time = localtime(&t);
    dt->date.year = new_time->tm_year + 1900;
    dt->date.month = new_time->tm_mon + 1;
    dt->date.day = new_time->tm_mday;
    dt->time.hour = new_time->tm_hour;
    dt->time.minute = new_time->tm_min;
    dt->time.second = new_time->tm_sec;
}

int main() {
    struct DateTime current_time;
    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    
    current_time.date.year = now->tm_year + 1900;
    current_time.date.month = now->tm_mon + 1;
    current_time.date.day = now->tm_mday;
    current_time.time.hour = now->tm_hour;
    current_time.time.minute = now->tm_min;
    current_time.time.second = now->tm_sec;
    
    struct DateTime future_time;
    future_time.date.year = 2077;
    future_time.date.month = 1;
    future_time.date.day = 1;
    future_time.time.hour = 0;
    future_time.time.minute = 0;
    future_time.time.second = 0;
    
    printf("Welcome to the Time Travel Simulator!\n\n");
    
    printf("Current date and time: %d/%d/%d %02d:%02d:%02d\n", 
            current_time.date.month, current_time.date.day, current_time.date.year, 
            current_time.time.hour, current_time.time.minute, current_time.time.second);
    printf("Future date and time: %d/%d/%d %02d:%02d:%02d\n", 
            future_time.date.month, future_time.date.day, future_time.date.year, 
            future_time.time.hour, future_time.time.minute, future_time.time.second);
    
    printf("\nHow many years will you travel forward in time?: ");
    int years;
    scanf("%d", &years);
    
    printf("How many months will you travel forward in time?: ");
    int months;
    scanf("%d", &months);
    
    printf("How many days will you travel forward in time?: ");
    int days;
    scanf("%d", &days);
    
    printf("How many hours will you travel forward in time?: ");
    int hours;
    scanf("%d", &hours);
    
    printf("How many minutes will you travel forward in time?: ");
    int minutes;
    scanf("%d", &minutes);
    
    printf("How many seconds will you travel forward in time?: ");
    int seconds;
    scanf("%d", &seconds);
    
    adjustDateTime(&future_time, years, months, days, hours, minutes, seconds);
    
    printf("\nYou have arrived at the destination time of %d/%d/%d %02d:%02d:%02d!\n",
            future_time.date.month, future_time.date.day, future_time.date.year,
            future_time.time.hour, future_time.time.minute, future_time.time.second);
    
    printf("\nThank you for using the Time Travel Simulator!\n");
    
    return 0;
}