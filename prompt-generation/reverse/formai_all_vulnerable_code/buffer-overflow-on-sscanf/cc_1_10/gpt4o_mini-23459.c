//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LENGTH 100

// Function to map month names to their respective numbers
int getMonthNumber(char* month) {
    char* months[] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };
    
    for(int i = 0; i < 12; i++) {
        if (strcasecmp(months[i], month) == 0) {
            return i + 1; // Months are 1-indexed
        }
    }
    return 0; // Invalid month
}

// Converts natural language date input to struct tm
struct tm parseNaturalLanguageDate(char* input) {
    struct tm date = {0};
    char month[20];
    int day, year;

    // Scan for day, month, and year in the input string
    if (sscanf(input, "%d %19s %d", &day, month, &year) == 3) {
        date.tm_mday = day;
        date.tm_mon = getMonthNumber(month) - 1; // Convert to 0-indexed
        date.tm_year = year - 1900; // Adjust for tm struct year
    } else {
        // Invalid format handling
        fprintf(stderr, "Invalid date format. Please use 'DD Month YYYY'.\n");
        exit(1);
    }

    return date;
}

// Function to display the date in a more user-friendly format
void displayFormattedDate(struct tm date) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", &date); // Format using strftime
    printf("Converted Date: %s\n", buffer);
}

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter a date (e.g., '25 December 2023'): ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    // Parse the natural language date
    struct tm date = parseNaturalLanguageDate(input);

    // Check for validity of the date
    if (mktime(&date) == -1) {
        fprintf(stderr, "Invalid date. Please check your input.\n");
        return 1;
    }

    // Display the formatted date
    displayFormattedDate(date);

    return 0;
}