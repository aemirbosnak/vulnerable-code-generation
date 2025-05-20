//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare the variables
    float value, converted_value;
    int choice;

    // Display the menu
    printf("Unit Converter\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Exit\n");

    // Get the user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Convert the value based on the user's choice
    switch (choice) {
        case 1:
            printf("Enter the value to be converted: ");
            scanf("%f", &value);
            printf("1. Inches to Centimeters\n");
            printf("2. Centimeters to Inches\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    converted_value = value * 2.54;
                    printf("%f inches is equal to %f centimeters\n", value, converted_value);
                    break;
                case 2:
                    converted_value = value / 2.54;
                    printf("%f centimeters is equal to %f inches\n", value, converted_value);
                    break;
                default:
                    printf("Invalid choice\n");
            }
            break;
        case 2:
            printf("Enter the value to be converted: ");
            scanf("%f", &value);
            printf("1. Pounds to Kilograms\n");
            printf("2. Kilograms to Pounds\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    converted_value = value * 0.453592;
                    printf("%f pounds is equal to %f kilograms\n", value, converted_value);
                    break;
                case 2:
                    converted_value = value / 0.453592;
                    printf("%f kilograms is equal to %f pounds\n", value, converted_value);
                    break;
                default:
                    printf("Invalid choice\n");
            }
            break;
        case 3:
            printf("Enter the value to be converted: ");
            scanf("%f", &value);
            printf("1. Fahrenheit to Celsius\n");
            printf("2. Celsius to Fahrenheit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    converted_value = (value - 32) * 5 / 9;
                    printf("%f Fahrenheit is equal to %f Celsius\n", value, converted_value);
                    break;
                case 2:
                    converted_value = (value * 9 / 5) + 32;
                    printf("%f Celsius is equal to %f Fahrenheit\n", value, converted_value);
                    break;
                default:
                    printf("Invalid choice\n");
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
    }

    return 0;
}