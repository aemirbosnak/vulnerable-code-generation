//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function to convert a string to uppercase
void strtoupper(char* str)
{
    int i = 0;
    while (str[i])
    {
        str[i] = toupper(str[i]);
        i++;
    }
}

// Function to check if a string is a valid date
int isvaliddate(char* str)
{
    char* date_format = "dd/mm/yyyy";
    char* token;
    int i = 0;
    char* delimiter = "/";
    token = strtok(str, delimiter);

    while (token!= NULL)
    {
        if (strlen(token)!= 2)
        {
            return 0;
        }
        if (!isdigit(token[0]) ||!isdigit(token[1]))
        {
            return 0;
        }
        i++;
        token = strtok(NULL, delimiter);
    }

    if (i!= 3)
    {
        return 0;
    }

    return 1;
}

// Function to convert a string to a date
time_t stringtodate(char* str)
{
    struct tm date;
    strtoupper(str);
    if (!isvaliddate(str))
    {
        return -1;
    }
    sscanf(str, "%d/%d/%d", &date.tm_mday, &date.tm_mon, &date.tm_year);
    date.tm_year -= 1900;
    date.tm_mon--;
    return mktime(&date);
}

// Function to convert a date to a string
char* datetostring(time_t date)
{
    struct tm* timeinfo;
    char* str;
    timeinfo = localtime(&date);
    str = (char*)malloc(sizeof(char) * 11);
    strftime(str, 11, "%d/%m/%Y", timeinfo);
    return str;
}

int main()
{
    char* input;
    time_t date;
    char* output;

    printf("Enter a date (dd/mm/yyyy): ");
    scanf("%s", input);

    date = stringtodate(input);

    if (date == -1)
    {
        printf("Invalid date\n");
    }
    else
    {
        output = datetostring(date);
        printf("The date is: %s\n", output);
    }

    return 0;
}