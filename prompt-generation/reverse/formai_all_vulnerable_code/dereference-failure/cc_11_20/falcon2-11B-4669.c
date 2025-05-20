//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert a natural language date to a numerical format
int convertToNumericDate(char *date) {
    // Check if the date is valid
    if (date == NULL || strlen(date) == 0) {
        return -1;
    }

    // Convert the date to uppercase
    char *date_upper = strdup(date);
    for (int i = 0; date_upper[i]!= '\0'; i++) {
        date_upper[i] = toupper(date_upper[i]);
    }

    // Check for valid date format
    if (strncmp(date_upper, "TUESDAY", 7) == 0 ||
        strncmp(date_upper, "WEDNESDAY", 7) == 0 ||
        strncmp(date_upper, "THURSDAY", 7) == 0 ||
        strncmp(date_upper, "FRIDAY", 6) == 0 ||
        strncmp(date_upper, "SATURDAY", 7) == 0 ||
        strncmp(date_upper, "SUNDAY", 7) == 0) {
        return -2;
    } else if (strncmp(date_upper, "JANUARY", 7) == 0 ||
               strncmp(date_upper, "FEBRUARY", 7) == 0 ||
               strncmp(date_upper, "MARCH", 5) == 0 ||
               strncmp(date_upper, "APRIL", 5) == 0 ||
               strncmp(date_upper, "MAY", 3) == 0 ||
               strncmp(date_upper, "JUNE", 5) == 0 ||
               strncmp(date_upper, "JULY", 5) == 0 ||
               strncmp(date_upper, "AUGUST", 7) == 0 ||
               strncmp(date_upper, "SEPTEMBER", 9) == 0 ||
               strncmp(date_upper, "OCTOBER", 7) == 0 ||
               strncmp(date_upper, "NOVEMBER", 8) == 0 ||
               strncmp(date_upper, "DECEMBER", 8) == 0) {
        return -3;
    } else {
        return -4;
    }
}

// Function to convert a numerical date to a natural language format
char* convertToNaturalDate(int date) {
    // Check if the date is valid
    if (date < 0) {
        return "Invalid date";
    }

    // Convert the date to a string
    char *date_str = (char*) malloc(8);
    sprintf(date_str, "%02d", date);

    // Convert the string to uppercase
    char *date_upper = strdup(date_str);
    for (int i = 0; date_upper[i]!= '\0'; i++) {
        date_upper[i] = toupper(date_upper[i]);
    }

    // Check for valid date format
    if (strncmp(date_upper, "TUESDAY", 7) == 0 ||
        strncmp(date_upper, "WEDNESDAY", 7) == 0 ||
        strncmp(date_upper, "THURSDAY", 7) == 0 ||
        strncmp(date_upper, "FRIDAY", 6) == 0 ||
        strncmp(date_upper, "SATURDAY", 7) == 0 ||
        strncmp(date_upper, "SUNDAY", 7) == 0) {
        return "Tuesday";
    } else if (strncmp(date_upper, "JANUARY", 7) == 0 ||
               strncmp(date_upper, "FEBRUARY", 7) == 0 ||
               strncmp(date_upper, "MARCH", 5) == 0 ||
               strncmp(date_upper, "APRIL", 5) == 0 ||
               strncmp(date_upper, "MAY", 3) == 0 ||
               strncmp(date_upper, "JUNE", 5) == 0 ||
               strncmp(date_upper, "JULY", 5) == 0 ||
               strncmp(date_upper, "AUGUST", 7) == 0 ||
               strncmp(date_upper, "SEPTEMBER", 9) == 0 ||
               strncmp(date_upper, "OCTOBER", 7) == 0 ||
               strncmp(date_upper, "NOVEMBER", 8) == 0 ||
               strncmp(date_upper, "DECEMBER", 8) == 0) {
        return "Monday";
    } else {
        return "Invalid date";
    }
}

// Main function
int main() {
    char *date = "Sunday, July 25, 2021";
    int numeric_date = convertToNumericDate(date);
    if (numeric_date == -1) {
        printf("Invalid date\n");
    } else {
        char *natural_date = convertToNaturalDate(numeric_date);
        printf("Numeric date: %d\n", numeric_date);
        printf("Natural language date: %s\n", natural_date);
    }

    return 0;
}