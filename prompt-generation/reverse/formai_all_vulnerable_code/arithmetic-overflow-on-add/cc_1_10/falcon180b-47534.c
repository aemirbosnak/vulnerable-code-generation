//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>
#include <wchar.h>

#define YEAR 1
#define MONTH 2
#define DAY 3
#define HOUR 4
#define MINUTE 5
#define SECOND 6

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Date;

void print_date(Date* date) {
    printf("%04d-%02d-%02d %02d:%02d:%02d", date->year, date->month, date->day, date->hour, date->minute, date->second);
}

void parse_date(char* input, Date* date) {
    char delimiter = '-';
    int i = 0;
    while (i < 10 && input[i]!= delimiter) {
        date->year = date->year * 10 + input[i] - '0';
        i++;
    }
    i++;
    date->month = input[i] - '0';
    i++;
    date->day = input[i] - '0';
    i++;
    delimiter = ':';
    date->hour = input[i] - '0';
    i++;
    date->minute = input[i] - '0';
    i++;
    date->second = input[i] - '0';
}

int main() {
    setlocale(LC_ALL, "en_US.utf8");
    printf("Enter date in format yyyy-mm-dd hh:mm:ss: ");
    char input[20];
    scanf("%s", input);
    Date date;
    parse_date(input, &date);
    print_date(&date);
    return 0;
}