//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: expert-level
#include <stdio.h>
#include <time.h>

int main() {
    // initialize current time
    struct tm *current_time;
    time_t t = time(NULL);
    current_time = localtime(&t);
    
    // initialize future time
    struct tm future_time = *current_time;
    future_time.tm_year = 2100 - 1900;
    future_time.tm_mon = 0;
    future_time.tm_mday = 1;
    future_time.tm_hour = 0;
    future_time.tm_min = 0;
    future_time.tm_sec = 0;
    
    // initialize past time
    struct tm past_time = *current_time;
    past_time.tm_year = 1900 - 1900;
    past_time.tm_mon = 0;
    past_time.tm_mday = 1;
    past_time.tm_hour = 0;
    past_time.tm_min = 0;
    past_time.tm_sec = 0;
    
    // time travel to the future
    printf("You are now time traveling to the year 2100...\n");
    for (time_t i = t; i < mktime(&future_time); i++) {
        current_time = localtime(&i);
        printf("The date is %d-%d-%d and the time is %d:%d:%d\n", current_time->tm_year + 1900,
                                                                current_time->tm_mon + 1,
                                                                current_time->tm_mday,
                                                                current_time->tm_hour,
                                                                current_time->tm_min,
                                                                current_time->tm_sec);
    }
    
    // time travel to the past
    printf("You are now time traveling to the year 1900...\n");
    for (time_t i = t; i > mktime(&past_time); i--) {
        current_time = localtime(&i);
        printf("The date is %d-%d-%d and the time is %d:%d:%d\n", current_time->tm_year + 1900,
                                                                current_time->tm_mon + 1,
                                                                current_time->tm_mday,
                                                                current_time->tm_hour,
                                                                current_time->tm_min,
                                                                current_time->tm_sec);
    }
    
    return 0;
}