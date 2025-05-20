//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: mathematical
#include <stdio.h>

int main() {
    int date, month, year, numDays;
    printf("Enter a natural language date [e.g. first of January 2022]:\n");
    scanf("%*[^a-zA-Z]%*[a-zA-Z] %d%*c %d", &date, &year);
    getchar(); // to absorb the comma
    char monthStr[10];
    scanf("%s %d", monthStr, &year);
    
    // convert month string to a number
    if (strcmp(monthStr, "January") == 0) {
        month = 1;
    } else if (strcmp(monthStr, "February") == 0) {
        month = 2;
    } else if (strcmp(monthStr, "March") == 0) {
        month = 3;
    } else if (strcmp(monthStr, "April") == 0) {
        month = 4;
    } else if (strcmp(monthStr, "May") == 0) {
        month = 5;
    } else if (strcmp(monthStr, "June") == 0) {
        month = 6;
    } else if (strcmp(monthStr, "July") == 0) {
        month = 7;
    } else if (strcmp(monthStr, "August") == 0) {
        month = 8;
    } else if (strcmp(monthStr, "September") == 0) {
        month = 9;
    } else if (strcmp(monthStr, "October") == 0) {
        month = 10;
    } else if (strcmp(monthStr, "November") == 0) {
        month = 11;
    } else if (strcmp(monthStr, "December") == 0) {
        month = 12;
    } else {
        printf("Invalid month input.\n");
        return 1;
    }
    
    // check if it's a leap year
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        // leap year
        if (month == 2) {
            numDays = 29;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            numDays = 30;
        } else {
            numDays = 31;
        }
    } else {
        // not a leap year
        if (month == 2) {
            numDays = 28;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            numDays = 30;
        } else {
            numDays = 31;
        }
    }
    
    // output the date in a mathematical style
    if (date == 1 || date == 21 || date == 31) {
        printf("%dst", date);
    } else if (date == 2 || date == 22) {
        printf("%dnd", date);
    } else if (date == 3 || date == 23) {
        printf("%drd", date);
    } else {
        printf("%dth", date);
    }
    
    printf(" day of the %d", year);
    
    switch (month) {
        case 1:
            printf("st month.\n");
            break;
        case 2:
            printf("nd month.\n");
            break;
        case 3:
            printf("rd month.\n");
            break;
        default:
            printf("th month.\n");
    }
    
    printf("There are %d days in the %s %d.\n", numDays, monthStr, year);
    
    return 0;
}