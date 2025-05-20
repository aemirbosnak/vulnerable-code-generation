//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_leap_year(int year);
int days_in_month(int month, int year);
void convert_date(char *input_date);
int is_valid_date(char *input_date);

int main() {
    char input_date[11];

    printf("Enter a date in the format dd/mm/yyyy: ");
    fgets(input_date, 11, stdin);

    // Remove the newline character from the end of the input
    input_date[strcspn(input_date, "\n")] = '\0';

    if (is_valid_date(input_date)) {
        convert_date(input_date);
    } else {
        printf("Invalid input: %s\n", input_date);
    }

    return 0;
}

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

int days_in_month(int month, int year) {
    int days;

    switch (month) {
        case 1: days = 31; break;
        case 2: days = is_leap_year(year) ? 29 : 28; break;
        case 3: days = 31; break;
        case 4: days = 30; break;
        case 5: days = 31; break;
        case 6: days = 30; break;
        case 7: days = 31; break;
        case 8: days = 31; break;
        case 9: days = 30; break;
        case 10: days = 31; break;
        case 11: days = 30; break;
        case 12: days = 31; break;
        default: days = -1; break;
    }

    return days;
}

int is_valid_date(char *input_date) {
    int day, month, year;
    char separator;

    // Check the length of the input string
    if (strlen(input_date) != 10) {
        return 0;
    }

    // Check that the day, month, and year are integers
    if (sscanf(input_date, "%d/%d/%d%c", &day, &month, &year, &separator) != 4) {
        return 0;
    }

    // Check that the separator is a forward slash
    if (separator != '/') {
        return 0;
    }

    // Check that the month, day, and year are within valid ranges
    if (month < 1 || month > 12) {
        return 0;
    }

    if (day < 1 || day > days_in_month(month, year)) {
        return 0;
    }

    if (year < 1) {
        return 0;
    }

    return 1;
}

void convert_date(char *input_date) {
    int day, month, year, days_since_1_1_0001, julian_day, i;
    char month_name[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    // Extract the day, month, and year from the input string
    sscanf(input_date, "%d/%d/%d", &day, &month, &year);

    // Calculate the number of days since January 1, 0001
    days_since_1_1_0001 = (year - 1) * 365 + (year - 1) / 4
        - (year - 1) / 100 + (year - 1) / 400;

    for (i = 1; i < month; i++) {
        days_since_1_1_0001 += days_in_month(i, year);
    }

    days_since_1_1_0001 += day;

    // Convert to Julian day
    julian_day = days_since_1_1_0001 + 1721425;

    // Print the date in the format "dd Month yyyy"
    printf("%02d %s %d\n", day, month_name[month - 1], year);
}