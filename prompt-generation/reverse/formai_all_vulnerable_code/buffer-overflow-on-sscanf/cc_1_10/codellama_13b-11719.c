//Code Llama-13B DATASET v1.0 Category: Natural Language Date Converter ; Style: cheerful
// C Natural Language Date Converter Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a date from a natural language string to a YYYY-MM-DD string
char* convert_date(char* date_str) {
    // Initialize variables
    char month[10], day[10], year[10];
    int month_int, day_int, year_int;
    char* month_name[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Parse the date string
    sscanf(date_str, "%s %d, %d", month, &day_int, &year_int);

    // Find the month index
    for (int i = 0; i < 12; i++) {
        if (strcmp(month, month_name[i]) == 0) {
            month_int = i + 1;
            break;
        }
    }

    // Check for leap year
    if (month_int == 2 && day_int > 28) {
        if (year_int % 4 == 0 && (year_int % 100 != 0 || year_int % 400 == 0)) {
            day_int = 29;
        } else {
            day_int = 28;
        }
    }

    // Check for day of month
    if (day_int > month_days[month_int - 1]) {
        day_int = month_days[month_int - 1];
    }

    // Format the output date string
    sprintf(date_str, "%04d-%02d-%02d", year_int, month_int, day_int);

    return date_str;
}

int main() {
    // Test the function
    char date_str[100] = "April 30, 2023";
    printf("%s\n", convert_date(date_str));
    return 0;
}