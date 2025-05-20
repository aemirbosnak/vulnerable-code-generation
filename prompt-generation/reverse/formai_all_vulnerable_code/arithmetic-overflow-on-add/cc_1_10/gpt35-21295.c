//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_leap(int year) {
    // Returns 1 if the given year is a leap year, else returns 0.
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    }
    return 0;
}

int get_day_count(int month, int year) {
    // Returns the number of days in the given month of the given year.
    int days_in_month[12] = {31, 28 + is_leap(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days_in_month[month-1];
}

char* convert_date(char* date_str, char* from_format, char* to_format) {
    int day, month, year;

    // Parse input date string using input format string.
    sscanf(date_str, from_format, &day, &month, &year);

    // Convert to output format string.
    char* output_format = (char*) malloc(20 * sizeof(char));
    char* p_output_format = output_format;
    for (int i = 0; i < strlen(to_format); i++) {
        if (to_format[i] == 'd') {
            sprintf(p_output_format, "%02d", day);
            p_output_format += 2;
        } else if (to_format[i] == 'm') {
            sprintf(p_output_format, "%02d", month);
            p_output_format += 2;
        } else if (to_format[i] == 'y') {
            sprintf(p_output_format, "%04d", year);
            p_output_format += 4;
        } else {
            *p_output_format = to_format[i];
            p_output_format += 1;
        }
    }
    *p_output_format = '\0';

    // Calculate the number of days elapsed since January 1, 1970 according to input format.
    int days_elapsed = 0;
    if (strcmp(from_format, "%d-%m-%y") == 0) {
        int factor = 365 + is_leap(year);
        days_elapsed = (year - 1970) * factor;
        for (int i = 1; i < month; i++) {
            days_elapsed += get_day_count(i, year);
        }
        days_elapsed += day - 1;
    } else if (strcmp(from_format, "%y-%m-%d") == 0) {
        int factor = 365 + is_leap(year);
        days_elapsed = (year - 1970) * factor;
        for (int i = 1; i < month; i++) {
            days_elapsed += get_day_count(i, year);
        }
        days_elapsed += day - 1;
    } else if (strcmp(from_format, "%m/%d/%y") == 0) {
        days_elapsed = (year - 1970) * 365 + (year - 1969) / 4;
        for (int i = 1; i < month; i++) {
            days_elapsed += get_day_count(i, year);
        }
        days_elapsed += day - 1;
    }

    // Calculate day, month and year according to output format.
    if (strcmp(to_format, "%y-%m-%d") == 0) {
        int year_diff = days_elapsed / 365;
        int remaining_days = days_elapsed % 365;
        int month = 1;
        while (remaining_days >= get_day_count(month, 1970 + year_diff)) {
            remaining_days -= get_day_count(month, 1970 + year_diff);
            month++;
        }
        int day = remaining_days + 1;
        year = 1970 + year_diff;
        sprintf(output_format, "%04d-%02d-%02d", year, month, day);
    } else if (strcmp(to_format, "%m/%d/%y") == 0) {
        int year_diff = days_elapsed / 365;
        int remaining_days = days_elapsed % 365;
        int month = 1;
        while (remaining_days >= get_day_count(month, 1970 + year_diff)) {
            remaining_days -= get_day_count(month, 1970 + year_diff);
            month++;
        }
        int day = remaining_days + 1;
        year = 1970 + year_diff;
        sprintf(output_format, "%02d/%02d/%04d", month, day, year);
    } else if (strcmp(to_format, "%d-%m-%y") == 0) {
        year = 1970;
        while (days_elapsed >= 365 + is_leap(year)) {
            days_elapsed -= 365 + is_leap(year);
            year++;
        }
        int month = 1;
        while (days_elapsed >= get_day_count(month, year)) {
            days_elapsed -= get_day_count(month, year);
            month++;
        }
        int day = days_elapsed + 1;
        sprintf(output_format, "%02d-%02d-%04d", day, month, year);
    }

    return output_format;
}

int main() {
    char* date_str = "31-12-2021";
    char* from_format = "%d-%m-%y";
    char* to_format = "%y-%m-%d";
    char* output_str = convert_date(date_str, from_format, to_format);
    printf("%s\n", output_str);
    free(output_str);
    return 0;
}