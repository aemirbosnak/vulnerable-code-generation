//FormAI DATASET v1.0 Category: Unit converter ; Style: imaginative
#include <stdio.h>
#include <stdbool.h>

int main() {
    int choice;
    double value, result;

    printf("********************** Unit Converter **********************\n\n");
    printf("Enter the quantity to be converted:\n");
    printf("1. Length\n2. Temperature\n3. Mass\n4. Volume\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nEnter the value of length in meters: ");
        scanf("%lf", &value);
        printf("\nChoose the conversion unit:");
        printf("\n1. Kilometers");
        printf("\n2. Centimeters");
        printf("\n3. Miles");
        printf("\n4. Feet");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                result = value / 1000.0;
                printf("%.2lf meters is equal to %.2lf kilometers", value, result);
                break;
            case 2:
                result = value * 100.0;
                printf("%.2lf meters is equal to %.2lf centimeters", value, result);
                break;
           case 3:
                result = value / 1609.0;
                printf("%.2lf meters is equal to %.2lf miles", value, result);
                break;
            case 4:
                result = value * 3.281;
                printf("%.2lf meters is equal to %.2lf feet", value, result);
                break;
            default:
                printf("Invalid choice");
        }
    }

    else if (choice == 2) {
        printf("\nEnter the value of temperature in Celsius: ");
        scanf("%lf", &value);
        printf("\nChoose the conversion unit:");
        printf("\n1. Fahrenheit");
        printf("\n2. Kelvin");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                result = (value * 9/5) + 32;
                printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit", value, result);
                break;
            case 2:
                result = value + 273.15;
                printf("%.2lf degrees Celsius is equal to %.2lf Kelvin", value, result);
                break;
            default:
                printf("Invalid choice");
        }
    }

    else if (choice == 3) {
        printf("\nEnter the value of mass in kilograms: ");
        scanf("%lf", &value);
        printf("\nChoose the conversion unit:");
        printf("\n1. Pounds");
        printf("\n2. Ounces");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                result = value * 2.205;
                printf("%.2lf kilograms is equal to %.2lf pounds", value, result);
                break;
            case 2:
                result = value * 35.274;
                printf("%.2lf kilograms is equal to %.2lf ounces", value, result);
                break;
            default:
                printf("Invalid choice");
        }
    }

    else if (choice == 4) {
        printf("\nEnter the value of volume in liters: ");
        scanf("%lf", &value);
        printf("\nChoose the conversion unit:");
        printf("\n1. Milliliters");
        printf("\n2. Gallons");
        printf("\n3. Fluid Ounces");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                result = value * 1000;
                printf("%.2lf liters is equal to %.2lf milliliters", value, result);
                break;
            case 2:
                result = value / 3.785;
                printf("%.2lf liters is equal to %.2lf gallons", value, result);
                break;
            case 3:
                result = value * 33.814;
                printf("%.2lf liters is equal to %.2lf fluid ounces", value, result);
                break;
            default:
                printf("Invalid choice");
        }
    }

    else {
        printf("Invalid choice");
    }

    printf("\n\n********************** Thank You! **********************\n");

    return 0;
}