//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

#define MAX_TIME_STRING_LENGTH 40

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

void print_time(Time time) {
    char time_string[MAX_TIME_STRING_LENGTH];
    snprintf(time_string, MAX_TIME_STRING_LENGTH,
             "%04d-%02d-%02d %02d:%02d:%02d",
             time.year, time.month, time.day,
             time.hour, time.minute, time.second);

    printf("Current time: %s\n", time_string);
}

void travel_back_in_time(Time* current_time, int seconds) {
    current_time->second -= seconds;

    // Adjust minutes, hours, day, month, year if necessary
    while (current_time->second < 0) {
        current_time->second += 60;
        current_time->minute--;

        if (current_time->minute < 0) {
            current_time->minute += 60;
            current_time->hour--;

            if (current_time->hour < 0) {
                current_time->hour += 24;
                current_time->day--;

                if (current_time->day < 1) {
                    current_time->day += 31;
                    current_time->month--;

                    if (current_time->month < 1) {
                        current_time->month += 12;
                        current_time->year--;
                    }
                }
            }
        }
    }
}

int main() {
    int travel_seconds;
    Time current_time = {2023, 12, 31, 23, 59, 59};

    print_time(current_time);

    printf("Enter number of seconds to travel back in time: ");
    scanf("%d", &travel_seconds);

    travel_back_in_time(&current_time, travel_seconds);

    printf("New time: ");
    print_time(current_time);

    return 0;
}