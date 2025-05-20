//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEAP_YEAR(y) (((y)%4==0 && (y)%100!=0) || (y)%400==0)

// Function to determine if a year is a leap year
int isLeapYear(int year) {
    return LEAP_YEAR(year);
}

// Function to convert month name to month number
int getMonth(char* month) {
    char months[12][10] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    int i;
    for(i = 0; i < 12; i++) {
        if(strcmp(month, months[i]) == 0) {
            return i+1;
        }
    }
    return -1;
}

// Function to convert date in natural language to number format
void convertDate(char* date) {
    char* token;
    char* delim = " ";
    char* month;
    int day, year, monthNum;

    // Get day
    token = strtok(date, delim);
    day = atoi(token);

    // Get month
    token = strtok(NULL, delim);
    month = token;
    monthNum = getMonth(month);

    // Get year
    token = strtok(NULL, delim);
    year = atoi(token);

    // Calculate number of days
    int days = 0;
    int i;
    for(i = 1; i < monthNum; i++) {
        if(i == 2) {
            if(isLeapYear(year)) {
                days += 29;
            } else {
                days += 28;
            }
        } else if(i == 4 || i == 6 || i == 9 || i == 11) {
            days += 30;
        } else {
            days += 31;
        }
    }
    days += day;

    printf("Date in number format is: %d/%d/%d\n", monthNum, day, year);
    printf("Number of days since January 1st is: %d", days);
}

int main() {
    char date[30];
    printf("Enter a date in natural language (e.g. August 28th 2022): ");
    fgets(date, 30, stdin);

    // Remove new line character from input
    if(date[strlen(date)-1] == '\n') {
        date[strlen(date)-1] = '\0';
    }

    convertDate(date);

    return 0;
}