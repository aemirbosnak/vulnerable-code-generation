//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159
#define GRAVITY 9.80665

int main()
{
    int choice, num1, num2;
    float result;

    printf("Enter your choice:\n"
           "1. Convert meters to centimeters\n"
           "2. Convert kilograms to grams\n"
           "3. Convert liters to cubic meters\n"
           "4. Convert miles to kilometers\n"
           "5. Convert degrees Fahrenheit to Celsius\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the number of meters:");
            scanf("%d", &num1);
            num2 = num1 * 100;
            result = num2;
            printf("The number of centimeters is: %.2f\n", result);
            break;

        case 2:
            printf("Enter the number of kilograms:");
            scanf("%d", &num1);
            num2 = num1 * 1000;
            result = num2;
            printf("The number of grams is: %.2f\n", result);
            break;

        case 3:
            printf("Enter the number of liters:");
            scanf("%d", &num1);
            num2 = num1 * 1000;
            result = num2;
            printf("The number of cubic meters is: %.2f\n", result);
            break;

        case 4:
            printf("Enter the number of miles:");
            scanf("%d", &num1);
            num2 = num1 * 1.613;
            result = num2;
            printf("The number of kilometers is: %.2f\n", result);
            break;

        case 5:
            printf("Enter the number of degrees Fahrenheit:");
            scanf("%d", &num1);
            num2 = (num1 - 32) * 5 / 9;
            result = num2;
            printf("The number of degrees Celsius is: %.2f\n", result);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}