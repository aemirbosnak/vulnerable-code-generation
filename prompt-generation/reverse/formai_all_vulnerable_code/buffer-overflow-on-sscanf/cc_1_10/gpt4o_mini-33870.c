//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a structure to hold date information */
typedef struct {
    int day;
    int month;
    int year;
} Date;

/* Function to check if a given year is a leap year */
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/* Function to get the number of days in a month */
int daysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0; // Invalid month
    }
}

/* Function to convert a date from string format to Date struct */
Date parseDate(const char* dateStr) {
    Date date = {0, 0, 0};
    sscanf(dateStr, "%d-%d-%d", &date.year, &date.month, &date.day);
    return date;
}

/* Function to convert date from Date struct to string format */
void formatDate(const Date* date, char* formattedDate) {
    sprintf(formattedDate, "%02d-%02d-%04d", date->day, date->month, date->year);
}

/* Function to display the date in a user-friendly format */
void displayDate(const Date* date) {
    char formattedDate[11]; // "DD-MM-YYYY"
    formatDate(date, formattedDate);
    
    printf("The date is: %s\n", formattedDate);
}

/* Function to transform date from one format to another */
void transformDate(const char* inputDateStr) {
    Date date = parseDate(inputDateStr);
    
    if (date.month < 1 || date.month > 12 || date.day < 1 || date.day > daysInMonth(date.month, date.year)) {
        printf("Invalid Date: %s\n", inputDateStr);
        return;
    }
    
    displayDate(&date);
}

/* Shape shifting function to play with date transformations */
void shapeShiftDate(const char* inputDateStr) {
    printf("Original date string: %s\n", inputDateStr);
    transformDate(inputDateStr);

    for (int i = 0; i < 2; i++) {
        Date shiftedDate = parseDate(inputDateStr);
        // Shift date by one day
        shiftedDate.day += 1;
        if (shiftedDate.day > daysInMonth(shiftedDate.month, shiftedDate.year)) {
            shiftedDate.day = 1;
            shiftedDate.month += 1;
            if (shiftedDate.month > 12) {
                shiftedDate.month = 1;
                shiftedDate.year += 1;
            }
        }
        char newDateStr[11];
        formatDate(&shiftedDate, newDateStr);
        printf("Shifted date: %s\n", newDateStr);
        // Use current date string as base for next shift
        inputDateStr = newDateStr;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <date in YYYY-MM-DD format>\n", argv[0]);
        return 1;
    }

    shapeShiftDate(argv[1]);
    return 0;
}