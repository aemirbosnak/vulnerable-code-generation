//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: single-threaded
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    }
    else if (year % 100 == 0) {
        return false;
    }
    else if (year % 4 == 0) {
        return true;
    }
    return false;
}

int monthDays(int month, int year) {
    switch (month) {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;
        case 2:
            if (isLeapYear(year)) {
                return 29;
            }
            else {
                return 28;
            }
            break;
        default:
            return 31;
            break;
    }
}

void convertToNaturalLanguageDate(int day, int month, int year) {
    // Convert month number to month name
    char monthName[10];
    switch (month) {
        case 1:
            strcpy(monthName, "January");
            break;
        case 2:
            strcpy(monthName, "February");
            break;
        case 3:
            strcpy(monthName, "March");
            break;
        case 4:
            strcpy(monthName, "April");
            break;
        case 5:
            strcpy(monthName, "May");
            break;
        case 6:
            strcpy(monthName, "June");
            break;
        case 7:
            strcpy(monthName, "July");
            break;
        case 8:
            strcpy(monthName, "August");
            break;
        case 9:
            strcpy(monthName, "September");
            break;
        case 10:
            strcpy(monthName, "October");
            break;
        case 11:
            strcpy(monthName, "November");
            break;
        case 12:
            strcpy(monthName, "December");
            break;
    }
    
    // Print natural language date
    printf("%s %d, %d\n", monthName, day, year);
}

int main() {
    int day, month, year;
    printf("Enter date in dd/mm/yyyy format: ");
    scanf("%d/%d/%d", &day, &month, &year);
    
    // Check for valid date
    if (month < 1 || month > 12) {
        printf("Invalid date!\n");
        return 0;
    }
    if (day < 1 || day > monthDays(month, year)) {
        printf("Invalid date!\n");
        return 0;
    }
    
    // Convert to natural language date
    convertToNaturalLanguageDate(day, month, year);
    
    return 0;
}