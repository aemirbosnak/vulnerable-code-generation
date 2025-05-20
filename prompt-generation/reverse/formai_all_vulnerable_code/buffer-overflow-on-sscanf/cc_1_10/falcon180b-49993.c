//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STRING_LENGTH 50

struct date {
    int day;
    int month;
    int year;
};

struct date current_date;

void get_current_date() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    current_date.day = t->tm_mday;
    current_date.month = t->tm_mon + 1;
    current_date.year = t->tm_year + 1900;
}

void print_date(struct date d) {
    printf("%d/%d/%d\n", d.day, d.month, d.year);
}

int main() {
    char input_date[MAX_STRING_LENGTH];

    printf("Enter a date (YYYY/MM/DD): ");
    scanf("%s", input_date);

    struct date parsed_date;
    sscanf(input_date, "%d/%d/%d", &parsed_date.day, &parsed_date.month, &parsed_date.year);

    if (parsed_date.day < 1 || parsed_date.day > 31 ||
        parsed_date.month < 1 || parsed_date.month > 12 ||
        parsed_date.year < 1900 || parsed_date.year > 2100) {
        printf("Invalid date\n");
        return 1;
    }

    printf("You entered: ");
    print_date(parsed_date);

    get_current_date();
    printf("Today is: ");
    print_date(current_date);

    int difference_days = (current_date.year - parsed_date.year) * 365 +
                          (current_date.month - parsed_date.month) * 30 +
                          (current_date.day - parsed_date.day);

    if (difference_days >= 0) {
        printf("The difference between the dates is %d days\n", difference_days);
    } else {
        printf("The second date is in the future\n");
    }

    return 0;
}