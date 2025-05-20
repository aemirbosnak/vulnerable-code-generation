//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

enum MONTHS { J = 1, F, M, A, M2, J2, J3, A2, S, O, N, D };

//Function to convert date from string to integer format
int dateToInt(char *date) {
    char *token = strtok(date, "/");
    int day = atoi(token);
    token = strtok(NULL, "/");
    int month = atoi(token);
    token = strtok(NULL, "/");
    int year = atoi(token);

    int dateInt = year * 10000 + month * 100 + day;
    return dateInt;
}

//Function to convert date from integer to string format
char *intToDate(int dateInt) {
    int day = dateInt % 100;
    int month = (dateInt / 100) % 100;
    int year = dateInt / 10000;

    char *date = (char *)malloc(sizeof(char) * 11);
    sprintf(date, "%02d/%02d/%04d", day, month, year);
    return date;
}

//Function to calculate number of days in a month
int daysInMonth(int month, int year) {
    int days;

    if (month == J || month == M2 || month == M || month == J3 || month == A || month == N || month == D)
        days = 31;
    else if (month == F) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            days = 29;
        else
            days = 28;
    }
    else
        days = 30;

    return days;
}

//Function to find the next date in natural language
char *nextDate(char *date) {
    int dateInt = dateToInt(date);

    int day = dateInt % 100;
    int month = (dateInt / 100) % 100;
    int year = dateInt / 10000;

    int days = daysInMonth(month, year);

    if (day == days) {
        day = 1;
        if (month == D) {
            month = J;
            year++;
        }
        else
            month++;
    }
    else
        day++;

    int nextDateInt = year * 10000 + month * 100 + day;
    char *nextDateStr = intToDate(nextDateInt);

    return nextDateStr;
}


int main() {
    //Current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int today = (tm.tm_year + 1900) * 10000 + (tm.tm_mon + 1) * 100 + tm.tm_mday;

    char *input = (char *)malloc(sizeof(char) * 11);
    printf("Enter a date in dd/mm/yyyy format: ");
    fgets(input, 11, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character

    int inputInt = dateToInt(input);

    char *next = nextDate(input);
    printf("Next date: %s\n", next);

    int diff = dateToInt(next) - inputInt;
    printf("Difference from today: %d days\n", dateToInt(next) - today);

    free(input);
    free(next);
    return 0;
}