//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

struct date {
    int day;
    int month;
    int year;
};

bool is_leap_year(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return true;
    } else {
        return false;
    }
}

int days_in_month(int month, int year) {
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

struct date convert_date(char *input_date) {
    struct date d;
    char *token;
    int i = 0;
 
    token = strtok(input_date, "-");
 
    while (token != NULL) {
        switch (i) {
            case 0:
                d.year = atoi(token);
                break;
            case 1:
                d.month = atoi(token);
                break;
            case 2:
                d.day = atoi(token);
                break;
        }
        i++;
        token = strtok(NULL, "-");
    }
 
    return d;
}

int days_since_epoch(struct date d) {
    int year, month;
    int days = 0;
 
    for (year = 1970; year < d.year; year++) {
        if (is_leap_year(year)) {
            days += 366;
        } else {
            days += 365;
        }
    }
 
    for (month = 1; month < d.month; month++) {
        days += days_in_month(month, d.year);
    }
 
    days += d.day - 1;
 
    return days;
}

char *convert_date_to_string(struct date d) {
    char *str = malloc(11);
    sprintf(str, "%04d-%02d-%02d", d.year, d.month, d.day);
    return str;
}

int main() {
    char input_date[11];
    struct date d;
 
    printf("Enter a date in the format YYYY-MM-DD: ");
    scanf("%s", input_date);
 
    d = convert_date(input_date);
 
    printf("The number of days since January 1st, 1970 is: %d\n", days_since_epoch(d));
 
    printf("The date in the format YYYY-MM-DD is: %s\n", convert_date_to_string(d));
 
    return 0;
}