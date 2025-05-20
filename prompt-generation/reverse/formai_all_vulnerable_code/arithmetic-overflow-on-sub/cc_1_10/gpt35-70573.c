//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to convert natural language dates to a modified Julian day number */
int convert_date(char *date) {
    const char *months[] = {"january","february","march","april","may","june","july","august","september","october","november","december"};
    int month, day, year, century, julian_day;
    char *token;

    /* Convert the date string to lowercase */
    int i;
    for (i = 0; date[i]; i++) {
        date[i] = tolower(date[i]);
    }

    /* Tokenize the date string to extract month, day and year */
    token = strtok(date, " ");
    while (token != NULL) {
        if (atoi(token)) {
            day = atoi(token);
        } else {
            for (i = 0; i < 12; i++) {
                if (strcmp(token, months[i]) == 0) {
                    month = i + 1;
                    break;
                }
            }
        }
        token = strtok(NULL, " ");
        if (atoi(token)) {
            year = atoi(token);
        }
    }

    /* Determine the century of the year */
    if (year < 100) {
        century = 19;
    } else {
        century = year / 100 + 1;
    }

    /* Compute the Julian day number */
    julian_day = (1461 * (year + 4800 + (month - 14) / 12)) / 4
                 + (367 * (month - 2 - 12 * ((month - 14) / 12))) / 12
                 - (3 * ((year + 4900 + (month - 14) / 12) / 100)) / 4
                 + day - 32075;

    return julian_day;
}

int main() {
    char date[100];

    /* Prompt the user to enter a natural language date */
    printf("Enter a natural language date: ");
    fgets(date, sizeof(date), stdin);

    /* Convert the date to a Julian day number */
    int julian_day = convert_date(date);

    /* Output the Julian day number */
    printf("The Julian day number is %d\n", julian_day);

    return 0;
}