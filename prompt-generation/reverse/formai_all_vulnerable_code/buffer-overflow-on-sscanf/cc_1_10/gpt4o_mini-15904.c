//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 100

// Shape-shifting input handling
void input_date(char *date_str) {
    printf("Enter a date (YYYY-MM-DD): ");
    fgets(date_str, BUFFER_SIZE, stdin);
    date_str[strcspn(date_str, "\n")] = 0; // Remove newline character
}

// Date structure
typedef struct {
    int year;
    int month;
    int day;
} Date;

// Function to validate the date
int is_valid_date(Date date) {
    if (date.year < 0 || date.month < 1 || date.month > 12 || date.day < 1) {
        return 0;
    }
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0)) {
        days_in_month[2] = 29; // Leap year adjustment
    }
    return date.day <= days_in_month[date.month];
}

// Function to convert to timestamp
time_t date_to_timestamp(Date date) {
    struct tm tm_date;
    tm_date.tm_year = date.year - 1900; // Year since 1900
    tm_date.tm_mon = date.month - 1;    // Month from 0 to 11
    tm_date.tm_mday = date.day;
    tm_date.tm_hour = 0;
    tm_date.tm_min = 0;
    tm_date.tm_sec = 0;
    tm_date.tm_isdst = -1; // Automatic daylight saving time adjustment
    return mktime(&tm_date);
}

// Function to format the date
void format_and_display(Date date) {
    char buffer[BUFFER_SIZE];
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", mktime(&(struct tm){.tm_year = date.year - 1900, .tm_mon = date.month - 1, .tm_mday = date.day}));
    printf("Formatted Date: %s\n", buffer);
}

// Main function to put it all together
int main() {
    char date_input[BUFFER_SIZE];
    Date date;

    // Input date from user
    input_date(date_input);

    // Splitting input string into components
    if (sscanf(date_input, "%d-%d-%d", &date.year, &date.month, &date.day) != 3) {
        printf("Invalid date format! Please use YYYY-MM-DD.\n");
        return 1;
    }

    // Validating the date
    if (!is_valid_date(date)) {
        printf("Invalid date entered!\n");
        return 1;
    }

    // Convert date to a timestamp
    time_t timestamp = date_to_timestamp(date);
    if (timestamp == -1) {
        printf("Error converting to timestamp.\n");
        return 1;
    }

    // Display formatted date
    format_and_display(date);
    
    // Print timestamp
    printf("Timestamp: %ld\n", (long)timestamp);
    
    // Optionally, display in additional formats
    char *range_of_years[] = {"2020", "2021", "2022", "2023", NULL};
    printf("Shape-shifting display of years:\n");
    for (int i = 0; range_of_years[i] != NULL; i++) {
        printf("Year: %s\n", range_of_years[i]);
    }

    return 0;
}