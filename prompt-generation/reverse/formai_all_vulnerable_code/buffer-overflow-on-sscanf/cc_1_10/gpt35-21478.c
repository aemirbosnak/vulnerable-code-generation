//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define YEAR_RANGE 5000 // maximum years to consider

// function to calculate if year is a leap year
int isLeap(int year) {
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        return 1;
    }
    return 0;
}

// function to convert month number to month name
char* getMonthName(int monthNum) {
    char* monthName;
    switch(monthNum) {
        case 1:
            monthName = "January";
            break;
        case 2:
            monthName = "February";
            break;
        case 3:
            monthName = "March";
            break;
        case 4:
            monthName = "April";
            break;
        case 5:
            monthName = "May";
            break;
        case 6:
            monthName = "June";
            break;
        case 7:
            monthName = "July";
            break;
        case 8:
            monthName = "August";
            break;
        case 9:
            monthName = "September";
            break;
        case 10:
            monthName = "October";
            break;
        case 11:
            monthName = "November";
            break;
        case 12:
            monthName = "December";
            break;
        default:
            monthName = "";
            break;
    }
    return monthName;
}

// function to convert a date string to a date object
void getDateFromString(char* dateString, int* year, int* month, int* day) {
    sscanf(dateString, "%d-%d-%d", year, month, day);
}

// function to convert a date object to a string in natural language
char* getNaturalLanguageDate(int year, int month, int day) {
    char* naturalLanguageDate = malloc(50 * sizeof(char));
    char* monthName = getMonthName(month);
    sprintf(naturalLanguageDate, "%s %d, %d", monthName, day, year);
    return naturalLanguageDate;
}

int main() {
    // initialize variables
    int year, month, day;
    char dateString[11];
    char* naturalLanguageDate;

    // get date string from user input
    printf("Enter date in yyyy-mm-dd format: ");
    scanf("%s", dateString);

    // convert date string to date object
    getDateFromString(dateString, &year, &month, &day);

    // validate year
    if (year < 0 || year > YEAR_RANGE) {
        printf("Invalid year input.\n");
        return -1;
    }

    // validate month
    if (month < 1 || month > 12) {
        printf("Invalid month input.\n");
        return -1;
    }

    // validate day
    int daysInMonth;
    switch(month) {
        case 2:
            if (isLeap(year)) {
                daysInMonth = 29;
            } else {
                daysInMonth = 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            daysInMonth = 30;
            break;
        default:
            daysInMonth = 31;
            break;
    }
    if (day < 1 || day > daysInMonth) {
        printf("Invalid day input.\n");
        return -1;
    }

    // convert date object to natural language date
    naturalLanguageDate = getNaturalLanguageDate(year, month, day);
    printf("Natural language date: %s\n", naturalLanguageDate);

    // free dynamically allocated memory
    free(naturalLanguageDate);

    return 0;
}