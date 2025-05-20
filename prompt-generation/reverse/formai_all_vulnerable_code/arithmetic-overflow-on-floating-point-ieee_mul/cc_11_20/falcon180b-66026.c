//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    float value, result;

    printf("Welcome to the Unit Converter!\n");
    printf("Enter 1 for length conversion\n");
    printf("Enter 2 for weight conversion\n");
    printf("Enter 3 for temperature conversion\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the value in meters: ");
            scanf("%f", &value);
            printf("Enter the unit to convert to:\n1. Millimeters\n2. Centimeters\n3. Kilometers\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    result = value * 1000;
                    printf("The value in millimeters is: %.2f", result);
                    break;

                case 2:
                    result = value / 100;
                    printf("The value in centimeters is: %.2f", result);
                    break;

                case 3:
                    result = value / 1000;
                    printf("The value in kilometers is: %.2f", result);
                    break;

                default:
                    printf("Invalid choice!");
                    break;
            }

            break;

        case 2:
            printf("Enter the value in kilograms: ");
            scanf("%f", &value);
            printf("Enter the unit to convert to:\n1. Grams\n2. Ounces\n3. Pounds\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    result = value * 1000;
                    printf("The value in grams is: %.2f", result);
                    break;

                case 2:
                    result = value * 35.274;
                    printf("The value in ounces is: %.2f", result);
                    break;

                case 3:
                    result = value * 2.20462;
                    printf("The value in pounds is: %.2f", result);
                    break;

                default:
                    printf("Invalid choice!");
                    break;
            }

            break;

        case 3:
            printf("Enter the value in Celsius: ");
            scanf("%f", &value);
            printf("Enter the unit to convert to:\n1. Fahrenheit\n2. Kelvin\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    result = (value * 9/5) + 32;
                    printf("The value in Fahrenheit is: %.2f", result);
                    break;

                case 2:
                    result = value + 273.15;
                    printf("The value in Kelvin is: %.2f", result);
                    break;

                default:
                    printf("Invalid choice!");
                    break;
            }

            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}