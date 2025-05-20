//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 9999

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

void print_time(Time t) {
    printf("%04d-%02d-%02d %02d:%02d:%02d\n", t.year, t.month, t.day, t.hour, t.minute, t.second);
}

int main() {
    Time current_time = {2021, 11, 1, 0, 0, 0};
    Time destination_time = {MAX_YEAR, 12, 31, 23, 59, 59};

    printf("Current time: ");
    print_time(current_time);

    printf("Enter destination time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%04d-%02d-%02d %02d:%02d:%02d", &destination_time.year, &destination_time.month, &destination_time.day, &destination_time.hour, &destination_time.minute, &destination_time.second);

    int time_travel_duration = (destination_time.year - current_time.year) * 365 * 24 * 60 * 60 + (destination_time.month - current_time.month) * 30 * 24 * 60 * 60 + (destination_time.day - current_time.day) * 24 * 60 * 60 + (destination_time.hour - current_time.hour) * 60 * 60 + (destination_time.minute - current_time.minute) * 60 + (destination_time.second - current_time.second);

    printf("Time travel duration: %d seconds\n", time_travel_duration);

    int i;
    for (i = 0; i <= time_travel_duration; i++) {
        current_time.second++;
        if (current_time.second == 60) {
            current_time.second = 0;
            current_time.minute++;
            if (current_time.minute == 60) {
                current_time.minute = 0;
                current_time.hour++;
                if (current_time.hour == 24) {
                    current_time.hour = 0;
                    current_time.day++;
                    if (current_time.day == 30) {
                        current_time.day = 1;
                        current_time.month++;
                        if (current_time.month == 13) {
                            current_time.month = 1;
                            current_time.year++;
                        }
                    }
                }
            }
        }
        print_time(current_time);
        sleep(1);
    }

    return 0;
}