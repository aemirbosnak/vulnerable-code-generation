//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100

// Function to convert month name to month number
int month_name_to_number(const char *month) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(month, months[i]) == 0) {
            return i + 1; // Months are 1-indexed
        }
    }
    return -1; // Invalid month
}

// Function to validate the date
int is_valid_date(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return 0; // Invalid date
    }
    
    int days_in_month;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            days_in_month = 31;
            break;
        case 4: case 6: case 9: case 11:
            days_in_month = 30;
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                days_in_month = 29; // Leap year
            } else {
                days_in_month = 28;
            }
            break;
        default:
            return 0; // Invalid month
    }

    return day <= days_in_month; // Check if day is valid
}

// Function to convert natural language date to structured date
void convert_to_date(const char *input, int *day, int *month, int *year) {
    char month_name[MAX_LENGTH];
    if (sscanf(input, "%d %s %d", day, month_name, year) == 3) {
        *month = month_name_to_number(month_name);
    } else {
        *day = *month = *year = 0; // Invalidate
    }
}

// Function to print the formatted date
void print_formatted_date(int day, int month, int year) {
    printf("The formatted date is: %02d-%02d-%04d\n", day, month, year);
}

int main() {
    char input[MAX_LENGTH];
    int day, month, year;

    printf("Enter a date in the format '<day> <month name> <year>': ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    convert_to_date(input, &day, &month, &year);

    if (day == 0 || month == 0 || year == 0 || !is_valid_date(day, month, year)) {
        printf("Invalid date format or date does not exist.\n");
        return 1;
    }

    print_formatted_date(day, month, year);

    return 0;
}