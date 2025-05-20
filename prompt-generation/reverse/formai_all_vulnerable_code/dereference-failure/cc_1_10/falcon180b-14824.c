//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 32
#define MAX_DATE_LEN 32
#define NUM_MONTHS 12
#define NUM_DAYS_IN_MONTH 31

typedef struct {
    char word[MAX_WORD_LEN];
    int month;
    int day;
    int year;
} Date;

int main() {
    char input[MAX_DATE_LEN];
    Date date;

    printf("Enter a date in the format YYYY-MM-DD: ");
    scanf("%s", input);

    int i = 0;
    while (input[i]!= '-') {
        strncat(date.word, input[i], MAX_WORD_LEN);
        i++;
    }
    date.word[strlen(date.word) - 1] = '\0'; // remove last character (which is a dash)

    i++; // skip dash
    while (input[i]!= '-') {
        date.month = date.month * 10 + (input[i] - '0');
        i++;
    }
    date.month = date.month % NUM_MONTHS;

    i++; // skip dash
    while (input[i]!= '\0') {
        date.day = date.day * 10 + (input[i] - '0');
        i++;
    }
    date.day = date.day % NUM_DAYS_IN_MONTH;

    i++; // skip dash
    while (input[i]!= '\0') {
        date.year = date.year * 10 + (input[i] - '0');
        i++;
    }

    printf("Date: %s\n", date.word);
    printf("Month: %d\n", date.month);
    printf("Day: %d\n", date.day);
    printf("Year: %d\n", date.year);

    return 0;
}