//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function to check if a string is a valid date
int is_valid_date(char* str) {
    struct tm tm;
    strptime(str, "%Y-%m-%d", &tm);
    return tm.tm_year >= 1000 && tm.tm_year <= 9999;
}

// Function to convert a string to a date
time_t string_to_date(char* str) {
    struct tm tm;
    strptime(str, "%Y-%m-%d", &tm);
    return mktime(&tm);
}

// Function to convert a date to a string
char* date_to_string(time_t date) {
    char* str = malloc(20);
    strftime(str, 20, "%Y-%m-%d", localtime(&date));
    return str;
}

// Function to convert a string to a date in a specific format
char* convert_date(char* str, char* format) {
    time_t date = string_to_date(str);
    char* result = malloc(strlen(format) + 1);
    strftime(result, strlen(format) + 1, format, localtime(&date));
    return result;
}

int main() {
    char* str;
    printf("Enter a date in YYYY-MM-DD format: ");
    scanf("%s", str);

    if (is_valid_date(str)) {
        char* original_format = "%Y-%m-%d";
        char* new_format = "Today is %A, %B %d, %Y";
        char* formatted_date = convert_date(str, new_format);
        printf("Formatted date: %s\n", formatted_date);
    } else {
        printf("Invalid date\n");
    }

    return 0;
}