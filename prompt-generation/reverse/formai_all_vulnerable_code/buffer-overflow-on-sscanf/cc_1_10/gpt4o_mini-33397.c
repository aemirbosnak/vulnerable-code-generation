//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_INPUT_LENGTH 256

int monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
char *monthNames[] = { 
    "January", "February", "March", "April", "May", "June", 
    "July", "August", "September", "October", "November", "December" 
};

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int findMonthIndex(const char *month) {
    for (int i = 0; i < 12; i++) {
        if (strcmp(monthNames[i], month) == 0) {
            return i + 1; // return month index (1-12)
        }
    }
    return -1; // month not found
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void validateDate(int year, int month, int day) {
    if (month < 1 || month > 12) {
        printf("Invalid month: %d\n", month);
        exit(1);
    }
    int daysInMonth = monthDays[month - 1];
    if (month == 2 && isLeapYear(year)) {
        daysInMonth++;
    }
    if (day < 1 || day > daysInMonth) {
        printf("Invalid day: %d for month: %d\n", day, month);
        exit(1);
    }
}

void naturalLanguageDateConverter(char *input) {
    int year = 0, month = 0, day = 0;
    char monthStr[20];
    
    sscanf(input, "%d %s %d", &day, monthStr, &year);
    toLowerCase(monthStr);
    
    month = findMonthIndex(monthStr);
    
    validateDate(year, month, day);
    
    printf("Converted Date: %04d-%02d-%02d\n", year, month, day);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date in the format 'day month year' (e.g. 12 January 2023):\n");
    
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // Remove the newline character
    
    naturalLanguageDateConverter(input);
    
    return 0;
}