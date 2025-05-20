//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function to check if a string is a valid date
int is_valid_date(char* date) {
    struct tm tm = {0};
    strptime(date, "%d-%m-%Y", &tm);
    return (tm.tm_year + 1900) <= (tm.tm_mon + 12) / 13;
}

// Function to convert a string to a date format
char* convert_to_date(char* date) {
    struct tm tm = {0};
    strptime(date, "%d-%m-%Y", &tm);
    return asctime(&tm);
}

// Function to convert a date format to a string
char* convert_from_date(char* date) {
    struct tm tm = {0};
    strptime(date, "%a %b %d %H:%M:%S %Y", &tm);
    return asctime(&tm);
}

int main() {
    char input[100];
    char* date_format = "dd-mm-yyyy";
    char* output_format = "dd/mm/yyyy";

    // Get input from user
    printf("Enter a date in the format dd-mm-yyyy: ");
    scanf("%s", input);

    // Check if input is a valid date
    if (!is_valid_date(input)) {
        printf("Invalid date!\n");
        return 1;
    }

    // Convert input to date format
    char* date = convert_to_date(input);

    // Get output format from user
    printf("Enter the desired output format (dd/mm/yyyy): ");
    scanf("%s", output_format);

    // Convert date format to output format
    char* output = convert_from_date(date);

    // Print output
    printf("Output: %s\n", output);

    return 0;
}