//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>

// Function prototypes
void lengthConverter();
void weightConverter();
void temperatureConverter();
void displayMenu();
void clearBuffer();

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        clearBuffer(); // Clear buffer to avoid input issues

        switch (choice) {
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
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);
    return 0;
}

void displayMenu() {
    printf("\n=========================\n");
    printf("       Unit Converter    \n");
    printf("=========================\n");
    printf("1. Length Converter\n");
    printf("2. Weight Converter\n");
    printf("3. Temperature Converter\n");
    printf("4. Exit\n");
}

void lengthConverter() {
    int choice;
    double value, result;

    printf("\nLength Converter\n");
    printf("Select the conversion type:\n");
    printf("1. Meters to Kilometers\n");
    printf("2. Kilometers to Meters\n");
    printf("3. Meters to Centimeters\n");
    printf("4. Centimeters to Meters\n");
    printf("5. Inches to Centimeters\n");
    printf("6. Centimeters to Inches\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);
    clearBuffer();

    printf("Enter value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            result = value / 1000.0;
            printf("%.2lf Meters = %.2lf Kilometers\n", value, result);
            break;
        case 2:
            result = value * 1000.0;
            printf("%.2lf Kilometers = %.2lf Meters\n", value, result);
            break;
        case 3:
            result = value * 100.0;
            printf("%.2lf Meters = %.2lf Centimeters\n", value, result);
            break;
        case 4:
            result = value / 100.0;
            printf("%.2lf Centimeters = %.2lf Meters\n", value, result);
            break;
        case 5:
            result = value * 2.54;
            printf("%.2lf Inches = %.2lf Centimeters\n", value, result);
            break;
        case 6:
            result = value / 2.54;
            printf("%.2lf Centimeters = %.2lf Inches\n", value, result);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

void weightConverter() {
    int choice;
    double value, result;

    printf("\nWeight Converter\n");
    printf("Select the conversion type:\n");
    printf("1. Grams to Kilograms\n");
    printf("2. Kilograms to Grams\n");
    printf("3. Grams to Pounds\n");
    printf("4. Pounds to Grams\n");
    printf("5. Kilograms to Pounds\n");
    printf("6. Pounds to Kilograms\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);
    clearBuffer();

    printf("Enter value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            result = value / 1000.0;
            printf("%.2lf Grams = %.2lf Kilograms\n", value, result);
            break;
        case 2:
            result = value * 1000.0;
            printf("%.2lf Kilograms = %.2lf Grams\n", value, result);
            break;
        case 3:
            result = value * 0.00220462;
            printf("%.2lf Grams = %.2lf Pounds\n", value, result);
            break;
        case 4:
            result = value / 0.00220462;
            printf("%.2lf Pounds = %.2lf Grams\n", value, result);
            break;
        case 5:
            result = value * 2.20462;
            printf("%.2lf Kilograms = %.2lf Pounds\n", value, result);
            break;
        case 6:
            result = value / 2.20462;
            printf("%.2lf Pounds = %.2lf Kilograms\n", value, result);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

void temperatureConverter() {
    int choice;
    double value, result;

    printf("\nTemperature Converter\n");
    printf("Select the conversion type:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);
    clearBuffer();

    printf("Enter value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            result = (value * 9.0 / 5.0) + 32.0;
            printf("%.2lf Celsius = %.2lf Fahrenheit\n", value, result);
            break;
        case 2:
            result = (value - 32.0) * 5.0 / 9.0;
            printf("%.2lf Fahrenheit = %.2lf Celsius\n", value, result);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}