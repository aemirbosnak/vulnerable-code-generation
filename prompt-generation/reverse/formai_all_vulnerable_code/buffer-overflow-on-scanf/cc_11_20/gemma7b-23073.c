//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, day, month, year;
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the day of the month: ");
    scanf("%d", &day);

    printf("Enter the month of the year: ");
    scanf("%d", &month);

    printf("Enter the year: ");
    scanf("%d", &year);

    switch (month)
    {
        case 1:
            printf("The month of January is cold and snowy.");
            break;
        case 2:
            printf("The month of February is windy and dreary.");
            break;
        case 3:
            printf("The month of March is mild and pleasant.");
            break;
        case 4:
            printf("The month of April is sunny and warm.");
            break;
        case 5:
            printf("The month of May is warm and flowery.");
            break;
        case 6:
            printf("The month of June is hot and humid.");
            break;
        case 7:
            printf("The month of July is scorching hot and full of fun.");
            break;
        case 8:
            printf("The month of August is hot and sunny.");
            break;
        case 9:
            printf("The month of September is mild and pleasant.");
            break;
        case 10:
            printf("The month of October is cool and windy.");
            break;
        case 11:
            printf("The month of November is cold and rainy.");
            break;
        case 12:
            printf("The month of December is frosty and magical.");
            break;
        default:
            printf("Invalid month.");
    }

    printf("\nHello, %s. The date is %d/%d/%d.", name, day, month, year);

    return 0;
}