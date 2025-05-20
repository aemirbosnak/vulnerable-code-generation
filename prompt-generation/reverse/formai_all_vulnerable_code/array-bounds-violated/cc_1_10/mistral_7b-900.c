//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MONTHS "JanFebMarAprMayJunJulAugSepOctNovDec"

typedef struct Date {
    int day, month, year;
} Date;

void parseDate(const char *dateStr, Date *date) {
    int day, month, year, pos, len;
    char *token;

    pos = 0;
    token = strtok(dateStr, " ");
    sscanf(token, "%d%n", &day, &len);
    date->day = day;

    token += len;
    if (*token == '/') token++;

    pos = 0;
    token = strtok(NULL, MONTHS+1);
    for (month = 0; month < 12; month++) {
        len = strlen(MONTHS+1);
        if (strncmp(MONTHS, token, len) == 0) {
            break;
        }
        token += len + 1;
        if (*token++ != ' ') break;
    }
    date->month = month + 1;

    sscanf(token, "%d%n", &year, &len);
    date->year = year;
}

void printDate(const Date *date) {
    printf("%02d/%s/%04d", date->day, MONTHS+date->month, date->year);
}

int main(void) {
    char dateStr[33];
    Date date;

    fgets(dateStr, sizeof(dateStr), stdin);
    dateStr[strlen(dateStr)-1] = '\0'; // remove newline character
    parseDate(dateStr, &date);
    printDate(&date);
    printf("\n");

    return 0;
}