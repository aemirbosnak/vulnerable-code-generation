//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define NUM_MONTHS 12

// Function to check if a string is a valid date
int is_valid_date(char* date_str) {
    struct tm tm;
    strptime(date_str, "%Y-%m-%d", &tm);
    return (tm.tm_year + 1900) > 0 && tm.tm_mon >= 0 && tm.tm_mon < NUM_MONTHS && tm.tm_mday > 0;
}

// Function to convert a month number to its string representation
char* month_to_string(int month) {
    static char months[NUM_MONTHS][MAX_WORD_LENGTH] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months[month];
}

// Function to convert a day of the week number to its string representation
char* day_of_week_to_string(int day_of_week) {
    static char days_of_week[7][MAX_WORD_LENGTH] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return days_of_week[day_of_week];
}

// Function to print the date in natural language format
void print_date(char* date_str) {
    struct tm tm;
    strptime(date_str, "%Y-%m-%d", &tm);
    int month = tm.tm_mon + 1;
    int day = tm.tm_mday;
    int year = tm.tm_year + 1900;
    int day_of_week = tm.tm_wday;
    printf("Today is %s, %d %s %d\n", day_of_week_to_string(day_of_week), day, month_to_string(month), year);
}

int main() {
    char date_str[MAX_WORD_LENGTH];
    printf("Enter a date in YYYY-MM-DD format: ");
    scanf("%s", date_str);
    if (is_valid_date(date_str)) {
        print_date(date_str);
    } else {
        printf("Invalid date\n");
    }
    return 0;
}