//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

void convertDate(char *inputDate, Date *outputDate) {
    int day, month, year, index;
    char monthName[13][10] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};

    // Splitting input string by space
    char *token = strtok(inputDate, " ");
    day = atoi(token);

    // Checking month name in input string
    index = 0;
    for (; index < 12; index++) {
        if (strstr(inputDate, monthName[index]) != NULL) {
            month = index + 1;
            break;
        }
    }

    token = strtok(NULL, " ");
    year = atoi(token);

    // Setting output date
    outputDate->day = day;
    outputDate->month = month;
    outputDate->year = year;
}

void printDate(Date date) {
    printf("%d/%d/%d\n", date.day, date.month, date.year);
}

int main() {
    char inputDate[20];
    Date outputDate;

    printf("Enter date in DD MMM YYYY format: ");
    scanf("%s", inputDate);

    convertDate(inputDate, &outputDate);
    printDate(outputDate);

    return 0;
}