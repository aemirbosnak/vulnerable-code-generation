//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the day of the week
int calculate_day(int year, int month, int day) {
    int a, y, m;
    a = (14 - month) / 12;
    y = year - a;
    m = month + 12 * a - 2;
    return (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

// Function to convert date to string format
char* date_to_string(int year, int month, int day) {
    char* date_str = (char*) malloc(11 * sizeof(char));
    sprintf(date_str, "%04d-%02d-%02d", year, month, day);
    return date_str;
}

// Function to convert string format to date
void string_to_date(char* date_str, int* year, int* month, int* day) {
    *year = atoi(date_str);
    *month = atoi(date_str + 5);
    *day = atoi(date_str + 8);
}

// Function to add days to date
void add_days(int* year, int* month, int* day, int days) {
    int total_days, i;
    for (i = 0; i < days; i++) {
        total_days = calculate_day(*year, *month, *day);
        if ((*day == 31 && (*month == 4 || *month == 6 || *month == 9 || *month == 11))
            || (*day == 30 && *month == 2)) {
            *day = 1;
            *month += 1;
        } else if ((*day == 28 || *day == 29) && *month == 2) {
            if ((*year % 4 == 0 && *year % 100 != 0) || *year % 400 == 0) {
                *day += 1;
            } else {
                *day = 1;
                *month += 1;
            }
        } else {
            *day += 1;
        }
        if (*month == 13) {
            *month = 1;
            *year += 1;
        }
    }
}

int main() {
    // Get input from user
    printf("Enter a date (YYYY-MM-DD): ");
    char input_date_str[11];
    fgets(input_date_str, 11, stdin);
    input_date_str[strcspn(input_date_str, "\r\n")] = 0;

    // Convert input to date
    int year, month, day;
    string_to_date(input_date_str, &year, &month, &day);

    // Get number of days to add
    printf("Enter number of days to add: ");
    int days;
    scanf("%d", &days);

    // Add days to date
    add_days(&year, &month, &day, days);

    // Convert date to string and print result
    char* result_date_str = date_to_string(year, month, day);
    printf("Result: %s\n", result_date_str);

    // Free memory allocated for strings
    free(result_date_str);

    return 0;
}