//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

char* month_name(int month) {
    static char* months[] = {"Januarius", "Februarius", "Martius", "Aprilis", "Maius", "Junius", "Julius", "Augustus", "September", "October", "November", "December"};
    return months[month];
}

char* day_name(int day) {
    static char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return days[day];
}

int is_leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

int get_days_in_month(int month, int year) {
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

int is_valid_date(int day, int month, int year) {
    if (month < 1 || month > 12) {
        return 0;
    }
    if (day < 1 || day > get_days_in_month(month, year)) {
        return 0;
    }
    return 1;
}

int main() {
    time_t now = time(NULL);
    struct tm* today = localtime(&now);
    int year = today->tm_year + 1900;
    int month = today->tm_mon + 1;
    int day = today->tm_mday;
    printf("Today's date in the medieval style is:\n");
    printf("The %d day of %s, in the year of our Lord %d.\n", day, month_name(month), year);
    return 0;
}