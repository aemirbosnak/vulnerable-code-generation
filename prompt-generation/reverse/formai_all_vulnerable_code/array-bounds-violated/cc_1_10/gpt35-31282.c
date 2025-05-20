//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: automated
#include <stdio.h>
#include <string.h>

// Function to convert month to number
int monthToNumber(char *month) {
    char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    for (int i = 0; i < 12; i++) {
        if (strcmp(month, months[i]) == 0) {
            return i + 1;
        }
    }

    return -1;
}

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

// Function to get the number of days in a month
int getMonthDays(int month, int year) {
    switch (month) {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            if (isLeapYear(year)) {
                return 29;
            } else {
                return 28;
            }
        default:
            return 31;
    }
}

// Function to convert natural language date to number
void naturalLanguageDateToNumber(char *date, int *day, int *month, int *year) {
    char delim[] = " ";
    char *ptr = strtok(date, delim);
    int count = 0;

    while (ptr != NULL) {
        switch (count) {
            case 0:
                *day = atoi(ptr);
                break;
            case 1:
                *month = monthToNumber(ptr);
                break;
            case 2:
                *year = atoi(ptr);
                break;
        }
        count++;
        ptr = strtok(NULL, delim);
    }
}

// Function to convert number date to natural language date
void numberDateToNaturalLanguage(int day, int month, int year) {
    char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("%s %d, %d\n", months[month-1], day, year);
}

int main() {
    char naturalDate[100];
    int day, month, year;

    // Prompt user for natural language date
    printf("Enter a natural language date (e.g. \"August 27, 2021\"): ");
    fgets(naturalDate, 100, stdin);

    // Convert natural language date to number date
    naturalLanguageDateToNumber(naturalDate, &day, &month, &year);

    // Get the number of days in the month
    int monthDays = getMonthDays(month, year);

    // Check if the day input is valid
    if (day <= 0 || day > monthDays) {
        printf("Invalid day.\n");
        return 0;
    }

    // Convert number date to natural language date
    numberDateToNaturalLanguage(day, month, year);

    return 0;
}