//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char date[11];
    int day, month, year;
    char monthName[15];

    printf("Enter a date in the format (DD-MM-YYYY): ");
    scanf("%s", date);

    char* token = strtok(date, "-");
    day = atoi(token);

    token = strtok(NULL, "-");
    month = atoi(token);

    token = strtok(NULL, "-");
    year = atoi(token);

    switch(month)
    {
        case 1:
            strcpy(monthName, "January");
            break;
        case 2:
            strcpy(monthName, "February");
            break;
        case 3:
            strcpy(monthName, "March");
            break;
        case 4:
            strcpy(monthName, "April");
            break;
        case 5:
            strcpy(monthName, "May");
            break;
        case 6:
            strcpy(monthName, "June");
            break;
        case 7:
            strcpy(monthName, "July");
            break;
        case 8:
            strcpy(monthName, "August");
            break;
        case 9:
            strcpy(monthName, "September");
            break;
        case 10:
            strcpy(monthName, "October");
            break;
        case 11:
            strcpy(monthName, "November");
            break;
        case 12:
            strcpy(monthName, "December");
            break;
        default:
            printf("Invalid month entered.\n");
            exit(0);
    }

    printf("You entered: %02d %s %04d\n", day, monthName, year);

    return 0;
}