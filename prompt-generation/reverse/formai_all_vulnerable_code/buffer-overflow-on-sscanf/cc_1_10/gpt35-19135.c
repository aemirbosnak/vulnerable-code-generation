//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: rigorous
#include <stdio.h>

// Function to check if given year is a leap year or not
int isLeapYear(int year) {
    // If year is multiple of 400 then it is a leap year
    if (year % 400 == 0) return 1;
    // If year is multiple of 100 then it is not a leap year
    if (year % 100 == 0) return 0;
    // If year is multiple of 4 then it is a leap year
    if (year % 4 == 0) return 1;
    // Otherwise it is not a leap year
    return 0;
}

// Function to convert given month and year to number of days
int getMonthDays(int month, int year) {
    // If month is February, check if it is a leap year and return accordingly
    if (month == 2) {
        return (isLeapYear(year)) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        // If month is April, June, September or November, return 30 days
        return 30;
    } else {
        // For all other months return 31 days
        return 31;
    }
}

// Function to convert given date, month and year to number of days
int getDateNumber(int date, int month, int year) {
    int days = 0;
    for (int i = 1900; i < year; i++) {
        days += isLeapYear(i) ? 366 : 365;
    }
    for (int i = 1; i < month; i++) {
        days += getMonthDays(i, year);
    }
    days += date - 1;
    return days;
}

// Function to convert given date in natural language format to ISO date format (yyyy-mm-dd)
void convertDate(char *date) {
    int day, year, month = 0;
    char month_string[12];
    sscanf(date, "%s %d, %d", month_string, &day, &year);
    // Match given month name with months array and get corresponding month index
    const char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i < 12; i++) {
        if (!strcmp(month_string, months[i])) {
            month = i + 1;
            break;
        }
    }
    // Calculate number of days since January 1, 1900
    int days = getDateNumber(day, month, year);
    // Calculate number of days since January 1, 0000 (which is a Monday)
    int total_days = days + 1;
    // Calculate day of week index (0-6)
    int day_of_week = total_days % 7;
    printf("Iso Date: %04d-%02d-%02d\n", year, month, day);
    printf("Day of week: ");
    switch (day_of_week) {
        case 0:
            printf("Sunday\n");
            break;
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
}

// Main function to read input and call date conversion function
int main() {
    char date[20];
    printf("Enter date in natural language format (e.g. January 1, 2000): ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = 0;  // Remove newline character from input
    convertDate(date);
    return 0;
}