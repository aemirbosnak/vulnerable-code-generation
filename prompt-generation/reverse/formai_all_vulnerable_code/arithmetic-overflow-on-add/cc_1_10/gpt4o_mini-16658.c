//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100
#define MAX_DATE 11 

typedef struct {
    int day;
    int month;
    int year;
    char monthName[20];
} Date;

const char *month_names[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

void extractDate(char *input, Date *date) {
    sscanf(input, "%d %s %d", &date->day, date->monthName, &date->year);
    
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(date->monthName, month_names[i]) == 0) {
            date->month = i + 1;
            return;
        }
    }
    date->month = 0; // Invalid month
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    switch (month) {
        case 1: return 31;
        case 2: return isLeapYear(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0; // Invalid month
    }
}

int isValidDate(Date *date) {
    if (date->month < 1 || date->month > 12 || date->day < 1) return 0;
    if (date->day > daysInMonth(date->month, date->year)) return 0;
    return 1;
}

void printDate(Date *date) {
    if (!isValidDate(date)) {
        printf("Invalid date: %d %s %d\n", date->day, date->monthName, date->year);
        return;
    }
    printf("Converted date: %02d-%02d-%04d\n", date->day, date->month, date->year);
}

void getCurrentDate() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    Date currentDate;
    currentDate.day = tm.tm_mday;
    currentDate.month = tm.tm_mon + 1;
    currentDate.year = tm.tm_year + 1900;
    
    printf("Current date is: %02d-%02d-%04d\n", currentDate.day, currentDate.month, currentDate.year);
}

int main() {
    char input[MAX_INPUT];
    Date date;

    printf("Welcome to the Cryptic Date Converter!\n");

    getCurrentDate();
    
    printf("\nEnter the date in the format 'DD Month YYYY' (e.g., '25 December 2023'): ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character
    
    extractDate(input, &date);
    
    printDate(&date);
    
    return 0;
}