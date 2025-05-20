//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE_LENGTH 11
#define MAX_MONTH_LENGTH 10
#define MAX_YEAR_LENGTH 5

const char *months[] = {
    "January", "February", "March", "April",
    "May", "June", "July", "August",
    "September", "October", "November", "December"
};

int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

typedef struct {
    int day;
    int month;
    int year;
} Date;

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void input_date(char *date_string) {
    printf("Enter a date in the format DD-MM-YYYY: ");
    fgets(date_string, MAX_DATE_LENGTH, stdin);
    date_string[strcspn(date_string, "\n")] = 0;  // Remove newline character
}

int validate_date(const char *date_string, Date *date) {
    return sscanf(date_string, "%d-%d-%d", &date->day, &date->month, &date->year) == 3 &&
           date->month >= 1 && date->month <= 12 &&
           date->day >= 1 && date->day <= (days_in_month[date->month - 1] + (date->month == 2 && is_leap_year(date->year) ? 1 : 0));
}

void convert_date(const Date *date, char *date_output) {
    sprintf(date_output, "%s %d, %d", months[date->month - 1], date->day, date->year);
}

int main() {
    char date_string[MAX_DATE_LENGTH];
    Date date;
    char date_output[50];

    input_date(date_string);
    
    if (validate_date(date_string, &date)) {
        convert_date(&date, date_output);
        printf("Converted date: %s\n", date_output);
    } else {
        printf("Invalid date entered. Please use the format DD-MM-YYYY.\n");
    }

    return 0;
}