//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 100

void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void parse_date_string(const char *date_str, int *day, int *month, int *year) {
    char month_str[20];
    
    if (sscanf(date_str, "%d %s %d", day, month_str, year) == 3) {
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
        else {
            fprintf(stderr, "Invalid month: %s\n", month_str);
            exit(EXIT_FAILURE);
        }
    } else {
        fprintf(stderr, "Invalid date string format. Expected format: 'day Month year'\n");
        exit(EXIT_FAILURE);
    }
}

void convert_to_timestamp(int day, int month, int year) {
    struct tm time_struct = {0};

    time_struct.tm_mday = day;
    time_struct.tm_mon = month - 1; // tm_mon is 0-11
    time_struct.tm_year = year - 1900; // tm_year is years since 1900

    time_t timestamp = mktime(&time_struct);
    
    if (timestamp == -1) {
        fprintf(stderr, "Failed to convert date to timestamp.\n");
        exit(EXIT_FAILURE);
    }

    printf("The timestamp for %02d-%02d-%04d is: %ld\n", day, month, year, (long)timestamp);
}

int main() {
    char input[MAX_INPUT_SIZE];
    int day, month, year;

    printf("Please enter a date in the format 'day Month year' (e.g., '16 February 2023'):\n");
    fgets(input, MAX_INPUT_SIZE, stdin);
    trim_newline(input);
    
    parse_date_string(input, &day, &month, &year);
    
    convert_to_timestamp(day, month, year);

    return 0;
}