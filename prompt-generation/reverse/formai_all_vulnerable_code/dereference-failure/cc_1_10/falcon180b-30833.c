//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 9999
#define MIN_YEAR 0

struct Date {
    int year;
    int month;
    int day;
};

struct TimeMachine {
    struct Date current_date;
    struct Date target_date;
    int status;
};

void init_date(struct Date* date) {
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    date->year = tm->tm_year + 1900;
    date->month = tm->tm_mon + 1;
    date->day = tm->tm_mday;
}

void print_date(struct Date date) {
    printf("%04d-%02d-%02d\n", date.year, date.month, date.day);
}

int is_valid_date(struct Date date) {
    if (date.year < MIN_YEAR || date.year > MAX_YEAR) {
        return 0;
    }
    if (date.month < 1 || date.month > 12) {
        return 0;
    }
    if (date.day < 1 || date.day > 31) {
        return 0;
    }
    return 1;
}

int main() {
    struct Date current_date;
    init_date(&current_date);
    struct TimeMachine time_machine;
    time_machine.current_date = current_date;

    int choice;
    do {
        printf("Current date: ");
        print_date(time_machine.current_date);
        printf("Enter your choice:\n");
        printf("1. Set target date\n");
        printf("2. Time travel\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                init_date(&time_machine.target_date);
                printf("Target date: ");
                print_date(time_machine.target_date);
                break;
            case 2:
                if (!is_valid_date(time_machine.target_date)) {
                    printf("Invalid target date.\n");
                } else {
                    time_machine.status = 1;
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice!= 3);

    return 0;
}