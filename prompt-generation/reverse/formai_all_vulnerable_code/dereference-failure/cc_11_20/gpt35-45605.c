//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date in natural language format (e.g. 2nd of March 2022): ");

    char input[30];
    fgets(input, 30, stdin); // get user input

    // separate date elements
    char *day = strtok(input, " ");
    char *nth = strtok(NULL, " ");
    char *month = strtok(NULL, " ");
    char *year = strtok(NULL, " ");

    // change nth to integer format
    int n = atoi(&nth[0]);

    // check if nth is valid
    if ((n < 1) || (n > 31))
    {
        printf("Error: Invalid day input.\n");
        return 0;
    }

    // change month to integer format
    int m;
    if (strcmp(month, "January") == 0) m = 1;
    else if (strcmp(month, "February") == 0) m = 2;
    else if (strcmp(month, "March") == 0) m = 3;
    else if (strcmp(month, "April") == 0) m = 4;
    else if (strcmp(month, "May") == 0) m = 5;
    else if (strcmp(month, "June") == 0) m = 6;
    else if (strcmp(month, "July") == 0) m = 7;
    else if (strcmp(month, "August") == 0) m = 8;
    else if (strcmp(month, "September") == 0) m = 9;
    else if (strcmp(month, "October") == 0) m = 10;
    else if (strcmp(month, "November") == 0) m = 11;
    else if (strcmp(month, "December") == 0) m = 12;
    else
    {
        printf("Error: Invalid month input.\n");
        return 0;
    }

    // check if year is valid
    if ((atoi(year) < 0) || (atoi(year) > 9999))
    {
        printf("Error: Invalid year input.\n");
        return 0;
    }

    // print out converted date
    printf("The date is %i/%i/%s.\n", n, m, year);

    return 0;
}