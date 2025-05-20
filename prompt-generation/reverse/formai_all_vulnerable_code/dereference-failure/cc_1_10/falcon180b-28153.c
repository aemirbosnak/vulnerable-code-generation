//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_DATE_LENGTH 100
#define MAX_MONTH_LENGTH 20
#define MAX_YEAR_LENGTH 10

/* Function to check if a string is a valid date */
int is_valid_date(char *date) {
    struct tm tm;
    strptime(date, "%d-%b-%Y", &tm);
    return tm.tm_year + 1900 > 0;
}

/* Function to convert a date string to a different format */
char *convert_date(char *date, char *format) {
    struct tm tm;
    strptime(date, "%d-%b-%Y", &tm);
    char result[MAX_DATE_LENGTH];
    strftime(result, MAX_DATE_LENGTH, format, &tm);
    return strdup(result);
}

/* Function to get the current date and time */
char *get_current_date() {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    char result[MAX_DATE_LENGTH];
    strftime(result, MAX_DATE_LENGTH, "%d-%b-%Y", tm);
    return strdup(result);
}

/* Function to print the usage of the program */
void print_usage() {
    printf("Usage:./date_converter [date] [format]\n");
    printf("Where:\n");
    printf("  date: The date to be converted in the format 'dd-mm-yyyy'.\n");
    printf("  format: The desired format of the date. Supported formats are:\n");
    printf("    - 'dd/mm/yyyy'\n");
    printf("    -'mm/dd/yyyy'\n");
    printf("    - 'yyyy/mm/dd'\n");
    printf("    - 'dd-mmm-yyyy' (where mmm is the abbreviated month name)\n");
}

/* Main function of the program */
int main(int argc, char *argv[]) {
    if (argc!= 3) {
        print_usage();
        return 1;
    }

    char *date = argv[1];
    char *format = argv[2];

    /* Check if the date is valid */
    if (!is_valid_date(date)) {
        printf("Invalid date format. The date should be in the format 'dd-mm-yyyy'.\n");
        return 1;
    }

    /* Convert the date to the desired format */
    char *converted_date = convert_date(date, format);
    printf("Converted date: %s\n", converted_date);

    return 0;
}