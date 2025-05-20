//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: portable
/* 
 * Date Converter Program in C
 * Converts natural language dates to machine-readable format
 * Written by [Your Name], [Your Email]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 50

// Function to convert month name to its numerical representation
int month_to_number(char *month) {
    char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int i;
    for (i = 0; i < 12; i++) {
        if (strcmp(month, months[i]) == 0) {
            return i + 1;
        }
    }
    return -1; // Invalid month name
}

// Function to convert machine-readable date to natural language format
void number_to_month(int month, char *buffer) {
    char *months[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    strcpy(buffer, months[month]);
}

// Function to convert natural language date to machine-readable format
void convert_date(char *input, char *output) {
    int day, month, year;
    char month_name[4];
    sscanf(input, "%d %s %d", &day, month_name, &year);
    month = month_to_number(month_name);
    if (month == -1) {
        // Invalid month name
        sprintf(output, "Invalid month name: %s", month_name);
        return;
    }
    sprintf(output, "%d-%02d-%02d", year, month, day);
}

int main() {
    char input[MAX_INPUT];
    char output[MAX_INPUT];
    printf("Enter a natural language date (e.g. 1 Jan 2022): ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character
    convert_date(input, output);
    printf("Machine-readable format: %s\n", output);
    return 0;
}