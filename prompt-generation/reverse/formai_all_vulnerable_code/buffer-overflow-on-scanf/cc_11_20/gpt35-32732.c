//FormAI DATASET v1.0 Category: Unit converter ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int choice;
    double value, result;

    printf("Welcome to Unit Converter!\n");
    printf("------------------------------------\n");

    printf("Please select an option:\n");
    printf("1. Feet to Meter\t\t\t2. Meter to Feet\n");
    printf("3. Pounds to Kilograms\t\t4. Kilograms to Pounds\n");
    printf("5. Gallon to Liter\t\t6. Liter to Gallon\n");
    printf("7. Fahrenheit to Celsius\t8. Celsius to Fahrenheit\n");
    printf("9. Miles to Kilometers\t\t10. Kilometers to Miles\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter the value in Feet: ");
            scanf("%lf", &value);
            result = value * 0.3048;
            printf("%.2lf feet = %.2lf meters.\n", value, result);
            break;
        case 2:
            printf("Enter the value in Meters: ");
            scanf("%lf", &value);
            result = value / 0.3048;
            printf("%.2lf meters = %.2lf feet.\n", value, result);
            break;
        case 3:
            printf("Enter the value in Pounds: ");
            scanf("%lf", &value);
            result = value * 0.453592;
            printf("%.2lf pounds = %.2lf kilograms.\n", value, result);
            break;
        case 4:
            printf("Enter the value in Kilograms: ");
            scanf("%lf", &value);
            result = value / 0.453592;
            printf("%.2lf kilograms = %.2lf pounds.\n", value, result);
            break;
        case 5:
            printf("Enter the value in Gallons: ");
            scanf("%lf", &value);
            result = value * 3.78541;
            printf("%.2lf gallons = %.2lf liters.\n", value, result);
            break;
        case 6:
            printf("Enter the value in Liters: ");
            scanf("%lf", &value);
            result = value / 3.78541;
            printf("%.2lf liters = %.2lf gallons.\n", value, result);
            break;
        case 7:
            printf("Enter the value in Fahrenheit: ");
            scanf("%lf", &value);
            result = (value - 32) / 1.8;
            printf("%.2lf F = %.2lf C.\n", value, result);
            break;
        case 8:
            printf("Enter the value in Celsius: ");
            scanf("%lf", &value);
            result = (value * 1.8) + 32;
            printf("%.2lf C = %.2lf F.\n", value, result);
            break;
        case 9:
            printf("Enter the value in Miles: ");
            scanf("%lf", &value);
            result = value * 1.60934;
            printf("%.2lf miles = %.2lf kilometers.\n", value, result);
            break;
        case 10:
            printf("Enter the value in Kilometers: ");
            scanf("%lf", &value);
            result = value / 1.60934;
            printf("%.2lf kilometers = %.2lf miles.\n", value, result);
            break;
        default:
            printf("Invalid Choice. Please try again.\n");
            break;
    }

    return 0;
}