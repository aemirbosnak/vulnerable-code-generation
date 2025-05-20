//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

typedef struct {
    char* month;
    char* day;
    char* year;
} Date;

void initializeDate(Date* date) {
    date->month = NULL;
    date->day = NULL;
    date->year = NULL;
}

void setDate(Date* date, char* month, char* day, char* year) {
    date->month = month;
    date->day = day;
    date->year = year;
}

void printDate(Date* date) {
    printf("%s %s, %s\n", date->month, date->day, date->year);
}

void parseDate(char* input, Date* date) {
    char* month = strtok(input, ",");
    char* day = strtok(NULL, ",");
    char* year = strtok(NULL, ",");

    setDate(date, month, day, year);
}

int main() {
    char input[MAX_STRING_LENGTH];
    Date date;

    initializeDate(&date);

    printf("Enter a date in the format'month day, year': ");
    scanf("%s", input);

    parseDate(input, &date);
    printDate(&date);

    return 0;
}