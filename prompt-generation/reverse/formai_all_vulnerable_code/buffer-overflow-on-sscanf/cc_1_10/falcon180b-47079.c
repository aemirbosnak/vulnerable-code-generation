//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 100

char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
char *weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

bool isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12) {
        return false;
    }
    if (day < 1 || day > 31) {
        return false;
    }
    if (month == 2) {
        if (day > 29) {
            return false;
        }
        if (day == 29 &&!(year % 4 == 0 && (year % 100!= 0 || year % 400 == 0))) {
            return false;
        }
    }
    return true;
}

int getNumberOfDays(int month, int year) {
    if (month == 2) {
        if ((year % 4 == 0 && year % 100!= 0) || year % 400 == 0) {
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

int getWeekday(int day, int month, int year) {
    int numDays = 0;
    for (int i = 0; i < month - 1; i++) {
        numDays += getNumberOfDays(i, year);
    }
    numDays += day;
    return (numDays % 7) + 1;
}

void convertDate(int day, int month, int year) {
    if (!isValidDate(day, month, year)) {
        printf("Invalid date.\n");
        return;
    }
    printf("The date %d/%s/%d falls on a %s.\n", day, months[month - 1], year, weekdays[getWeekday(day, month, year) - 1]);
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a date in the format DD/MM/YYYY: ");
    fgets(input, MAX_LENGTH, stdin);
    int day, month, year;
    sscanf(input, "%d/%d/%d", &day, &month, &year);
    convertDate(day, month, year);
    return 0;
}