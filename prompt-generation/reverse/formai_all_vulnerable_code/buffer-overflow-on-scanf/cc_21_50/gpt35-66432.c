//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
    char date[20], month[20], year[20], delimiter[2], convertedDate[20], convertedMonth[20];
    int iDay, iMonth, iYear;

    printf("Enter date in natural language format (example: 22nd of June, 2021): ");
    scanf("%d%s%s%s", &iDay, delimiter, month, year);

    if (strcmp(month, "January") == 0) {
        iMonth = 1;
    } else if (strcmp(month, "February") == 0) {
        iMonth = 2;
    } else if (strcmp(month, "March") == 0) {
        iMonth = 3;
    } else if (strcmp(month, "April") == 0) {
        iMonth = 4;
    } else if (strcmp(month, "May") == 0) {
        iMonth = 5;
    } else if (strcmp(month, "June") == 0) {
        iMonth = 6;
    } else if (strcmp(month, "July") == 0) {
        iMonth = 7;
    } else if (strcmp(month, "August") == 0) {
        iMonth = 8;
    } else if (strcmp(month, "September") == 0) {
        iMonth = 9;
    } else if (strcmp(month, "October") == 0) {
        iMonth = 10;
    } else if (strcmp(month, "November") == 0) {
        iMonth = 11;
    } else if (strcmp(month, "December") == 0) {
        iMonth = 12;
    } else {
        printf("Invalid month format. Please try again.");
        return 0;
    }

    sprintf(convertedDate, "%d", iDay);

    if (iDay == 1 || iDay == 21 || iDay == 31) {
        strcat(convertedDate, "st");
    } else if (iDay == 2 || iDay == 22) {
        strcat(convertedDate, "nd");
    } else if (iDay == 3 || iDay == 23) {
        strcat(convertedDate, "rd");
    } else {
        strcat(convertedDate, "th");
    }

    sprintf(convertedMonth, "%d", iMonth);

    if (iMonth == 1) {
        strcat(convertedMonth, "st");
    } else if (iMonth == 2) {
        strcat(convertedMonth, "nd");
    } else if (iMonth == 3) {
        strcat(convertedMonth, "rd");
    } else {
        strcat(convertedMonth, "th");
    }

    sprintf(year, "%d", iYear);

    printf("The converted date is: %s of %s, %s", convertedDate, convertedMonth, year);

    return 0;
}