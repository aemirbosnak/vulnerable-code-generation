//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// month names for conversion
char *month_names[] = {
    "January", "February", "March", "April",
    "May", "June", "July", "August", 
    "September", "October", "November", "December"
};

// function to convert date from Natural Language to numerical format
void natural_to_numerical(char *date) {
    char *month_string; // to store month name string
    int month_index = -1; // to store month index
    int day, year; // to store day and year

    // parse date string for day, month and year values
    sscanf(date, "%d %s %d", &day, month_string, &year);

    // check for leap year
    int is_leap_year = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

    // match month name with month_names array to get index
    for (int i = 0; i < 12; i++) {
        if (strcmp(month_string, month_names[i]) == 0) {
            month_index = i;
            break;
        }
    }

    // print numerical date
    printf("%d-%02d-%02d\n", year, month_index + 1, day);
}

int main() {
    char date[50]; // to store natural language date

    // get natural language date from user
    printf("Enter natural language date (e.g. \"December 31, 2021\"): ");
    fgets(date, 50, stdin);

    // remove trailing newline character
    date[strcspn(date, "\n")] = 0;

    // convert natural language date to numerical date
    natural_to_numerical(date);

    return 0;
}