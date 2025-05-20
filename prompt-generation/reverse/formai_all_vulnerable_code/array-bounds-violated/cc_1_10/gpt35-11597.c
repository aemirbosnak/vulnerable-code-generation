//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given year is a leap year
int isLeapYear(int year) {
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
        return 1;
    else
        return 0;
}

// Function to convert month from string to integer
int monthToNumber(char month[]) {
    if (strcmp(month, "January") == 0)
        return 1;
    else if (strcmp(month, "February") == 0)
        return 2;
    else if (strcmp(month, "March") == 0)
        return 3;
    else if (strcmp(month, "April") == 0)
        return 4;
    else if (strcmp(month, "May") == 0)
        return 5;
    else if (strcmp(month, "June") == 0)
        return 6;
    else if (strcmp(month, "July") == 0)
        return 7;
    else if (strcmp(month, "August") == 0)
        return 8;
    else if (strcmp(month, "September") == 0)
        return 9;
    else if (strcmp(month, "October") == 0)
        return 10;
    else if (strcmp(month, "November") == 0)
        return 11;
    else if (strcmp(month, "December") == 0)
        return 12;
    else
        return -1;
}

// Function to convert month from integer to string
char* numberToMonth(int month) {
    if (month == 1)
        return "January";
    else if (month == 2)
        return "February";
    else if (month == 3)
        return "March";
    else if (month == 4)
        return "April";
    else if (month == 5)
        return "May";
    else if (month == 6)
        return "June";
    else if (month == 7)
        return "July";
    else if (month == 8)
        return "August";
    else if (month == 9)
        return "September";
    else if (month == 10)
        return "October";
    else if (month == 11)
        return "November";
    else if (month == 12)
        return "December";
    else
        return "Invalid Month";
}

// Function to convert date from natural language to integer format
void convertDate(char dateString[]) {
    char *token;
    char delimiters[] = ", ";
    int year, month, day;

    token = strtok(dateString, delimiters);  // Extract day
    day = atoi(token);

    token = strtok(NULL, delimiters);  // Extract month
    month = monthToNumber(token);

    token = strtok(NULL, delimiters);  // Extract year
    year = atoi(token);

    // Output the date in integer format
    printf("%d-%02d-%02d\n", year, month, day);
}

// Function to add days to a given date
void addDays(char dateString[], int daysToAdd) {
    char *token;
    char delimiters[] = ", ";
    int year, month, day, daysInMonth;

    token = strtok(dateString, delimiters);  // Extract day
    day = atoi(token);

    token = strtok(NULL, delimiters);  // Extract month
    month = monthToNumber(token);

    token = strtok(NULL, delimiters);  // Extract year
    year = atoi(token);

    // Calculate the number of days in the given month and year
    if (month == 2) {
        if (isLeapYear(year))
            daysInMonth = 29;
        else
            daysInMonth = 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        daysInMonth = 30;
    else
        daysInMonth = 31;

    // Calculate the new day, month and year after adding the given number of days
    while (daysToAdd > 0) {
        day++;
        if (day > daysInMonth) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
            if (month == 2) {
                if (isLeapYear(year))
                    daysInMonth = 29;
                else
                    daysInMonth = 28;
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11)
                daysInMonth = 30;
            else
                daysInMonth = 31;
        }
        daysToAdd--;
    }

    // Output the new date in natural language format
    printf("%d %s %d\n", day, numberToMonth(month), year);
}

// Main function of the program
int main() {
    char dateString[100];
    int option, daysToAdd;

    printf("Enter a date in natural language format (e.g. 12 September, 2022):\n");
    fgets(dateString, 100, stdin);
    dateString[strlen(dateString)-1] = '\0';  // Remove newline character

    printf("Choose an option:\n");
    printf("1. Convert to integer format\n");
    printf("2. Add days\n");
    scanf("%d", &option);

    switch(option) {
        case 1:
            convertDate(dateString);
            break;
        case 2:
            printf("Enter the number of days to add:\n");
            scanf("%d", &daysToAdd);
            addDays(dateString, daysToAdd);
            break;
        default:
            printf("Invalid option\n");
    }

    return 0;
}