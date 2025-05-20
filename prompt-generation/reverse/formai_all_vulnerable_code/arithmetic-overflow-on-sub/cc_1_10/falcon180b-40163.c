//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_YEAR 9999
#define MAX_MONTH 12
#define MAX_DAY 31
#define MAX_HOUR 23
#define MAX_MINUTE 59
#define MAX_SECOND 59

struct tm current_time;
struct tm target_time;
bool valid_input = false;

void set_current_time() {
    time_t now = time(NULL);
    localtime_r(&now, &current_time);
}

void print_current_time() {
    printf("Current time: %d-%d-%d %d:%d:%d\n",
           current_time.tm_year + 1900,
           current_time.tm_mon + 1,
           current_time.tm_mday,
           current_time.tm_hour,
           current_time.tm_min,
           current_time.tm_sec);
}

void set_target_time() {
    printf("Enter target year (between 1900 and %d): ", MAX_YEAR);
    scanf("%d", &target_time.tm_year);
    target_time.tm_year += 1900;

    printf("Enter target month (between 1 and %d): ", MAX_MONTH);
    scanf("%d", &target_time.tm_mon);

    printf("Enter target day (between 1 and %d): ", MAX_DAY);
    scanf("%d", &target_time.tm_mday);

    printf("Enter target hour (between 0 and %d): ", MAX_HOUR);
    scanf("%d", &target_time.tm_hour);

    printf("Enter target minute (between 0 and %d): ", MAX_MINUTE);
    scanf("%d", &target_time.tm_min);

    printf("Enter target second (between 0 and %d): ", MAX_SECOND);
    scanf("%d", &target_time.tm_sec);

    valid_input = true;
}

void check_input() {
    if (!valid_input) {
        printf("Invalid input. Please try again.\n");
        set_target_time();
    }
}

void time_travel() {
    time_t target_time_t = mktime(&target_time);
    time_t current_time_t = mktime(&current_time);
    time_t diff = target_time_t - current_time_t;

    if (diff > 0) {
        printf("Traveling to the future...\n");
        sleep(diff);
    } else if (diff < 0) {
        printf("Traveling to the past...\n");
        localtime_r(&current_time_t + diff, &current_time);
    } else {
        printf("You are already in the target time.\n");
    }

    print_current_time();
}

int main() {
    set_current_time();
    print_current_time();

    set_target_time();
    check_input();

    time_travel();

    return 0;
}