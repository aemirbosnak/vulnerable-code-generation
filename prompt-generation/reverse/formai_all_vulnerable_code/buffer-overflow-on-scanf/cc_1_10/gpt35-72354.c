//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function for checking leap year
int isLeap(int year) {
    if ((year % 4 == 0) && (year % 100 != 0)) {
        return 1;
    } else if (year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

// function for getting total number of days in a month
int getDaysInMonth(int month, int year) {
    int days;
    if (month == 2) {
        if (isLeap(year)) {
            days = 29;
        } else {
            days = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days = 30;
    } else {
        days = 31;
    }

    return days;
}

// function for converting date format from dd/mm/yyyy to yyyy/mm/dd
char* convertDateFormat(char* dateStr) {
    char* year = malloc(sizeof(char) * 5);
    char* month = malloc(sizeof(char) * 3);
    char* day = malloc(sizeof(char) * 3);
    sscanf(dateStr, "%[^/]/%[^/]/%[^/]", day, month, year);
    char* newDateStr = malloc(sizeof(char) * 11);
    sprintf(newDateStr, "%s/%s/%s", year, month, day);
    free(year);
    free(month);
    free(day);
    return newDateStr;
}

// function for converting date string to integer array
void convertDateToIntArray(char* dateStr, int dateArr[]) {
    char* tmpDateStr = convertDateFormat(dateStr);
    sscanf(tmpDateStr, "%d/%d/%d", &dateArr[0], &dateArr[1], &dateArr[2]);
    free(tmpDateStr);
}

// function for converting integer array to date string
char* convertIntArrayToDate(int dateArr[]) {
    char* dateStr = malloc(sizeof(char) * 11);
    sprintf(dateStr, "%04d/%02d/%02d", dateArr[0], dateArr[1], dateArr[2]);
    return dateStr;
}

// function for adding days to a date
void addDaysToDate(int dateArr[], int days) {
    while (days > 0) {
        int daysInMonth = getDaysInMonth(dateArr[1], dateArr[0]);
        int remainingDays = daysInMonth - dateArr[2] + 1;
        if (remainingDays <= days) {
            dateArr[1]++;
            if (dateArr[1] > 12) {
                dateArr[0]++;
                dateArr[1] = 1;
            }
            dateArr[2] = 1;
            days -= remainingDays;
        } else {
            dateArr[2] += days;
            days = 0;
        }
    }
}

int main() {
    char* dateStr = malloc(sizeof(char) * 11);
    printf("Please enter a date in the format dd/mm/yyyy: ");
    scanf("%s", dateStr);

    // converting date string to integer array
    int dateArr[3];
    convertDateToIntArray(dateStr, dateArr);

    // adding days to date
    int daysToAdd;
    printf("Please enter the number of days you would like to add to this date: ");
    scanf("%d", &daysToAdd);
    addDaysToDate(dateArr, daysToAdd);

    // converting integer array back to date string
    char* newDateStr = convertIntArrayToDate(dateArr);

    printf("The new date is: %s\n", newDateStr);

    // freeing memory
    free(dateStr);
    free(newDateStr);

    return 0;
}