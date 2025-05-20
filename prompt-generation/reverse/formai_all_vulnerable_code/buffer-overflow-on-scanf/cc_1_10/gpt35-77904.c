//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isLeapYear(int year) {
    if (year%400 == 0) {
        return 1;
    }
    if (year%100 == 0) {
        return 0;
    }
    if (year%4 == 0) {
        return 1;
    }
    return 0;
}

char *monthName(int month) {
    char *months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};
    if (month < 1 || month > 12) {
        return "";
    }
    return months[month - 1];
}

int monthDays(int month, int year) {
    if (month < 1 || month > 12) {
        return 0;
    }
    int days[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30,
                  31, 31, 30, 31, 30, 31};
    return days[month - 1];
}

int isValidDate(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > monthDays(month, year)) {
        return 0;
    }
    return 1;
}

char *convertDate(int day, int month, int year) {
    char *date = malloc(50 * sizeof(char));
    if (isValidDate(day, month, year)) {
        sprintf(date, "%d %s %d", day, monthName(month), year);
    } else {
        sprintf(date, "%d/%d/%d is not a valid date.", day, month, year);
    }
    return date;
}

int main() {
    int day, month, year;
    printf("Enter a date in format DD MM YYYY: ");
    scanf("%d%d%d", &day, &month, &year);
    char *date = convertDate(day, month, year);
    printf("%s\n", date);
    free(date);
    return 0;
}