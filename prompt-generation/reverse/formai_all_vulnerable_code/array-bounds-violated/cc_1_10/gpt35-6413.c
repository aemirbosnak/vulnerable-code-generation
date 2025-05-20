//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void month_conversion(char* month, int* month_num);
void date_conversion(char* input, int* output);

int main()
{
    char input_date[20];
    int year, month_num, day;
    char month[4];

    printf("Enter date in natural language format (eg. March 5th, 2022): ");
    fgets(input_date, 20, stdin);
    input_date[strlen(input_date) - 1] = '\0';

    sscanf(input_date, "%s %dth, %d", month, &day, &year);

    month_conversion(month, &month_num);

    printf("The equivalent date in standard format is: %d/%d/%d", month_num, day, year);

    return 0;
}

void month_conversion(char* month, int* month_num)
{
    if (strcmp(month, "January") == 0)
    {
        *month_num = 1;
    }
    else if (strcmp(month, "February") == 0)
    {
        *month_num = 2;
    }
    else if (strcmp(month, "March") == 0)
    {
        *month_num = 3;
    }
    else if (strcmp(month, "April") == 0)
    {
        *month_num = 4;
    }
    else if (strcmp(month, "May") == 0)
    {
        *month_num = 5;
    }
    else if (strcmp(month, "June") == 0)
    {
        *month_num = 6;
    }
    else if (strcmp(month, "July") == 0)
    {
        *month_num = 7;
    }
    else if (strcmp(month, "August") == 0)
    {
        *month_num = 8;
    }
    else if (strcmp(month, "September") == 0)
    {
        *month_num = 9;
    }
    else if (strcmp(month, "October") == 0)
    {
        *month_num = 10;
    }
    else if (strcmp(month, "November") == 0)
    {
        *month_num = 11;
    }
    else if (strcmp(month, "December") == 0)
    {
        *month_num = 12;
    }
}

void date_conversion(char* input, int* output)
{
    // Function to convert the natural language date format to a standard format
    // Eg. March 5th, 2022 => 3/5/2022

    char* month = strtok(input, " ");
    char* day = strtok(NULL, ", ");
    char* year = strtok(NULL, ", ");

    if (strcmp(day, "1st") == 0 || strcmp(day, "21st") == 0 || strcmp(day, "31st") == 0)
    {
        day[strlen(day) - 2] = '\0';
    }
    else if (strcmp(day, "2nd") == 0 || strcmp(day, "22nd") == 0)
    {
        day[strlen(day) - 2] = '\0';
        strcat(day, "2");
    }
    else if (strcmp(day, "3rd") == 0 || strcmp(day, "23rd") == 0)
    {
        day[strlen(day) - 2] = '\0';
        strcat(day, "3");
    }
    else
    {
        day[strlen(day) - 2] = '\0';
        day = strcat(day, "0");
    }

    month_conversion(month, output);

    output[1] = atoi(day);
    output[2] = atoi(year);
}