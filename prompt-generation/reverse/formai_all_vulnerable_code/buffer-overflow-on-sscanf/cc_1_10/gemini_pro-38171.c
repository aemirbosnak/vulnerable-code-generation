//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_LEN 256

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    char *str;
    int len;
} String;

String *create_string(const char *str) {
    String *s = malloc(sizeof(String));
    s->len = strlen(str);
    s->str = malloc(s->len + 1);
    strcpy(s->str, str);
    return s;
}

void free_string(String *s) {
    free(s->str);
    free(s);
}

Date *create_date(int year, int month, int day) {
    Date *d = malloc(sizeof(Date));
    d->year = year;
    d->month = month;
    d->day = day;
    return d;
}

void free_date(Date *d) {
    free(d);
}

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int days_in_month(int month, int year) {
    switch (month) {
        case 1:  // January
        case 3:  // March
        case 5:  // May
        case 7:  // July
        case 8:  // August
        case 10: // October
        case 12: // December
            return 31;
        case 4:  // April
        case 6:  // June
        case 9:  // September
        case 11: // November
            return 30;
        case 2:  // February
            return is_leap_year(year) ? 29 : 28;
        default:
            return -1;
    }
}

int days_in_year(int year) {
    return is_leap_year(year) ? 366 : 365;
}

Date *parse_date(String *s) {
    int year, month, day;
    if (sscanf(s->str, "%d-%d-%d", &year, &month, &day) != 3) {
        return NULL;
    }
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > days_in_month(month, year)) {
        return NULL;
    }
    return create_date(year, month, day);
}

void print_date(Date *d) {
    printf("%d-%d-%d\n", d->year, d->month, d->day);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <date>\n", argv[0]);
        return EXIT_FAILURE;
    }

    String *s = create_string(argv[1]);
    Date *d = parse_date(s);
    if (d != NULL) {
        print_date(d);
        free_date(d);
    } else {
        fprintf(stderr, "Invalid date: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    free_string(s);
    return EXIT_SUCCESS;
}