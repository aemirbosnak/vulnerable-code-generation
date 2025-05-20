//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LEN 100

const char *months[] = {
    "January", "February", "March", "April", "May", "June", 
    "July", "August", "September", "October", "November", "December"
};

int get_month_index(const char *month_name) {
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(month_name, months[i]) == 0) {
            return i + 1; // Return month index (1-12)
        }
    }
    return -1; // Invalid month
}

int is_valid_date(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return 0;
    }

    int max_days = 31;
    if (month == 2) { // February
        if (year % 4 == 0) {
            if (year % 100 == 0 && year % 400 != 0) {
                max_days = 28;
            } else {
                max_days = 29;
            }
        } else {
            max_days = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        max_days = 30; // April, June, September, November
    }

    return day <= max_days;
}

void convert_natural_language_date(const char *input) {
    char month_name[20];
    int day, year;
    
    if (sscanf(input, "%d %19s %d", &day, month_name, &year) != 3) {
        printf("Invalid date format. Please use 'DD Month YYYY' format.\n");
        return;
    }

    int month = get_month_index(month_name);
    if (month == -1) {
        printf("Invalid month: %s\n", month_name);
        return;
    }

    if (!is_valid_date(day, month, year)) {
        printf("The date %d %s %d is not a valid date.\n", day, month_name, year);
        return;
    }

    printf("The converted date is: %04d-%02d-%02d\n", year, month, day);
}

int main() {
    char input[MAX_INPUT_LEN];
    
    printf("Enter a date in 'DD Month YYYY' format: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove trailing newline character
    input[strcspn(input, "\n")] = 0;

    convert_natural_language_date(input);

    return 0;
}