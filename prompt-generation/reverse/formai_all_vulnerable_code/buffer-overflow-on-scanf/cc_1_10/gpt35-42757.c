//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: portable
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    time(&current_time);
    struct tm *time_info = localtime(&current_time);

    printf("Welcome to the Time Travel Simulator!\n");

    // Display current date and time
    printf("The current date and time is: %s", asctime(time_info));

    int year, month, day, hour, minutes, seconds;
    printf("Please enter the year you wish to travel to: ");
    scanf("%d", &year);
    printf("Please enter the month you wish to travel to (1-12): ");
    scanf("%d", &month);
    printf("Please enter the day you wish to travel to: ");
    scanf("%d", &day);
    printf("Please enter the hour you wish to travel to (0-23): ");
    scanf("%d", &hour);
    printf("Please enter the minute you wish to travel to (0-59): ");
    scanf("%d", &minutes);
    printf("Please enter the second you wish to travel to (0-59): ");
    scanf("%d", &seconds);

    struct tm travel_time;
    travel_time.tm_year = year - 1900;
    travel_time.tm_mon = month - 1;
    travel_time.tm_mday = day;
    travel_time.tm_hour = hour;
    travel_time.tm_min = minutes;
    travel_time.tm_sec = seconds;

    // Convert travel time to time_t format
    time_t travel_time_t = mktime(&travel_time);

    printf("\nCalculating travel time...\n");

    double seconds_difference = difftime(travel_time_t, current_time);
    int years_difference = (int)(seconds_difference / (60 * 60 * 24 * 365.25));
    int days_difference = (int)(seconds_difference / (60 * 60 * 24)) % 365;
    int hours_difference = (int)(seconds_difference / (60 * 60)) % 24;
    int minutes_difference = (int)(seconds_difference / 60) % 60;
    int seconds_remainder = (int)seconds_difference % 60;

    // Display travel information
    printf("You will be travelling to: %s", asctime(&travel_time));
    printf("The time difference is:\n");
    printf("Years: %d\n", years_difference);
    printf("Days: %d\n", days_difference);
    printf("Hours: %d\n", hours_difference);
    printf("Minutes: %d\n", minutes_difference);
    printf("Seconds: %d\n", seconds_remainder);

    return 0;
}