//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: unmistakable
#include <stdio.h>
#include <ctype.h>
#include <time.h>

// Function to check if a string is a valid date
int is_valid_date(char* str_date) {
    struct tm date = {0};
    strptime(str_date, "%d-%m-%Y", &date);
    return (date.tm_mday >= 1 && date.tm_mday <= 31 &&
            date.tm_mon >= 0 && date.tm_mon <= 11 &&
            date.tm_year >= 1000 && date.tm_year <= 9999);
}

// Function to convert a string date to a time_t value
time_t string_to_time(char* str_date) {
    struct tm date = {0};
    strptime(str_date, "%d-%m-%Y", &date);
    return mktime(&date);
}

// Function to convert a time_t value to a string date
char* time_to_string(time_t t) {
    struct tm* date = localtime(&t);
    char str_date[20];
    strftime(str_date, 20, "%d-%m-%Y", date);
    return strdup(str_date);
}

int main() {
    char input[100];
    char* output;

    // Prompt the user to enter a date
    printf("Enter a date (dd-mm-yyyy): ");
    scanf("%s", input);

    // Check if the input is a valid date
    if (is_valid_date(input)) {
        // Convert the input to a time_t value
        time_t t = string_to_time(input);

        // Convert the time_t value to a string date
        output = time_to_string(t);

        // Display the converted date
        printf("The converted date is: %s\n", output);
    } else {
        // Display an error message if the input is not a valid date
        printf("Invalid date format.\n");
    }

    return 0;
}