//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void parse_date(const char *input, int *day, int *month, int *year) {
    char month_str[20];
    sscanf(input, "%d %s %d", day, month_str, year);
    
    // Month conversion
    if (strcmp(month_str, "January") == 0) *month = 1;
    else if (strcmp(month_str, "February") == 0) *month = 2;
    else if (strcmp(month_str, "March") == 0) *month = 3;
    else if (strcmp(month_str, "April") == 0) *month = 4;
    else if (strcmp(month_str, "May") == 0) *month = 5;
    else if (strcmp(month_str, "June") == 0) *month = 6;
    else if (strcmp(month_str, "July") == 0) *month = 7;
    else if (strcmp(month_str, "August") == 0) *month = 8;
    else if (strcmp(month_str, "September") == 0) *month = 9;
    else if (strcmp(month_str, "October") == 0) *month = 10;
    else if (strcmp(month_str, "November") == 0) *month = 11;
    else if (strcmp(month_str, "December") == 0) *month = 12;
    else *month = -1; // Invalid month
}

void print_date(int day, int month, int year) {
    if (month < 1 || month > 12) {
        printf("Invalid month provided!\n");
        return;
    }
    printf("Converted Date: %04d-%02d-%02d\n", year, month, day);
}

int main() {
    char input[100];
    int day, month, year;

    printf("Enter a date (e.g., '15 April 2023'): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    parse_date(input, &day, &month, &year);

    if (day < 1 || day > 31 || year < 0) {
        printf("Invalid date input!\n");
    } else {
        print_date(day, month, year);
    }

    return 0;
}