//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: Ada Lovelace
#include <stdio.h>

// Function prototypes for unit conversions
float fahrenheit_to_celsius(float f);
float celsius_to_fahrenheit(float c);
float miles_to_kilometers(float miles);
float kilometers_to_miles(float km);
float pounds_to_kilograms(float lbs);
float kilograms_to_pounds(float kg);

// Function to display the conversion menu and handle user choice
void display_menu() {
    printf("\nUnit Converter:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Kilometers to Miles\n");
    printf("5. Pounds to Kilograms\n");
    printf("6. Kilograms to Pounds\n");
    printf("7. Exit\n");
    printf("Enter your choice (1-7): ");
}

// Function for Fahrenheit to Celsius conversion
float fahrenheit_to_celsius(float f) {
    return (f - 32) * 5.0 / 9.0;
}

// Function for Celsius to Fahrenheit conversion
float celsius_to_fahrenheit(float c) {
    return (c * 9.0 / 5.0) + 32;
}

// Function for Miles to Kilometers conversion
float miles_to_kilometers(float miles) {
    return miles * 1.60934;
}

// Function for Kilometers to Miles conversion
float kilometers_to_miles(float km) {
    return km / 1.60934;
}

// Function for Pounds to Kilograms conversion
float pounds_to_kilograms(float lbs) {
    return lbs * 0.453592;
}

// Function for Kilograms to Pounds conversion
float kilograms_to_pounds(float kg) {
    return kg / 0.453592;
}

// Main function to run the unit converter
int main() {
    int choice;
    float input, result;

    while (1) {
        display_menu(); // Show available conversions
        scanf("%d", &choice); // Get user's choice

        switch (choice) {
            case 1:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &input);
                result = fahrenheit_to_celsius(input);
                printf("%.2f Fahrenheit = %.2f Celsius\n", input, result);
                break;
            case 2:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &input);
                result = celsius_to_fahrenheit(input);
                printf("%.2f Celsius = %.2f Fahrenheit\n", input, result);
                break;
            case 3:
                printf("Enter distance in Miles: ");
                scanf("%f", &input);
                result = miles_to_kilometers(input);
                printf("%.2f Miles = %.2f Kilometers\n", input, result);
                break;
            case 4:
                printf("Enter distance in Kilometers: ");
                scanf("%f", &input);
                result = kilometers_to_miles(input);
                printf("%.2f Kilometers = %.2f Miles\n", input, result);
                break;
            case 5:
                printf("Enter weight in Pounds: ");
                scanf("%f", &input);
                result = pounds_to_kilograms(input);
                printf("%.2f Pounds = %.2f Kilograms\n", input, result);
                break;
            case 6:
                printf("Enter weight in Kilograms: ");
                scanf("%f", &input);
                result = kilograms_to_pounds(input);
                printf("%.2f Kilograms = %.2f Pounds\n", input, result);
                break;
            case 7:
                printf("Exiting the Unit Converter. Thank you!\n");
                return 0; // Exit the program
            default:
                printf("Invalid choice! Please select a valid option (1-7).\n");
        }
    }
    
    return 0; // Ensure a return from main
}