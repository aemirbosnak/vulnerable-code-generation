//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MONTHS 12
#define MAX_DAYS 31
#define MAX_MONTH_NAME_LENGTH 9

typedef struct {
    char *month_name;
    int month_number;
    int days_in_month;
} Month;

Month months[] = {
    {"January", 1, 31},
    {"February", 2, 28},
    {"March", 3, 31},
    {"April", 4, 30},
    {"May", 5, 31},
    {"June", 6, 30},
    {"July", 7, 31},
    {"August", 8, 31},
    {"September", 9, 30},
    {"October", 10, 31},
    {"November", 11, 30},
    {"December", 12, 31}
};

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s [month_name] [day] [year]\n", argv[0]);
        return 1;
    }

    char *month_name = argv[1];
    int day = atoi(argv[2]);
    int year = atoi(argv[3]);

    int month_number = -1;
    for (int i = 0; i < MAX_MONTHS; i++) {
        if (strcmp(months[i].month_name, month_name) == 0) {
            month_number = i + 1;
            break;
        }
    }

    if (month_number == -1) {
        printf("Invalid month name\n");
        return 1;
    }

    if (day < 1 || day > months[month_number - 1].days_in_month) {
        printf("Invalid day\n");
        return 1;
    }

    struct tm date = {0};
    date.tm_year = year - 1900;
    date.tm_mon = month_number - 1;
    date.tm_mday = day;

    char date_string[MAX_MONTH_NAME_LENGTH + 1 + 2 + 4];
    strftime(date_string, sizeof(date_string), "%B %e, %Y", &date);

    printf("%s\n", date_string);

    return 0;
}