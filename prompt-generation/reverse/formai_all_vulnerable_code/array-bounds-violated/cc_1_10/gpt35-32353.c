//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multivariable
#include <stdio.h>
#include <string.h>

const char *MONTHS[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

struct Date {
    int day;
    int month;
    int year;
};

int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}

int daysInMonth(int month, int year) {
    if (month == 2) {
        if (isLeapYear(year)) {
            return 29;
        }
        return 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

struct Date convertDate(char *inputDate) {
    struct Date date;
    int day, year, month;

    sscanf(inputDate, "%d-%d-%d", &day, &month, &year);

    date.day = day;
    date.month = month;
    date.year = year;

    return date;
}

void printDate(struct Date date) {
    printf("The date is %d %s %d\n", date.day, MONTHS[date.month - 1], date.year);
}

int main() {
    char inputDate[11];
    printf("Enter a date in the format dd-mm-yyyy: ");
    scanf("%s", inputDate);

    struct Date date = convertDate(inputDate);
    printDate(date);

    return 0;
}