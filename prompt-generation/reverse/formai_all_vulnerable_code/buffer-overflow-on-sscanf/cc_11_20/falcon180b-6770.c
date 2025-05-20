//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STRING_SIZE 100

int main() {
    char input[MAX_STRING_SIZE];
    char *month_str;
    int year, month, day;
    enum { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC } month_enum;

    // Prompt user for input
    printf("Enter a date in the format MM/DD/YYYY: ");
    fgets(input, MAX_STRING_SIZE, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Convert input string to integers
    sscanf(input, "%d/%d/%d", &month, &day, &year);

    // Convert month number to month name
    switch (month) {
        case 1:
            month_str = "January";
            month_enum = JAN;
            break;
        case 2:
            month_str = "February";
            month_enum = FEB;
            break;
        case 3:
            month_str = "March";
            month_enum = MAR;
            break;
        case 4:
            month_str = "April";
            month_enum = APR;
            break;
        case 5:
            month_str = "May";
            month_enum = MAY;
            break;
        case 6:
            month_str = "June";
            month_enum = JUN;
            break;
        case 7:
            month_str = "July";
            month_enum = JUL;
            break;
        case 8:
            month_str = "August";
            month_enum = AUG;
            break;
        case 9:
            month_str = "September";
            month_enum = SEP;
            break;
        case 10:
            month_str = "October";
            month_enum = OCT;
            break;
        case 11:
            month_str = "November";
            month_enum = NOV;
            break;
        case 12:
            month_str = "December";
            month_enum = DEC;
            break;
        default:
            printf("Invalid month number\n");
            return 1;
    }

    // Convert day and year to strings
    char day_str[3];
    char year_str[5];
    snprintf(day_str, 3, "%02d", day);
    snprintf(year_str, 5, "%04d", year);

    // Print date in natural language format
    printf("Today is %s %s, %s\n", day_str, month_str, year_str);

    return 0;
}