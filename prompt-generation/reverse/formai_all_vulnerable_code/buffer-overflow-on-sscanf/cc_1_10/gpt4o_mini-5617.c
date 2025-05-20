//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 256

// Function to check leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the number of days in a month
int daysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0; // Invalid month
    }
}

// Function to convert date from string to struct tm
int parseDate(char *dateString, struct tm *date) {
    int year, month, day;
    char monthName[20];
    
    if (sscanf(dateString, "%d %s %d", &day, monthName, &year) != 3) {
        return 0; // Parsing failed
    }

    if (strcasecmp(monthName, "January") == 0) month = 1;
    else if (strcasecmp(monthName, "February") == 0) month = 2;
    else if (strcasecmp(monthName, "March") == 0) month = 3;
    else if (strcasecmp(monthName, "April") == 0) month = 4;
    else if (strcasecmp(monthName, "May") == 0) month = 5;
    else if (strcasecmp(monthName, "June") == 0) month = 6;
    else if (strcasecmp(monthName, "July") == 0) month = 7;
    else if (strcasecmp(monthName, "August") == 0) month = 8;
    else if (strcasecmp(monthName, "September") == 0) month = 9;
    else if (strcasecmp(monthName, "October") == 0) month = 10;
    else if (strcasecmp(monthName, "November") == 0) month = 11;
    else if (strcasecmp(monthName, "December") == 0) month = 12;
    else return 0; // Invalid month name

    if (day < 1 || day > daysInMonth(month, year)) {
        return 0; // Invalid day
    }

    date->tm_year = year - 1900; // years since 1900
    date->tm_mon = month - 1;    // months since January
    date->tm_mday = day;
    date->tm_hour = 0;
    date->tm_min = 0;
    date->tm_sec = 0;
    date->tm_isdst = -1; // let the system determine if DST is in effect

    return 1; // Success
}

// Function to format struct tm to a standard date string
void formatDate(struct tm *date, char *outputString) {
    strftime(outputString, BUFFER_SIZE, "%Y-%m-%d", date); // Format: YYYY-MM-DD
}

int main() {
    char inputString[BUFFER_SIZE];
    struct tm date;
    
    printf("Enter a date in the format 'DD Month YYYY' (e.g., '21 January 2023'):\n");
    fgets(inputString, BUFFER_SIZE, stdin);
    inputString[strcspn(inputString, "\n")] = 0; // Remove newline char

    if (!parseDate(inputString, &date)) {
        printf("Invalid date format or values, please use 'DD Month YYYY'.\n");
        return EXIT_FAILURE;
    }

    char formattedDate[BUFFER_SIZE];
    formatDate(&date, formattedDate);
    
    printf("The formatted date is: %s\n", formattedDate);
    
    return EXIT_SUCCESS;
}