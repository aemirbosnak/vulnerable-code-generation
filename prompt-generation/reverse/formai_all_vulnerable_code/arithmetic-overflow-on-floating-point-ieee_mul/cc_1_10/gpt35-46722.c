//FormAI DATASET v1.0 Category: Unit converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    float value, result;

    printf("Welcome to the C Unit Converter!\n\n");
    printf("Choose an option from the following list:\n");
    printf("1. Kilometers to Miles\n");
    printf("2. Centimeters to Inches\n");
    printf("3. Meters to Feet\n");
    printf("4. Celsius to Fahrenheit\n");
    printf("5. Fahrenheit to Celsius\n");
    printf("6. Kilograms to Pounds\n");
    printf("7. Grams to Ounces\n");
    printf("8. Exit\n\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter a value in kilometers: ");
                scanf("%f", &value);
                result = value * 0.621371;
                printf("%.2f km = %.2f mi\n\n", value, result);
                break;

            case 2:
                printf("\nEnter a value in centimeters: ");
                scanf("%f", &value);
                result = value * 0.393701;
                printf("%.2f cm = %.2f in\n\n", value, result);
                break;

            case 3:
                printf("\nEnter a value in meters: ");
                scanf("%f", &value);
                result = value * 3.28084;
                printf("%.2f m = %.2f ft\n\n", value, result);
                break;

            case 4:
                printf("\nEnter a value in Celsius: ");
                scanf("%f", &value);
                result = (value * 9/5) + 32;
                printf("%.2f C = %.2f F\n\n", value, result);
                break;

            case 5:
                printf("\nEnter a value in Fahrenheit: ");
                scanf("%f", &value);
                result = (value - 32) * 5/9;
                printf("%.2f F = %.2f C\n\n", value, result);
                break;

            case 6:
                printf("\nEnter a value in kilograms: ");
                scanf("%f", &value);
                result = value * 2.20462;
                printf("%.2f kg = %.2f lb\n\n", value, result);
                break;

            case 7:
                printf("\nEnter a value in grams: ");
                scanf("%f", &value);
                result = value * 0.035274;
                printf("%.2f g = %.2f oz\n\n", value, result);
                break;

            case 8:
                printf("\nThank you for using the C Unit Converter!");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n\n");
        }
    }

    return 0;
}