//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: synchronous
#include <stdio.h>
#include <string.h>

// Function to check if a year is a leap year
int isLeapYear(int year) {
    // A year is a leap year if it is divisible by 4 but not by 100
    // If it is divisible by 100, it must also be divisible by 400 to be a leap year
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    }
}

// Function to convert a string month to its integer equivalent
int monthStringToInt(char* month) {
    if (strcmp(month, "January") == 0) {
        return 1;
    }
    else if (strcmp(month, "February") == 0) {
        return 2;
    }
    else if (strcmp(month, "March") == 0) {
        return 3;
    }
    else if (strcmp(month, "April") == 0) {
        return 4;
    }
    else if (strcmp(month, "May") == 0) {
        return 5;
    }
    else if (strcmp(month, "June") == 0) {
        return 6;
    }
    else if (strcmp(month, "July") == 0) {
        return 7;
    }
    else if (strcmp(month, "August") == 0) {
        return 8;
    }
    else if (strcmp(month, "September") == 0) {
        return 9;
    }
    else if (strcmp(month, "October") == 0) {
        return 10;
    }
    else if (strcmp(month, "November") == 0) {
        return 11;
    }
    else if (strcmp(month, "December") == 0) {
        return 12;
    }
    else {
        return -1;
    }
}

// Function to convert an integer month to its string equivalent
char* intToMonthString(int month) {
    if (month == 1) {
        return "January";
    }
    else if (month == 2) {
        return "February";
    }
    else if (month == 3) {
        return "March";
    }
    else if (month == 4) {
        return "April";
    }
    else if (month == 5) {
        return "May";
    }
    else if (month == 6) {
        return "June";
    }
    else if (month == 7) {
        return "July";
    }
    else if (month == 8) {
        return "August";
    }
    else if (month == 9) {
        return "September";
    }
    else if (month == 10) {
        return "October";
    }
    else if (month == 11) {
        return "November";
    }
    else if (month == 12) {
        return "December";
    }
    else {
        return "INVALID MONTH";
    }
}

// Function to convert a string date in the format "Month Day, Year" to an integer date in the format "YYYYMMDD"
long stringDateToIntDate(char* stringDate) {
    char month[10];
    int day;
    int year;
    sscanf(stringDate, "%s %d, %d", month, &day, &year);
    int monthInt = monthStringToInt(month);
    long intDate = year * 10000 + monthInt * 100 + day;
    return intDate;
}

// Function to convert an integer date in the format "YYYYMMDD" to a string date in the format "Month Day, Year"
void intDateToStringDate(long intDate, char* stringDate) {
    int year = intDate / 10000;
    int month = (intDate % 10000) / 100;
    int day = intDate % 100;
    char* monthString = intToMonthString(month);
    sprintf(stringDate, "%s %d, %d", monthString, day, year);
}

// Function to add or subtract a number of days from a date
long addDaysToDate(long intDate, int numDays) {
    int year = intDate / 10000;
    int month = (intDate % 10000) / 100;
    int day = intDate % 100;
    int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }
    while (numDays > 0) {
        if (numDays >= daysInMonth[month-1] - day + 1) {
            // Subtract the number of remaining days in the current month and move to the next month
            numDays -= daysInMonth[month-1] - day + 1;
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
                if (isLeapYear(year)) {
                    daysInMonth[1] = 29;
                }
                else {
                    daysInMonth[1] = 28;
                }
            }
        }
        else {
            // Add the remaining number of days to the current day
            day += numDays;
            numDays = 0;
        }
    }
    long newIntDate = year * 10000 + month * 100 + day;
    return newIntDate;
}

int main() {
    char inputDate[20];
    int numDays;
    printf("Enter a date in the format 'Month Day, Year': ");
    fgets(inputDate, 20, stdin);
    inputDate[strlen(inputDate)-1] = '\0'; // Remove the trailing newline character
    long intDate = stringDateToIntDate(inputDate);
    printf("Enter the number of days to add or subtract: ");
    scanf("%d", &numDays);
    long newIntDate = addDaysToDate(intDate, numDays);
    char stringDate[20];
    intDateToStringDate(newIntDate, stringDate);
    printf("%d days after %s is %s\n", numDays, inputDate, stringDate);
    return 0;
}