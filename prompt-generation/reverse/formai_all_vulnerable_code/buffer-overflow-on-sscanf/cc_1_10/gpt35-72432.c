//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to check if a given year is a leap year
int isLeapYear(int year) {
    if(year%400 == 0 || (year%4 == 0 && year%100 != 0)) {
        return 1;
    }
    else {
        return 0;
    }
}

// function to get the number of days in a month for a given year
int getDaysInMonth(int month, int year) {
    if(month == 2) {
        if(isLeapYear(year)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

// function to convert a date string to integers for day, month, and year
void convertDateToInt(char* date, int* day, int* month, int* year) {
    sscanf(date, "%d/%d/%d", day, month, year);
}

// function to convert a date represented as integers for day, month, and year to a string
char* convertDateToString(int day, int month, int year) {
    char monthStr[10];
    switch(month) {
        case 1:
            strcpy(monthStr, "January");
            break;
        case 2:
            strcpy(monthStr, "February");
            break;
        case 3:
            strcpy(monthStr, "March");
            break;
        case 4:
            strcpy(monthStr, "April");
            break;
        case 5:
            strcpy(monthStr, "May");
            break;
        case 6:
            strcpy(monthStr, "June");
            break;
        case 7:
            strcpy(monthStr, "July");
            break;
        case 8:
            strcpy(monthStr, "August");
            break;
        case 9:
            strcpy(monthStr, "September");
            break;
        case 10:
            strcpy(monthStr, "October");
            break;
        case 11:
            strcpy(monthStr, "November");
            break;
        case 12:
            strcpy(monthStr, "December");
            break;
        default:
            strcpy(monthStr, "");
            break;
    }
    char* date = malloc(sizeof(char)*20);
    sprintf(date, "%d %s %d", day, monthStr, year);
    return date;
}

// function to add days to a given date
char* addDays(char* date, int daysToAdd) {
    int day, month, year;
    convertDateToInt(date, &day, &month, &year);
    int daysInMonth = getDaysInMonth(month, year);
    while(daysToAdd > 0) {
        if(day+daysToAdd > daysInMonth) {
            daysToAdd -= (daysInMonth - day + 1);
            month++;
            if(month > 12) {
                month = 1;
                year++;
            }
            daysInMonth = getDaysInMonth(month, year);
            day = 1;
        }
        else {
            day += daysToAdd;
            daysToAdd = 0;
        }
    }
    char* newDate = convertDateToString(day, month, year);
    return newDate;
}

// main function
int main() {
    char date[20];
    printf("Enter a date (dd/mm/yyyy): ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = '\0'; // remove newline character from string
    
    int daysToAdd;
    printf("Enter number of days to add: ");
    scanf("%d", &daysToAdd);

    char* newDate = addDays(date, daysToAdd);
    printf("New date: %s", newDate);
    
    return 0;
}