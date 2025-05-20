//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char date_string[200];
    printf("Please enter a date in the format YYYY-MM-DD:");
    scanf("%s", date_string);

    int year = atoi(strtok(date_string, "-"));
    int month = atoi(strtok(strtok(date_string, "-"), "-"));
    int day = atoi(strtok(strtok(date_string, "-"), "-"));

    switch (month)
    {
        case 1:
            printf("The date is %d %s %d, %d.", day, "January", year);
            break;
        case 2:
            printf("The date is %d %s %d, %d.", day, "February", year);
            break;
        case 3:
            printf("The date is %d %s %d, %d.", day, "March", year);
            break;
        case 4:
            printf("The date is %d %s %d, %d.", day, "April", year);
            break;
        case 5:
            printf("The date is %d %s %d, %d.", day, "May", year);
            break;
        case 6:
            printf("The date is %d %s %d, %d.", day, "June", year);
            break;
        case 7:
            printf("The date is %d %s %d, %d.", day, "July", year);
            break;
        case 8:
            printf("The date is %d %s %d, %d.", day, "August", year);
            break;
        case 9:
            printf("The date is %d %s %d, %d.", day, "September", year);
            break;
        case 10:
            printf("The date is %d %s %d, %d.", day, "October", year);
            break;
        case 11:
            printf("The date is %d %s %d, %d.", day, "November", year);
            break;
        case 12:
            printf("The date is %d %s %d, %d.", day, "December", year);
            break;
    }

    return 0;
}