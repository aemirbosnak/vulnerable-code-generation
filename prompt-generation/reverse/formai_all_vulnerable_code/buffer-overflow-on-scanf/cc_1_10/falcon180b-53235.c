//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    struct tm current_time;
    time_t now = time(NULL);
    localtime_r(&now, &current_time);

    printf("Current time: %04d-%02d-%02d %02d:%02d:%02d\n",
            current_time.tm_year + 1900,
            current_time.tm_mon + 1,
            current_time.tm_mday,
            current_time.tm_hour,
            current_time.tm_min,
            current_time.tm_sec);

    int year, month, day, hour, minute, second;
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month: ");
    scanf("%d", &month);
    printf("Enter day: ");
    scanf("%d", &day);
    printf("Enter hour: ");
    scanf("%d", &hour);
    printf("Enter minute: ");
    scanf("%d", &minute);
    printf("Enter second: ");
    scanf("%d", &second);

    time_t target_time = mktime(&(struct tm){
       .tm_year = year - 1900,
       .tm_mon = month - 1,
       .tm_mday = day,
       .tm_hour = hour,
       .tm_min = minute,
       .tm_sec = second,
    });

    if (target_time == -1) {
        printf("Invalid date/time.\n");
        return 1;
    }

    printf("Time travel initiated.\n");
    sleep(3);
    printf("Arrived at destination: %04d-%02d-%02d %02d:%02d:%02d\n",
            current_time.tm_year + 1900,
            current_time.tm_mon + 1,
            current_time.tm_mday,
            current_time.tm_hour,
            current_time.tm_min,
            current_time.tm_sec);

    return 0;
}