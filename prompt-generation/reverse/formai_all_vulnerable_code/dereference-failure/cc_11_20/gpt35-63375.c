//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main()
{
    int day, month, year;
    char date[20];

    printf("Enter a date in natural language (e.g. January 1st, 2022): ");
    fgets(date, 20, stdin);

    // remove newline character from string
    int len = strlen(date);
    if (date[len - 1] == '\n')
        date[len - 1] = '\0';

    // determine month
    if (strstr(date, "January"))
        month = 1;
    else if (strstr(date, "February"))
        month = 2;
    else if (strstr(date, "March"))
        month = 3;
    else if (strstr(date, "April"))
        month = 4;
    else if (strstr(date, "May"))
        month = 5;
    else if (strstr(date, "June"))
        month = 6;
    else if (strstr(date, "July"))
        month = 7;
    else if (strstr(date, "August"))
        month = 8;
    else if (strstr(date, "September"))
        month = 9;
    else if (strstr(date, "October"))
        month = 10;
    else if (strstr(date, "November"))
        month = 11;
    else if (strstr(date, "December"))
        month = 12;

    // determine day
    char * pch;
    pch = strtok(date, " ,stndhr");
    while (pch != NULL)
    {
        if (isdigit(*pch))
        {
            day = atoi(pch);
            break;
        }
        pch = strtok(NULL, " ,stndhr");
    }

    // determine year
    pch = strtok(NULL, " ");
    year = atoi(pch);

    // output result
    printf("The date %s is equivalent to %02d/%02d/%d\n", date, month, day, year);

    return 0;
}