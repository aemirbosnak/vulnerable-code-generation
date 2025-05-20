//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER_SIZE 256

typedef struct DateConverter {
    char month_name[32];
    int day;
    int year;
} DateConverter;

int main() {

    DateConverter date_converter;
    char input_date[MAX_BUFFER_SIZE];
    char format_string[MAX_BUFFER_SIZE];
    time_t timestamp;

    printf("Enter the date in the format mm/dd/yyyy: ");
    scanf("%s", input_date);

    printf("Enter the format string (e.g. MM/DD/YY): ");
    scanf("%s", format_string);

    timestamp = convert_date(input_date, format_string, &date_converter);

    if (timestamp == -1) {
        printf("Error converting date.\n");
    } else {
        printf("Date converted: %s %d, %d\n", date_converter.month_name, date_converter.day, date_converter.year);
    }

    return 0;
}

int convert_date(char *input_date, char *format_string, DateConverter *date_converter) {

    time_t timestamp;
    struct tm *tm_ptr;

    timestamp = strtol(input_date, NULL, 10);

    if (timestamp == -1) {
        return -1;
    }

    tm_ptr = localtime(&timestamp);

    date_converter->month_name[0] = tm_ptr->tm_mon + 1;
    date_converter->day = tm_ptr->tm_mday;
    date_converter->year = tm_ptr->tm_year;

    return 0;
}