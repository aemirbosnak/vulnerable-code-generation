//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_LENGTH 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int day;
    int month;
    int year;
} Date;

// Function declarations
void print_menu();
void process_input(char *input);
void convert_to_date(const char *date_string, Date *date);
int is_valid_date(Date date);
void print_date(Date date);

int main() {
    char input[MAX_DATE_LENGTH];
    
    printf("Welcome to the Natural Language Date Converter!\n");
    print_menu();
    
    while (1) {
        printf("Please enter a date (or type 'exit' to quit): ");
        fgets(input, MAX_DATE_LENGTH, stdin);
        
        // Remove trailing newline character
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            printf("Exiting program. Goodbye!\n");
            break;
        }

        process_input(input);
    }
    
    return 0;
}

void print_menu() {
    printf("Available commands:\n");
    printf(" - January 1, 2023\n");
    printf(" - 13th of March, 1985\n");
    printf(" - 4/7/2021\n");
    printf("Type 'exit' to quit.\n");
}

void process_input(char *input) {
    Date date;
    convert_to_date(input, &date);
    if (is_valid_date(date)) {
        print_date(date);
    } else {
        printf("The entered date is invalid.\n");
    }
}

void convert_to_date(const char *date_string, Date *date) {
    char month_str[MAX_NAME_LENGTH];
    int day = 0, year = 0, month = 0;

    // Scan for different date formats
    if (sscanf(date_string, "%d/%d/%d", &month, &day, &year) == 3) {
        date->day = day;
        date->month = month;
        date->year = year;
    } else if (sscanf(date_string, "%d-%d-%d", &year, &month, &day) == 3) {
        date->day = day;
        date->month = month;
        date->year = year;
    } else if (sscanf(date_string, "%s %d, %d", month_str, &day, &year) == 3) {
        // Convert month name to month number
        if (strcmp(month_str, "January") == 0) month = 1;
        else if (strcmp(month_str, "February") == 0) month = 2;
        else if (strcmp(month_str, "March") == 0) month = 3;
        else if (strcmp(month_str, "April") == 0) month = 4;
        else if (strcmp(month_str, "May") == 0) month = 5;
        else if (strcmp(month_str, "June") == 0) month = 6;
        else if (strcmp(month_str, "July") == 0) month = 7;
        else if (strcmp(month_str, "August") == 0) month = 8;
        else if (strcmp(month_str, "September") == 0) month = 9;
        else if (strcmp(month_str, "October") == 0) month = 10;
        else if (strcmp(month_str, "November") == 0) month = 11;
        else if (strcmp(month_str, "December") == 0) month = 12;
        
        date->day = day;
        date->month = month;
        date->year = year;
    }
}

int is_valid_date(Date date) {
    if (date.year < 1 || date.month < 1 || date.month > 12 || date.day < 1) {
        return 0; // Invalid year, month, or day
    }

    // Array of month days
    int month_days[] = {31, 28 + (date.year % 4 == 0 && (date.year % 100 != 0 || date.year % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (date.day > month_days[date.month - 1]) {
        return 0; // Invalid day for the given month
    }

    return 1; // Valid date
}

void print_date(Date date) {
    const char *months[] = { "January", "February", "March", "April", "May", "June", 
                             "July", "August", "September", "October", "November", "December" };
                             
    printf("The entered date is: %d %s, %d\n", date.day, months[date.month - 1], date.year);
}