//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_LENGTH 32
#define DAYS_PER_MONTH(month, year) (month == 2 && ((year % 4 == 0 && year % 100!= 0) || year % 400 == 0))? 29 : (month - 1) % 7 == 0? 31 : 30

struct date {
    int year;
    int month;
    int day;
};

char *month_names[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

char *week_days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

char *get_month_name(int month) {
    return month_names[month - 1];
}

void get_date(struct date *date) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    date->year = t->tm_year + 1900;
    date->month = t->tm_mon + 1;
    date->day = t->tm_mday;
}

int get_weekday(struct date date) {
    int y = date.year % 100;
    int m = date.month - 1;
    int d = date.day;
    int c = y / 100;
    int n = (365.25 * (y + 3 - c)) / 4;
    int k = y % 100;
    int j = (5 * (m - 3 + 4800 + (30 * (m + 1) / 2))) / 153;
    int l = (y + 3 - c - ((c + 4) / 4) + ((8 * (c + 5)) / 25) - 5 * k + (2 * j) - (366 * (c / 4)) - (367 * (c / 100)) - (367 * (c / 400)) + (d - 1)) % 7;
    return (l + 5) % 7;
}

char *get_weekday_name(int weekday) {
    return week_days[weekday];
}

void print_date(struct date date) {
    printf("%s %d, %d\n", get_weekday_name(get_weekday(date)), date.day, date.month);
}

int main() {
    char input[MAX_DATE_LENGTH];
    struct date date;
    printf("Enter a date in the format YYYY-MM-DD: ");
    scanf("%s", input);
    sscanf(input, "%d-%d-%d", &date.year, &date.month, &date.day);
    if (date.month < 1 || date.month > 12) {
        printf("Invalid month.\n");
        return 1;
    }
    if (date.day < 1 || date.day > DAYS_PER_MONTH(date.month, date.year)) {
        printf("Invalid day.\n");
        return 1;
    }
    get_date(&date);
    printf("Today's date: ");
    print_date(date);
    return 0;
}