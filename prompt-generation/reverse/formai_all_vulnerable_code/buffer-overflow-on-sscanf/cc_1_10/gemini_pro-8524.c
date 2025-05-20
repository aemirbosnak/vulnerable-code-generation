//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

Date *convert_date(const char *date_str) {
    // Allocate memory for the date struct
    Date *date = malloc(sizeof(Date));
    if (date == NULL) {
        return NULL;
    }

    // Parse the date string
    int year, month, day;
    if (sscanf(date_str, "%d-%d-%d", &year, &month, &day) != 3) {
        free(date);
        return NULL;
    }

    // Check if the date is valid
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31) {
        free(date);
        return NULL;
    }

    // Set the date struct
    date->year = year;
    date->month = month;
    date->day = day;

    return date;
}

void print_date(const Date *date) {
    printf("%d-%d-%d\n", date->year, date->month, date->day);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <date_str>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Convert the date string to a date struct
    Date *date = convert_date(argv[1]);
    if (date == NULL) {
        fprintf(stderr, "Invalid date string: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Print the date struct
    print_date(date);

    // Free the memory for the date struct
    free(date);

    return EXIT_SUCCESS;
}