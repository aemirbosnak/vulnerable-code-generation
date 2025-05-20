//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 11

// Function to check if a given string is valid date
int is_valid_date(char *date) {
    int day, month, year;
    sscanf(date, "%d-%d-%d", &day, &month, &year);

    if (day < 1 || day > 31) return 0;
    if (month < 1 || month > 12) return 0;

    int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 31, 31};

    if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
        days_in_month[month] = 29;

    if (day > days_in_month[month]) return 0;

    return 1;
}

// Function to convert a given date from "dd-mm-yyyy" to "yyyy-mm-dd"
void convert_date(char *date_in, char *date_out) {
    int day, month, year;
    sscanf(date_in, "%d-%d-%d", &day, &month, &year);

    sprintf(date_out, "%d-%02d-%02d", year, month, day);
}

int main() {
    char date_in[MAX_SIZE], date_out[MAX_SIZE];

    printf("Enter a date in the format dd-mm-yyyy: ");
    scanf("%s", date_in);

    // Check if the given date is valid
    if (!is_valid_date(date_in)) {
        printf("Invalid date!\n");
        return 1;
    }

    // Convert the date to the desired format
    convert_date(date_in, date_out);

    printf("The date %s in the format yyyy-mm-dd is: %s\n", date_in, date_out);

    return 0;
}