//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_DATE_LENGTH 50

struct tm get_date_from_string(char *date_string) {
    struct tm date = {0};
    char *month_string = NULL;
    char *day_string = NULL;
    char *year_string = NULL;

    // Extract month, day, and year from input string
    month_string = strtok(date_string, " ");
    day_string = strtok(NULL, " ");
    year_string = strtok(NULL, " ");

    // Validate input
    if (month_string == NULL || day_string == NULL || year_string == NULL) {
        printf("Invalid date format.\n");
        return date;
    }

    // Convert month, day, and year strings to integers
    date.tm_mon = atoi(month_string) - 1;
    date.tm_mday = atoi(day_string);
    date.tm_year = atoi(year_string) - 1900;

    // Check for leap year
    if (date.tm_year % 4 == 0 && (date.tm_year % 100!= 0 || date.tm_year % 400 == 0)) {
        date.tm_mon--;
    }

    return date;
}

char *get_date_string(struct tm date) {
    static char date_string[MAX_DATE_LENGTH];
    strftime(date_string, MAX_DATE_LENGTH, "%B %d, %Y", &date);
    return date_string;
}

int main() {
    char input_date[MAX_DATE_LENGTH];
    printf("Enter a date (MM/DD/YYYY): ");
    scanf("%s", input_date);

    struct tm date = get_date_from_string(input_date);
    if (date.tm_year == -1) {
        return 1;
    }

    char *output_date = get_date_string(date);
    printf("Date in natural language: %s\n", output_date);

    return 0;
}