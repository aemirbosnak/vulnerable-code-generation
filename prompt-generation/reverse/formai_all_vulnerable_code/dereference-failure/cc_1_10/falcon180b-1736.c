//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DATE_LENGTH 100

typedef struct {
    char day[MAX_DATE_LENGTH];
    char month[MAX_DATE_LENGTH];
    int year;
} Date;

Date *parseDate(char *dateString);
void printDate(Date *date);

int main() {
    char dateString[MAX_DATE_LENGTH];
    Date *date;

    printf("Enter a date in the format DD/MM/YYYY: ");
    fgets(dateString, MAX_DATE_LENGTH, stdin);

    date = parseDate(dateString);

    if (date!= NULL) {
        printf("Parsed date: ");
        printDate(date);
    } else {
        printf("Invalid date.\n");
    }

    return 0;
}

Date *parseDate(char *dateString) {
    Date *date = malloc(sizeof(Date));
    if (date == NULL) {
        return NULL;
    }

    char *token = strtok(dateString, "/");
    strcpy(date->day, token);

    token = strtok(NULL, "/");
    strcpy(date->month, token);

    token = strtok(NULL, "/");
    date->year = atoi(token);

    if (!isValidDate(date)) {
        free(date);
        return NULL;
    }

    return date;
}

void printDate(Date *date) {
    printf("%s %s, %d\n", date->day, date->month, date->year);
}

int isValidDate(Date *date) {
    int day, month, year;

    if (sscanf(date->day, "%d", &day)!= 1 || day < 1 || day > 31) {
        return 0;
    }

    if (sscanf(date->month, "%d", &month)!= 1 || month < 1 || month > 12) {
        return 0;
    }

    if (date->year < 1000 || date->year > 9999) {
        return 0;
    }

    return 1;
}