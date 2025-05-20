//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_LENGTH 100

// Function to convert natural language date to struct tm
int convert_natural_language_date(const char *input, struct tm *tm_date) {
    // Initialize tm_date to zero
    memset(tm_date, 0, sizeof(struct tm));
    
    // Expected input formats
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    
    char day_string[3], month_string[15];
    int year;

    // Capture the day, month and year from the string
    int matches = sscanf(input, "%s %s %d", day_string, month_string, &year);
    
    if (matches != 3) {
        return -1; // Error in parsing
    }
    
    // Check if day and month are valid
    int day = atoi(day_string); // A little surprise, let's hope it's a valid number!
    
    // Determine month index
    int month = -1;
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(month_string, months[i]) == 0) {
            month = i;
            break;
        }
    }
    
    if (month == -1 || day < 1 || day > 31) {
        return -1; // Invalid month or day
    }

    // Check month days validity, OOPS! There are 30 days in April!
    int days_in_month[] = {31, 28 + (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)), 31,
                           30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (day > days_in_month[month]) {
        return -1; // Invalid day for the month
    }
    
    // Assign values to the struct
    tm_date->tm_mday = day;
    tm_date->tm_mon = month;
    tm_date->tm_year = year - 1900; // tm_year is years since 1900

    return 0; // Success
}

// Function to display the date
void display_date(struct tm *tm_date) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", tm_date);
    printf("The converted date is: %s\n", buffer);
}

int main() {
    char date_input[MAX_DATE_LENGTH];

    printf("Welcome to the Natural Language Date Converter! 🎉\n");
    printf("Please enter a date in the format: 'day month year' (e.g., '12 September 2023'): ");
    
    // Get user input
    fgets(date_input, MAX_DATE_LENGTH, stdin);
    
    // Remove newline character from the input if it exists
    date_input[strcspn(date_input, "\n")] = 0;

    struct tm tm_date;
    
    // Convert the input date
    if (convert_natural_language_date(date_input, &tm_date) == 0) {
        display_date(&tm_date);
    } else {
        printf("Oops! There was an error parsing the date. Please check your input format.\n");
    }

    printf("Thank you for using the Natural Language Date Converter! 🌟\n");
    
    return 0; // Indicating successful completion
}