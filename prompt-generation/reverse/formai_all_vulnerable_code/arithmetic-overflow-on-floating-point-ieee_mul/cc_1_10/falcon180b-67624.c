//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: artistic
#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    float amount, result;

    printf("Welcome to the Artistic Unit Converter!\n");
    printf("Please select the unit you want to convert from:\n");
    printf("1. Meters\n");
    printf("2. Kilometers\n");
    printf("3. Grams\n");
    printf("4. Kilograms\n");
    printf("5. Liters\n");
    printf("6. Milliliters\n");
    printf("7. Celsius\n");
    printf("8. Fahrenheit\n");
    scanf("%d", &choice);

    printf("Enter the amount you want to convert: ");
    scanf("%f", &amount);

    switch(choice) {
        case 1:
            printf("You entered %.2f meters.\n", amount);
            result = amount * 100;
            printf("This is equal to %.2f centimeters.\n", result);
            break;
        case 2:
            printf("You entered %.2f kilometers.\n", amount);
            result = amount * 1000;
            printf("This is equal to %.2f meters.\n", result);
            break;
        case 3:
            printf("You entered %.2f grams.\n", amount);
            result = amount * 1000;
            printf("This is equal to %.2f kilograms.\n", result);
            break;
        case 4:
            printf("You entered %.2f kilograms.\n", amount);
            result = amount * 1000;
            printf("This is equal to %.2f grams.\n", result);
            break;
        case 5:
            printf("You entered %.2f liters.\n", amount);
            result = amount * 1000;
            printf("This is equal to %.2f milliliters.\n", result);
            break;
        case 6:
            printf("You entered %.2f milliliters.\n", amount);
            result = amount / 1000;
            printf("This is equal to %.2f liters.\n", result);
            break;
        case 7:
            printf("You entered %.2f degrees Celsius.\n", amount);
            result = (amount * 9/5) + 32;
            printf("This is equal to %.2f degrees Fahrenheit.\n", result);
            break;
        case 8:
            printf("You entered %.2f degrees Fahrenheit.\n", amount);
            result = (amount - 32) * 5/9;
            printf("This is equal to %.2f degrees Celsius.\n", result);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}