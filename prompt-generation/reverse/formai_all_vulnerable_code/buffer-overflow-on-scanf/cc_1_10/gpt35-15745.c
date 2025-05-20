//FormAI DATASET v1.0 Category: Unit converter ; Style: happy
#include <stdio.h>

int main() {
    printf("\n***************************************************************\n");
    printf("\t Welcome to the Happy Unit Converter\n");
    printf("***************************************************************\n\n");

    printf("This Awesome converter can convert:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Kilometers to Miles\n");
    printf("3. Kilograms to Pounds\n");
    printf("4. Meters to Feet\n");
    printf("5. Liters to Gallons\n\n");

    // Let's ask the user what they want to convert
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    double value;
    printf("Enter the value you want to convert: ");
    scanf("%lf", &value);

    double result;
    
    switch(choice) {
        case 1:
            result = (value * 9/5) + 32;
            printf("%lf Celsius = %lf Fahrenheit\n", value, result);
            break;
        case 2:
            result = value * 0.621371;
            printf("%lf Kilometers = %lf Miles\n", value, result);
            break;
        case 3:
            result = value * 2.20462;
            printf("%lf Kilograms = %lf Pounds\n", value, result);
            break;
        case 4:
            result = value * 3.28084;
            printf("%lf Meters = %lf Feet\n", value, result);
            break;
        case 5:
            result = value * 0.264172;
            printf("%lf Liters = %lf Gallons\n", value, result);
            break;
        default:
            printf("Invalid choice! Please enter a number between 1 and 5.\n");
    }

    printf("\nThank you for using the Happy Unit Converter! Have a great day!\n");

    return 0;
}