//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define months
const char* Months[12] = {"January", "February", "March", "April", "May", "June", "July",
                        "August", "September", "October", "November", "December"};

// Define days of the month
const int DaysOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Define Leap Year function
int isLeapYear(int year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Define date conversion function
void convertDate(char* input_date) {
    // Get input values
    char month[4];
    int day, year;
    sscanf(input_date, "%s %d, %d", month, &day, &year);

    // Find corresponding month
    int month_num = 0;
    for (int i = 0; i < 12; i++) {
        if (strcmp(Months[i], month) == 0) {
            month_num = i + 1;
            break;
        }
    }

    // Ensure input date is valid
    if (month_num == 0) {
        printf("Invalid date format: %s\n", input_date);
        return;
    }
    if (day < 1 || day > DaysOfMonth[month_num - 1]) {
        printf("Invalid date format: %s\n", input_date);
        return;
    }
    if (month_num == 2 && isLeapYear(year) && day > 29) {
        printf("Invalid date format: %s\n", input_date);
        return;
    }

    // Print output date in natural language format
    printf("The date is ");
    if (month_num == 1) {
        printf("January ");
    } else if (month_num == 2) {
        printf("February ");
    } else if (month_num == 3) {
        printf("March ");
    } else if (month_num == 4) {
        printf("April ");
    } else if (month_num == 5) {
        printf("May ");
    } else if (month_num == 6) {
        printf("June ");
    } else if (month_num == 7) {
        printf("July ");
    } else if (month_num == 8) {
        printf("August ");
    } else if (month_num == 9) {
        printf("September ");
    } else if (month_num == 10) {
        printf("October ");
    } else if (month_num == 11) {
        printf("November ");
    } else if (month_num == 12) {
        printf("December ");
    }
    printf("%d, %d.\n", day, year);
}

// Main function to get user input and call conversion function
int main() {
    char input[20];
    printf("Enter a date in the format of Month Day, Year (ex. March 14, 2022): ");
    fgets(input, 20, stdin);
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0'; // Remove newline character if present
    }
    convertDate(input);
    return 0;
}