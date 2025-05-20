//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: standalone
#include <stdio.h>
#include <time.h>
#include <string.h>

void printDate(const char *inputDate) {
    int day, month, year;
    char monthString[15];
    struct tm tmDate;
    memset(&tmDate, 0, sizeof(struct tm));

    // Parse input date string
    sscanf(inputDate, "%d %s %d", &day, monthString, &year);

    // Convert month string to month number
    if (strcmp(monthString, "January") == 0) {
        month = 1;
    } else if (strcmp(monthString, "February") == 0) {
        month = 2;
    } else if (strcmp(monthString, "March") == 0) {
        month = 3;
    } else if (strcmp(monthString, "April") == 0) {
        month = 4;
    } else if (strcmp(monthString, "May") == 0) {
        month = 5;
    } else if (strcmp(monthString, "June") == 0) {
        month = 6;
    } else if (strcmp(monthString, "July") == 0) {
        month = 7;
    } else if (strcmp(monthString, "August") == 0) {
        month = 8;
    } else if (strcmp(monthString, "September") == 0) {
        month = 9;
    } else if (strcmp(monthString, "October") == 0) {
        month = 10;
    } else if (strcmp(monthString, "November") == 0) {
        month = 11;
    } else if (strcmp(monthString, "December") == 0) {
        month = 12;
    }

    // Set tm struct members
    tmDate.tm_mday = day;
    tmDate.tm_mon = month - 1;
    tmDate.tm_year = year - 1900;

    // Convert to time_t
    time_t t = mktime(&tmDate);

    // Convert back to struct tm
    struct tm *tmDate2 = localtime(&t);

    // Print date in desired format
    printf("%d/%d/%d\n", tmDate2->tm_mday, tmDate2->tm_mon + 1, tmDate2->tm_year + 1900);
}

int main() {
    char inputDate[20];

    // Get input date from user
    printf("Enter date in format 'DD Month YYYY':\n");
    scanf("%[^\n]s", inputDate);

    // Print date in desired format
    printDate(inputDate);

    return 0;
}