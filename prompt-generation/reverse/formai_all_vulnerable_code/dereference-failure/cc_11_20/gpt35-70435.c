//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char date_input[20];
    char month[20];
    char month_index[3];
    char year[5];
    int day;
    int year_int;
    int month_int;
    int i;

    printf("Enter a date in natural language (e.g. March 2nd, 2022): ");
    fgets(date_input, 20, stdin); //read user input

    //parse month name
    for (i = 0; i < strlen(date_input); i++)
    {
        if (date_input[i] == ' ')
        {
            i++;
            break;
        }
        month[i] = date_input[i];
    }
    month[i - 1] = '\0';

    //parse day
    day = atoi(strtok(date_input+i, " ,stndhr"));

    //parse year
    year_int = atoi(strtok(NULL, " ,stndhr"));
    sprintf(year, "%d", year_int);

    //determine month index
    if (strcmp(month, "January") == 0)
    {
        strcpy(month_index, "01");
    }
    else if (strcmp(month, "February") == 0)
    {
        strcpy(month_index, "02");
    }
    else if (strcmp(month, "March") == 0)
    {
        strcpy(month_index, "03");
    }
    else if (strcmp(month, "April") == 0)
    {
        strcpy(month_index, "04");
    }
    else if (strcmp(month, "May") == 0)
    {
        strcpy(month_index, "05");
    }
    else if (strcmp(month, "June") == 0)
    {
        strcpy(month_index, "06");
    }
    else if (strcmp(month, "July") == 0)
    {
        strcpy(month_index, "07");
    }
    else if (strcmp(month, "August") == 0)
    {
        strcpy(month_index, "08");
    }
    else if (strcmp(month, "September") == 0)
    {
        strcpy(month_index, "09");
    }
    else if (strcmp(month, "October") == 0)
    {
        strcpy(month_index, "10");
    }
    else if (strcmp(month, "November") == 0)
    {
        strcpy(month_index, "11");
    }
    else if (strcmp(month, "December") == 0)
    {
        strcpy(month_index, "12");
    }
    else
    {
        printf("Invalid month name\n");
        return 0;
    }

    // print result in yyyy-mm-dd format
    printf("%s-%s-%02d", year, month_index, day);
    return 0;
}