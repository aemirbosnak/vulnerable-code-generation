//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEARS 100
#define TIME_FORMAT "%d-%d-%d %H:%M:%S"

struct Date {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

void print_date(struct Date date) {
    char time_string[30];
    sprintf(time_string, TIME_FORMAT, date.month, date.day, date.year, date.hour, date.minute, date.second);
    printf("You are now in the year %d, month %d, day %d, hour %d, minute %d, second %d.\n", date.year, date.month, date.day, date.hour, date.minute, date.second);
    printf("Current time: %s\n", time_string);
}

void travel_in_time(struct Date* current_date, struct Date* target_date) {
    time_t current_time = mktime(current_date);
    time_t target_time = mktime(target_date);
    long time_difference = target_time - current_time;

    if (time_difference < 0) {
        printf("Error: Cannot travel to the past!\n");
        return;
    }

    current_time += time_difference;
    struct tm* new_date = localtime(&current_time);

    current_date->year = new_date->tm_year + 1900;
    current_date->month = new_date->tm_mon + 1;
    current_date->day = new_date->tm_mday;
    current_date->hour = new_date->tm_hour;
    current_date->minute = new_date->tm_min;
    current_date->second = new_date->tm_sec;

    print_date(*current_date);
}

int main() {
    struct Date current_date = { 2022, 1, 1, 0, 0, 0 };
    struct Date target_date = { 2000, 1, 1, 12, 0, 0 };

    while (1) {
        print_date(current_date);
        printf("Press Enter to travel in time or q to quit: ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'q') {
            break;
        }

        printf("Enter target date (YYYY MM DD HH MM SS): ");
        scanf("%d%d%d%d%d%d", &target_date.year, &target_date.month, &target_date.day, &target_date.hour, &target_date.minute, &target_date.second);

        travel_in_time(&current_date, &target_date);
    }

    return 0;
}