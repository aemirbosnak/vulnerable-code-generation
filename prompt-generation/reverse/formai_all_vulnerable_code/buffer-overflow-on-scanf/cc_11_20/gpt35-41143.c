//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: detailed
#include <stdio.h>

// function for determining leap year
int isLeapYear(int year) {
    if(year % 4 != 0)
        return 0;
    else if(year % 100 != 0)
        return 1;
    else if(year % 400 != 0)
        return 0;
    else
        return 1;
}

// function for converting month number to month name
char* getMonthName(int month) {
    switch(month) {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "";
    }
}

// main function
int main() {
    int day, month, year;
    printf("Enter date in natural language format [DD Month YYYY]: ");
    scanf("%d %s %d", &day, getMonthName(month), &year);
    
    // converting month name to month number
    if(strcmp(getMonthName(month), "January") == 0)
        month = 1;
    else if(strcmp(getMonthName(month), "February") == 0)
        month = 2;
    else if(strcmp(getMonthName(month), "March") == 0)
        month = 3;
    else if(strcmp(getMonthName(month), "April") == 0)
        month = 4;
    else if(strcmp(getMonthName(month), "May") == 0)
        month = 5;
    else if(strcmp(getMonthName(month), "June") == 0)
        month = 6;
    else if(strcmp(getMonthName(month), "July") == 0)
        month = 7;
    else if(strcmp(getMonthName(month), "August") == 0)
        month = 8;
    else if(strcmp(getMonthName(month), "September") == 0)
        month = 9;
    else if(strcmp(getMonthName(month), "October") == 0)
        month = 10;
    else if(strcmp(getMonthName(month), "November") == 0)
        month = 11;
    else if(strcmp(getMonthName(month), "December") == 0)
        month = 12;

    // check for invalid date cases
    if(month < 1 || month > 12 || day < 1 || day > 31 || (month == 2 && day > 29) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
        printf("Invalid date entered!\n");
        return 0;
    }

    // check for valid date and determine the day number of the year
    int dayOfYear = 0;
    for(int i=1; i<month; i++) {
        if(i == 2)
            dayOfYear += isLeapYear(year) ? 29 : 28;
        else if(i == 4 || i == 6 || i == 9 || i == 11)
            dayOfYear += 30;
        else
            dayOfYear += 31;
    }
    dayOfYear += day;

    // print the day number of the year
    printf("Day number of the year: %d\n", dayOfYear);

    return 0;
}