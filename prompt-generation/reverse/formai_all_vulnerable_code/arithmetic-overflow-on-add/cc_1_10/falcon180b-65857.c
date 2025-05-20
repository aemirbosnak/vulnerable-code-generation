//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

void parse_date(char* str, Date* date) {
    char* token = strtok(str, " ");
    if (token == NULL) {
        date->day = 1;
        date->month = 1;
        date->year = 1900;
    } else {
        date->day = atoi(token);
        token = strtok(NULL, " ");
        if (token == NULL) {
            date->month = 1;
            date->year = 1900;
        } else {
            date->month = atoi(token);
            token = strtok(NULL, " ");
            if (token == NULL) {
                date->year = 1900;
            } else {
                date->year = atoi(token);
            }
        }
    }
}

void print_date(Date date) {
    printf("%d-%d-%d\n", date.year, date.month, date.day);
}

void convert_date(Date* date) {
    time_t timestamp = mktime(&(struct tm){0, 0, 0, date->day, date->month - 1, date->year - 1900, 0, 0, -1});
    struct tm* tm = localtime(&timestamp);
    date->day = tm->tm_mday;
    date->month = tm->tm_mon + 1;
    date->year = tm->tm_year + 1900;
}

int main() {
    char input[100];
    Date date;
    while (1) {
        printf("Enter a date (dd/mm/yyyy): ");
        fgets(input, sizeof(input), stdin);
        parse_date(input, &date);
        convert_date(&date);
        print_date(date);
    }
    return 0;
}