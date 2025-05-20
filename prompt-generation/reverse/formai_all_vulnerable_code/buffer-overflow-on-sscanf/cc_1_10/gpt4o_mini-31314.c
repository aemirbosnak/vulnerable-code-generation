//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INPUT_LENGTH 100
#define MAX_FORMAT_LENGTH 20

typedef struct {
    int day;
    int month;
    int year;
} Date;

const char *MONTH_NAMES[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

void printUsage() {
    printf("Usage: date_converter <date_string>\n");
    printf("Example date strings:\n");
    printf("1. '15 April 2021'\n");
    printf("2. 'July 4, 1776'\n");
    printf("3. '2022-12-31'\n");
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void parseDate(const char *input, Date *date) {
    char monthStr[MAX_INPUT_LENGTH];
    int day, year;
    
    // Try parsing format "DD Month YYYY"
    if (sscanf(input, "%d %s %d", &day, monthStr, &year) == 3) {
        for (int i = 0; i < 12; i++) {
            if (strcasecmp(monthStr, MONTH_NAMES[i]) == 0) {
                date->day = day;
                date->month = i + 1;
                date->year = year;
                return;
            }
        }
    }

    // Try parsing format "Month DD, YYYY"
    if (sscanf(input, "%s %d, %d", monthStr, &day, &year) == 3) {
        for (int i = 0; i < 12; i++) {
            if (strcasecmp(monthStr, MONTH_NAMES[i]) == 0) {
                date->day = day;
                date->month = i + 1;
                date->year = year;
                return;
            }
        }
    }

    // Try parsing format "YYYY-MM-DD"
    if (sscanf(input, "%d-%d-%d", &year, &date->month, &date->day) == 3) {
        return;
    }

    printf("Error: Unable to parse the date string: '%s'\n", input);
    exit(EXIT_FAILURE);
}

int validateDate(Date *date) {
    if (date->year < 1 || date->month < 1 || date->month > 12 || date->day < 1) {
        return 0; // Invalid date
    }

    int daysInMonth[] = { 31, isLeapYear(date->year) ? 29 : 28, 31, 30, 31, 30,
                          31, 31, 30, 31, 30, 31 };

    return date->day <= daysInMonth[date->month - 1];
}

void convertDateToTimestamp(Date *date, time_t *timestamp) {
    struct tm timeStruct = {0};
    timeStruct.tm_mday = date->day;
    timeStruct.tm_mon = date->month - 1; // tm_mon is 0-11
    timeStruct.tm_year = date->year - 1900; // tm_year is years since 1900

    *timestamp = mktime(&timeStruct);
    if (*timestamp == -1) {
        printf("Error: Invalid date.\n");
        exit(EXIT_FAILURE);
    }
}

void printDateInVariousFormats(const Date *date) {
    time_t timestamp;
    convertDateToTimestamp((Date *)date, &timestamp);

    printf("Converted date:\n");
    printf("Timestamp: %ld\n", timestamp);
    printf("Formatted Date (YYYY-MM-DD): %04d-%02d-%02d\n", date->year, date->month, date->day);
    printf("Formatted Date (DD Month YYYY): %02d %s %d\n", date->day, MONTH_NAMES[date->month - 1], date->year);
    printf("Formatted Date (Month DD, YYYY): %s %02d, %d\n", MONTH_NAMES[date->month - 1], date->day, date->year);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printUsage();
        return EXIT_FAILURE;
    }

    Date date;
    parseDate(argv[1], &date);

    if (!validateDate(&date)) {
        printf("Error: The date is invalid.\n");
        return EXIT_FAILURE;
    }

    printDateInVariousFormats(&date);
    return EXIT_SUCCESS;
}