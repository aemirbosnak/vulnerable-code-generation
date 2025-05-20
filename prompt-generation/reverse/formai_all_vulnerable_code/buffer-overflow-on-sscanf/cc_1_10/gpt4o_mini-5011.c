//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function declarations
void convert_date(const char *input);
int month_to_number(const char *month_name);
const char *day_suffix(int day);

int main() {
    char input[100];
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Enter a date in natural language format (e.g., '12th of April 2023'): \n");

    while (1) {
        printf("\n> ");
        fgets(input, sizeof(input), stdin);

        // Remove trailing newline character
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        if (strcmp(input, "exit") == 0) {
            printf("Exiting the Natural Language Date Converter. Goodbye!\n");
            break;
        }

        convert_date(input);
    }
    
    return 0;
}

void convert_date(const char *input) {
    int day, year;
    char month_name[20];

    // Initialize month_name
    memset(month_name, 0, sizeof(month_name));

    // Using sscanf to parse the date
    if (sscanf(input, "%d%s%d", &day, month_name, &year) == 3) {
        int month = month_to_number(month_name);
        if (month == -1) {
            printf("Invalid month name: %s\n", month_name);
            return;
        }

        printf("Converted date: %04d-%02d-%02d\n", year, month, day);
    } else {
        printf("Invalid input format. Please try again.\n");
    }
}

int month_to_number(const char *month_name) {
    if (strcasecmp(month_name, "January") == 0 || strcasecmp(month_name, "Jan") == 0) return 1;
    if (strcasecmp(month_name, "February") == 0 || strcasecmp(month_name, "Feb") == 0) return 2;
    if (strcasecmp(month_name, "March") == 0 || strcasecmp(month_name, "Mar") == 0) return 3;
    if (strcasecmp(month_name, "April") == 0 || strcasecmp(month_name, "Apr") == 0) return 4;
    if (strcasecmp(month_name, "May") == 0) return 5;
    if (strcasecmp(month_name, "June") == 0 || strcasecmp(month_name, "Jun") == 0) return 6;
    if (strcasecmp(month_name, "July") == 0 || strcasecmp(month_name, "Jul") == 0) return 7;
    if (strcasecmp(month_name, "August") == 0 || strcasecmp(month_name, "Aug") == 0) return 8;
    if (strcasecmp(month_name, "September") == 0 || strcasecmp(month_name, "Sep") == 0) return 9;
    if (strcasecmp(month_name, "October") == 0 || strcasecmp(month_name, "Oct") == 0) return 10;
    if (strcasecmp(month_name, "November") == 0 || strcasecmp(month_name, "Nov") == 0) return 11;
    if (strcasecmp(month_name, "December") == 0 || strcasecmp(month_name, "Dec") == 0) return 12;

    return -1; // Invalid month
}

const char *day_suffix(int day) {
    if (day % 10 == 1 && day != 11) {
        return "st";
    } else if (day % 10 == 2 && day != 12) {
        return "nd";
    } else if (day % 10 == 3 && day != 13) {
        return "rd";
    } else {
        return "th";
    }
}