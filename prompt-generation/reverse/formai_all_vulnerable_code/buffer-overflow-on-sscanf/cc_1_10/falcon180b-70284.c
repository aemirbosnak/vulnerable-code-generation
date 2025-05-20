//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

char* weekday_names[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
char* month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

Date* get_date(int year, int month, int day) {
    struct tm date = {0};
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;
    time_t t = mktime(&date);
    return (Date*)malloc(sizeof(Date));
}

void free_date(Date* date) {
    free(date);
}

char* get_weekday_name(int day_of_week) {
    return weekday_names[day_of_week % 7];
}

char* get_month_name(int month) {
    return month_names[month % 12];
}

void print_date_full(Date* date) {
    printf("%s, %d %s %d\n", get_weekday_name(date->day), date->day, get_month_name(date->month), date->year);
}

void print_date_short(Date* date) {
    printf("%d/%d/%d\n", date->month, date->day, date->year);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s [date_string] [output_format]\n", argv[0]);
        return 1;
    }

    char* date_string = argv[1];
    char* output_format = argv[2];

    Date* date = get_date(0, 0, 0);
    if (sscanf(date_string, "%d/%d/%d", &date->month, &date->day, &date->year)!= 3) {
        printf("Invalid date format\n");
        free_date(date);
        return 1;
    }

    if (strcmp(output_format, "full") == 0) {
        print_date_full(date);
    } else if (strcmp(output_format, "short") == 0) {
        print_date_short(date);
    } else {
        printf("Invalid output format\n");
        free_date(date);
        return 1;
    }

    free_date(date);
    return 0;
}