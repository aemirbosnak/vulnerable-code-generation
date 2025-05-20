//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Ada Lovelace
// Ada Lovelace Style Natural Language Date Converter in C

#include <stdio.h>
#include <string.h>

// Function to convert month name to month number
int get_month_number(char *month_name) {
    month_name[0] = toupper(month_name[0]); // Capitalize first letter
    if (strcmp(month_name, "January") == 0) {
        return 1;
    } else if (strcmp(month_name, "February") == 0) {
        return 2;
    } else if (strcmp(month_name, "March") == 0) {
        return 3;
    } else if (strcmp(month_name, "April") == 0) {
        return 4;
    } else if (strcmp(month_name, "May") == 0) {
        return 5;
    } else if (strcmp(month_name, "June") == 0) {
        return 6;
    } else if (strcmp(month_name, "July") == 0) {
        return 7;
    } else if (strcmp(month_name, "August") == 0) {
        return 8;
    } else if (strcmp(month_name, "September") == 0) {
        return 9;
    } else if (strcmp(month_name, "October") == 0) {
        return 10;
    } else if (strcmp(month_name, "November") == 0) {
        return 11;
    } else if (strcmp(month_name, "December") == 0) {
        return 12;
    } else {
        return 0; // No matching month found
    }
}

// Function to convert date in natural language format (e.g. "December 25, 2022") to numeric format (e.g. 25/12/2022)
void convert_natural_language_date_to_numeric(char *date_string) {
    char month_name[20];
    int day, year;
    sscanf(date_string, "%s %d, %d", month_name, &day, &year);
    int month = get_month_number(month_name);
    if (month == 0) {
        printf("Invalid month name \"%s\"\n", month_name);
    } else {
        printf("%d/%d/%d\n", day, month, year);
    }
}

// Main function to test the date converter
int main() {
    // Test with different date formats
    convert_natural_language_date_to_numeric("December 25, 2022");
    convert_natural_language_date_to_numeric("February 29, 2024");
    convert_natural_language_date_to_numeric("foo 25, 2022"); // Should print "Invalid month name "Foo""

    return 0;
}