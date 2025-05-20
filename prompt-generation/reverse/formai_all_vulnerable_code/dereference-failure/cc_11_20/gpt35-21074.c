//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char date[20], month[10], monthNum[3], year[5];
    int day, i = 0, j = 0;

    printf("Enter a date in natural language (e.g. January 1, 2000): ");
    fgets(date, 20, stdin);

    // identify day
    char* token = strtok(date, " ,\n");
    if (isdigit(token[0]))
    {
        day = atoi(token);
    }

    // identify month
    while (token != NULL)
    {
        token = strtok(NULL, " ,\n");
        if (token != NULL)
        {
            for (i = 0; token[i]; i++)
            {
                month[j++] = tolower(token[i]);
            }
        }
    }

    if (strncmp(month, "jan", 3) == 0)
    {
        strcpy(monthNum, "01");
    }
    else if (strncmp(month, "feb", 3) == 0)
    {
        strcpy(monthNum, "02");
    }
    else if (strncmp(month, "mar", 3) == 0)
    {
        strcpy(monthNum, "03");
    }
    else if (strncmp(month, "apr", 3) == 0)
    {
        strcpy(monthNum, "04");
    }
    else if (strncmp(month, "may", 3) == 0)
    {
        strcpy(monthNum, "05");
    }
    else if (strncmp(month, "jun", 3) == 0)
    {
        strcpy(monthNum, "06");
    }
    else if (strncmp(month, "jul", 3) == 0)
    {
        strcpy(monthNum, "07");
    }
    else if (strncmp(month, "aug", 3) == 0)
    {
        strcpy(monthNum, "08");
    }
    else if (strncmp(month, "sep", 3) == 0)
    {
        strcpy(monthNum, "09");
    }
    else if (strncmp(month, "oct", 3) == 0)
    {
        strcpy(monthNum, "10");
    }
    else if (strncmp(month, "nov", 3) == 0)
    {
        strcpy(monthNum, "11");
    }
    else if (strncmp(month, "dec", 3) == 0)
    {
        strcpy(monthNum, "12");
    }

    // identify year
    token = strtok(NULL, " ,\n");
    if (token != NULL)
    {
        strncpy(year, token + strlen(token) - 4, 4);
        year[4] = '\0';
    }

    printf("Date in YYYY/MM/DD format: %s-%s-%d\n", year, monthNum, day);

    return 0;
}