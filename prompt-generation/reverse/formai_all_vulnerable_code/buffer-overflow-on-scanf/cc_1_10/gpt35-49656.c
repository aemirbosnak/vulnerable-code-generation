//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *MONTHS[] = {"January", "February", "March", "April",
                        "May", "June", "July", "August",
                        "September", "October", "November", "December"};

// Function to check if a given year is a leap year or not
int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

// Function to convert month name to month number
int getMonthNumber(char *month) {
    for (int i = 0; i < 12; i++) {
        if (strcmp(month, MONTHS[i]) == 0) {
            return i + 1;
        }
    }
    return -1;
}

// Function to convert month number to month name
char *getMonthName(int month) {
    if (month < 1 || month > 12) return "";
    return MONTHS[month - 1];
}

// Function to convert a date string to integer values of day, month, and year
void convertDate(char *dateString, int *day, int *month, int *year) {
    char *token = strtok(dateString, "/");
    int index = 0;

    while (token != NULL) {
        if (index == 0) {
            *day = atoi(token);
        } else if (index == 1) {
            *month = atoi(token);
        } else if (index == 2) {
            *year = atoi(token);
        }
        token = strtok(NULL, "/");
        index++;
    }
}

// Function to convert integer values of day, month, and year to a date string
char *convertDateToString(int day, int month, int year) {
    char *dateString = (char *) malloc(sizeof(char) * 11);
    sprintf(dateString, "%02d/%02d/%04d", day, month, year);
    return dateString;
}

// Function to add days to a given date
char *addDays(char *dateString, int daysToAdd) {
    int day = 0, month = 0, year = 0;
    convertDate(dateString, &day, &month, &year);

    // Calculate the maximum days in the given month and year
    int maxDaysInMonth = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDaysInMonth = 30;
    } else if (month == 2) {
        if (isLeapYear(year)) {
            maxDaysInMonth = 29;
        } else {
            maxDaysInMonth = 28;
        }
    }

    // Add the days
    for (int i = 0; i < daysToAdd; i++) {
        if (day < maxDaysInMonth) {
            day++;
        } else {
            day = 1;
            if (month < 12) {
                month++;
            } else {
                month = 1;
                year++;
            }
            maxDaysInMonth = 31;
            if (month == 4 || month == 6 || month == 9 || month == 11) {
                maxDaysInMonth = 30;
            } else if (month == 2) {
                if (isLeapYear(year)) {
                    maxDaysInMonth = 29;
                } else {
                    maxDaysInMonth = 28;
                }
            }
        }
    }

    return convertDateToString(day, month, year);
}

int main() {
    char dateString[15];
    int daysToAdd;
    printf("Enter a date in the format DD/MM/YYYY: ");
    scanf("%s", dateString);
    printf("Enter the number of days to add: ");
    scanf("%d", &daysToAdd);

    char *newDate = addDays(dateString, daysToAdd);
    printf("The new date is %s\n", newDate);

    free(newDate);

    return 0;
}