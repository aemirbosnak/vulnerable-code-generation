//FormAI DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>

int main() {
    printf("Welcome to the Ultimate Unit Converter!\n");
    printf("We can convert anything, from height in feet to temperature in kelvin!\n");
    printf("What do you want to convert today?\n");
    printf("(1) Feet to Meters\n");
    printf("(2) Pounds to Kilograms\n");
    printf("(3) Miles to Kilometers\n");
    printf("(4) Fahrenheit to Celsius\n");
    printf("(5) Inches to Centimeters\n");
    printf("(6) Gallons to Liters\n");
    printf("(7) Quit\n");

    int choice;
    double input, result;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter height in feet: ");
            scanf("%lf", &input);
            result = input * 0.3048;
            printf("%.2lf feet is equal to %.2lf meters\n", input, result);
            break;
        case 2:
            printf("Enter weight in pounds: ");
            scanf("%lf", &input);
            result = input * 0.453592;
            printf("%.2lf pounds is equal to %.2lf kilograms\n", input, result);
            break;
        case 3:
            printf("Enter distance in miles: ");
            scanf("%lf", &input);
            result = input * 1.60934;
            printf("%.2lf miles is equal to %.2lf kilometers\n", input, result);
            break;
        case 4:
            printf("Enter temperature in fahrenheit: ");
            scanf("%lf", &input);
            result = (input - 32) * 5/9;
            printf("%.2lf fahrenheit is equal to %.2lf celsius\n", input, result);
            break;
        case 5:
            printf("Enter length in inches: ");
            scanf("%lf", &input);
            result = input * 2.54;
            printf("%.2lf inches is equal to %.2lf centimeters\n", input, result);
            break;
        case 6:
            printf("Enter volume in gallons: ");
            scanf("%lf", &input);
            result = input * 3.78541;
            printf("%.2lf gallons is equal to %.2lf liters\n", input, result);
            break;
        case 7:
            printf("Thanks for using the Ultimate Unit Converter!\n");
            return 0;
        default:
            printf("Invalid choice! Please enter a number between 1 and 7\n");
            break;
    }
    main();
}