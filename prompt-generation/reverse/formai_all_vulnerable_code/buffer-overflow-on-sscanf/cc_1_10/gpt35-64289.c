//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multivariable
#include <stdio.h>
#include <string.h>

/* Function that returns the number of days in a given month and year */
int daysInMonth(int month, int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        // Leap year, February has 29 days
        if (month == 2) return 29;
    }
    switch (month) {
        case 2:
            return 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

/* Function that converts a string month name to its corresponding month number */
int monthNameToNum(char *month) {
    if (strcasecmp(month, "January") == 0) return 1;
    if (strcasecmp(month, "February") == 0) return 2;
    if (strcasecmp(month, "March") == 0) return 3;
    if (strcasecmp(month, "April") == 0) return 4;
    if (strcasecmp(month, "May") == 0) return 5;
    if (strcasecmp(month, "June") == 0) return 6;
    if (strcasecmp(month, "July") == 0) return 7;
    if (strcasecmp(month, "August") == 0) return 8;
    if (strcasecmp(month, "September") == 0) return 9;
    if (strcasecmp(month, "October") == 0) return 10;
    if (strcasecmp(month, "November") == 0) return 11;
    if (strcasecmp(month, "December") == 0) return 12;
    // Return invalid month number if input is not a valid month name
    return -1;
}

/* Function that converts a date string of the form "Mmm dd, yyyy" to a date of the form "yyyy-mm-dd" */
char *convertDate(char *dateStr) {
    // Separate month, day and year from input string
    char month[10], day[3], year[5];
    sscanf(dateStr, "%s %s, %s", month, day, year);
    // Convert month name to month number
    int monthNum = monthNameToNum(month);
    // Check if month number is valid
    if (monthNum == -1) {
        return "Invalid month.";
    }
    // Convert day and year to integers
    int dayNum = atoi(day);
    int yearNum = atoi(year);
    // Check if day number is valid
    if (dayNum < 1 || dayNum > daysInMonth(monthNum, yearNum)) {
        return "Invalid day.";
    }
    // Convert date to yyyy-mm-dd format
    char *date = malloc(11); // Allocate memory for date
    sprintf(date, "%d-%02d-%02d", yearNum, monthNum, dayNum); // Format date string
    return date; // Return formatted date string
}

/* Main function */
int main() {
    char dateStr[20];
    printf("Enter a date (format: Mmm dd, yyyy): ");
    fgets(dateStr, 20, stdin); // Read date string from user input
    dateStr[strcspn(dateStr, "\n")] = '\0'; // Remove newline character from end of string
    char *date = convertDate(dateStr); // Convert date
    printf("%s\n", date); // Print formatted date
    free(date); // Free memory allocated for date string
    return 0;
}