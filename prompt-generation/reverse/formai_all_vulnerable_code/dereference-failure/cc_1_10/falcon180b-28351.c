//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_DATE_LENGTH 100
#define DAYS_PER_MONTH(month) (((month) == 2 && ((year) % 4 == 0 && (year) % 100!= 0))? 29 : ((month) == 2)? 28 : 31)

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char* weekday;
    char* month;
    char* day;
    char* year;
} DateFormat;

Date* parseDate(const char* input, DateFormat* format) {
    int day = 0;
    int month = 0;
    int year = 0;
    if (sscanf(input, "%d %s %d %d", &day, format->weekday, &month, &year)!= 4) {
        return NULL;
    }
    if (month < 1 || month > 12) {
        return NULL;
    }
    if (day < 1 || day > DAYS_PER_MONTH(month)) {
        return NULL;
    }
    if (year < 1000 || year > 9999) {
        return NULL;
    }
    Date* date = malloc(sizeof(Date));
    date->day = day;
    date->month = month;
    date->year = year;
    return date;
}

char* formatDate(const Date* date, DateFormat* format) {
    char* result = malloc(MAX_DATE_LENGTH);
    strftime(result, MAX_DATE_LENGTH, format->day, localtime(&date->year));
    strcat(result, ", ");
    strftime(result + strlen(result), MAX_DATE_LENGTH - strlen(result), format->month, localtime(&date->year));
    strcat(result, " ");
    strftime(result + strlen(result), MAX_DATE_LENGTH - strlen(result), format->year, localtime(&date->year));
    return result;
}

int main() {
    DateFormat format = {
       .weekday = "%A",
       .month = "%B",
       .day = "%d",
       .year = "%Y"
    };
    const char* input = "Saturday, October 31, 2020";
    Date* date = parseDate(input, &format);
    if (date!= NULL) {
        char* output = formatDate(date, &format);
        printf("Input: %s\n", input);
        printf("Output: %s\n", output);
        free(output);
        free(date);
    }
    return 0;
}