//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE_LEN 20

void convert_date(char *date_str)
{
    char month_str[3];
    int day, month, year;
    char delimeter = '-';

    // Validate date format
    if (strlen(date_str) < 10)
    {
        printf("Invalid date format.\n");
        return;
    }

    // Extract month, day, and year
    month_str[0] = date_str[0];
    month_str[1] = date_str[1];
    month_str[2] = '\0';

    day = atoi(&date_str[3]);
    month = atoi(&month_str[0]) - 1;
    year = atoi(&date_str[6]);

    // Convert month to string
    switch (month)
    {
        case 0:
            month_str[0] = 'J';
            break;
        case 1:
            month_str[0] = 'F';
            break;
        case 2:
            month_str[0] = 'M';
            break;
        case 3:
            month_str[0] = 'A';
            break;
        case 4:
            month_str[0] = 'M';
            break;
        case 5:
            month_str[0] = 'J';
            break;
        case 6:
            month_str[0] = 'A';
            break;
        case 7:
            month_str[0] = 'S';
            break;
        case 8:
            month_str[0] = 'O';
            break;
        case 9:
            month_str[0] = 'N';
            break;
        case 10:
            month_str[0] = 'D';
            break;
    }

    // Print converted date
    printf("%d %s %d, %d\n", day, month_str, year);
}

int main()
{
    char date_str[MAX_DATE_LEN];

    printf("Enter a date in the format MM-DD-YYYY:");
    scanf("%s", date_str);

    convert_date(date_str);

    return 0;
}