//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to check if input is a valid date
int is_valid_date(int day, int month, int year) {
    struct tm tm = {0};
    tm.tm_mday = day;
    tm.tm_mon = month - 1;
    tm.tm_year = year - 1900;
    return mktime(&tm)!= -1;
}

// Function to convert a date string to a struct tm object
struct tm *string_to_tm(const char *date_string) {
    struct tm tm = {0};
    strptime(date_string, "%d %B %Y", &tm);
    return &tm;
}

// Function to convert a struct tm object to a date string
char *tm_to_string(const struct tm *tm) {
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%d %B %Y", tm);
    return strdup(buffer);
}

// Main function
int main() {
    char input_date[100];
    char output_date[100];

    // Get input date from user
    printf("Enter a date in the format DD/MM/YYYY: ");
    scanf("%s", input_date);

    // Check if input is a valid date
    if (!is_valid_date(atoi(input_date), atoi(input_date + 3), atoi(input_date + 6))) {
        printf("Invalid date.\n");
        return 1;
    }

    // Convert input date to a struct tm object
    struct tm *tm = string_to_tm(input_date);

    // Get output date format from user
    printf("Enter the desired output date format (DD/MM/YYYY or MM/DD/YYYY): ");
    scanf("%s", output_date);

    // Convert struct tm object to output date string
    char *output_date_string = tm_to_string(tm);

    // Print converted date
    printf("The converted date is: %s\n", output_date_string);

    return 0;
}