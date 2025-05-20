//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100

struct Date {
    int day;
    int month;
    int year;
};

int get_month_number(const char *month) {
    if (strcmp(month, "January") == 0) return 1;
    else if (strcmp(month, "February") == 0) return 2;
    else if (strcmp(month, "March") == 0) return 3;
    else if (strcmp(month, "April") == 0) return 4;
    else if (strcmp(month, "May") == 0) return 5;
    else if (strcmp(month, "June") == 0) return 6;
    else if (strcmp(month, "July") == 0) return 7;
    else if (strcmp(month, "August") == 0) return 8;
    else if (strcmp(month, "September") == 0) return 9;
    else if (strcmp(month, "October") == 0) return 10;
    else if (strcmp(month, "November") == 0) return 11;
    else if (strcmp(month, "December") == 0) return 12;
    return 0; // Invalid month
}

struct Date parse_date(const char *input) {
    struct Date date = {0, 0, 0};
    char month[20];
    char temp[10];
    
    // Example input formats: "12th January 2023", "March 3rd, 2022", "2023-10-25".
    
    if (sscanf(input, "%d %s %d", &date.day, month, &date.year) == 3) {
        // Handling ordinal suffixes (th, rd, st, nd)
        if (date.day % 10 == 0) {
            snprintf(temp, 10, "%s", input);
            if (strstr(temp, "th")) {
                date.day -= 10; // Remove the threshold for th
            }
        } else if (date.day % 10 == 1) {
            snprintf(temp, 10, "%s", input);
            if (strstr(temp, "st")) {
                date.day -= 1; // Remove the threshold for st
            }
        } else if (date.day % 10 == 2) {
            snprintf(temp, 10, "%s", input);
            if (strstr(temp, "nd")) {
                date.day -= 2; // Remove the threshold for nd
            }
        } else if (date.day % 10 == 3) {
            snprintf(temp, 10, "%s", input);
            if (strstr(temp, "rd")) {
                date.day -= 3; // Remove the threshold for rd
            }
        }

        date.month = get_month_number(month);
        return date;
    } else if (sscanf(input, "%d-%d-%d", &date.year, &date.month, &date.day) == 3) {
        // Format: YYYY-MM-DD
        return date;
    } else {
        printf("Invalid date format.\n");
        date.year = date.month = date.day = -1; // Indicate error
        return date;
    }
}

void print_date(struct Date date) {
    if (date.year == -1) {
        printf("Error: Invalid date.\n");
        return;
    }
    
    printf("Converted Date: %02d/%02d/%04d\n", date.day, date.month, date.year);
}

int main() {
    char input[MAX_INPUT];
    struct Date date;
    
    printf("Natural Language Date Converter\n");
    printf("Enter a date (e.g., '12th January 2023' or '2023-10-25'): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline

    date = parse_date(input);
    print_date(date);

    return 0;
}