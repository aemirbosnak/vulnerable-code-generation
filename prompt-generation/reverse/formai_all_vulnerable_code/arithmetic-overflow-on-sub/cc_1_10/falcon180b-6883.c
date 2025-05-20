//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int choice, celsius, fahrenheit;
    char ch;

    do
    {
        printf("\n\n\t\t\t\t\t\t\t\tTEMPERATURE CONVERTER\n\n");
        printf("\nEnter your choice:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter temperature in Celsius: ");
                scanf("%d", &celsius);
                fahrenheit = (celsius * 9/5) + 32;
                printf("\n%d Celsius = %d Fahrenheit\n", celsius, fahrenheit);
                break;

            case 2:
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%d", &fahrenheit);
                celsius = (fahrenheit - 32) * 5/9;
                printf("\n%d Fahrenheit = %d Celsius\n", fahrenheit, celsius);
                break;

            case 3:
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &ch);

    } while(ch == 'y' || ch == 'Y');

    return 0;
}