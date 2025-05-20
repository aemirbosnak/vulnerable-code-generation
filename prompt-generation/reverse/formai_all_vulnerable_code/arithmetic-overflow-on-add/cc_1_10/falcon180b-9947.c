//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 9999
#define MAX_MONTH 12
#define MAX_DAY 31

struct date {
    int year;
    int month;
    int day;
};

struct date current_date;
struct date destination_date;

void set_current_date() {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    current_date.year = t->tm_year + 1900;
    current_date.month = t->tm_mon + 1;
    current_date.day = t->tm_mday;
}

void set_destination_date() {
    printf("Enter destination year: ");
    scanf("%d", &destination_date.year);
    printf("Enter destination month: ");
    scanf("%d", &destination_date.month);
    printf("Enter destination day: ");
    scanf("%d", &destination_date.day);
}

int is_valid_date(struct date date) {
    if (date.year < 1900 || date.year > MAX_YEAR) {
        return 0;
    }
    if (date.month < 1 || date.month > MAX_MONTH) {
        return 0;
    }
    if (date.day < 1 || date.day > MAX_DAY) {
        return 0;
    }
    return 1;
}

void time_travel() {
    set_current_date();
    set_destination_date();
    if (!is_valid_date(current_date) ||!is_valid_date(destination_date)) {
        printf("Invalid date.\n");
        return;
    }
    if (current_date.year == destination_date.year &&
        current_date.month == destination_date.month &&
        current_date.day == destination_date.day) {
        printf("You are already in the destination time.\n");
        return;
    }
    if (destination_date.year < current_date.year) {
        printf("Time travel to the past is not possible.\n");
        return;
    }
    printf("Time travel initiated...\n");
    sleep(3);
    printf("You have arrived in the year %d.\n", destination_date.year);
}

int main() {
    time_travel();
    return 0;
}