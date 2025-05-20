//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

#define MAX_TIME_TRAVEL_DEPTH 10
#define MAX_LINE_LENGTH 1024

// Function to print the current time and depth
void print_time_and_depth(int depth) {
    time_t rawtime;
    struct tm * timeinfo;

    char time_buffer[MAX_LINE_LENGTH];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    printf("\nDepth: %d, Current Time: %s", depth, asctime(timeinfo));
}

// Function to travel back in time by the given number of seconds
void travel_back_in_time(int seconds) {
    struct tm newtime;
    time_t new_time;

    time(&new_time);
    localtime_r(&new_time, &newtime);

    newtime.tm_sec -= seconds;
    if (newtime.tm_sec < 0) {
        newtime.tm_sec += 60;
        newtime.tm_min--;
    }

    if (newtime.tm_min < 0) {
        newtime.tm_min += 60;
        newtime.tm_hour--;
    }

    if (newtime.tm_hour < 0) {
        newtime.tm_hour += 24;
        newtime.tm_mday--;
    }

    if (newtime.tm_mday < 0) {
        newtime.tm_mday += 30;
        newtime.tm_mon--;
    }

    if (newtime.tm_mon < 0) {
        newtime.tm_mon += 12;
        newtime.tm_year--;
    }

    if (newtime.tm_year < 1970) {
        printf("Unable to travel back in time further than 1970.");
        exit(1);
    }

    new_time = mktime(&newtime);
    putenv("TZ=UTC");
    tzset();
    setenv("TZ", "UTC", 1);

    printf("Travelling back in time by %d seconds to %s", seconds, ctime(&new_time));
    sleep(seconds);
}

// Main function for the time travel simulator
int main() {
    int depth = 0, command, seconds;
    char input[MAX_LINE_LENGTH];

    while (1) {
        print_time_and_depth(depth);
        fgets(input, MAX_LINE_LENGTH, stdin);
        sscanf(input, "%s %d", &command, &seconds);

        if (command == 1) { // Travel forward in time
            travel_back_in_time(-seconds);
            depth++;
        } else if (command == 2) { // Travel back in time
            if (depth <= MAX_TIME_TRAVEL_DEPTH) {
                travel_back_in_time(seconds);
                depth++;
            } else {
                printf("Maximum time travel depth reached.\n");
            }
        } else if (command == 3) { // Exit the program
            break;
        } else {
            printf("Invalid command. Please enter '1' to travel forward in time, '2' to travel back in time, or '3' to exit.\n");
        }
    }

    return 0;
}