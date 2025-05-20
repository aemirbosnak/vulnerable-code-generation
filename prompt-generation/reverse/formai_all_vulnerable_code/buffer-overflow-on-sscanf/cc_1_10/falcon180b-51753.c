//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

// Function prototypes
void convert_date(char *date_str);
int is_valid_date(char *date_str);
void display_date(char *date_str);

int main() {
    setlocale(LC_ALL, "English");
    char date_str[100];
    printf("Enter a date in the format 'DD/MM/YYYY': ");
    scanf("%s", date_str);
    convert_date(date_str);
    return 0;
}

void convert_date(char *date_str) {
    int day, month, year;
    struct tm date;
    if (is_valid_date(date_str)) {
        sscanf(date_str, "%d/%d/%d", &day, &month, &year);
        date.tm_mday = day;
        date.tm_mon = month - 1;
        date.tm_year = year - 1900;
        time_t t = mktime(&date);
        printf("The date '%s' is equivalent to %s", date_str, ctime(&t));
    } else {
        printf("Invalid date format!\n");
    }
}

int is_valid_date(char *date_str) {
    int day, month, year;
    if (sscanf(date_str, "%d/%d/%d", &day, &month, &year)!= 3) {
        return 0;
    }
    if (day < 1 || day > 31 || month < 1 || month > 12) {
        return 0;
    }
    if (year < 1900 || year > 2099) {
        return 0;
    }
    return 1;
}

void display_date(char *date_str) {
    int day, month, year;
    struct tm date;
    sscanf(date_str, "%d/%d/%d", &day, &month, &year);
    date.tm_mday = day;
    date.tm_mon = month - 1;
    date.tm_year = year - 1900;
    time_t t = mktime(&date);
    printf("The date '%s' is equivalent to %s", date_str, ctime(&t));
}