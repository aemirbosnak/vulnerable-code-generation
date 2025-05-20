//FormAI DATASET v1.0 Category: Unit converter ; Style: artistic
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int option;
    float value, result;

    printf("Welcome to the Artistic Unit Converter!\n");
    printf("Choose the conversion type from the following list:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Meters to Feet\n");
    printf("4. Feet to Meters\n");
    printf("5. Kilograms to Pounds\n");
    printf("6. Pounds to Kilograms\n");
    printf("Enter option: ");
    scanf("%d", &option);
    
    switch(option)
    {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &value);
            result = (value * 9/5) + 32;
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", value, result);
            break;

        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &value);
            result = (value - 32) * 5/9;
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", value, result);
            break;
        
        case 3:
            printf("Enter distance in meters: ");
            scanf("%f", &value);
            result = value * 3.281;
            printf("%.2f meters is equal to %.2f feet.\n", value, result);
            break;
        
        case 4:
            printf("Enter distance in feet: ");
            scanf("%f", &value);
            result = value * 0.3048;
            printf("%.2f feet is equal to %.2f meters.\n", value, result);
            break;

        case 5:
            printf("Enter weight in kilograms: ");
            scanf("%f", &value);
            result = value * 2.20462;
            printf("%.2f kilograms is equal to %.2f pounds.\n", value, result);
            break;

        case 6:
            printf("Enter weight in pounds: ");
            scanf("%f", &value);
            result = value * 0.453592;
            printf("%.2f pounds is equal to %.2f kilograms.\n", value, result);
            break;

        default:
            printf("Invalid option selected. Please select an option from the list.\n");
            break;
    }

    printf("\nThank you for using Artistic Unit Converter!\n");

    return 0;
}