//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

// Function to check if a string is a valid date
int is_valid_date(char *date) {
    struct tm tm;
    strptime(date, "%d/%m/%Y", &tm);
    return tm.tm_mday >= 1 && tm.tm_mday <= 31 && tm.tm_mon >= 0 && tm.tm_mon <= 11 && tm.tm_year >= 1900 && tm.tm_year <= 2100;
}

// Function to convert a date string to a time_t value
time_t string_to_time(char *date) {
    struct tm tm;
    strptime(date, "%d/%m/%Y", &tm);
    return mktime(&tm);
}

// Function to convert a time_t value to a date string
void time_to_string(time_t t, char *date) {
    struct tm tm = *localtime(&t);
    strftime(date, 80, "%d/%m/%Y", &tm);
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    char input[80];
    char output[80];

    // Prompt user for input
    printf("Enter a date (dd/mm/yyyy): ");
    fgets(input, 80, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Check if input is a valid date
    if (is_valid_date(input)) {
        // Convert input to time_t value
        time_t t = string_to_time(input);

        // Convert time_t value to output string
        time_to_string(t, output);

        // Print output
        printf("The date %s is equivalent to %s.\n", input, output);
    } else {
        printf("Invalid date format.\n");
    }

    return 0;
}