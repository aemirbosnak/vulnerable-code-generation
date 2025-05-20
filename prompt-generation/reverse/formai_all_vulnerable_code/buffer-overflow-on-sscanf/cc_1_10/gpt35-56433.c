//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DATE_LENGTH 11 // "mm/dd/yyyy\0"

//helper function to check if a year is a leap year or not
bool isLeapYear(int year) {
    if(year % 4 != 0) {
        return false;
    } else if(year % 100 != 0) {
        return true;
    } else if(year % 400 != 0) {
        return false;
    } else {
        return true;
    }
}

//helper function to get the number of days in a given month
int daysInMonth(int month, int year) {
    if(month == 2) {
        return (isLeapYear(year) ? 29 : 28);
    } else if(month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

//main function to convert natural language date to standard date format
void convertDate(char* naturalDate) {
    char month[3], day[3], year[5];
    sscanf(naturalDate, "%s %s %s", month, day, year);

    //convert month to numerical value
    int numMonth;
    if(strcasecmp(month, "January") == 0) {
        numMonth = 1;
    } else if(strcasecmp(month, "February") == 0) {
        numMonth = 2;
    } else if(strcasecmp(month, "March") == 0) {
        numMonth = 3;
    } else if(strcasecmp(month, "April") == 0) {
        numMonth = 4;
    } else if(strcasecmp(month, "May") == 0) {
        numMonth = 5;
    } else if(strcasecmp(month, "June") == 0) {
        numMonth = 6;
    } else if(strcasecmp(month, "July") == 0) {
        numMonth = 7;
    } else if(strcasecmp(month, "August") == 0) {
        numMonth = 8;
    } else if(strcasecmp(month, "September") == 0) {
        numMonth = 9;
    } else if(strcasecmp(month, "October") == 0) {
        numMonth = 10;
    } else if(strcasecmp(month, "November") == 0) {
        numMonth = 11;
    } else if(strcasecmp(month, "December") == 0) {
        numMonth = 12;
    } else {
        printf("Invalid month entered!\n");
        exit(EXIT_FAILURE);
    }

    //validate day and year
    int numDay = atoi(day);
    int numYear = atoi(year);
    if(numDay < 1 || numDay > daysInMonth(numMonth, numYear)) {
        printf("Invalid day entered for this month/year combination!\n");
        exit(EXIT_FAILURE);
    } else if(numYear < 1900 || numYear > 2099) {
        printf("Invalid year entered! Please enter a year between 1900 and 2099.\n");
        exit(EXIT_FAILURE);
    }

    //format date in mm/dd/yyyy
    char stdDate[MAX_DATE_LENGTH];
    snprintf(stdDate, MAX_DATE_LENGTH, "%d/%d/%d", numMonth, numDay, numYear);

    //print converted date to stdout
    printf("Natural language date \"%s\" was successfully converted to standard date format \"%s\".\n", naturalDate, stdDate);
}

int main(void) {
    printf("==============================================================\n");
    printf("Welcome to the Natural Language Date Converter program!\n");
    printf("Enter a date in natural language (e.g. March 23, 2022) to convert it to standard date format.\n");
    printf("Type \"quit\" to exit the program.\n");
    printf("==============================================================\n");

    while(true) {
        char input[100];
        printf("Enter natural date: ");
        fgets(input, 100, stdin);

        //remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        if(strcasecmp(input, "quit") == 0) {
            printf("Exiting program...\n");
            break;
        } else {
            convertDate(input);
        }
    }

    return 0;
}