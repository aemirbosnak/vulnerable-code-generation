//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: asynchronous
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// function to determine if a given year is a leap year
bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    else
        return false;
}

// function to convert a string month name to its numeric equivalent
int monthNameToNumber(char* monthName) {
    char* monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int monthNumbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int i;
    for (i = 0; i < 12; i++) {
        if (strcmp(monthName, monthNames[i]) == 0)
            return monthNumbers[i];
    }
    return -1; // return -1 if month name is not recognized
}

// function to convert a date string in the format "Month Day, Year" to a time_t timestamp
time_t convertDateStringToTimestamp(char* dateString) {
    int month, day, year;
    char monthName[10];
    sscanf(dateString, "%s %d, %d", monthName, &day, &year);
    month = monthNameToNumber(monthName);
    struct tm dateInfo = {0}; // initialize to zero to avoid garbage values
    dateInfo.tm_year = year - 1900; // years since 1900
    dateInfo.tm_mon = month - 1; // month index is zero-based
    dateInfo.tm_mday = day;
    dateInfo.tm_hour = 12; // set to noon to avoid timezone issues
    time_t timestamp = mktime(&dateInfo); // convert to timestamp
    return timestamp;
}

// function to convert a time_t timestamp to a string in the format "Month Day, Year"
char* convertTimestampToDateString(time_t timestamp) {
    struct tm* dateInfo;
    char dateString[20];
    dateInfo = localtime(&timestamp); // get date/time struct from timestamp
    strftime(dateString, 20, "%B %d, %Y", dateInfo); // convert to string in desired format
    return strdup(dateString); // allocate memory for string and return pointer to it
}

// main function
int main() {
    char dateString[20];
    printf("Enter a date in the format 'Month Day, Year': ");
    fgets(dateString, 20, stdin);
    strtok(dateString, "\n"); // remove trailing newline if present
    time_t timestamp = convertDateStringToTimestamp(dateString);
    printf("Converted date: %s\n", convertTimestampToDateString(timestamp));
    return 0;
}