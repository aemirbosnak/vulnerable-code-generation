//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to get the number of days in a month
int daysInMonth(int month, int year) {
    if (month == 2) {
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
    }
    return (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
}

// Function to convert a natural language date to structured data
void convertDate(const char *naturalDate, int *day, int *month, int *year) {
    sscanf(naturalDate, "%d %d %d", day, month, year);
}

// Function to validate if the date is correct
int validateDate(int day, int month, int year) {
    if (year < 1900 || year > 2100 || month < 1 || month > 12) {
        return 0; // Invalid year or month
    }
    if (day < 1 || day > daysInMonth(month, year)) {
        return 0; // Invalid day
    }
    return 1; // Valid date
}

// Function to print the formatted date
void printFormattedDate(int day, int month, int year) {
    const char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    
    printf("You have entered the date: %d %s %d\n", day, months[month - 1], year);
}

// Main function
int main() {
    char naturalDate[50];
    int day, month, year;

    // An artistic introduction
    printf("***************************************\n");
    printf("*  Welcome to the Natural Language    *\n");
    printf("*         Date Converter!             *\n");
    printf("***************************************\n");

    // Input from the user
    printf("Please enter a date in the format 'DD MM YYYY': ");
    fgets(naturalDate, sizeof(naturalDate), stdin);
    naturalDate[strcspn(naturalDate, "\n")] = 0; // Remove newline character

    // Convert the natural language date
    convertDate(naturalDate, &day, &month, &year);

    // Validate the date
    if (validateDate(day, month, year)) {
        printFormattedDate(day, month, year);
        
        // Generate a structured date
        struct tm date = {0};
        date.tm_mday = day;
        date.tm_mon = month - 1; // tm_mon is 0-based
        date.tm_year = year - 1900; // tm_year is years since 1900

        // Calculate the day of the week
        mktime(&date);
        const char *daysOfWeek[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
        printf("This date falls on a: %s\n", daysOfWeek[date.tm_wday]);
    } else {
        printf("Oops! The date you entered is invalid. Please try again.\n");
    }

    // Artistic Exit
    printf("***************************************\n");
    printf("*  Thank you for using the converter! *\n");
    printf("***************************************\n");

    return 0;
}