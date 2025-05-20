//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Protected functions and variables
static int _is_valid_date(char month[], char day[], char year[]) {
    int valid_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int is_valid = 1;

    if (atoi(month) < 1 || atoi(month) > 12) {
        is_valid = 0;
    } else if (atoi(month) == 2 && (atoi(year) % 4 != 0 || atoi(year) % 100 == 0 && atoi(year) % 400 != 0)) {
        valid_months[1] = 28;
    }

    if (atoi(day) < 1 || atoi(day) > valid_months[atoi(month) - 1]) {
        is_valid = 0;
    }

    return is_valid;
}

static time_t _string_to_time(char month[], char day[], char year[]) {
    struct tm tm;
    int m, d, y;

    y = atoi(year);
    m = atoi(month) - 1;
    d = atoi(day);

    tm.tm_year = y;
    tm.tm_mon = m;
    tm.tm_mday = d;
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    tm.tm_isdst = -1;

    return mktime(&tm);
}

// Main function
int main(int argc, char *argv[]) {
    char month[3], day[3], year[5];
    time_t timestamp;

    if (argc != 2) {
        printf("Usage: %s <MM/DD/YYYY>\n", argv[0]);
        return 1;
    }

    sscanf(argv[1], "%s/%s/%s", month, day, year);

    if (!_is_valid_date(month, day, year)) {
        printf("Invalid date format or invalid date.\n");
        return 1;
    }

    timestamp = _string_to_time(month, day, year);
    printf("Timestamp: %ld\n", (long int)timestamp);

    return 0;
}

// Public function for date conversion
void date_convert(char *date_str) {
    char month[3], day[3], year[5];
    time_t timestamp;

    sscanf(date_str, "%s/%s/%s", month, day, year);

    if (!_is_valid_date(month, day, year)) {
        printf("Invalid date format or invalid date.\n");
        return;
    }

    timestamp = _string_to_time(month, day, year);
    printf("Timestamp: %ld\n", (long int)timestamp);
}