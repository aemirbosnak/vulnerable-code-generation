//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int year, month, day;
    printf("Welcome to the Farty Date Converter!\n");
    printf("Enter the year: ");
    scanf("%d", &year);
    printf("Enter the month: ");
    scanf("%d", &month);
    printf("Enter the day: ");
    scanf("%d", &day);

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
    {
        printf("Oops! Looks like you entered an invalid date. Try again!\n");
        exit(0);
    }
    // convert date format
    switch (month)
    {
    case 1:
        printf("January ");
        break;
    case 2:
        printf("February ");
        break;
    case 3:
        printf("March ");
        break;
    case 4:
        printf("April ");
        break;
    case 5:
        printf("May ");
        break;
    case 6:
        printf("June ");
        break;
    case 7:
        printf("July ");
        break;
    case 8:
        printf("August ");
        break;
    case 9:
        printf("September ");
        break;
    case 10:
        printf("October ");
        break;
    case 11:
        printf("November ");
        break;
    case 12:
        printf("December ");
        break;
    }

    printf("%d", day);

    switch (day)
    {
    case 1:
    case 21:
    case 31:
        printf("st");
        break;
    case 2:
    case 22:
        printf("nd");
        break;
    case 3:
    case 23:
        printf("rd");
        break;
    default:
        printf("th");
    }

    printf(", %d\n", year);

    printf("There you have it! Your stinkin' date has been converted. Come back anytime!\n");
    return 0;
}