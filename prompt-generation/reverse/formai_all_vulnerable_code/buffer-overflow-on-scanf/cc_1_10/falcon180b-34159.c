//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_DATE_LEN 50

typedef struct {
    char day[MAX_DATE_LEN];
    char month[MAX_DATE_LEN];
    char year[MAX_DATE_LEN];
} Date;

Date *parseDate(char *dateStr) {
    Date *date = malloc(sizeof(Date));
    if (date == NULL) {
        printf("Error: could not allocate memory for date.\n");
        exit(1);
    }
    memset(date, 0, sizeof(Date));
    char *word = strtok(dateStr, " ");
    if (word == NULL) {
        printf("Error: invalid date string.\n");
        free(date);
        exit(1);
    }
    strcpy(date->month, word);
    word = strtok(NULL, " ");
    if (word == NULL) {
        printf("Error: invalid date string.\n");
        free(date);
        exit(1);
    }
    strcpy(date->day, word);
    word = strtok(NULL, " ");
    if (word == NULL) {
        printf("Error: invalid date string.\n");
        free(date);
        exit(1);
    }
    strcpy(date->year, word);
    return date;
}

void formatDate(Date *date, char *formattedDate) {
    if (date == NULL || formattedDate == NULL) {
        printf("Error: invalid parameters.\n");
        exit(1);
    }
    if (strlen(date->day) == 1) {
        sprintf(formattedDate, "%s, %02d %s %04d", date->day, atoi(date->day), date->month, atoi(date->year));
    } else {
        sprintf(formattedDate, "%s %02d, %04d", date->day, atoi(date->month), atoi(date->year));
    }
}

int main() {
    char dateStr[MAX_DATE_LEN];
    printf("Enter a date in the format 'Day Month Year': ");
    scanf("%s", dateStr);
    Date *date = parseDate(dateStr);
    if (date == NULL) {
        return 1;
    }
    char formattedDate[MAX_DATE_LEN];
    formatDate(date, formattedDate);
    printf("Formatted date: %s\n", formattedDate);
    free(date);
    return 0;
}