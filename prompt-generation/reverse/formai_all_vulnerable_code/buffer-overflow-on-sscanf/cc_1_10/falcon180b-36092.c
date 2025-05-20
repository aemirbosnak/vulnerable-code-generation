//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

#define MAX_STR_LEN 80

typedef struct {
    int day;
    int month;
    int year;
} Date;

void setLocale() {
    setlocale(LC_TIME, "");
}

char* toString(Date date) {
    char* str = malloc(MAX_STR_LEN * sizeof(char));
    if (str == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    strftime(str, MAX_STR_LEN, "%d/%m/%Y", localtime(&date.year));
    return str;
}

int main() {
    setLocale();
    Date date;
    char input[MAX_STR_LEN];
    printf("Enter a date in the format dd/mm/yyyy: ");
    fgets(input, MAX_STR_LEN, stdin);
    sscanf(input, "%d/%d/%d", &date.day, &date.month, &date.year);
    if (date.month < 1 || date.month > 12) {
        printf("Error: Invalid month\n");
        return 1;
    }
    if (date.day < 1 || date.day > 31) {
        printf("Error: Invalid day\n");
        return 1;
    }
    if (date.year < 1900 || date.year > 2099) {
        printf("Error: Invalid year\n");
        return 1;
    }
    char* str = toString(date);
    printf("The input date is: %s\n", str);
    free(str);
    return 0;
}