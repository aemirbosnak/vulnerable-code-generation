//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

#define MAX_LENGTH 100

int main()
{
    char input[MAX_LENGTH];
    char *token;
    int day, month, year;
    struct tm date;

    printf("Enter a date in the format dd/mm/yyyy: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character from input
    if(input[strlen(input)-1] == '\n')
    {
        input[strlen(input)-1] = '\0';
    }

    // Tokenize input string
    token = strtok(input, "/");
    if(token == NULL)
    {
        printf("Invalid date format!\n");
        return 0;
    }
    day = atoi(token);

    token = strtok(NULL, "/");
    if(token == NULL)
    {
        printf("Invalid date format!\n");
        return 0;
    }
    month = atoi(token);

    token = strtok(NULL, "/");
    if(token == NULL)
    {
        printf("Invalid date format!\n");
        return 0;
    }
    year = atoi(token);

    // Validate input
    if(day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 9999)
    {
        printf("Invalid date!\n");
        return 0;
    }

    // Convert input to struct tm format
    date.tm_mday = day;
    date.tm_mon = month - 1;
    date.tm_year = year - 1900;
    date.tm_wday = 0;
    date.tm_yday = 0;
    date.tm_isdst = 0;

    // Convert struct tm to time_t format
    time_t timestamp = mktime(&date);

    // Convert time_t to string format
    char *formatted_date = ctime(&timestamp);

    // Print formatted date
    printf("Formatted date: %s\n", formatted_date);

    return 0;
}