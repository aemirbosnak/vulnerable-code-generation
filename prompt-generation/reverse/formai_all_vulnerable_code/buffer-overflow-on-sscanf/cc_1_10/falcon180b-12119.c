//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define DAYS_PER_WEEK 7
#define DAYS_PER_MONTH(year, month) ((month) == 2 && ((year) % 4 == 0 && (year) % 100!= 0 || (year) % 400 == 0))? 29 : ((month) - 1) % 7 == 0 && (month)!= 2? 31 : 30

typedef struct {
    int day;
    int month;
    int year;
} Date;

Date parse_date(const char* input);
char* format_date(Date date, int format);

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <date>\n", argv[0]);
        return 1;
    }

    Date date = parse_date(argv[1]);
    char* formatted_date = format_date(date, 1);
    printf("Formatted date: %s\n", formatted_date);
    free(formatted_date);

    return 0;
}

Date parse_date(const char* input) {
    char* endptr;
    Date date = {0};

    if (sscanf(input, "%d-%d-%d", &date.year, &date.month, &date.day)!= 3) {
        printf("Invalid date format\n");
        return date;
    }

    if (date.month < 1 || date.month > 12) {
        printf("Invalid month\n");
        return date;
    }

    if (date.day < 1 || date.day > DAYS_PER_MONTH(date.year, date.month)) {
        printf("Invalid day\n");
        return date;
    }

    return date;
}

char* format_date(Date date, int format) {
    char* formatted_date = malloc(80 * sizeof(char));
    strftime(formatted_date, 80, (format == 1)? "%A, %B %d, %Y" : "%m/%d/%Y", &date);
    return formatted_date;
}