//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: authentic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a valid date
int is_valid_date(char* str) {
    struct tm tm;
    strptime(str, "%m/%d/%Y", &tm);
    return (tm.tm_year >= 1000 && tm.tm_year <= 9999 && tm.tm_mon >= 1 && tm.tm_mon <= 12 && tm.tm_mday >= 1 && tm.tm_mday <= 31);
}

// Function to convert a string to a date
time_t string_to_date(char* str) {
    struct tm tm;
    strptime(str, "%m/%d/%Y", &tm);
    return mktime(&tm);
}

// Function to convert a date to a string
char* date_to_string(time_t date) {
    char* result = malloc(20);
    strftime(result, 20, "%m/%d/%Y", localtime(&date));
    return result;
}

// Function to convert a date to a natural language string
char* date_to_natural_string(time_t date) {
    char* result = malloc(100);
    strftime(result, 100, "Today is %A, %B %d, %Y.", localtime(&date));
    return result;
}

int main() {
    char input[100];
    char* date_str;
    time_t date;

    // Prompt the user to enter a date
    printf("Please enter a date (mm/dd/yyyy): ");
    scanf("%s", input);

    // Check if the input is a valid date
    if (!is_valid_date(input)) {
        printf("Invalid date.\n");
        return 1;
    }

    // Convert the input to a date
    date_str = input;
    date = string_to_date(date_str);

    // Print the date in natural language
    printf("The date %s is %s.\n", date_str, date_to_natural_string(date));

    // Convert the date to a string and print it
    printf("The string representation of the date is %s.\n", date_to_string(date));

    return 0;
}