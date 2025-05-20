//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER 256

// Function prototypes
void convertDateToNaturalLanguage(char* inputDate);
void parseDate(const char* dateString, int* day, int* month, int* year);
const char* getMonthName(int month);
const char* getOrdinalSuffix(int day);
void printDateInNaturalLanguage(int day, int month, int year);

int main() {
    char inputDate[MAX_BUFFER];
    
    printf("Welcome to the C Natural Language Date Converter!\n");
    printf("Please enter a date in the format DD/MM/YYYY:\n");
    
    // Read the user input
    fgets(inputDate, sizeof(inputDate), stdin);
    // Remove newline character from input
    inputDate[strcspn(inputDate, "\n")] = 0;

    // Convert the entered date to natural language
    convertDateToNaturalLanguage(inputDate);
    
    return 0;
}

void convertDateToNaturalLanguage(char* inputDate) {
    int day, month, year;
    
    // Parse the input date
    parseDate(inputDate, &day, &month, &year);
    
    // Print the result in natural language form
    printDateInNaturalLanguage(day, month, year);
}

void parseDate(const char* dateString, int* day, int* month, int* year) {
    if (sscanf(dateString, "%d/%d/%d", day, month, year) != 3) {
        fprintf(stderr, "Error: Invalid date format. Please use DD/MM/YYYY.\n");
        exit(EXIT_FAILURE);
    }
}

const char* getMonthName(int month) {
    const char* monthNames[] = {
        "Invalid Month", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    
    if (month >= 1 && month <= 12) {
        return monthNames[month];
    }
    
    return monthNames[0];
}

const char* getOrdinalSuffix(int day) {
    if (day % 10 == 1 && day % 100 != 11) {
        return "st";
    } else if (day % 10 == 2 && day % 100 != 12) {
        return "nd";
    } else if (day % 10 == 3 && day % 100 != 13) {
        return "rd";
    } else {
        return "th";
    }
}

void printDateInNaturalLanguage(int day, int month, int year) {
    const char* monthName = getMonthName(month);
    const char* ordinalSuffix = getOrdinalSuffix(day);
    
    // Checking if the date is valid
    if (month < 1 || month > 12 || day < 1 || day > 31 ||
        (month == 2 && day > 29) ||
        ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
        printf("Error: The date you entered does not exist. Please try again.\n");
        return;
    }
    
    printf("The date you entered is: %s the %d%s of %s, %d.\n", 
           monthName, day, ordinalSuffix, monthName, year);
}