//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void main()
{
    float dollar, euro, pound;
    char choice;

    printf("Welcome to the Currency Converter!\n");
    printf("Please choose an option:\n");
    printf("1. USD to Euro\n");
    printf("2. Euro to USD\n");
    printf("3. USD to Pound\n");
    printf("4. Pound to USD\n");

    scanf("%c", &choice);

    switch (choice)
    {
        case '1':
            printf("Enter the amount of USD: ");
            scanf("%f", &dollar);
            euro = dollar * 0.99;
            printf("The amount of Euro is: %.2f\n", euro);
            break;

        case '2':
            printf("Enter the amount of Euro: ");
            scanf("%f", &euro);
            dollar = euro * 1.01;
            printf("The amount of USD is: %.2f\n", dollar);
            break;

        case '3':
            printf("Enter the amount of USD: ");
            scanf("%f", &dollar);
            pound = dollar * 0.84;
            printf("The amount of Pound is: %.2f\n", pound);
            break;

        case '4':
            printf("Enter the amount of Pound: ");
            scanf("%f", &pound);
            dollar = pound * 1.16;
            printf("The amount of USD is: %.2f\n", dollar);
            break;

        default:
            printf("Invalid input.\n");
    }

    return;
}