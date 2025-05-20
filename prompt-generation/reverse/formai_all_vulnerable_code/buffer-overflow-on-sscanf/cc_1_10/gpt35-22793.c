//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: shocked
#include<stdio.h>
#include<ctype.h>
#include<string.h>

// function to check if the given year is leap year or not
int isLeap(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        return 1;
    else
        return 0;   
}

// function to convert month string to integer value
int monthToInt(char* month) {
    if (strcmp(month, "January") == 0) return 1;
    if (strcmp(month, "February") == 0) return 2;
    if (strcmp(month, "March") == 0) return 3;
    if (strcmp(month, "April") == 0) return 4;
    if (strcmp(month, "May") == 0) return 5;
    if (strcmp(month, "June") == 0) return 6;
    if (strcmp(month, "July") == 0) return 7;
    if (strcmp(month, "August") == 0) return 8;
    if (strcmp(month, "September") == 0) return 9;
    if (strcmp(month, "October") == 0) return 10;
    if (strcmp(month, "November") == 0) return 11;
    if (strcmp(month, "December") == 0) return 12;
}

/**
 * function to convert new date format to yyyy-mm-dd format
 * format example: "April 3, 2022"
 */
void convertDateFormat(char* input, char* output) {

    char* month = (char*) malloc(sizeof(char) * 10);
    int day, year;

    sscanf(input, "%s %d, %d", month, &day, &year);

    // converting month string to integer
    int monthVal = monthToInt(month);

    // checking if the year is leap year or not
    if (isLeap(year) && monthVal == 2 && day == 29) {
        sprintf(output, "%d-02-29", year);
    } else {
        sprintf(output, "%d-%02d-%02d", year, monthVal, day);
    }

    free(month);
}

int main() {
    char date[15];
    char output[11];

    printf("Enter a date (Example: April 3, 2022): ");
    fgets(date, 15, stdin);

    // converting format and printing output
    convertDateFormat(date, output);
    printf("\nConverted date: %s", output);

    return 0;
}