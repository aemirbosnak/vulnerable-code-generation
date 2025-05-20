//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: future-proof
#include <stdio.h>
#include <time.h>

int main() {
    time_t present_time;
    struct tm *time_data;
    int year, month, day, hour, minute, second;

    // Current time
    present_time = time(NULL);
    time_data = localtime(&present_time);
    printf("Welcome to the Time Travel Simulator!\n");
    printf("The current date and time is: %s\n\n", asctime(time_data));

    // Enter desired date and time
    printf("Please enter the date and time you wish to travel to: \n\n");
    printf("Year (format: yyyy): ");
    scanf("%d", &year);
    printf("Month (format: mm): ");
    scanf("%d", &month);
    printf("Day (format: dd): ");
    scanf("%d", &day);
    printf("Hour (format: hh): ");
    scanf("%d", &hour);
    printf("Minute (format: mm): ");
    scanf("%d", &minute);
    printf("Second (format: ss): ");
    scanf("%d", &second);

    // Time travel initiation
    struct tm travel_time = { .tm_year = year - 1900, .tm_mon = month - 1, .tm_mday = day, .tm_hour = hour, .tm_min = minute, .tm_sec = second };
    time_t travel_time_t = mktime(&travel_time);

    // Check if time travel is possible
    if (travel_time_t < present_time) {
        printf("\nTime travel to the past is not possible!\n");
        return 0;
    }

    // Countdown to time travel
    printf("\nInitiating time travel..\n");
    int i;
    for (i = 5; i > 0; i--) {
        printf("%d..\n", i);
        sleep(1);
    }

    printf("\nWelcome to the future!\n");
    struct tm *travel_data = localtime(&travel_time_t);
    printf("The date and time is: %s\n", asctime(travel_data));

    return 0;
}