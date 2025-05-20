//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

Time now() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    return (Time){tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec};
}

Time add_years(Time t, int years) {
    t.year += years;
    return t;
}

Time add_months(Time t, int months) {
    t.month += months;
    while (t.month > 12) {
        t.month -= 12;
        t.year++;
    }
    return t;
}

Time add_days(Time t, int days) {
    t.day += days;
    while (t.day > 31) {
        t.day -= 31;
        t.month++;
    }
    return t;
}

Time add_hours(Time t, int hours) {
    t.hour += hours;
    while (t.hour > 24) {
        t.hour -= 24;
        t.day++;
    }
    return t;
}

Time add_minutes(Time t, int minutes) {
    t.minute += minutes;
    while (t.minute > 60) {
        t.minute -= 60;
        t.hour++;
    }
    return t;
}

Time add_seconds(Time t, int seconds) {
    t.second += seconds;
    while (t.second > 60) {
        t.second -= 60;
        t.minute++;
    }
    return t;
}

int main() {
    Time t = now();
    printf("Current time: %04d-%02d-%02d %02d:%02d:%02d\n", t.year, t.month, t.day, t.hour, t.minute, t.second);

    t = add_years(t, 1);
    printf("One year later: %04d-%02d-%02d %02d:%02d:%02d\n", t.year, t.month, t.day, t.hour, t.minute, t.second);

    t = add_months(t, 6);
    printf("Six months later: %04d-%02d-%02d %02d:%02d:%02d\n", t.year, t.month, t.day, t.hour, t.minute, t.second);

    t = add_days(t, 10);
    printf("Ten days later: %04d-%02d-%02d %02d:%02d:%02d\n", t.year, t.month, t.day, t.hour, t.minute, t.second);

    t = add_hours(t, 12);
    printf("Twelve hours later: %04d-%02d-%02d %02d:%02d:%02d\n", t.year, t.month, t.day, t.hour, t.minute, t.second);

    t = add_minutes(t, 30);
    printf("Thirty minutes later: %04d-%02d-%02d %02d:%02d:%02d\n", t.year, t.month, t.day, t.hour, t.minute, t.second);

    t = add_seconds(t, 60);
    printf("One minute later: %04d-%02d-%02d %02d:%02d:%02d\n", t.year, t.month, t.day, t.hour, t.minute, t.second);

    return 0;
}