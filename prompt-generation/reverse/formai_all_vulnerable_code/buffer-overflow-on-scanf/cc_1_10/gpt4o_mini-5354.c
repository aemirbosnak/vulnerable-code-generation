//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: introspective
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
} TimePoint;

void display_time(TimePoint tp) {
    printf("Current Time: %04d-%02d-%02d %02d:%02d:%02d\n", 
           tp.year, tp.month, tp.day, tp.hour, tp.minute, tp.second);
}

TimePoint time_travel(TimePoint tp, int years, int months, int days) {
    // Update the time_point by the specified years, months, and days
    tp.year += years;
    tp.month += months;

    if (tp.month > 12) {
        tp.year += tp.month / 12;
        tp.month = tp.month % 12;
    }
    
    tp.day += days;
    // Assuming a simplistic model of month length, not accounting for leap years/months
    int month_length[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    while (tp.day > month_length[tp.month - 1]) {
        tp.day -= month_length[tp.month - 1];
        tp.month++;
        if (tp.month > 12) {
            tp.month = 1;
            tp.year++;
        }
    }

    return tp;
}

int main() {
    TimePoint current_time;
    time_t raw_time;
    struct tm *time_info;

    time(&raw_time);
    time_info = localtime(&raw_time);

    // Set current time to TimePoint structure
    current_time.year = time_info->tm_year + 1900;
    current_time.month = time_info->tm_mon + 1;
    current_time.day = time_info->tm_mday;
    current_time.hour = time_info->tm_hour;
    current_time.minute = time_info->tm_min;
    current_time.second = time_info->tm_sec;

    printf("Welcome to the C Time Travel Simulator! \n");
    display_time(current_time);

    while (1) {
        int years, months, days;
        printf("\nEnter the number of years, months, and days to travel back or forward (e.g., -1 0 0 to go back 1 year): ");
        if (scanf("%d %d %d", &years, &months, &days) != 3) {
            printf("Invalid input. Please enter three integers for years, months, and days.\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue;
        }

        current_time = time_travel(current_time, years, months, days);
        display_time(current_time);

        printf("Would you like to continue traveling through time? (y/n): ");
        char ch;
        scanf(" %c", &ch);
        if (ch != 'y' && ch != 'Y') {
            break;
        }
    }

    printf("Thank you for using the C Time Travel Simulator! \n");
    printf("Ending simulation at: ");
    display_time(current_time);
    
    return 0;
}