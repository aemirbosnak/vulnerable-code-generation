//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    float num;
    char unit;

    printf("Welcome to the Unit Converter!\n");
    printf("Please select an option:\n");
    printf("1. Convert meters to kilometers\n");
    printf("2. Convert liters to gallons\n");
    printf("3. Convert grams to ounces\n");
    printf("Please enter your choice: ");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the number of meters: ");
            scanf("%f", &num);
            unit = 'k';
            break;
        case 2:
            printf("Enter the number of liters: ");
            scanf("%f", &num);
            unit = 'g';
            break;
        case 3:
            printf("Enter the number of grams: ");
            scanf("%f", &num);
            unit = 'o' ;
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    switch (unit)
    {
        case 'k':
            printf("%f meters is equal to %f kilometers.\n", num, num * 1000);
            break;
        case 'g':
            printf("%f liters is equal to %f gallons.\n", num, num * 1.05669);
            break;
        case 'o':
            printf("%f grams is equal to %f ounces.\n", num, num * 0.035274) ;
            break;
        default:
            printf("Invalid unit.\n");
            break;
    }

    return 0;
}