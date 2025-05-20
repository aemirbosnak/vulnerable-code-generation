//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the months of the year
char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// Define the days of the week
char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Define the number of days in each month
int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Define the leap year rule
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

// Convert a date from the format "dd/mm/yyyy" to the format "yyyy-mm-dd"
char *convertDate(char *date) {
    char *newDate = malloc(11);
    char *day = strtok(date, "/");
    char *month = strtok(NULL, "/");
    char *year = strtok(NULL, "/");
    sprintf(newDate, "%s-%s-%s", year, month, day);
    return newDate;
}

// Print the date in the format "dd/mm/yyyy"
void printDate(int day, int month, int year) {
    printf("%02d/%02d/%04d\n", day, month, year);
}

// Get the day of the week for a given date
char *getDayOfWeek(int day, int month, int year) {
    int julianDay = day + (153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5 + 365 * year + year / 4 - year / 100 + year / 400 - 2440588;
    return days[julianDay % 7];
}

// Main function
int main() {
    // Get the date from the user
    char date[11];
    printf("Enter a date in the format \"dd/mm/yyyy\": ");
    scanf("%s", date);

    // Convert the date to the format "yyyy-mm-dd"
    char *newDate = convertDate(date);

    // Get the year, month, and day from the new date
    char *year = strtok(newDate, "-");
    char *month = strtok(NULL, "-");
    char *day = strtok(NULL, "-");

    // Print the date in the format "dd/mm/yyyy"
    printDate(atoi(day), atoi(month), atoi(year));

    // Print the day of the week for the date
    printf("The day of the week is: %s\n", getDayOfWeek(atoi(day), atoi(month), atoi(year)));

    return 0;
}