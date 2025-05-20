//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to swap two integers
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to validate the given date (dd/mm/yyyy)
int validate_date(char* date) {
    int day, month, year;
    sscanf(date, "%d/%d/%d", &day, &month, &year);

    // Check if month is valid for the given year
    if (month < 1 || month > 12)
        return 0;

    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check if the given date is valid for the given month and year
    if (month == 2) {
        int is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        days_in_month[1] = is_leap_year ? 29 : 28;
    }

    if (day < 1 || day > days_in_month[month - 1])
        return 0;

    return 1;
}

// Function to convert the given date to "mm/dd/yyyy" format
void convert_to_american(char* date, char* output) {
    int day, month, year;
    sscanf(date, "%d/%d/%d", &day, &month, &year);

    sprintf(output, "%d/%d/%d", month, day, year);
}

// Function to convert the given date to "dd/mm/yyyy" format
void convert_to_European(char* date, char* output) {
    int day, month, year;
    sscanf(date, "%d/%d/%d", &day, &month, &year);

    swap(&day, &month);
    sprintf(output, "%d/%d/%d", day, month, year);
}

int main() {
    char date[11], date_formatted[11];

    printf("Enter a date in dd/mm/yyyy format: ");
    scanf("%s", date);

    // Validate the given date
    if (!validate_date(date)) {
        printf("Invalid date.\n");
        return 1;
    }

    // Convert the date to American format
    convert_to_american(date, date_formatted);
    printf("American format: %s\n", date_formatted);

    // Convert the date to European format
    convert_to_European(date_formatted, date);
    printf("European format: %s\n", date);

    return 0;
}