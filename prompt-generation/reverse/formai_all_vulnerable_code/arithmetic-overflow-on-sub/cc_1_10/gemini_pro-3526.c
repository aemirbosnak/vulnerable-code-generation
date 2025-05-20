//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TIME_TRAVEL_MAX_DIST 100

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} datetime_t;

void print_datetime(datetime_t dt) {
    printf("%d-%02d-%02d %02d:%02d:%02d\n",
        dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second);
}

int main() {
    srand(time(NULL));

    datetime_t now;
    time_t t = time(NULL);
    localtime_r(&t, &now);

    printf("Current Datetime: ");
    print_datetime(now);

    while (1) {
        // Get a random time offset within the allowed range
        int time_offset = (rand() % (2 * TIME_TRAVEL_MAX_DIST)) - TIME_TRAVEL_MAX_DIST;

        // Apply the offset to the current datetime
        datetime_t dt = now;
        dt.second += time_offset;
        while (dt.second < 0) {
            dt.second += 60;
            dt.minute--;
        }
        while (dt.second >= 60) {
            dt.second -= 60;
            dt.minute++;
        }

        dt.minute += time_offset;
        while (dt.minute < 0) {
            dt.minute += 60;
            dt.hour--;
        }
        while (dt.minute >= 60) {
            dt.minute -= 60;
            dt.hour++;
        }

        dt.hour += time_offset;
        while (dt.hour < 0) {
            dt.hour += 24;
            dt.day--;
        }
        while (dt.hour >= 24) {
            dt.hour -= 24;
            dt.day++;
        }

        dt.day += time_offset;
        while (dt.day < 1) {
            dt.day += 30;
            dt.month--;
        }
        while (dt.day > 30) {
            dt.day -= 30;
            dt.month++;
        }

        dt.month += time_offset;
        while (dt.month < 1) {
            dt.month += 12;
            dt.year--;
        }
        while (dt.month > 12) {
            dt.month -= 12;
            dt.year++;
        }

        printf("New Datetime: ");
        print_datetime(dt);
        
        // Sleep for a while to let the user read the output
        sleep(1);
    }

    return 0;
}