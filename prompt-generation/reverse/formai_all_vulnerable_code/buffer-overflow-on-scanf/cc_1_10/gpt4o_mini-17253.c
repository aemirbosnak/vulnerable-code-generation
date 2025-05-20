//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>

void displayMenu() {
    printf("\n=== Unit Converter ===\n");
    printf("1. Length Converter\n");
    printf("2. Weight Converter\n");
    printf("3. Temperature Converter\n");
    printf("4. Area Converter\n");
    printf("5. Volume Converter\n");
    printf("6. Exit\n");
    printf("=======================\n");
    printf("Select an option (1-6): ");
}

void lengthConverter() {
    double value, converted;
    int choice;

    printf("\n=== Length Converter ===\n");
    printf("1. Meters to Feet\n");
    printf("2. Feet to Meters\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Miles to Kilometers\n");
    printf("Enter your choice (1-4): ");
    
    scanf("%d", &choice);
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch(choice) {
        case 1:
            converted = value * 3.28084;
            printf("%.2lf Meters = %.2lf Feet\n", value, converted);
            break;
        case 2:
            converted = value / 3.28084;
            printf("%.2lf Feet = %.2lf Meters\n", value, converted);
            break;
        case 3:
            converted = value * 0.621371;
            printf("%.2lf Kilometers = %.2lf Miles\n", value, converted);
            break;
        case 4:
            converted = value / 0.621371;
            printf("%.2lf Miles = %.2lf Kilometers\n", value, converted);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void weightConverter() {
    double value, converted;
    int choice;

    printf("\n=== Weight Converter ===\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Grams to Ounces\n");
    printf("4. Ounces to Grams\n");
    printf("Enter your choice (1-4): ");
    
    scanf("%d", &choice);
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch(choice) {
        case 1:
            converted = value * 2.20462;
            printf("%.2lf Kilograms = %.2lf Pounds\n", value, converted);
            break;
        case 2:
            converted = value / 2.20462;
            printf("%.2lf Pounds = %.2lf Kilograms\n", value, converted);
            break;
        case 3:
            converted = value * 0.035274;
            printf("%.2lf Grams = %.2lf Ounces\n", value, converted);
            break;
        case 4:
            converted = value / 0.035274;
            printf("%.2lf Ounces = %.2lf Grams\n", value, converted);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void temperatureConverter() {
    double value, converted;
    int choice;

    printf("\n=== Temperature Converter ===\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");
    printf("Enter your choice (1-4): ");
    
    scanf("%d", &choice);
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch(choice) {
        case 1:
            converted = (value * 9/5) + 32;
            printf("%.2lf Celsius = %.2lf Fahrenheit\n", value, converted);
            break;
        case 2:
            converted = (value - 32) * 5/9;
            printf("%.2lf Fahrenheit = %.2lf Celsius\n", value, converted);
            break;
        case 3:
            converted = value - 273.15;
            printf("%.2lf Kelvin = %.2lf Celsius\n", value, converted);
            break;
        case 4:
            converted = value + 273.15;
            printf("%.2lf Celsius = %.2lf Kelvin\n", value, converted);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void areaConverter() {
    double value, converted;
    int choice;

    printf("\n=== Area Converter ===\n");
    printf("1. Square Meters to Acres\n");
    printf("2. Acres to Square Meters\n");
    printf("3. Hectares to Acres\n");
    printf("4. Acres to Hectares\n");
    printf("Enter your choice (1-4): ");
    
    scanf("%d", &choice);
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch(choice) {
        case 1:
            converted = value * 0.000247105;
            printf("%.2lf Square Meters = %.2lf Acres\n", value, converted);
            break;
        case 2:
            converted = value / 0.000247105;
            printf("%.2lf Acres = %.2lf Square Meters\n", value, converted);
            break;
        case 3:
            converted = value * 2.47105;
            printf("%.2lf Hectares = %.2lf Acres\n", value, converted);
            break;
        case 4:
            converted = value / 2.47105;
            printf("%.2lf Acres = %.2lf Hectares\n", value, converted);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void volumeConverter() {
    double value, converted;
    int choice;

    printf("\n=== Volume Converter ===\n");
    printf("1. Liters to Gallons\n");
    printf("2. Gallons to Liters\n");
    printf("3. Cubic Meters to Liters\n");
    printf("4. Liters to Cubic Meters\n");
    printf("Enter your choice (1-4): ");
    
    scanf("%d", &choice);
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch(choice) {
        case 1:
            converted = value * 0.264172;
            printf("%.2lf Liters = %.2lf Gallons\n", value, converted);
            break;
        case 2:
            converted = value / 0.264172;
            printf("%.2lf Gallons = %.2lf Liters\n", value, converted);
            break;
        case 3:
            converted = value * 1000;
            printf("%.2lf Cubic Meters = %.2lf Liters\n", value, converted);
            break;
        case 4:
            converted = value / 1000;
            printf("%.2lf Liters = %.2lf Cubic Meters\n", value, converted);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                lengthConverter();
                break;
            case 2:
                weightConverter();
                break;
            case 3:
                temperatureConverter();
                break;
            case 4:
                areaConverter();
                break;
            case 5:
                volumeConverter();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please select again.\n");
        }
    } while(choice != 6);

    return 0;
}