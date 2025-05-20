//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_DATE_LENGTH 20
#define MAX_MONTH_LENGTH 10
#define MAX_YEAR_LENGTH 4

typedef struct {
    char month[MAX_MONTH_LENGTH];
    int day;
    int year;
} date_t;

char* get_month_name(int month) {
    static char month_names[12][MAX_MONTH_LENGTH] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    return month_names[month];
}

int is_valid_date(int day, int month, int year) {
    if (month < 1 || month > 12) {
        return 0;
    }
    if (day < 1 || day > 31) {
        return 0;
    }
    if (month == 2) {
        if (day > 29 &&!((year % 4 == 0 && year % 100!= 0) || year % 400 == 0)) {
            return 0;
        }
    }
    return 1;
}

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100!= 0) || year % 400 == 0;
}

void print_date(date_t* date) {
    char month_name[MAX_MONTH_LENGTH];
    strcpy(month_name, get_month_name(date->month));
    printf("%s %d, %d\n", month_name, date->day, date->year);
}

int main() {
    date_t date;
    char input_date[MAX_DATE_LENGTH];
    int day, month, year;

    printf("Enter a date in the format 'Month Day, Year':\n");
    scanf("%s", input_date);

    // Parse the input date
    sscanf(input_date, "%d %s, %d", &day, date.month, &year);

    // Convert the month name to a number
    for (month = 1; month <= 12; month++) {
        if (strcmp(date.month, get_month_name(month)) == 0) {
            break;
        }
    }

    // Check if the date is valid
    if (!is_valid_date(day, month, year)) {
        printf("Invalid date.\n");
        return 1;
    }

    // Print the date in a natural language format
    print_date(&date);

    return 0;
}