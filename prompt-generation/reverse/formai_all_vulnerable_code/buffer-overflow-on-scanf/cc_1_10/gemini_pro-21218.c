//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the days of the week
char *days[] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

// Define the months of the year
char *months[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

// Convert a string to an integer
int strToInt(char *str) {
    int num = 0;
    while (*str != '\0') {
        num = num * 10 + (*str - '0');
        str++;
    }
    return num;
}

// Convert a date to a string
char *dateToString(int day, int month, int year) {
    char *date = (char *)malloc(11);
    sprintf(date, "%02d/%02d/%04d", day, month, year);
    return date;
}

// Convert a string to a date
int *stringToDate(char *str) {
    int *date = (int *)malloc(3);
    date[0] = strToInt(strtok(str, "/"));
    date[1] = strToInt(strtok(NULL, "/"));
    date[2] = strToInt(strtok(NULL, "/"));
    return date;
}

// Print the day of the week for a given date
void printDayOfWeek(int day, int month, int year) {
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    int d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    printf("The day of the week for %s is %s.\n", dateToString(day, month, year), days[d]);
}

// Print the next date
void printNextDate(int day, int month, int year) {
    int nextDay = day + 1;
    int nextMonth = month;
    int nextYear = year;
    if (nextDay > 31) {
        nextDay = 1;
        nextMonth++;
    }
    if (nextMonth > 12) {
        nextMonth = 1;
        nextYear++;
    }
    printf("The next date after %s is %s.\n", dateToString(day, month, year), dateToString(nextDay, nextMonth, nextYear));
}

// Print the previous date
void printPreviousDate(int day, int month, int year) {
    int previousDay = day - 1;
    int previousMonth = month;
    int previousYear = year;
    if (previousDay < 1) {
        previousDay = 31;
        previousMonth--;
    }
    if (previousMonth < 1) {
        previousMonth = 12;
        previousYear--;
    }
    printf("The previous date before %s is %s.\n", dateToString(day, month, year), dateToString(previousDay, previousMonth, previousYear));
}

// Main function
int main() {
    // Get the date from the user
    char *date = (char *)malloc(11);
    printf("Enter a date in the format dd/mm/yyyy: ");
    scanf("%s", date);

    // Convert the date to an integer
    int *dateArr = stringToDate(date);
    int day = dateArr[0];
    int month = dateArr[1];
    int year = dateArr[2];

    // Print the day of the week for the given date
    printDayOfWeek(day, month, year);

    // Print the next date
    printNextDate(day, month, year);

    // Print the previous date
    printPreviousDate(day, month, year);

    return 0;
}