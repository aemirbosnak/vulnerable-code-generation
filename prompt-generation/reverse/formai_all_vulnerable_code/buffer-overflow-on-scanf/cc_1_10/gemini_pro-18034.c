//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: cheerful
#include <stdio.h>

int main() {
    // Declare variables
    float input, result;
    int choice;

    // Display a cheerful greeting
    printf("Hello, there! Welcome to the Unit Converter Extravaganza!\n");

    // Display the conversion options
    printf("What kind of conversion would you like to make?\n");
    printf("1. Inches to Centimeters\n");
    printf("2. Centimeters to Inches\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Kilometers to Miles\n");
    printf("5. Pounds to Kilograms\n");
    printf("6. Kilograms to Pounds\n");
    printf("7. Gallons to Liters\n");
    printf("8. Liters to Gallons\n");

    // Get the user's choice
    printf("Enter your choice (1-8): ");
    scanf("%d", &choice);

    // Get the input value
    printf("Enter the value to be converted: ");
    scanf("%f", &input);

    // Perform the conversion
    switch (choice) {
        case 1:
            result = input * 2.54;
            printf("%.2f inches is %.2f centimeters.\n", input, result);
            break;
        case 2:
            result = input / 2.54;
            printf("%.2f centimeters is %.2f inches.\n", input, result);
            break;
        case 3:
            result = input * 1.60934;
            printf("%.2f miles is %.2f kilometers.\n", input, result);
            break;
        case 4:
            result = input / 1.60934;
            printf("%.2f kilometers is %.2f miles.\n", input, result);
            break;
        case 5:
            result = input * 0.453592;
            printf("%.2f pounds is %.2f kilograms.\n", input, result);
            break;
        case 6:
            result = input / 0.453592;
            printf("%.2f kilograms is %.2f pounds.\n", input, result);
            break;
        case 7:
            result = input * 3.78541;
            printf("%.2f gallons is %.2f liters.\n", input, result);
            break;
        case 8:
            result = input / 3.78541;
            printf("%.2f liters is %.2f gallons.\n", input, result);
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 8.\n");
            break;
    }

    // Display a cheerful farewell
    printf("Thank you for using the Unit Converter Extravaganza! Have a wonderful day!\n");

    return 0;
}