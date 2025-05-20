//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool is_leap_year(int year) {
    if (year % 400 == 0) {
        return true;
    } else if (year % 100 == 0) {
        return false;
    } else if (year % 4 == 0) {
        return true;
    } else {
        return false;
    }
}

int days_in_month(int month, int year) {
    switch(month) {
        case 2:
            if (is_leap_year(year)) {
                return 29;
            } else {
                return 28;
            }
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

void print_date(int day, int month, int year) {
    char *date_str;
    date_str = malloc(sizeof(char) * 11);

    sprintf(date_str, "%02d/%02d/%04d", day, month, year);
    printf("%s\n", date_str);

    free(date_str);
}

void date_converter(char *date_str) {
    int day, month, year;
    char *day_str, *month_str, *year_str;
    day_str = malloc(sizeof(char) * 3);
    month_str = malloc(sizeof(char) * 3);
    year_str = malloc(sizeof(char) * 5);

    strncpy(day_str, date_str, 2);
    day_str[2] = '\0';
    strncpy(month_str, date_str + 3, 2);
    month_str[2] = '\0';    
    strncpy(year_str, date_str + 6, 4);
    year_str[4] = '\0';

    day = atoi(day_str);
    month = atoi(month_str);
    year = atoi(year_str);

    free(day_str);
    free(month_str);
    free(year_str);

    if (day <= 0 || month <= 0 || month > 12 || year <= 0) {
        printf("Invalid date entered.\n");
        return;
    }

    int days_in_month_max = days_in_month(month, year);
    if (day > days_in_month_max) {
        printf("Invalid date entered.\n");
        return;
    }

    printf("Converted date: ");
    print_date(day, month, year);
}

int main() {
    char date_str[11];
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", date_str);
    date_converter(date_str);

    return 0;
}