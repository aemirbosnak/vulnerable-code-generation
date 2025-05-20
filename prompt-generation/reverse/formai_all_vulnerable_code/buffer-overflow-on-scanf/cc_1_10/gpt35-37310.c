//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: light-weight
#include <stdio.h>

// function to check if given year is a leap year or not
int isLeapYear(int year) {
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
        return 1;
    }
    return 0;
}

// function to get total number of days in a given month
int getDaysInMonth(int month, int year) {
    int days[] = { 31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return days[month - 1];
}

// function to get the day of the week for a given date
int getDayOfWeek(int day, int month, int year) {
    int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    if (month < 3) {
        year -= 1;
    }
    return (year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
}

// function to print the date in natural language format
void printDate(int day, int month, int year) {
    // array of month names
    char *months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    // array of day suffixes
    char *suffix[] = { "st", "nd", "rd", "th", "th", "th", "th", "th", "th", "th", "th", "th", "th", "th", "th", "th", "th", "th", "th", "th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th", "th", "st" };

    // get the day of the week for the given date
    int dow = getDayOfWeek(day, month, year);

    // print the date in natural language format
    printf("%s %d%s, %d is a %s\n", months[month - 1], day, suffix[day - 1], year, (dow == 0) ? "Sunday" : (dow == 1) ? "Monday" : (dow == 2) ? "Tuesday" : (dow == 3) ? "Wednesday" : (dow == 4) ? "Thursday" : (dow == 5) ? "Friday" : "Saturday");
}

int main() {
    int day, month, year;
    printf("Enter the date in YYYY-MM-DD format: ");
    scanf("%d-%d-%d", &year, &month, &day);

    // check if the entered date is valid
    if (month < 1 || month > 12 || day < 1 || day > getDaysInMonth(month, year)) {
        printf("Invalid date.\n");
        return -1;
    }

    // print the date in natural language format
    printDate(day, month, year);

    return 0;
}