//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date date;
    int event;
} Event;

Event events[] = {
    { 1969, 7, 20, 1},
    { 1972, 8, 26, 2},
    { 1981, 4, 12, 3},
    { 1984, 1, 24, 4},
    { 1989, 11, 9, 5},
    { 1991, 8, 19, 6},
    { 1993, 1, 20, 7},
    { 1997, 7, 1, 8},
    { 2001, 9, 11, 9},
    { 2003, 3, 20, 10},
    { 2007, 7, 11, 11},
    { 2008, 9, 15, 12},
    { 2009, 1, 20, 13},
    { 2011, 3, 11, 14},
    { 2013, 4, 15, 15},
    { 2015, 7, 14, 16},
    { 2017, 8, 21, 17},
    { 2019, 12, 31, 18},
    { 2020, 3, 11, 19},
    { 2021, 8, 30, 20},
    { 2023, 2, 13, 21},
};

int num_events = sizeof(events) / sizeof(Event);

void print_date(Date date) {
    printf("%d-%02d-%02d\n", date.year, date.month, date.day);
}

void print_event(Event event) {
    print_date(event.date);
    printf("Event %d occurred.\n", event.event);
}

int compare_dates(Date date1, Date date2) {
    if (date1.year == date2.year) {
        if (date1.month == date2.month) {
            return date1.day - date2.day;
        } else {
            return date1.month - date2.month;
        }
    } else {
        return date1.year - date2.year;
    }
}

int find_event(Date date) {
    int low = 0;
    int high = num_events - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        int cmp = compare_dates(date, events[mid].date);
        
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

void simulate_time_travel(Date date) {
    int event_index = find_event(date);

    if (event_index == -1) {
        printf("No event occurred on that date.\n");
    } else {
        print_event(events[event_index]);

        printf("Would you like to travel to another date? (y/n) ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'y') {
            printf("Enter a date (YYYY-MM-DD): ");
            scanf(" %d-%d-%d", &date.year, &date.month, &date.day);

            simulate_time_travel(date);
        }
    }
}

int main() {
    srand(time(NULL));

    Date date;
    printf("Enter a date (YYYY-MM-DD): ");
    scanf(" %d-%d-%d", &date.year, &date.month, &date.day);

    simulate_time_travel(date);

    return 0;
}