//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TIME 1000
#define TIME_STEP 1

typedef struct {
    int year;
    int month;
    int day;
} Date;

void print_date(Date date) {
    printf("%d-%02d-%02d", date.year, date.month, date.day);
}

void travel_back(Date* current_date, int days) {
    current_date->day -= days;
    while (current_date->day < 1) {
        current_date->day += 30;
        if (current_date->month == 2) {
            if (current_date->year % 4 == 0 && current_date->year % 100 != 0 || current_date->year % 400 == 0) {
                current_date->month++;
            } else {
                current_date->month--;
                current_date->year--;
            }
        } else {
            current_date->month--;
        }
    }
}

int main() {
    Date current_date = { .year = 2022, .month = 1, .day = 1 };
    int days_to_travel;

    printf("Current date: ");
    print_date(current_date);
    printf("\n");

    scanf("%d", &days_to_travel);

    travel_back(&current_date, days_to_travel);

    printf("New date: ");
    print_date(current_date);
    printf("\n");

    return 0;
}