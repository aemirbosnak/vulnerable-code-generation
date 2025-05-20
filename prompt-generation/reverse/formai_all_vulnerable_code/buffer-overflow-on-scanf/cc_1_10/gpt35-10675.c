//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int year, month, day, hour, minute, timezone;
    printf("Enter your current timezone (GMT):");
    scanf("%d", &timezone);
    printf("Enter the year that you would like to travel to:");
    scanf("%d", &year);
    printf("Enter the month that you would like to travel to:");
    scanf("%d", &month);
    printf("Enter the day that you would like to travel to:");
    scanf("%d", &day);
    printf("Enter the hour that you would like to travel to:");
    scanf("%d", &hour);
    printf("Enter the minute that you would like to travel to:");
    scanf("%d", &minute);
    struct tm timeinfo = { 0 };
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;
    timeinfo.tm_hour = hour;
    timeinfo.tm_min = minute;
    timeinfo.tm_sec = 0;
    time_t time_travel = mktime(&timeinfo);
    if (time_travel == (time_t)(-1)) {
        printf("Invalid input. Please try again.\n");
        return -1;
    }
    time_t now = time(NULL);
    int gmt_diff = timezone * 3600;
    time_t time_now = now - gmt_diff;
    double time_diff = difftime(time_travel, time_now);
    if (time_diff < 0) {
        printf("Time travel to the past is not possible.\n");
        return -1;
    }
    printf("Time travel successful. Travelling to:\n");
    printf("%d/%d/%d %02d:%02d GMT\n", day, month, year, hour, minute);
    printf("Current time at origin: %s", asctime(gmtime(&now)));
    printf("Current time at destination: %s", asctime(gmtime(&time_travel)));
    while (time_diff > 0) {
        printf("Time remaining: %.0f seconds\n", time_diff);
        time_diff -= 1.0;
        sleep(1);
    }
    printf("Welcome to the year %d!\n", year);
    return 0;
}