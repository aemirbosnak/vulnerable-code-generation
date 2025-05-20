//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MONTHS_IN_YEAR 12

void extract_date_components(const char *input_date, int *day, int *month, int *year) {
    int index = 0;
    int year_length = 4;

    while (isdigit(input_date[index])) {
        *year = *year * 10 + (input_date[index] - '0');
        index++;

        if (index == (strlen(input_date) - year_length))
            break;
    }

    *day = 0;
    *month = 0;

    int i = 0;
    for (; i < index; i++) {
        if (!isdigit(input_date[i])) {
            if (input_date[i] == '-') {
                if (*day || !*month) {
                    fprintf(stderr, "Invalid date format: %s\n", input_date);
                    exit(EXIT_FAILURE);
                }

                *month = atoi(input_date + i + 1);
                i += 2;

                if (*month < 1 || *month > MONTHS_IN_YEAR) {
                    fprintf(stderr, "Invalid month: %d\n", *month);
                    exit(EXIT_FAILURE);
                }

                *day = 0;
                continue;
            }

            if (*day) {
                *day = *day * 10 + (input_date[i] - '0');
            } else {
                fprintf(stderr, "Invalid date format: %s\n", input_date);
                exit(EXIT_FAILURE);
            }
        }
    }

    if (!*day || !*month || !*year) {
        fprintf(stderr, "Invalid date format: %s\n", input_date);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <dd-mm-yyyy>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int day, month, year;
    extract_date_components(argv[1], &day, &month, &year);

    struct tm input_tm = {
        .tm_sec = 0,
        .tm_min = 0,
        .tm_hour = 0,
        .tm_mday = day,
        .tm_mon = month - 1,
        .tm_year = year,
        .tm_isdst = -1
    };

    time_t input_time = mktime(&input_tm);

    if (input_time == (time_t) -1) {
        perror("Error converting date to time_t");
        exit(EXIT_FAILURE);
    }

    printf("Unix timestamp for %d-%02d-%02d is:\n", year, month, day);
    printf("%ld\n", (long int) input_time);

    return EXIT_SUCCESS;
}