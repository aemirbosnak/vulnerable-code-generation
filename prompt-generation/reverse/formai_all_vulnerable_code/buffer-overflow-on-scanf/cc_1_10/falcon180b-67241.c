//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

/* Function to check if a given string is a valid date */
int is_valid_date(char* date) {
    struct tm tm;
    strptime(date, "%d-%m-%Y", &tm);
    return!mktime(&tm);
}

/* Function to convert a given date string to natural language format */
char* date_to_natural_language(char* date) {
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    char* natural_language_date = malloc(50 * sizeof(char));
    strftime(natural_language_date, 50, "%A, %B %d, %Y", tm);
    return natural_language_date;
}

/* Function to convert a given natural language date string to the corresponding date string */
char* natural_language_to_date(char* natural_language_date) {
    struct tm tm;
    strptime(natural_language_date, "%A, %B %d, %Y", &tm);
    char* date = malloc(20 * sizeof(char));
    strftime(date, 20, "%d-%m-%Y", &tm);
    return date;
}

/* Function to prompt the user for input and perform the conversion */
int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    char* input;
    char* converted_date;
    while(1) {
        printf("Enter a date in either YYYY-MM-DD or natural language format: ");
        scanf("%s", input);
        if(is_valid_date(input)) {
            /* Convert the date string to natural language format */
            converted_date = date_to_natural_language(input);
            printf("Natural language format: %s\n", converted_date);
            /* Convert the natural language date string back to YYYY-MM-DD format */
            char* converted_back = natural_language_to_date(converted_date);
            printf("YYYY-MM-DD format: %s\n", converted_back);
        } else {
            printf("Invalid date format.\n");
        }
    }
    return 0;
}