//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: unmistakable
#include <stdio.h>

// Function prototypes for unit conversion
float feetToMeters(float feet);
float metersToFeet(float meters);
float poundsToKilograms(float pounds);
float kilogramsToPounds(float kilograms);
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);

// Main function
int main() {
    int choice;
    float value, result;

    printf("Welcome to the Ultimate Unit Converter! 🌍\n");
    printf("What would you like to convert?\n");
    printf("1. Feet to Meters\n");
    printf("2. Meters to Feet\n");
    printf("3. Pounds to Kilograms\n");
    printf("4. Kilograms to Pounds\n");
    printf("5. Celsius to Fahrenheit\n");
    printf("6. Fahrenheit to Celsius\n");
    printf("7. Exit\n");
    
    while (1) {
        printf("\nEnter your choice (1-7): ");
        scanf("%d", &choice);

        // Exit the program if the user chooses option 7
        if (choice == 7) {
            printf("Thank you for using the Ultimate Unit Converter! Goodbye! 👋\n");
            break;
        }

        // Prompt the user for the value to convert
        printf("Enter the value to convert: ");
        scanf("%f", &value);

        switch (choice) {
            case 1:
                result = feetToMeters(value);
                printf("%.2f feet is equal to %.2f meters.\n", value, result);
                break;
            case 2:
                result = metersToFeet(value);
                printf("%.2f meters is equal to %.2f feet.\n", value, result);
                break;
            case 3:
                result = poundsToKilograms(value);
                printf("%.2f pounds is equal to %.2f kilograms.\n", value, result);
                break;
            case 4:
                result = kilogramsToPounds(value);
                printf("%.2f kilograms is equal to %.2f pounds.\n", value, result);
                break;
            case 5:
                result = celsiusToFahrenheit(value);
                printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", value, result);
                break;
            case 6:
                result = fahrenheitToCelsius(value);
                printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", value, result);
                break;
            default:
                printf("Invalid choice! Please select a number between 1 and 7.\n");
                break;
        }
    }

    return 0;
}

// Function definitions for unit conversions
float feetToMeters(float feet) {
    return feet * 0.3048;
}

float metersToFeet(float meters) {
    return meters / 0.3048;
}

float poundsToKilograms(float pounds) {
    return pounds * 0.453592;
}

float kilogramsToPounds(float kilograms) {
    return kilograms / 0.453592;
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}