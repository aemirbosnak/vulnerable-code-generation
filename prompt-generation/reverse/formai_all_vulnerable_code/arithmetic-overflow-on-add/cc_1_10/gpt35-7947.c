//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: careful
#include <stdio.h>
#include <string.h>

// Function to determine if a year is a leap year
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    }
    return 0;
}

// Function to determine the number of days in a given month and year
int daysInMonth(int month, int year) {
    int days;

    switch(month) {
        case 2:
            if (isLeapYear(year)) {
                days = 29;
            } else {
                days = 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        default:
            days = 31;
            break;
    }

    return days;
}

// Function to convert a date string to an integer array
void dateToIntArray(char *dateString, int *dateArray) {
    char *token;
    token = strtok(dateString, "/");
    int i = 0;

    while (token != NULL) {
        dateArray[i] = atoi(token);
        token = strtok(NULL, "/");
        i++;
    }
}

// Function to convert an integer date array to a string
void intArrayToDate(int *dateArray, char *dateString) {
    sprintf(dateString, "%d/%d/%d", dateArray[0], dateArray[1], dateArray[2]);
}

// Function to increment a given date by 'n' days
void incrementDate(int *dateArray, int n) {
    int day = dateArray[0];
    int month = dateArray[1];
    int year = dateArray[2];

    for (int i = 0; i < n; i++) {
        day++;
        if (day > daysInMonth(month, year)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

    dateArray[0] = day;
    dateArray[1] = month;
    dateArray[2] = year;
}

int main() {
    char date[9];
    printf("Enter a date in MM/DD/YYYY format: ");
    scanf("%s", date);

    int dateArray[3];
    dateToIntArray(date, dateArray);

    int n;
    printf("Enter the number of days to increment: ");
    scanf("%d", &n);

    incrementDate(dateArray, n);
    char newDate[9];
    intArrayToDate(dateArray, newDate);

    printf("The new date is: %s\n", newDate);

    return 0;
}