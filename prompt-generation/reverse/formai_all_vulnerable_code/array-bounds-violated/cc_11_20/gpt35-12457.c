//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    printf("Welcome to C Natural Language Date Converter\n");
    printf("Please enter a date in words (e.g January 1, 2022): ");
    char date[50];
    fgets(date, sizeof(date), stdin);

    // remove newline character from date string
    int len = strlen(date);
    if (date[len-1] == '\n')
        date[len-1] = '\0';

    // separate date string into month, day, year
    char *month, *day, *year;
    month = strtok(date, " ");
    day = strtok(NULL, ", ");
    year = strtok(NULL, "\n");

    // convert month string to number
    int m;
    if (strcasecmp(month, "January") == 0)
        m = 1;
    else if (strcasecmp(month, "February") == 0)
        m = 2;
    else if (strcasecmp(month, "March") == 0)
        m = 3;
    else if (strcasecmp(month, "April") == 0)
        m = 4;
    else if (strcasecmp(month, "May") == 0)
        m = 5;
    else if (strcasecmp(month, "June") == 0)
        m = 6;
    else if (strcasecmp(month, "July") == 0)
        m = 7;
    else if (strcasecmp(month, "August") == 0)
        m = 8;
    else if (strcasecmp(month, "September") == 0)
        m = 9;
    else if (strcasecmp(month, "October") == 0)
        m = 10;
    else if (strcasecmp(month, "November") == 0)
        m = 11;
    else if (strcasecmp(month, "December") == 0)
        m = 12;
    else {
        printf("Invalid month\n");
        return 0;
    }

    // convert day string to number
    int d = atoi(day);
    if (d < 1 || d > 31) {
        printf("Invalid day\n");
        return 0;
    }

    // convert year string to number
    int y = atoi(year);
    if (y < 0) {
        printf("Invalid year\n");
        return 0;
    }

    // print converted date
    printf("The converted date is: %d/%d/%d\n", m, d, y);

    return 0;
}