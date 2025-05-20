//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

// function to convert month from string to integer
int month_to_num(char *month) {
    char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i < 12; i++) {
        if (strcmp(month, months[i]) == 0) {
            return i + 1;
        }
    }
    return -1;
}

// function to convert integer month to string
char *num_to_month(int month) {
    char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months[month - 1];
}

// function to check if leap year
int is_leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    int year, month, day;

    printf("Welcome to Natural Language Date Converter\n\n");
    printf("Please enter the date in natural language format (e.g. January 1st, 2022): ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // remove newline character at end of input
    input[strcspn(input, "\n")] = 0;

    // parse input using %s and %d format specifiers
    sscanf(input, "%s %d, %d", input, &day, &year);

    // get month as integer
    month = month_to_num(input);

    if (month != -1) {
        // valid month
        if (day > 0 && day <= 31) {
            // valid day
            if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
                printf("Invalid date\n");
            } else if (month == 2) {
                if ((is_leap_year(year) && day > 29) || (!is_leap_year(year) && day > 28)) {
                    printf("Invalid date\n");
                } else {
                    printf("The date is %s %d, %d\n", num_to_month(month), day, year);
                }
            } else {
                printf("The date is %s %d, %d\n", num_to_month(month), day, year);
            }
        } else {
            printf("Invalid date\n");
        }
    } else {
        printf("Invalid date\n");
    }

    return 0;
}