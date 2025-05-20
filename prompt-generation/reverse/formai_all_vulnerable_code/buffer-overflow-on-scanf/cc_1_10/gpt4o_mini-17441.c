//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: all-encompassing
#include <stdio.h>

// Function prototypes
void displayMenu();
void convertLength();
void convertWeight();
void convertTemperature();
void convertArea();
void convertVolume();
void convertSpeed();

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convertLength();
                break;
            case 2:
                convertWeight();
                break;
            case 3:
                convertTemperature();
                break;
            case 4:
                convertArea();
                break;
            case 5:
                convertVolume();
                break;
            case 6:
                convertSpeed();
                break;
            case 0:
                printf("Exiting the converter. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n--- Unit Converter ---\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Area\n");
    printf("5. Volume\n");
    printf("6. Speed\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}

void convertLength() {
    double value, result;
    int unitChoice;

    printf("\n--- Length Conversion ---\n");
    printf("Select the conversion:\n");
    printf("1. Meters to Feet\n");
    printf("2. Feet to Meters\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Miles to Kilometers\n");
    printf("Choose an option: ");
    scanf("%d", &unitChoice);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (unitChoice) {
        case 1:
            result = value * 3.28084; // Meters to Feet
            printf("%.2f Meters = %.2f Feet\n", value, result);
            break;
        case 2:
            result = value / 3.28084; // Feet to Meters
            printf("%.2f Feet = %.2f Meters\n", value, result);
            break;
        case 3:
            result = value * 0.621371; // Kilometers to Miles
            printf("%.2f Kilometers = %.2f Miles\n", value, result);
            break;
        case 4:
            result = value / 0.621371; // Miles to Kilometers
            printf("%.2f Miles = %.2f Kilometers\n", value, result);
            break;
        default:
            printf("Invalid choice for length conversion.\n");
    }
}

void convertWeight() {
    double value, result;
    int unitChoice;

    printf("\n--- Weight Conversion ---\n");
    printf("Select the conversion:\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Grams to Ounces\n");
    printf("4. Ounces to Grams\n");
    printf("Choose an option: ");
    scanf("%d", &unitChoice);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (unitChoice) {
        case 1:
            result = value * 2.20462; // Kilograms to Pounds
            printf("%.2f Kilograms = %.2f Pounds\n", value, result);
            break;
        case 2:
            result = value / 2.20462; // Pounds to Kilograms
            printf("%.2f Pounds = %.2f Kilograms\n", value, result);
            break;
        case 3:
            result = value * 0.035274; // Grams to Ounces
            printf("%.2f Grams = %.2f Ounces\n", value, result);
            break;
        case 4:
            result = value / 0.035274; // Ounces to Grams
            printf("%.2f Ounces = %.2f Grams\n", value, result);
            break;
        default:
            printf("Invalid choice for weight conversion.\n");
    }
}

void convertTemperature() {
    double value, result;
    int unitChoice;

    printf("\n--- Temperature Conversion ---\n");
    printf("Select the conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");
    printf("Choose an option: ");
    scanf("%d", &unitChoice);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (unitChoice) {
        case 1:
            result = (value * 9.0/5.0) + 32; // Celsius to Fahrenheit
            printf("%.2f Celsius = %.2f Fahrenheit\n", value, result);
            break;
        case 2:
            result = (value - 32) * 5.0/9.0; // Fahrenheit to Celsius
            printf("%.2f Fahrenheit = %.2f Celsius\n", value, result);
            break;
        case 3:
            result = value - 273.15; // Kelvin to Celsius
            printf("%.2f Kelvin = %.2f Celsius\n", value, result);
            break;
        case 4:
            result = value + 273.15; // Celsius to Kelvin
            printf("%.2f Celsius = %.2f Kelvin\n", value, result);
            break;
        default:
            printf("Invalid choice for temperature conversion.\n");
    }
}

void convertArea() {
    double value, result;
    int unitChoice;

    printf("\n--- Area Conversion ---\n");
    printf("Select the conversion:\n");
    printf("1. Square Meters to Acres\n");
    printf("2. Acres to Square Meters\n");
    printf("3. Hectares to Acres\n");
    printf("4. Acres to Hectares\n");
    printf("Choose an option: ");
    scanf("%d", &unitChoice);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (unitChoice) {
        case 1:
            result = value * 0.000247105; // Square Meters to Acres
            printf("%.2f Square Meters = %.2f Acres\n", value, result);
            break;
        case 2:
            result = value / 0.000247105; // Acres to Square Meters
            printf("%.2f Acres = %.2f Square Meters\n", value, result);
            break;
        case 3:
            result = value * 2.47105; // Hectares to Acres
            printf("%.2f Hectares = %.2f Acres\n", value, result);
            break;
        case 4:
            result = value / 2.47105; // Acres to Hectares
            printf("%.2f Acres = %.2f Hectares\n", value, result);
            break;
        default:
            printf("Invalid choice for area conversion.\n");
    }
}

void convertVolume() {
    double value, result;
    int unitChoice;

    printf("\n--- Volume Conversion ---\n");
    printf("Select the conversion:\n");
    printf("1. Liters to Gallons\n");
    printf("2. Gallons to Liters\n");
    printf("3. Cubic Meters to Cubic Feet\n");
    printf("4. Cubic Feet to Cubic Meters\n");
    printf("Choose an option: ");
    scanf("%d", &unitChoice);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (unitChoice) {
        case 1:
            result = value * 0.264172; // Liters to Gallons
            printf("%.2f Liters = %.2f Gallons\n", value, result);
            break;
        case 2:
            result = value / 0.264172; // Gallons to Liters
            printf("%.2f Gallons = %.2f Liters\n", value, result);
            break;
        case 3:
            result = value * 35.3147; // Cubic Meters to Cubic Feet
            printf("%.2f Cubic Meters = %.2f Cubic Feet\n", value, result);
            break;
        case 4:
            result = value / 35.3147; // Cubic Feet to Cubic Meters
            printf("%.2f Cubic Feet = %.2f Cubic Meters\n", value, result);
            break;
        default:
            printf("Invalid choice for volume conversion.\n");
    }
}

void convertSpeed() {
    double value, result;
    int unitChoice;

    printf("\n--- Speed Conversion ---\n");
    printf("Select the conversion:\n");
    printf("1. Kilometers per Hour to Miles per Hour\n");
    printf("2. Miles per Hour to Kilometers per Hour\n");
    printf("Choose an option: ");
    scanf("%d", &unitChoice);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (unitChoice) {
        case 1:
            result = value * 0.621371; // Kilometers per Hour to Miles per Hour
            printf("%.2f Kilometers per Hour = %.2f Miles per Hour\n", value, result);
            break;
        case 2:
            result = value / 0.621371; // Miles per Hour to Kilometers per Hour
            printf("%.2f Miles per Hour = %.2f Kilometers per Hour\n", value, result);
            break;
        default:
            printf("Invalid choice for speed conversion.\n");
    }
}