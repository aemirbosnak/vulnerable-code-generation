//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char date_str[20];
    printf("Enter a date in the format YYYY-MM-DD: ");
    scanf("%s", date_str);

    int year = atoi(strtok(date_str, "-"));
    int month = atoi(strtok(strtok(date_str, "-"), "-"));
    int day = atoi(strtok(strtok(date_str, "-"), "-"));

    switch (month)
    {
        case 1:
            printf("The date is: %d/%d/%d - January", day, month, year);
            break;
        case 2:
            printf("The date is: %d/%d/%d - February", day, month, year);
            break;
        case 3:
            printf("The date is: %d/%d/%d - March", day, month, year);
            break;
        case 4:
            printf("The date is: %d/%d/%d - April", day, month, year);
            break;
        case 5:
            printf("The date is: %d/%d/%d - May", day, month, year);
            break;
        case 6:
            printf("The date is: %d/%d/%d - June", day, month, year);
            break;
        case 7:
            printf("The date is: %d/%d/%d - July", day, month, year);
            break;
        case 8:
            printf("The date is: %d/%d/%d - August", day, month, year);
            break;
        case 9:
            printf("The date is: %d/%d/%d - September", day, month, year);
            break;
        case 10:
            printf("The date is: %d/%d/%d - October", day, month, year);
            break;
        case 11:
            printf("The date is: %d/%d/%d - November", day, month, year);
            break;
        case 12:
            printf("The date is: %d/%d/%d - December", day, month, year);
            break;
    }

    return 0;
}