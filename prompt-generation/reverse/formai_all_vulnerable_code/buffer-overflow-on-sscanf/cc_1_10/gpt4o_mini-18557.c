//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_INPUT 256
#define MAX_MONTH_LENGTH 12
#define MAX_DATE_LENGTH 10

const char* months[] = { 
    "January", "February", "March", "April", "May", "June", 
    "July", "August", "September", "October", "November", "December" 
};

int monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
char input[MAX_INPUT];

void print_intro() {
    printf("**************************************\n");
    printf("*          Natural Language Date     *\n");
    printf("*          Converter Program         *\n");
    printf("**************************************\n\n");
}

void normalize_date(char *input, int *day, int *month, int *year) {
    sscanf(input, "%d %s %d", day, input, year);
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(input, months[i]) == 0) {
            *month = i + 1;
            return;
        }
    }
    *month = 0; // Not found
}

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int is_valid_date(int day, int month, int year) {
    if (month < 1 || month > 12) return 0;
    if (is_leap_year(year) && month == 2) {
        return (day >= 1 && day <= 29);
    }
    return (day >= 1 && day <= monthDays[month - 1]);
}

void convert_to_iso_date(int day, int month, int year) {
    printf("Converted Date: %04d-%02d-%02d\n", year, month, day);
}

void prompt_user() {
    printf("Enter a date (e.g., '12 February 2023'): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character
}

int main() {
    print_intro();
    int day, month, year;
    
    while (1) {
        prompt_user();
        if (strcmp(input, "exit") == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
        normalize_date(input, &day, &month, &year);
        
        if (is_valid_date(day, month, year)) {
            convert_to_iso_date(day, month, year);
        } else {
            printf("Error: Invalid date! Please try again.\n");
        }
    }
    
    return 0;
}