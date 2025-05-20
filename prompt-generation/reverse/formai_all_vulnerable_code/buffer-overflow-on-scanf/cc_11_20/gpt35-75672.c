//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: relaxed
#include <stdio.h>
#include <string.h>

int main()
{
    char date[11], month[10], year[5];
    int month_num;

    printf("Enter date in natural language (eg: 21st August 2022): ");
    scanf("%s %s %s", date, month, year);

    //Convert month name to its numerical representation
    if(strcmp(month, "January") == 0)
    {
        month_num = 1;
    }
    else if(strcmp(month, "February") == 0)
    {
        month_num = 2;
    }
    else if(strcmp(month, "March") == 0)
    {
        month_num = 3;
    }
    else if(strcmp(month, "April") == 0)
    {
        month_num = 4;
    }
    else if(strcmp(month, "May") == 0)
    {
        month_num = 5;
    }
    else if(strcmp(month, "June") == 0)
    {
        month_num = 6;
    }
    else if(strcmp(month, "July") == 0)
    {
        month_num = 7;
    }
    else if(strcmp(month, "August") == 0)
    {
        month_num = 8;
    }
    else if(strcmp(month, "September") == 0)
    {
        month_num = 9;
    }
    else if(strcmp(month, "October") == 0)
    {
        month_num = 10;
    }
    else if(strcmp(month, "November") == 0)
    {
        month_num = 11;
    }
    else if(strcmp(month, "December") == 0)
    {
        month_num = 12;
    }

    //Print the converted date in dd/mm/yyyy format
    printf("%s/%d/%s", date, month_num, year);

    return 0;
}