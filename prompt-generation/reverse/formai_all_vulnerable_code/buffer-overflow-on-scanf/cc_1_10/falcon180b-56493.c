//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_DATE_LENGTH 20

typedef struct {
    int day;
    int month;
    int year;
} Date;

char* parseDate(const char* input, Date* date) {
    char* token = strtok(input, " ");
    if (token == NULL) {
        return "Invalid date format";
    }

    int day = atoi(token);
    if (day < 1 || day > 31) {
        return "Invalid day";
    }

    token = strtok(NULL, " ");
    if (token == NULL) {
        return "Invalid date format";
    }

    int month = atoi(token);
    if (month < 1 || month > 12) {
        return "Invalid month";
    }

    token = strtok(NULL, " ");
    if (token == NULL) {
        return "Invalid date format";
    }

    int year = atoi(token);
    if (year < 1900 || year > 2099) {
        return "Invalid year";
    }

    date->day = day;
    date->month = month;
    date->year = year;

    return NULL;
}

char* toString(Date date) {
    char buffer[MAX_DATE_LENGTH];
    sprintf(buffer, "%02d/%02d/%04d", date.day, date.month, date.year);
    return strdup(buffer);
}

int main() {
    char input[MAX_DATE_LENGTH];
    printf("Enter a date (dd/mm/yyyy): ");
    scanf("%s", input);

    Date date;
    char* error = parseDate(input, &date);
    if (error!= NULL) {
        printf("Error: %s\n", error);
        return 1;
    }

    char* output = toString(date);
    printf("Date: %s\n", output);
    free(output);

    return 0;
}