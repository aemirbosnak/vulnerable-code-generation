//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STRING_LENGTH 80

struct tm *convert_to_tm(char *date_string);
char *convert_tm_to_string(struct tm *tm);

int main() {
    char input_date[MAX_STRING_LENGTH];
    struct tm *tm_ptr;
    char output_date[MAX_STRING_LENGTH];

    // Prompt the user to enter a date in the format MM/DD/YYYY
    printf("Enter a date in the format MM/DD/YYYY: ");
    scanf("%s", input_date);

    // Convert the input date string to a tm struct
    tm_ptr = convert_to_tm(input_date);

    // Convert the tm struct to a string in the format DD/MM/YYYY
    strcpy(output_date, convert_tm_to_string(tm_ptr));

    // Print the converted date string
    printf("Converted date: %s\n", output_date);

    return 0;
}

// Convert a date string to a tm struct
struct tm *convert_to_tm(char *date_string) {
    struct tm tm;
    int month, day, year;

    // Check if the date string is valid
    if (sscanf(date_string, "%d/%d/%d", &month, &day, &year)!= 3) {
        printf("Invalid date format\n");
        exit(1);
    }

    // Set the tm struct fields
    tm.tm_sec = 0;
    tm.tm_min = 0;
    tm.tm_hour = 0;
    tm.tm_mday = day;
    tm.tm_mon = month - 1;
    tm.tm_year = year - 1900;
    tm.tm_wday = 0;
    tm.tm_yday = 0;
    tm.tm_isdst = -1;

    // Return the tm struct pointer
    return &tm;
}

// Convert a tm struct to a date string in the format DD/MM/YYYY
char *convert_tm_to_string(struct tm *tm) {
    char date_string[MAX_STRING_LENGTH];
    int day, month, year;

    // Get the tm struct fields
    day = tm->tm_mday;
    month = tm->tm_mon + 1;
    year = tm->tm_year + 1900;

    // Convert the tm struct fields to a date string
    sprintf(date_string, "%d/%d/%d", day, month, year);

    // Return the date string
    return strdup(date_string);
}