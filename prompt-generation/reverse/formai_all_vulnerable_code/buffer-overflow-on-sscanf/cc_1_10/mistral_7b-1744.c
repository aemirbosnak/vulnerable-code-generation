//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

void extract_date(const char *input, Date *date) {
    int year, month, day, idx;
    const char *month_names[] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};

    sscanf(input, "%d %s %d", &year, &input, &day);
    month = 0;

    for (int i = 0; i < 12; i++) {
        idx = strlen(month_names[i]);
        if (strncmp(input, month_names[i], idx) == 0) {
            month = i + 1;
            break;
        }
    }

    date->year = year;
    date->month = month;
    date->day = day;
}

void print_date(const Date *date) {
    printf("%04d-%02d-%02d", date->year, date->month, date->day);
}

int main() {
    char input[100];
    Date date;

    printf("Enter a date in the format 'MONTH DAY, YEAR' or 'YEAR-MONTH-DAY': ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0'; // remove newline character

    extract_date(input, &date);

    print_date(&date);

    return 0;
}