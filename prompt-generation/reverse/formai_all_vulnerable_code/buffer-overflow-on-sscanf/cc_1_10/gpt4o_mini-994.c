//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 100

const char *months[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

int get_month_index(const char *month) {
    for(int i = 0; i < 12; i++) {
        if (strcasecmp(months[i], month) == 0) {
            return i + 1; // returning month as 1-12
        }
    }
    return -1; // month not found
}

int main() {
    char input[MAX_INPUT_SIZE];
    int day, year, month;
    
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date in the format 'Month Day, Year' (e.g., 'January 1, 2022'): \n");
    
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    // Example input: "January 1, 2022"
    char month_str[20];
    if (sscanf(input, "%s %d, %d", month_str, &day, &year) != 3) {
        fprintf(stderr, "Invalid date format. Please try again.\n");
        return 1;
    }
    
    month = get_month_index(month_str);
    if (month == -1) {
        fprintf(stderr, "Invalid month name. Please try again.\n");
        return 1;
    }
    
    // Validate day
    if (day < 1 || day > 31) {
        fprintf(stderr, "Invalid day. Please try again.\n");
        return 1;
    }

    // Validate year
    if (year < 1900) {
        fprintf(stderr, "Year must be 1900 or later.\n");
        return 1;
    }

    // Convert to YYYY-MM-DD format and print
    char output[11]; // YYYY-MM-DD format
    snprintf(output, sizeof(output), "%04d-%02d-%02d", year, month, day);
    printf("Converted Date: %s\n", output);

    // Calculate day of the week
    struct tm time_info = {0};
    time_info.tm_year = year - 1900; // tm_year is years since 1900
    time_info.tm_mon = month - 1;     // tm_mon is 0-11
    time_info.tm_mday = day;

    mktime(&time_info); // Normalize the time structure
    char *weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    printf("Day of the week: %s\n", weekdays[time_info.tm_wday]);

    return 0;
}