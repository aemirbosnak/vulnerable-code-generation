//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

char* convert_date(char* date) {
    int day, month, year;
    char* month_str;
    char* day_str;
    char* year_str;

    if (sscanf(date, "%d-%s-%d", &day, month_str, &year)!= 3) {
        printf("Invalid date format: %s\n", date);
        exit(1);
    }

    if (strlen(month_str)!= 3) {
        printf("Invalid month format: %s\n", month_str);
        exit(1);
    }

    month = atoi(month_str);

    if (month < 1 || month > 12) {
        printf("Invalid month: %d\n", month);
        exit(1);
    }

    if (strlen(year_str)!= 4) {
        printf("Invalid year format: %s\n", year_str);
        exit(1);
    }

    year = atoi(year_str);

    if (year < 1000 || year > 9999) {
        printf("Invalid year: %d\n", year);
        exit(1);
    }

    if (month == 2) {
        if (day > 29) {
            printf("Invalid day for February: %d\n", day);
            exit(1);
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            printf("Invalid day for %s: %d\n", month_str, day);
            exit(1);
        }
    } else {
        if (day > 31) {
            printf("Invalid day for %s: %d\n", month_str, day);
            exit(1);
        }
    }

    sprintf(day_str, "%02d", day);
    sprintf(month_str, "%02d", month);

    return strcat(strcat(month_str, "-"), day_str);
}

int main(int argc, char* argv[]) {
    char* input_date;
    char* natural_date;

    printf("Enter a date in the format dd-mm-yyyy: ");
    scanf("%s", input_date);

    natural_date = convert_date(input_date);

    printf("Natural language date: %s\n", natural_date);

    return 0;
}