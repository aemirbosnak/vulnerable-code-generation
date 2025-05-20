//Code Llama-13B DATASET v1.0 Category: Natural Language Date Converter ; Style: paranoid
// Paranoid Date Converter

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // Get the current date and time
    time_t t = time(NULL);
    struct tm *current_time = localtime(&t);

    // Get the user's input
    char input[100];
    printf("Enter the date in the format 'DD-MM-YYYY': ");
    scanf("%99s", input);

    // Parse the input and check for errors
    char *date = strtok(input, "-");
    if (date == NULL) {
        printf("Invalid input. Please try again.\n");
        return 1;
    }
    char *month = strtok(NULL, "-");
    if (month == NULL) {
        printf("Invalid input. Please try again.\n");
        return 1;
    }
    char *year = strtok(NULL, "-");
    if (year == NULL) {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    // Convert the input to a time_t value
    int dd = atoi(date);
    int mm = atoi(month);
    int yy = atoi(year);
    struct tm input_time = { dd, mm, yy, 0, 0, 0, 0, 0, 0 };
    time_t input_t = mktime(&input_time);

    // Check if the input is valid
    if (input_t == -1) {
        printf("Invalid date. Please try again.\n");
        return 1;
    }

    // Convert the input time to the current time zone
    struct tm *input_time_current_zone = localtime(&input_t);

    // Print the converted date
    printf("The date is: %d-%d-%d\n", input_time_current_zone->tm_mday, input_time_current_zone->tm_mon + 1, input_time_current_zone->tm_year + 1900);

    return 0;
}