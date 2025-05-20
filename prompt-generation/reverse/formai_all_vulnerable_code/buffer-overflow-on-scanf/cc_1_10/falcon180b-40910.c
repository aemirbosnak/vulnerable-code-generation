//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <time.h>
#include <ctype.h>

// Function to check if a string is a valid date
int is_valid_date(char* date) {
    struct tm tm = {0};
    strptime(date, "%d/%m/%Y", &tm);
    return (tm.tm_year + 1900) > 0 && (tm.tm_mon + 1) > 0 && (tm.tm_mday) > 0;
}

// Function to convert a date string to a numerical date
int string_to_date(char* date, int* year, int* month, int* day) {
    struct tm tm = {0};
    strptime(date, "%d/%m/%Y", &tm);
    *year = tm.tm_year + 1900;
    *month = tm.tm_mon + 1;
    *day = tm.tm_mday;
    return 1;
}

// Function to convert a numerical date to a date string
void date_to_string(int year, int month, int day, char* date) {
    sprintf(date, "%02d/%02d/%04d", month, day, year);
}

int main() {
    char input_date[100];
    char natural_date[100];
    int year, month, day;

    // Get user input date
    printf("Enter a date in DD/MM/YYYY format: ");
    scanf("%s", input_date);

    // Check if the input date is valid
    if (!is_valid_date(input_date)) {
        printf("Invalid date entered.\n");
        return 1;
    }

    // Convert input date to numerical date
    string_to_date(input_date, &year, &month, &day);

    // Convert numerical date to natural language date
    date_to_string(year, month, day, natural_date);

    // Output the natural language date
    printf("The date %s is %s in natural language.\n", input_date, natural_date);

    return 0;
}