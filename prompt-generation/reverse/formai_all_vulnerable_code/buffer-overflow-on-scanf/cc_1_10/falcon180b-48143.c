//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function to check if a string is a valid date
int is_valid_date(char* date_str, int* year, int* month, int* day) {
    // Check if the string is in the correct format
    if (strlen(date_str)!= 10 || date_str[2]!= '/' || date_str[5]!= '/') {
        return 0;
    }

    // Convert the string to integers
    *year = atoi(date_str);
    *month = atoi(date_str + 3);
    *day = atoi(date_str + 6);

    // Check if the year is valid
    struct tm tm = {0};
    tm.tm_year = *year - 1900;
    tm.tm_mon = *month - 1;
    tm.tm_mday = *day;
    time_t t = mktime(&tm);
    if (t == -1) {
        return 0;
    }

    return 1;
}

// Function to convert a date string to a natural language string
void date_to_natural_language(int year, int month, int day, char* natural_language_date) {
    struct tm tm = {0};
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    strftime(natural_language_date, 80, "Today is %A, %B %d, %Y.", &tm);
}

int main() {
    char date_str[11];
    int year, month, day;

    // Get the date from the user
    printf("Enter a date (MM/DD/YYYY): ");
    scanf("%s", date_str);

    // Check if the date is valid
    if (is_valid_date(date_str, &year, &month, &day)) {
        // Convert the date to a natural language string
        char natural_language_date[80];
        date_to_natural_language(year, month, day, natural_language_date);

        // Print the natural language date
        printf("The date %s is %s.\n", date_str, natural_language_date);
    } else {
        printf("Invalid date.\n");
    }

    return 0;
}