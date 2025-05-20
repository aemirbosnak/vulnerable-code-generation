//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MONTHS_IN_YEAR 12
#define MAX_INPUT_LEN 100

typedef struct {
    int day;
    int month;
    int year;
} date_t;

void parseDate(const char *input, date_t *output) {
    int i, day, month, year, leapYear;
    char monthName[MONTHS_IN_YEAR][MAX_INPUT_LEN];

    strcpy(monthName[0], "January");
    strcpy(monthName[1], "February");
    strcpy(monthName[2], "March");
    strcpy(monthName[3], "April");
    strcpy(monthName[4], "May");
    strcpy(monthName[5], "June");
    strcpy(monthName[6], "July");
    strcpy(monthName[7], "August");
    strcpy(monthName[8], "September");
    strcpy(monthName[9], "October");
    strcpy(monthName[10], "November");
    strcpy(monthName[11], "December");

    sscanf(input, "%d %s %d", &day, monthName, &year);

    for (i = 0; i < MONTHS_IN_YEAR; i++) {
        if (strcmp(monthName, monthName[i]) == 0) {
            month = i + 1;
            break;
        }
    }

    if (month < 3) {
        year -= 1;
        month += MONTHS_IN_YEAR;
    }

    leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));

    if (month == 2 && day > 28) {
        if (leapYear) {
            output->day = day - 29;
            output->month = month;
            output->year = year;
        } else {
            output->day = day - 28;
            output->month = month;
            output->year = year;
        }
    } else if (day > 30) {
        output->day = day - 30;
        output->month++;
        if (output->month > MONTHS_IN_YEAR) {
            output->month -= MONTHS_IN_YEAR;
            output->year++;
        }
    }

    output->year = year;
}

void printDate(const date_t *input) {
    char *monthName;

    switch (input->month) {
        case 1: monthName = "January"; break;
        case 2: monthName = "February"; break;
        case 3: monthName = "March"; break;
        case 4: monthName = "April"; break;
        case 5: monthName = "May"; break;
        case 6: monthName = "June"; break;
        case 7: monthName = "July"; break;
        case 8: monthName = "August"; break;
        case 9: monthName = "September"; break;
        case 10: monthName = "October"; break;
        case 11: monthName = "November"; break;
        case 12: monthName = "December"; break;
        default: monthName = "Unknown";
    }

    printf("%d %s %d\n", input->day, monthName, input->year);
}

int main() {
    char input[MAX_INPUT_LEN];
    date_t date;

    printf("Enter a date in the format 'day month year' (e.g. '31 December 1999'): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    parseDate(input, &date);
    printDate(&date);

    return 0;
}