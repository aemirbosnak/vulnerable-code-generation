//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: single-threaded
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// function to check if the given year is leap or not
int isLeapYear(int year) {
    if (year % 400 == 0)
        return 1;
    if (year % 100 == 0)
        return 0;
    if (year % 4 == 0)
        return 1;
    return 0;
}

// struct to hold date information
struct Date {
    int day;
    int month;
    int year;
};

const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// function to convert a string month name to its corresponding number
int monthStringToNumber(char* monthName) {
    char *p = monthName;
    int i = 0;
    // convert month name to uppercase
    while (*p) {
        *p = toupper((unsigned char) *p);
        p++;
    }
    for (i = 0; i < 12; i++) {
        if (strcmp(monthName, months[i]) == 0)
            return i+1;
    }
    return -1;
}

// function to convert date in natural language to a Date struct
struct Date naturalLanguageDateToStruct(char* naturalLanguageDate) {
    int day, month, year;
    char monthName[20];
    struct Date date;

    // check for format "Month Day, Year"
    if (sscanf(naturalLanguageDate, "%s %d, %d", monthName, &day, &year) == 3) {
        month = monthStringToNumber(monthName);
    } 
    // check for format "Day Month Year"
    else if (sscanf(naturalLanguageDate, "%d %s %d", &day, monthName, &year) == 3) {
        month = monthStringToNumber(monthName);
    }
    // check for format "Month Year"
    else if (sscanf(naturalLanguageDate, "%s %d", monthName, &year) == 2) {
        month = monthStringToNumber(monthName);
        day = 1;
    }
    // check for format "Year Month"
    else if (sscanf(naturalLanguageDate, "%d %s", &year, monthName) == 2) {
        month = monthStringToNumber(monthName);
        day = 1;
    }
    // if none of the above formats match, return an invalid date
    else {
        date.day = 0;
        date.month = 0;
        date.year = 0;
        return date;
    }

    // check if day is within range for the given month and year
    if (day < 1 || day > 31 || (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) || (month == 2 && (day > 29 || (day == 29 && !isLeapYear(year)))) || month < 1 || month > 12)
    {
        date.day = 0;
        date.month = 0;
        date.year = 0;
        return date;
    }

    date.day = day;
    date.month = month;
    date.year = year;
    return date;
}

int main() {
    char naturalLanguageDate[50];
    struct Date date;

    printf("Enter date in natural language: ");
    scanf("%[^\n]", naturalLanguageDate);

    // clear input buffer
    while (getchar() != '\n');

    date = naturalLanguageDateToStruct(naturalLanguageDate);

    // check if date is valid
    if (date.day == 0) {
        printf("Invalid date!\n");
    }
    else {
        printf("Date in structure format: %d-%02d-%02d\n", date.year, date.month, date.day);
    }

    return 0;
}