//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int year, month, day, hour, minute, second;
    char date_str[20];
    time_t now;
    struct tm *t;

    // Get current time
    now = time(NULL);
    t = localtime(&now);

    // Get current date and time
    year = t->tm_year + 1900;
    month = t->tm_mon + 1;
    day = t->tm_mday;
    hour = t->tm_hour;
    minute = t->tm_min;
    second = t->tm_sec;

    // Convert date and time to string
    strftime(date_str, 20, "%Y-%m-%d %H:%M:%S", t);

    // Display current date and time
    printf("Current date and time: %s\n", date_str);

    // Get destination time from user
    printf("Enter destination date and time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", date_str);

    // Convert destination date and time to seconds since epoch
    t = localtime(&now);
    t->tm_year = atoi(date_str) - 1900;
    t->tm_mon = atoi(date_str + 5) - 1;
    t->tm_mday = atoi(date_str + 8);
    t->tm_hour = atoi(date_str + 11);
    t->tm_min = atoi(date_str + 14);
    t->tm_sec = atoi(date_str + 17);
    now = mktime(t);

    // Travel through time
    if (now > 0) {
        sleep(now - time(NULL));
    }

    // Display destination date and time
    t = localtime(&now);
    strftime(date_str, 20, "%Y-%m-%d %H:%M:%S", t);
    printf("Destination date and time: %s\n", date_str);

    return 0;
}