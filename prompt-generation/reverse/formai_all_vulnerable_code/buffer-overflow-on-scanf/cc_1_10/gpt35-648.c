//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: minimalist
#include <stdio.h>

// Function to check if the given year is a leap year
int isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

// Function to get the number of days in the given month and year
int getDaysInMonth(int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    } else {
        return daysInMonth[month - 1];
    }
}

// Function to convert a date in natural language format to a YYYY-MM-DD format
void convertToDate(char* date) {
    // Array to hold the month names and their abbreviated forms
    char* monthNames[] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
    char* monthAbbreviations[] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
    
    int day, year;
    char monthAbbreviation[3];
    
    sscanf(date, "%d %s %d", &day, monthAbbreviation, &year);
    
    // Convert the month abbreviation to a numerical value using the monthNames and monthAbbreviations arrays
    int month;
    int i;
    for (i = 0; i < 12; i++) {
        if (strcmp(monthAbbreviation, monthNames[i]) == 0) {
            month = i + 1;
            break;
        } else if (strcmp(monthAbbreviation, monthAbbreviations[i]) == 0) {
            month = i + 1;
            break;
        }
    }
    
    // Get the number of days in the given month and year
    int daysInMonth = getDaysInMonth(month, year);
    
    // Print the date in YYYY-MM-DD format
    printf("%d-%02d-%02d", year, month, day);
}

int main() {
    char date[20];
    printf("Enter a date in natural language format (e.g. 23 jun 2019): ");
    scanf("%[^\n]", date);
    
    convertToDate(date);

    return 0;
}