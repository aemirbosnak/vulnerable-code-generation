//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
};

char* months[] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <date_string> <output_format>\n", argv[0]);
        return 1;
    }

    char* date_string = argv[1];
    char* output_format = argv[2];

    int day, month, year;
    if (sscanf(date_string, "%d/%d/%d", &day, &month, &year)!= 3) {
        printf("Invalid date format\n");
        return 1;
    }

    if (month < 1 || month > 12) {
        printf("Invalid month\n");
        return 1;
    }

    if (day < 1 || day > 31) {
        printf("Invalid day\n");
        return 1;
    }

    if (year < 1000 || year > 9999) {
        printf("Invalid year\n");
        return 1;
    }

    char* date_buffer[100];
    sprintf(date_buffer, "%d-%02d-%02d", year, month, day);

    if (strcmp(output_format, "long") == 0) {
        printf("%s, %s %d, %d\n", date_buffer, months[month - 1], day, year);
    } else if (strcmp(output_format, "short") == 0) {
        printf("%d/%d/%d\n", day, month, year);
    } else {
        printf("Invalid output format\n");
    }

    return 0;
}