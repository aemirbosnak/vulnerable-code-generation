//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: protected
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Protected Date Structure
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Error codes
#define INVALID_DAY 1
#define INVALID_MONTH 2
#define INVALID_YEAR 3
#define INVALID_FORMAT 4

// Function prototypes
void validateDate(const Date* date);
void convertDate(const Date* inputDate, Date* outputDate);
int isLeapYear(int year);
int getDaysInMonth(int month, int year);

int main() {
    Date inputDate, outputDate;
    char inputString[11];

    printf("Enter a date in dd-mm-yyyy format: ");
    scanf("%s", inputString);

    // String to Date conversion
    sscanf(inputString, "%d-%d-%d", &inputDate.day, &inputDate.month, &inputDate.year);

    // Validate input date
    validateDate(&inputDate);

    // Convert date format
    convertDate(&inputDate, &outputDate);

    // Print output date
    printf("The date in yyyy-mm-dd format is: %04d-%02d-%02d\n", outputDate.year, outputDate.month, outputDate.day);

    return 0;
}

// Validate date structure
void validateDate(const Date* date) {
    int daysInMonth = getDaysInMonth(date->month, date->year);

    if (date->day < 1 || date->day > daysInMonth) {
        perror("Invalid day");
        exit(INVALID_DAY);
    }

    if (date->month < 1 || date->month > 12) {
        perror("Invalid month");
        exit(INVALID_MONTH);
    }

    if (date->year < 0) {
        perror("Invalid year");
        exit(INVALID_YEAR);
    }
}

// Convert date format
void convertDate(const Date* inputDate, Date* outputDate) {
    int daysInMonth = getDaysInMonth(inputDate->month, inputDate->year);

    outputDate->year = inputDate->year;
    outputDate->month = inputDate->month;
    outputDate->day = daysInMonth - inputDate->day + 1;
}

// Check if a year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Get number of days in a given month and year
int getDaysInMonth(int month, int year) {
    int days[] = {31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[month - 1];
}