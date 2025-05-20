//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE_SIZE 11
#define MAX_MONTH_SIZE 3
#define MAX_YEAR_SIZE 5

typedef struct {
    int day;
    char month[MAX_MONTH_SIZE + 1];
    int year;
} Date;

typedef enum {
    MMDDYY,
    DDMMYY,
    YYMMDD
} Date_Format;

int get_date_format(char *date_string) {
    int day, month, year;
    if (sscanf(date_string, "%d/%d/%d", &day, &month, &year) == 3) {
        return MMDDYY;
    } else if (sscanf(date_string, "%d-%d-%d", &day, &month, &year) == 3) {
        return DDMMYY;
    } else if (sscanf(date_string, "%d%d%d", &year, &month, &day) == 3) {
        return YYMMDD;
    } else {
        return -1;
    }
}

Date convert_date(char *date_string, Date_Format format) {
    int day, month, year;
    switch (format) {
        case MMDDYY:
            sscanf(date_string, "%d/%d/%d", &month, &day, &year);
            break;
        case DDMMYY:
            sscanf(date_string, "%d-%d-%d", &day, &month, &year);
            break;
        case YYMMDD:
            sscanf(date_string, "%d%d%d", &year, &month, &day);
            break;
    }
    Date date = {day, month, year};
    return date;
}

int main() {
    char date_string[MAX_DATE_SIZE + 1];
    Date date;
    int format;

    printf("Enter a date in MM/DD/YY, DD-MM-YY, or YYMMDD format: ");
    scanf("%s", date_string);

    format = get_date_format(date_string);
    if (format == -1) {
        printf("Invalid date format.\n");
        return 1;
    }

    date = convert_date(date_string, format);

    printf("Day: %d\n", date.day);
    printf("Month: %s\n", date.month);
    printf("Year: %d\n", date.year);

    return 0;
}