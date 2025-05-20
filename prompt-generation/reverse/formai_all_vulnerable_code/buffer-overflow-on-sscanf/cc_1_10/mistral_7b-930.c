//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function to check if a given string is valid date
int is_valid_date(const char *date) {
    int day, month, year;
    sscanf(date, "%d/%d/%d", &day, &month, &year);

    if (strlen(date) != 10 ||
        day < 1 || day > 31 ||
        (month < 1 || month > 12) ||
        (month == 2 && (day > 29 || (day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)))))) {
        return 0;
    }

    return 1;
}

// Function to convert a given date to Unix timestamp
long long int date_to_timestamp(const char *date) {
    int day, month, year;
    long long int timestamp;
    struct tm tm;

    if (!is_valid_date(date)) {
        perror("Invalid date");
        exit(EXIT_FAILURE);
    }

    sscanf(date, "%d/%d/%d", &day, &month, &year);

    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = tm.tm_min = tm.tm_sec = 0;

    timestamp = mktime(&tm);
    if (timestamp == (time_t)(-1)) {
        perror("Failed to convert date to timestamp");
        exit(EXIT_FAILURE);
    }

    return timestamp;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s dd/mm/yyyy\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    long long int timestamp = date_to_timestamp(argv[1]);
    printf("Unix timestamp for %s is: %lld\n", argv[1], timestamp);

    return EXIT_SUCCESS;
}