//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

typedef struct {
    char* month;
    int day;
    int year;
} Date;

void print_date(Date* date) {
    printf("%s %d, %d\n", date->month, date->day, date->year);
}

int is_leap_year(int year) {
    if (year % 4 == 0 && year % 100!= 0) {
        return 1;
    } else if (year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int get_month_length(int year, int month) {
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

int get_day_of_week(int day, int month, int year) {
    int century = year / 100 + 1;
    int yoe = year % 100;
    int doy = (153 * (month + 12 * ((month - 3) / 5) - 3) + day + 365 * century - 365 * century / 4 - 365 * century / 100 + 365 * century / 400 - 32045) % 7;
    if (doy < 0) {
        doy += 7;
    }
    return doy;
}

char* get_month_name(int month) {
    switch (month) {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "Invalid month";
    }
}

void parse_date_string(char* date_string, Date* date) {
    int day, month, year;
    sscanf(date_string, "%d %s %d", &day, date->month, &year);
    date->day = day;
    date->year = year;
}

int main() {
    char input_buffer[MAX_STRING_LENGTH];
    Date date;

    printf("Enter a date in the format 'dd mmm yyyy': ");
    fgets(input_buffer, MAX_STRING_LENGTH, stdin);

    parse_date_string(input_buffer, &date);

    printf("The date '%s' is on a %s and falls on a %s.\n", input_buffer, get_month_name(date.month), get_day_of_week(date.day, date.month, date.year));

    return 0;
}