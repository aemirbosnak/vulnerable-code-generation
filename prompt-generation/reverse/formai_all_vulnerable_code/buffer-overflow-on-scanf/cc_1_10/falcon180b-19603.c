//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int year, month, day, hour, minute, second;
    char timezone[10];

    // Get current date and time
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);

    // Convert to readable format
    year = local_time->tm_year + 1900;
    month = local_time->tm_mon + 1;
    day = local_time->tm_mday;
    hour = local_time->tm_hour;
    minute = local_time->tm_min;
    second = local_time->tm_sec;
    strftime(timezone, 10, "%Z", local_time);

    // Print current date and time
    printf("Current date and time: %d-%02d-%02d %02d:%02d:%02d %s\n",
            year, month, day, hour, minute, second, timezone);

    // Ask user for destination date and time
    printf("Enter destination date and time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%d-%02d-%02d %02d:%02d:%02d", &year, &month, &day, &hour, &minute, &second);

    // Convert to time_t format
    struct tm destination_time = {0};
    destination_time.tm_year = year - 1900;
    destination_time.tm_mon = month - 1;
    destination_time.tm_mday = day;
    destination_time.tm_hour = hour;
    destination_time.tm_min = minute;
    destination_time.tm_sec = second;

    // Time travel!
    time_t destination_timestamp = mktime(&destination_time);
    printf("Time travel initiated. Destination: %s\n", asctime(gmtime(&destination_timestamp)));

    // Return to present time
    time_t present_timestamp = time(NULL);
    printf("Returning to present time: %s\n", asctime(localtime(&present_timestamp)));

    return 0;

}