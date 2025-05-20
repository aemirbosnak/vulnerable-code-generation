//FormAI DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>

int main()
{
    int choice;
    float input, output;

    printf("Welcome to the C unit converter!\n");
    printf("Choose an option:\n");
    printf("1. Feet to meters\n");
    printf("2. Miles to kilometers\n");
    printf("3. Gallons to liters\n");
    printf("4. Fahrenheit to Celsius\n");
    printf("5. Pounds to kilograms\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter length in feet: ");
            scanf("%f", &input);
            output = input / 3.281;
            printf("%.2f feet is equal to %.2f meters.\n", input, output);
            break;
        case 2:
            printf("Enter length in miles: ");
            scanf("%f", &input);
            output = input * 1.609;
            printf("%.2f miles is equal to %.2f kilometers.\n", input, output);
            break;
        case 3:
            printf("Enter volume in gallons: ");
            scanf("%f", &input);
            output = input * 3.785;
            printf("%.2f gallons is equal to %.2f liters.\n", input, output);
            break;
        case 4:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input);
            output = (input - 32) * (5.0 / 9.0);
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", input, output);
            break;
        case 5:
            printf("Enter weight in pounds: ");
            scanf("%f", &input);
            output = input * 0.453;
            printf("%.2f pounds is equal to %.2f kilograms.\n", input, output);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}