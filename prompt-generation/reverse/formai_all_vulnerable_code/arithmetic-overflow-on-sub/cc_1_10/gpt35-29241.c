//FormAI DATASET v1.0 Category: Date and time ; Style: active
#include <stdio.h>
#include <time.h>

int main() {
    // get current time
    time_t current_time = time(NULL);

    // convert to local time
    struct tm* local_time = localtime(&current_time);

    // print date and time
    printf("Current date and time: %s", asctime(local_time));

    // get user input for date and time
    printf("Enter year (YYYY): ");
    int year;
    scanf("%d", &year);
    printf("Enter month (1-12): ");
    int month;
    scanf("%d", &month);
    printf("Enter day (1-31): ");
    int day;
    scanf("%d", &day);
    printf("Enter hour (0-23): ");
    int hour;
    scanf("%d", &hour);
    printf("Enter minute (0-59): ");
    int minute;
    scanf("%d", &minute);
    printf("Enter second (0-59): ");
    int second;
    scanf("%d", &second);

    // create time struct from user input
    struct tm user_time = {0};
    user_time.tm_year = year - 1900;
    user_time.tm_mon = month - 1;
    user_time.tm_mday = day;
    user_time.tm_hour = hour;
    user_time.tm_min = minute;
    user_time.tm_sec = second;

    // convert time struct to Unix timestamp
    time_t user_timestamp = mktime(&user_time);

    // convert Unix timestamp to local time
    struct tm* user_local_time = localtime(&user_timestamp);

    // print user's date and time
    printf("User input date and time: %s", asctime(user_local_time));

    return 0;
}