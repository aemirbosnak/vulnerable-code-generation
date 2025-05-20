//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *time_info;

    time(&current_time);
    time_info = localtime(&current_time);

    int millenium_ceremony = 1000000000;
    int current_year = time_info->tm_year + 1900;
    int target_year = current_year;

    while (target_year == current_year) {
        printf("Enter the year you wish to travel to (between 1900 and %d): ", millenium_ceremony);
        scanf("%d", &target_year);
        if (target_year < 1900 || target_year > millenium_ceremony) {
            printf("That year is out of range.\n");
            target_year = current_year;
        }
        else if (target_year > current_year) {
            printf("You cannot travel to the future.\n");
            target_year = current_year;
        }
    }

    int years_traveled = current_year - target_year;
    int day_of_week = time_info->tm_wday;

    printf("\nTraveling back in time %d years...\n\n", years_traveled);

    int current_days_in_year = 0;
    for (int i = 0; i <= time_info->tm_yday; i++) {
        current_days_in_year++;
    }

    int target_leap_year = 1904;
    int days_in_year = 365;
    if (target_year % 4 == 0 && (target_year % 100 != 0 || target_year % 400 == 0)) {
        days_in_year = 366;
        target_leap_year = target_year;
    }

    int current_hour = time_info->tm_hour;
    int target_hour = current_hour;
    int current_minute = time_info->tm_min;
    int target_minute = current_minute;
    int current_second = time_info->tm_sec;
    int target_second = current_second;

    for (int day = current_days_in_year; day >= 1; day--) {
        if (day_of_week == 0 || day_of_week == 6) {
            printf("It's a weekend day (%d/%d/%d).\n", day, time_info->tm_mon + 1, target_year);
        }
        else {
            printf("It's a weekday (%d/%d/%d).\n", day, time_info->tm_mon + 1, target_year);
        }
        if (day == 1) {
            printf("\nHappy New Year, %d!\n", target_year);
        }
        for (int hour = current_hour; hour >= 0; hour--) {
            for (int minute = current_minute; minute >= 0; minute--) {
                for (int second = current_second; second >= 0; second--) {
                    printf("%02d:%02d:%02d\n", target_hour, target_minute, target_second);
                    target_second--;
                    if (target_second == -1) {
                        target_second = 59;
                        target_minute--;
                        if (target_minute == -1) {
                            target_minute = 59;
                            target_hour--;
                            if (target_hour == -1) {
                                target_hour = 23;
                            }
                        }
                    }
                    sleep(1);
                }
            }
        }
        current_hour = 23;
        current_minute = 59;
        current_second = 59;
        if (day_of_week == 6) {
            day_of_week = 0;
        }
        else {
            day_of_week++;
        }
    }

    printf("\nYou have successfully traveled back in time %d years to %d!\n", years_traveled, target_year);
    printf("Goodbye!\n");

    return 0;
}