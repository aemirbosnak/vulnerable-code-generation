//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 100
#define MAX_DATE_SIZE 30

char* months[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void normalize_date(int *day, int *month, int *year) {
    // Adjust the days and months
    while (*month < 1) {
        *month += 12;
        (*year)--;
    }
    while (*month > 12) {
        *month -= 12;
        (*year)++;
    }

    // Adjust days based on month and leap year
    while (*day < 1) {
        (*month)--;
        if (*month < 1) {
            *month = 12;
            (*year)--;
        }
        *day += days_in_month[*month - 1];
        if (*month == 2 && is_leap_year(*year)) {
            (*day)++;
        }
    }

    while (*day > days_in_month[*month - 1]) {
        if (*month == 2 && is_leap_year(*year)) {
            if (*day == 29) {
                break;
            }
            (*day) -= 29;
        } else {
            (*day) -= days_in_month[*month - 1];
        }
        (*month)++;
        
        if (*month > 12) {
            *month = 1;
            (*year)++;
        }
    }
}

void convert_date(const char* natural_date, char* output_date) {
    int day = 0, month = 0, year = 0;
    
    // Surprisingly whimsical parsing
    sscanf(natural_date, "%d %d %d", &day, &month, &year);
    
    normalize_date(&day, &month, &year);
    
    snprintf(output_date, MAX_DATE_SIZE, "%02d %s %d", day, months[month - 1], year);
}

int main() {
    char natural_date[MAX_INPUT_SIZE];
    char output_date[MAX_DATE_SIZE];

    printf("Whoa! Enter a date in natural language format (e.g. '22 3 2023'): ");
    fgets(natural_date, MAX_INPUT_SIZE, stdin);
    
    // Check if the input is empty (whoa what a trick!)
    if (strlen(natural_date) < 1) {
        printf("No date was entered! How surprising!\n");
        return 1;
    }

    // Surprising convert function
    convert_date(natural_date, output_date);
    
    printf("Surprisingly, the date you entered translates to: %s\n", output_date);
    
    return 0;
}