//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convertDayMonth(char *month);
int isLeapYear(int year);

int main() {

    printf("Enter date in natural language (eg. August 23, 2022): ");
    char input[50];
    fgets(input, 50, stdin);
  
    // Extract month, day, and year from input string
    char *month = strtok(input, " ");
    char *day = strtok(NULL, ",");
    char *year = strtok(NULL, " ");
    
    // Remove spaces from day string
    for (int i = 0; day[i]; i++) {
        if (day[i] != ' ') {
            day[i] = day[i];
        } else {
            for (int j = i; day[j]; j++) {
                day[j] = day[j + 1];
            }
            i--;
        }
    }
    
    // Convert month and day to integers
    int m = convertDayMonth(month);
    int d = atoi(day);
    int y = atoi(year);
    
    // Determine if year is a leap year
    int leap = isLeapYear(y);
    
    // Determine number of days in given month
    int daysInMonth;
    if (m == 2) {
        if (leap) {
            daysInMonth = 29;
        } else {
            daysInMonth = 28;
        }
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }
    
    // Validate the input date
    if (y < 1 || m < 1 || m > 12 || d < 1 || d > daysInMonth) {
        printf("Invalid date\n");
        exit(0);
    }
    
    // Count the number of days since January 1st
    int daysPassed = 0;
    for (int i = 1; i < m; i++) {
        if (i == 2) {
            if (leap) {
                daysPassed += 29;
            } else {
                daysPassed += 28;
            }
        } else if (i == 4 || i == 6 || i == 9 || i == 11) {
            daysPassed += 30;
        } else {
            daysPassed += 31;
        }
    }
    daysPassed += d - 1;
    
    // Compute the day of the week
    char *dayOfWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int dayOfWeekIndex = daysPassed % 7;
    
    // Print the final result
    printf("%s was a %s\n", input, dayOfWeek[dayOfWeekIndex]);
    
    return 0;
}

// Helper function to convert month string to integer
int convertDayMonth(char *month) {
    if (!strcmp(month, "January")) {
        return 1;
    } else if (!strcmp(month, "February")) {
        return 2;
    } else if (!strcmp(month, "March")) {
        return 3;
    } else if (!strcmp(month, "April")) {
        return 4;
    } else if (!strcmp(month, "May")) {
        return 5;
    } else if (!strcmp(month, "June")) {
        return 6;
    } else if (!strcmp(month, "July")) {
        return 7;
    } else if (!strcmp(month, "August")) {
        return 8;
    } else if (!strcmp(month, "September")) {
        return 9;
    } else if (!strcmp(month, "October")) {
        return 10;
    } else if (!strcmp(month, "November")) {
        return 11;
    } else if (!strcmp(month, "December")) {
        return 12;
    } else {
        printf("Invalid month\n");
        exit(0);
    }
}

// Helper function to determine if a year is a leap year
int isLeapYear(int year) {
    if (year % 4 != 0) {
        return 0;
    } else if (year % 100 != 0) {
        return 1;
    } else if (year % 400 != 0) {
        return 0;
    } else {
        return 1;
    }
}