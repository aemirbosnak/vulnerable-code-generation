//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <date>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *date_str = argv[1];
    int len = strlen(date_str);

    if (len != 10 || date_str[2] != '/' || date_str[5] != '/') {
        fprintf(stderr, "Invalid date format: %s\n", date_str);
        return EXIT_FAILURE;
    }

    Date date;
    date.year = atoi(date_str);
    date.month = atoi(date_str + 3);
    date.day = atoi(date_str + 6);

    if (date.year < 1 || date.year > 9999) {
        fprintf(stderr, "Invalid year: %d\n", date.year);
        return EXIT_FAILURE;
    }

    if (date.month < 1 || date.month > 12) {
        fprintf(stderr, "Invalid month: %d\n", date.month);
        return EXIT_FAILURE;
    }

    if (date.day < 1 || date.day > 31) {
        fprintf(stderr, "Invalid day: %d\n", date.day);
        return EXIT_FAILURE;
    }

    printf("Year: %d\n", date.year);
    printf("Month: %d\n", date.month);
    printf("Day: %d\n", date.day);

    return EXIT_SUCCESS;
}