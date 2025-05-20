//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_TIME_TRAVELS 100

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

void print_time(Time time) {
    printf("%04d-%02d-%02d %02d:%02d:%02d\n", time.year, time.month, time.day, time.hour, time.minute, time.second);
}

Time add_time(Time a, Time b) {
    Time result = {0};
    result.year = a.year + b.year;
    result.month = a.month + b.month;
    result.day = a.day + b.day;

    int carry = result.day / 365;
    result.day %= 365;

    carry += result.month / 12;
    result.month %= 12;

    result.year += carry;

    return result;
}

bool is_valid_date(int year, int month, int day) {
    if (month < 1 || month > 12) {
        return false;
    }

    switch (month) {
        case 2:
            if (day > 29 &&!(year % 4 == 0 && (year % 100!= 0 || year % 400 == 0))) {
                return false;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (day > 30) {
                return false;
            }
            break;
        default:
            if (day > 31) {
                return false;
            }
            break;
    }

    return true;
}

int main() {
    srand(time(NULL));

    Time initial_time = {2022, 1, 1, 0, 0, 0};
    Time destination_time = {rand() % 100, rand() % 12 + 1, rand() % 28 + 1, rand() % 24, rand() % 60, rand() % 60};

    while (!is_valid_date(destination_time.year, destination_time.month, destination_time.day)) {
        destination_time.year = rand() % 100;
        destination_time.month = rand() % 12 + 1;
        destination_time.day = rand() % 28 + 1;
    }

    int num_time_travels = rand() % MAX_TIME_TRAVELS + 1;
    Time *time_travels = malloc(sizeof(Time) * num_time_travels);

    for (int i = 0; i < num_time_travels; i++) {
        time_travels[i] = add_time(initial_time, destination_time);
    }

    for (int i = 0; i < num_time_travels; i++) {
        print_time(time_travels[i]);
    }

    free(time_travels);

    return 0;
}