//Falcon2-11B DATASET v1.0 Category: Time Travel Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

int main() {
    struct timeval tv;
    struct tm *tm;
    char buffer[80];
    int year, month, day, hour, min, sec;

    // Set the current time
    gettimeofday(&tv, NULL);
    tm = localtime(&tv.tv_sec);
    year = tm->tm_year + 1900;
    month = tm->tm_mon + 1;
    day = tm->tm_mday;
    hour = tm->tm_hour;
    min = tm->tm_min;
    sec = tm->tm_sec;

    // Travel to the future
    srand(time(NULL));
    int random_number = rand() % 10;
    if (random_number == 0) {
        printf("Warning: Time travel to the future is not allowed.\n");
        return 0;
    } else {
        printf("Traveling to the future...\n");
        sleep(random_number);
    }

    // Travel to the past
    srand(time(NULL));
    random_number = rand() % 10;
    if (random_number == 0) {
        printf("Warning: Time travel to the past is not allowed.\n");
        return 0;
    } else {
        printf("Traveling to the past...\n");
        sleep(random_number);
    }

    // Set the current time again
    gettimeofday(&tv, NULL);
    tm = localtime(&tv.tv_sec);
    year = tm->tm_year + 1900;
    month = tm->tm_mon + 1;
    day = tm->tm_mday;
    hour = tm->tm_hour;
    min = tm->tm_min;
    sec = tm->tm_sec;

    // Print the current time
    printf("Current time: %d-%d-%d %d:%d:%d\n", year, month, day, hour, min, sec);

    return 0;
}