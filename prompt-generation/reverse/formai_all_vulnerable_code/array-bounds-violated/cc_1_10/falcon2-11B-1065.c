//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convert_date(char* date) {
    char month[3];
    char day[2];
    char year[4];

    int month_index = 0;
    int day_index = 0;
    int year_index = 0;

    int month_len = strlen(month);
    int day_len = strlen(day);
    int year_len = strlen(year);

    while (date[year_index]!= '\0') {
        if (isdigit(date[year_index])) {
            year[year_len - 1] = date[year_index];
            year_len++;
        } else if (date[year_index] == '-') {
            break;
        } else if (date[year_index] == '/') {
            break;
        } else {
            year[year_len - 1] = '\0';
            break;
        }
        year_index++;
    }

    year[year_len - 1] = '\0';

    while (date[month_index]!= '\0') {
        if (isalpha(date[month_index])) {
            month[month_len - 1] = date[month_index];
            month_len++;
        } else {
            month[month_len - 1] = '\0';
            break;
        }
        month_index++;
    }

    while (date[day_index]!= '\0') {
        if (isdigit(date[day_index])) {
            day[day_len - 1] = date[day_index];
            day_len++;
        } else {
            day[day_len - 1] = '\0';
            break;
        }
        day_index++;
    }

    printf("Month: %s\n", month);
    printf("Day: %s\n", day);
    printf("Year: %s\n", year);
}

int main() {
    char date[100];
    printf("Enter a date in the format MM/DD/YYYY: ");
    fgets(date, sizeof(date), stdin);
    char* p = date;
    while (*p!= '\n' && *p!= '\0') p++;
    if (*p == '\n') {
        date[strlen(date) - 1] = '\0';
    } else {
        date[strlen(date) - 1] = '\0';
        date[strlen(date)] = '\0';
    }
    convert_date(date);
    return 0;
}