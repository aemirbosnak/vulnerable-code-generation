//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to hold date values
typedef struct {
    int year;
    int month;
    int day;
} Date;

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to convert a date from a string to a Date struct
Date convertToDate(char* dateStr) {
    Date date;
    char delimiter[2] = "/";
    char *token;
    // Split date string into day, month, year values
    token = strtok(dateStr, delimiter);
    date.day = atoi(token);
    token = strtok(NULL, delimiter);
    date.month = atoi(token);
    token = strtok(NULL, delimiter);
    date.year = atoi(token);
    return date;
}

// Function to convert a Date struct to a string
char* convertToString(Date date) {
    char* dateStr = (char*)malloc(11*sizeof(char));
    sprintf(dateStr, "%02d/%02d/%04d", date.day, date.month, date.year);
    return dateStr;
}

// Function to add years to a Date struct
Date addYears(Date date, int years) {
    date.year += years;
    return date;
}

// Function to add months to a Date struct
Date addMonths(Date date, int months) {
    int yearsToAdd = months / 12;
    int newYear = date.year + yearsToAdd;
    int newMonth = date.month + (months % 12);
    if(newMonth > 12) {
        newYear++;
        newMonth -= 12;
    }
    // Check if new date is valid
    if(newMonth == 2) {
        if(isLeapYear(newYear)) {
            if(date.day > 29) {
                date.day = 29;
            }
        } else {
            if(date.day > 28) {
                date.day = 28;
            }
        }
    } else if(newMonth == 4 || newMonth == 6 || newMonth == 9 || newMonth == 11) {
        if(date.day > 30) {
            date.day = 30;
        }
    }
    date.year = newYear;
    date.month = newMonth;
    return date;
}

// Function to add days to a Date struct
Date addDays(Date date, int days) {
    while(days > 0) {
        // Check if new day is valid
        if(date.day+1 > 28 && date.month == 2) {
            if(isLeapYear(date.year)) {
                if(date.day+1 > 29) {
                    date.day = 1;
                    date.month++;
                }
            } else {
                date.day = 1;
                date.month++;
            }
        } else if(date.day+1 > 30 && (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)) {
            date.day = 1;
            date.month++;
        } else if(date.day+1 > 31) {
            date.day = 1;
            if(date.month == 12) {
                date.month = 1;
                date.year++;
            } else {
                date.month++;
            }
        } else {
            date.day++;
        }
        days--;
    }
    return date;
}

// Main function
int main() {
    // Ask user for date input
    char dateStr[11];
    printf("Enter a date in the format dd/mm/yyyy: ");
    fgets(dateStr, sizeof(dateStr), stdin);
    dateStr[strlen(dateStr)-1] = '\0';
    // Convert date string to Date struct
    Date date = convertToDate(dateStr);
    // Ask user for number of years, months, and days to add
    int years, months, days;
    printf("Enter number of years to add: ");
    scanf("%d", &years);
    printf("Enter number of months to add: ");
    scanf("%d", &months);
    printf("Enter number of days to add: ");
    scanf("%d", &days);
    // Add years, months, and days to Date struct
    date = addYears(date, years);
    date = addMonths(date, months);
    date = addDays(date, days);
    // Convert updated Date struct to string and print to console
    char* dateStr2 = convertToString(date);
    printf("New date: %s\n", dateStr2);
    free(dateStr2);
    return 0;
}