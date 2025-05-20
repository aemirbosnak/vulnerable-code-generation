//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_LEN 100

struct date {
    int day, month, year;
};

void str2date(const char *str, struct date *date) {
    char *end;
    int month_len[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day, year, month;

    sscanf(str, "%d/%d/%d", &month, &day, &year);

    if (month < 1 || month > 12) {
        fprintf(stderr, "Invalid month\n");
        exit(1);
    }

    if (day < 1 || day > month_len[month - 1]) {
        fprintf(stderr, "Invalid day\n");
        exit(1);
    }

    if (month == 2) {
        if (isleapyear(year))
            month_len[1] = 29;
        else
            month_len[1] = 28;
    }

    date->day = day;
    date->month = month;
    date->year = year;
}

int isleapyear(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

void print_date(const struct date *date) {
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("%d %s %d\n", date->day, months[date->month - 1], date->year);
}

int main() {
    struct date date;
    char input[MAX_LEN];

    printf("Enter a date (dd/mm/yyyy): ");
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = '\0';

    str2date(input, &date);
    print_date(&date);

    return 0;
}