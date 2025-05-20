//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: automated
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <wctype.h>
#include <wchar.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int is_leap_year(int year) {
    if (year % 4 == 0 && year % 100!= 0 || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int get_days_in_month(int year, int month) {
    if (month == 2) {
        if (is_leap_year(year)) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int get_total_days(Date date) {
    int total_days = 0;
    for (int i = 1; i < date.month; i++) {
        total_days += get_days_in_month(date.year, i);
    }
    total_days += date.day;
    return total_days;
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");

    char input[100];
    printf("Enter a date in the format of MM/DD/YYYY: ");
    scanf("%s", input);

    int year = 0, month = 0, day = 0;
    if (sscanf(input, "%d/%d/%d", &month, &day, &year)!= 3) {
        printf("Invalid date format.\n");
        return 1;
    }

    if (month < 1 || month > 12) {
        printf("Invalid month.\n");
        return 1;
    }

    if (day < 1 || day > get_days_in_month(year, month)) {
        printf("Invalid day.\n");
        return 1;
    }

    Date date = {year, month, day};
    time_t timestamp = mktime(&date);
    if (timestamp == -1) {
        printf("Invalid date.\n");
        return 1;
    }

    struct tm *tm = localtime(&timestamp);
    printf("The date %s is %s, %d %s %d.\n", input, months[tm->tm_mon], tm->tm_mday, months[tm->tm_mon], tm->tm_year + 1900);

    return 0;
}