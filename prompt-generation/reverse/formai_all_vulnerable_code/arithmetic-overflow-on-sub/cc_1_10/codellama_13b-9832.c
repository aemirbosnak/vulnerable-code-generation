//Code Llama-13B DATASET v1.0 Category: Time Travel Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the time travel structure
struct TimeTravel {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

// Define the time travel functions
void init_time_travel(struct TimeTravel *tt);
void set_time_travel(struct TimeTravel *tt, int year, int month, int day, int hour, int minute, int second);
void travel_to_past(struct TimeTravel *tt);
void travel_to_future(struct TimeTravel *tt);
void print_time_travel(struct TimeTravel *tt);

// Implement the time travel functions
void init_time_travel(struct TimeTravel *tt) {
    tt->year = 1970;
    tt->month = 1;
    tt->day = 1;
    tt->hour = 0;
    tt->minute = 0;
    tt->second = 0;
}

void set_time_travel(struct TimeTravel *tt, int year, int month, int day, int hour, int minute, int second) {
    tt->year = year;
    tt->month = month;
    tt->day = day;
    tt->hour = hour;
    tt->minute = minute;
    tt->second = second;
}

void travel_to_past(struct TimeTravel *tt) {
    time_t current_time;
    struct tm *time_info;

    time(&current_time);
    time_info = localtime(&current_time);

    tt->year = time_info->tm_year + 1;
    tt->month = time_info->tm_mon + 1;
    tt->day = time_info->tm_mday;
    tt->hour = time_info->tm_hour;
    tt->minute = time_info->tm_min;
    tt->second = time_info->tm_sec;
}

void travel_to_future(struct TimeTravel *tt) {
    time_t current_time;
    struct tm *time_info;

    time(&current_time);
    time_info = localtime(&current_time);

    tt->year = time_info->tm_year - 1;
    tt->month = time_info->tm_mon - 1;
    tt->day = time_info->tm_mday;
    tt->hour = time_info->tm_hour;
    tt->minute = time_info->tm_min;
    tt->second = time_info->tm_sec;
}

void print_time_travel(struct TimeTravel *tt) {
    printf("Year: %d\n", tt->year);
    printf("Month: %d\n", tt->month);
    printf("Day: %d\n", tt->day);
    printf("Hour: %d\n", tt->hour);
    printf("Minute: %d\n", tt->minute);
    printf("Second: %d\n", tt->second);
}

int main() {
    struct TimeTravel tt;

    init_time_travel(&tt);

    travel_to_past(&tt);
    print_time_travel(&tt);

    travel_to_future(&tt);
    print_time_travel(&tt);

    return 0;
}