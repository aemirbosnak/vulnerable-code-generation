//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Dennis Ritchie
#include <stdio.h>

// Function to calculate the number of days in a given month
int getDaysInMonth(int month, int year) {
    switch(month) {
        case 2: // February
            if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) { // Leap Year
                return 29;
            } else {
                return 28;
            }
            break;
        case 4: // April
        case 6: // June
        case 9: // September
        case 11: // November
            return 30;
            break;
        default: // All other months
            return 31;
            break;
    }
}

// Function to convert a natural language date to a date string in the format "MM/DD/YYYY"
void convertNLDate(char* nlDate, char* date) {
    int day, month, year;
    sscanf(nlDate, "%d %*s %d %*s %d", &day, &month, &year); // Parse the day, month, and year from the natural language input string

    // Check if the day is valid for the given month and year
    if(day < 1 || day > getDaysInMonth(month, year)) {
        printf("ERROR: Invalid day for the given month and year!\n");
        return;
    }

    sprintf(date, "%02d/%02d/%04d", month, day, year); // Create the date string in the desired format
}

// Main function
int main() {
    char nlDate[20];
    char date[11];

    printf("Enter a natural language date (e.g. \"January 1, 2022\"):\n");
    fgets(nlDate, sizeof(nlDate), stdin); // Read the natural language input string from the user
    nlDate[strlen(nlDate)-1] = '\0'; // Remove the newline character at the end of the string

    convertNLDate(nlDate, date); // Convert the natural language date to a date string

    printf("Date in \"MM/DD/YYYY\" format: %s\n", date); // Output the date string in the desired format

    return 0;
}