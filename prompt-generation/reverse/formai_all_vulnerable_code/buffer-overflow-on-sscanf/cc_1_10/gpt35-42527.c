//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main()
{
    char date[11];
    int day, month, year;

    printf("Enter date in natural language (e.g. January 1st, 2050): ");
    fgets(date, 11, stdin);

    char * months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char * suffixes[] = {"th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th"};
    int num, j;

    sscanf(date, "%s %d%c%c%c%d", &months[j], &num, &date[strlen(date)-2], &date[strlen(date)-1], &date[strlen(date)-4], &year);

    day = num;

    if (strncmp(date+strlen(months[j]), "st", 2) == 0 || strncmp(date+strlen(months[j]), "nd", 2) == 0 || strncmp(date+strlen(months[j]), "rd", 2) == 0 || strncmp(date+strlen(months[j]), "th", 2) == 0)
    {
        day = date[strlen(date)-3] - '0';
        day *= 10;
        day += date[strlen(date)-2] - '0';
        if (day > 31)
        {
            printf("Invalid date\n");
            return 0;
        }
    }
    else
    {
        printf("Invalid date\n");
        return 0;
    }

    for (j = 0; j < 12; j++)
    {
        if (strcmp(months[j], date) == 0)
        {
            month = j + 1;
            break;
        }
    }

    if (j == 12)
    {
        printf("Invalid month\n");
        return 0;
    }

    printf("Equivalent C natural language format: %d-%02d-%02d\n", year, month, day);

    return 0;
}