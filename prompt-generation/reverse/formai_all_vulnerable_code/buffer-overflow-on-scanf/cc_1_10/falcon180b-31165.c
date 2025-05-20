//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_LENGTH 100

typedef struct {
    char day[MAX_DATE_LENGTH];
    char month[MAX_DATE_LENGTH];
    char year[MAX_DATE_LENGTH];
} Date;

void parseDate(char* input, Date* date) {
    char* token = strtok(input, " ");
    strcpy(date->day, token);

    token = strtok(NULL, " ");
    strcpy(date->month, token);

    token = strtok(NULL, " ");
    strcpy(date->year, token);
}

int isLeapYear(int year) {
    if (year % 4 == 0 && year % 100!= 0) {
        return 1;
    } else if (year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int getDaysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year)? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12) {
        return 0;
    }

    switch (month) {
        case 4:
        case 6:
        case 9:
        case 11:
            if (day < 1 || day > 30) {
                return 0;
            }
            break;
        default:
            if (day < 1 || day > getDaysInMonth(month, year)) {
                return 0;
            }
            break;
    }

    if (year < 1000 || year > 9999) {
        return 0;
    }

    return 1;
}

void convertDateToWords(Date* date, char* output) {
    int day = atoi(date->day);
    int month = atoi(date->month);
    int year = atoi(date->year);

    if (!isValidDate(day, month, year)) {
        strcpy(output, "Invalid date");
        return;
    }

    char dayStr[MAX_DATE_LENGTH];
    char monthStr[MAX_DATE_LENGTH];
    char yearStr[MAX_DATE_LENGTH];

    sprintf(dayStr, "%d", day);
    sprintf(monthStr, "%d", month);
    sprintf(yearStr, "%d", year);

    strcpy(output, monthStr);
    strcat(output, " ");
    strcat(output, dayStr);
    strcat(output, ", ");
    strcat(output, yearStr);
}

int main() {
    Date inputDate;
    char input[MAX_DATE_LENGTH];
    char output[MAX_DATE_LENGTH];

    printf("Enter a date in MM/DD/YYYY format: ");
    scanf("%s", input);

    parseDate(input, &inputDate);

    convertDateToWords(&inputDate, output);

    printf("Converted date: %s\n", output);

    return 0;
}