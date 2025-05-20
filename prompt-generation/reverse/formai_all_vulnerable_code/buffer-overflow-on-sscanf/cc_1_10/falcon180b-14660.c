//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function to check if a string is a valid date in the format dd/mm/yyyy
int is_valid_date(char* date_str) {
    int day, month, year;
    if (sscanf(date_str, "%d/%d/%d", &day, &month, &year)!= 3) {
        return 0; // Invalid format
    }
    if (month < 1 || month > 12) {
        return 0; // Invalid month
    }
    if (day < 1 || day > 31) {
        return 0; // Invalid day
    }
    if (year < 1000 || year > 9999) {
        return 0; // Invalid year
    }
    return 1; // Valid date
}

// Function to convert a date string to a time_t value
time_t string_to_time(char* date_str) {
    struct tm tm;
    strptime(date_str, "%d/%m/%Y", &tm);
    return mktime(&tm);
}

// Function to convert a time_t value to a date string
void time_to_string(time_t t, char* date_str) {
    struct tm* tm = localtime(&t);
    strftime(date_str, 20, "%d/%m/%Y", tm);
}

// Function to convert a date string to a natural language representation
void date_to_natural_language(char* date_str) {
    time_t t = string_to_time(date_str);
    char natural_language_date[100];
    strftime(natural_language_date, 100, "Today is %A, %B %d, %Y", localtime(&t));
    printf("%s\n", natural_language_date);
}

int main() {
    char date_str[20];
    printf("Enter a date in the format dd/mm/yyyy: ");
    scanf("%s", date_str);
    if (is_valid_date(date_str)) {
        printf("The entered date is valid.\n");
        date_to_natural_language(date_str);
    } else {
        printf("The entered date is invalid.\n");
    }
    return 0;
}