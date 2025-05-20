//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: retro
#include <stdio.h>

int main() {
    int choice;
    double value, result = 0;

    printf("Welcome to the Retro Unit Converter!\n");
    printf("Select a unit to convert:\n");
    printf("1. Meters to Feet\n");
    printf("2. Kilograms to Pounds\n");
    printf("3. Celsius to Fahrenheit\n");
    printf("4. Liters to Gallons\n");
    printf("5. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the value in meters: ");
            scanf("%lf", &value);
            result = value * 3.28084;
            printf("The value in feet is: %.2lf\n", result);
            break;
        case 2:
            printf("Enter the value in kilograms: ");
            scanf("%lf", &value);
            result = value * 2.20462;
            printf("The value in pounds is: %.2lf\n", result);
            break;
        case 3:
            printf("Enter the value in Celsius: ");
            scanf("%lf", &value);
            result = (value * 9/5) + 32;
            printf("The value in Fahrenheit is: %.2lf\n", result);
            break;
        case 4:
            printf("Enter the value in liters: ");
            scanf("%lf", &value);
            result = value * 0.264172;
            printf("The value in gallons is: %.2lf\n", result);
            break;
        case 5:
            printf("Thank you for using the Retro Unit Converter!\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}