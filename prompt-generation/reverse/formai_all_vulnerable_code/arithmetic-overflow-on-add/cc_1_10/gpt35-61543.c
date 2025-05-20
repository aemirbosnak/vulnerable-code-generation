//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct date
{
    int day;
    int month;
    int year;
};

typedef struct date date_t;

void convert_to_cyberpunk(date_t *date)
{
    date->year = date->year + 57;
    date->day = date->day + 23;
    date->month = date->month * 8;
}

void convert_to_human(date_t *date)
{
    date->year = date->year - 57;
    date->day = date->day - 23;
    date->month = date->month / 8;
}

int main()
{
    char inp_date[11];
    date_t date;

    printf("Enter date in DD/MM/YYYY format :\n");
    scanf("%s", inp_date);

    // Parse the input string to extract day, month and year.
    // Assume input date format to be always valid.
    sscanf(inp_date, "%d/%d/%d", &date.day, &date.month, &date.year);
    
    // Convert to Cyberpunk format
    convert_to_cyberpunk(&date);

    printf("Today's date in Cyberpunk style is : %d/%d/%d\n", date.day, date.month, date.year);

    // Convert back to human format
    convert_to_human(&date);

    printf("In human date format it is : %d/%d/%d", date.day, date.month, date.year);

    return 0;
}