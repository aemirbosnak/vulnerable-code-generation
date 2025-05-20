//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} DateTime;

DateTime currentTime() {
    DateTime now;
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    
    now.year = tm_info->tm_year + 1900;
    now.month = tm_info->tm_mon + 1;
    now.day = tm_info->tm_mday;
    now.hour = tm_info->tm_hour;
    now.minute = tm_info->tm_min;
    now.second = tm_info->tm_sec;

    return now;
}

void displayTime(DateTime dt) {
    printf("Current Date and Time: %04d-%02d-%02d %02d:%02d:%02d\n", 
           dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second);
}

void travelThroughTime(DateTime *dt, int years, int months, int days, int hours, int minutes, int seconds) {
    dt->year += years;
    dt->month += months;
    if (dt->month > 12) {
        dt->year += dt->month / 12;
        dt->month %= 12;
    }
    
    dt->day += days;
    if (dt->day > 30) { // Simplified for this example
        dt->month += dt->day / 30;
        dt->day %= 30;
    }
    
    dt->hour += hours;
    if (dt->hour >= 24) {
        dt->day += dt->hour / 24;
        dt->hour %= 24;
    }
    
    dt->minute += minutes;
    if (dt->minute >= 60) {
        dt->hour += dt->minute / 60;
        dt->minute %= 60;
    }
    
    dt->second += seconds;
    if (dt->second >= 60) {
        dt->minute += dt->second / 60;
        dt->second %= 60;
    }
}

void giveOverview() {
    printf("Welcome to the C Time Travel Simulator!\n");
    printf("What time would you like to travel to?\n");
    printf("You can specify years, months, days, hours, minutes, and seconds.\n");
}

int main() {
    giveOverview();

    DateTime now = currentTime();
    displayTime(now);

    int years, months, days, hours, minutes, seconds;
    
    printf("Enter years to travel (can be negative): ");
    scanf("%d", &years);
    printf("Enter months to travel (can be negative): ");
    scanf("%d", &months);
    printf("Enter days to travel (can be negative): ");
    scanf("%d", &days);
    printf("Enter hours to travel (can be negative): ");
    scanf("%d", &hours);
    printf("Enter minutes to travel (can be negative): ");
    scanf("%d", &minutes);
    printf("Enter seconds to travel (can be negative): ");
    scanf("%d", &seconds);

    printf("Time Traveling...\n");
    travelThroughTime(&now, years, months, days, hours, minutes, seconds);
    
    printf("You've traveled through time!\n");
    displayTime(now);
  
    printf("Isn't time travel fascinating? You're now in the future or past!\n");
    
    return 0;
}