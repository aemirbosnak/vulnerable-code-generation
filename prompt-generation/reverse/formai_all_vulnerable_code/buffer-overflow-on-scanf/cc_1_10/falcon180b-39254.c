//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

// Function to check if a string is a valid date
int is_valid_date(const char *date_str, const char *date_format) {
    struct tm tm;
    strptime(date_str, date_format, &tm);
    return (strftime(date_format, 15, date_format, &tm) == 15);
}

// Function to convert a date string to a human-readable format
void convert_date(const char *date_str, const char *date_format) {
    time_t now;
    struct tm *tm;
    now = time(NULL);
    tm = localtime(&now);
    strftime(date_str, 15, date_format, tm);
}

// Function to get user input for date format
void get_date_format(char *date_format) {
    printf("Enter the date format (e.g. yyyy-mm-dd): ");
    scanf("%s", date_format);
}

int main() {
    char date_str[15];
    char date_format[15];

    // Get user input for date string
    printf("Enter the date to be converted: ");
    scanf("%s", date_str);

    // Get user input for date format
    get_date_format(date_format);

    // Check if the date string is valid
    if (is_valid_date(date_str, date_format)) {
        // Convert the date string to a human-readable format
        convert_date(date_str, date_format);
        printf("The converted date is: %s\n", date_str);
    } else {
        printf("Invalid date format!\n");
    }

    return 0;
}