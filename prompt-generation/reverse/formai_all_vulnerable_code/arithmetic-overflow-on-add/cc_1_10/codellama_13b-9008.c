//Code Llama-13B DATASET v1.0 Category: Natural Language Date Converter ; Style: romantic
/*
 * A romantic C Natural Language Date Converter example program
 *
 * This program takes a date in natural language, such as "Today" or "Yesterday",
 * and converts it to a date in a more formal format, such as "2023-02-28" or
 * "2023-02-27".
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

// Function to convert a natural language date to a formal date
char *convert_date(char *input_date) {
    // Get the current date and time
    time_t current_time = time(NULL);
    struct tm *current_tm = localtime(&current_time);

    // Get the current year, month, and day
    int current_year = current_tm->tm_year + 1900;
    int current_month = current_tm->tm_mon + 1;
    int current_day = current_tm->tm_mday;

    // Convert the input date to lowercase
    char *lowercase_date = strdup(input_date);
    for (int i = 0; i < strlen(lowercase_date); i++) {
        lowercase_date[i] = tolower(lowercase_date[i]);
    }

    // Check if the input date is "today" or "yesterday"
    if (strcmp(lowercase_date, "today") == 0) {
        // Return the current date in the format "YYYY-MM-DD"
        char *formatted_date = malloc(11);
        sprintf(formatted_date, "%d-%02d-%02d", current_year, current_month, current_day);
        return formatted_date;
    } else if (strcmp(lowercase_date, "yesterday") == 0) {
        // Return the previous date in the format "YYYY-MM-DD"
        struct tm previous_tm = *current_tm;
        previous_tm.tm_mday -= 1;
        time_t previous_time = mktime(&previous_tm);
        char *formatted_date = malloc(11);
        strftime(formatted_date, 11, "%Y-%m-%d", localtime(&previous_time));
        return formatted_date;
    } else {
        // Return an error message if the input date is not "today" or "yesterday"
        char *error_message = "Invalid date. Please enter either 'today' or 'yesterday'.";
        return error_message;
    }
}

// Main function
int main() {
    // Get the input date from the user
    char input_date[100];
    printf("Enter a date in natural language (e.g. 'today' or 'yesterday'): ");
    fgets(input_date, 100, stdin);

    // Convert the input date to a formal date
    char *formatted_date = convert_date(input_date);

    // Print the formatted date to the console
    printf("Formatted date: %s\n", formatted_date);

    // Free the memory allocated for the formatted date
    free(formatted_date);

    return 0;
}