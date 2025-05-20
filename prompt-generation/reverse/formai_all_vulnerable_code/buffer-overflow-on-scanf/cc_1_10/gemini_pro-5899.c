//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: beginner-friendly
#include <stdio.h>

// Define the conversion factors
#define INCHES_TO_CM 2.54
#define CM_TO_INCHES 0.393701
#define POUNDS_TO_KILOGRAMS 0.453592
#define KILOGRAMS_TO_POUNDS 2.20462
#define GALLONS_TO_LITERS 3.78541
#define LITERS_TO_GALLONS 0.264172

// Function to convert inches to centimeters
float inches_to_cm(float inches) {
    return inches * INCHES_TO_CM;
}

// Function to convert centimeters to inches
float cm_to_inches(float centimeters) {
    return centimeters * CM_TO_INCHES;
}

// Function to convert pounds to kilograms
float pounds_to_kilograms(float pounds) {
    return pounds * POUNDS_TO_KILOGRAMS;
}

// Function to convert kilograms to pounds
float kilograms_to_pounds(float kilograms) {
    return kilograms * KILOGRAMS_TO_POUNDS;
}

// Function to convert gallons to liters
float gallons_to_liters(float gallons) {
    return gallons * GALLONS_TO_LITERS;
}

// Function to convert liters to gallons
float liters_to_gallons(float liters) {
    return liters * LITERS_TO_GALLONS;
}

// Main function
int main() {
    // Declare the input and output variables
    float input_value, output_value;
    int choice;

    // Display the menu of conversion options
    printf("Unit Converter\n");
    printf("1. Inches to Centimeters\n");
    printf("2. Centimeters to Inches\n");
    printf("3. Pounds to Kilograms\n");
    printf("4. Kilograms to Pounds\n");
    printf("5. Gallons to Liters\n");
    printf("6. Liters to Gallons\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Get the input value from the user
    printf("Enter the value to be converted: ");
    scanf("%f", &input_value);

    // Perform the conversion based on the user's choice
    switch (choice) {
        case 1:
            output_value = inches_to_cm(input_value);
            break;
        case 2:
            output_value = cm_to_inches(input_value);
            break;
        case 3:
            output_value = pounds_to_kilograms(input_value);
            break;
        case 4:
            output_value = kilograms_to_pounds(input_value);
            break;
        case 5:
            output_value = gallons_to_liters(input_value);
            break;
        case 6:
            output_value = liters_to_gallons(input_value);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    // Display the result
    printf("The converted value is: %.2f\n", output_value);

    return 0;
}