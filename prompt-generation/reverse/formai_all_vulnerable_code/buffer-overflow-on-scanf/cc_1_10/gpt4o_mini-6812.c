//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: shape shifting
#include <stdio.h>

// Function declarations
void convert_length();
void convert_mass();
void convert_temperature();
void display_menu();

int main() {
    int choice;
    
    do {
        display_menu();
        printf("Choose a conversion type (1-3) or 0 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convert_length();
                break;
            case 2:
                convert_mass();
                break;
            case 3:
                convert_temperature();
                break;
            case 0:
                printf("Exiting the converter. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
        printf("\n");
    } while (choice != 0);

    return 0;
}

void display_menu() {
    printf("=== Shape-Shifting Unit Converter ===\n");
    printf("1. Length Converter\n");
    printf("2. Mass Converter\n");
    printf("3. Temperature Converter\n");
}

void convert_length() {
    double value;
    int choice;

    printf("--- Length Converter ---\n");
    printf("1. Meters to Kilometers\n");
    printf("2. Kilometers to Meters\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Kilometers to Miles\n");
    printf("Choose conversion type (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter value in Meters: ");
            scanf("%lf", &value);
            printf("%.2lf Meters = %.2lf Kilometers\n", value, value / 1000.0);
            break;
        case 2:
            printf("Enter value in Kilometers: ");
            scanf("%lf", &value);
            printf("%.2lf Kilometers = %.2lf Meters\n", value, value * 1000.0);
            break;
        case 3:
            printf("Enter value in Miles: ");
            scanf("%lf", &value);
            printf("%.2lf Miles = %.2lf Kilometers\n", value, value * 1.60934);
            break;
        case 4:
            printf("Enter value in Kilometers: ");
            scanf("%lf", &value);
            printf("%.2lf Kilometers = %.2lf Miles\n", value, value / 1.60934);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void convert_mass() {
    double value;
    int choice;

    printf("--- Mass Converter ---\n");
    printf("1. Kilograms to Grams\n");
    printf("2. Grams to Kilograms\n");
    printf("3. Pounds to Kilograms\n");
    printf("4. Kilograms to Pounds\n");
    printf("Choose conversion type (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter value in Kilograms: ");
            scanf("%lf", &value);
            printf("%.2lf Kilograms = %.2lf Grams\n", value, value * 1000.0);
            break;
        case 2:
            printf("Enter value in Grams: ");
            scanf("%lf", &value);
            printf("%.2lf Grams = %.2lf Kilograms\n", value, value / 1000.0);
            break;
        case 3:
            printf("Enter value in Pounds: ");
            scanf("%lf", &value);
            printf("%.2lf Pounds = %.2lf Kilograms\n", value, value * 0.453592);
            break;
        case 4:
            printf("Enter value in Kilograms: ");
            scanf("%lf", &value);
            printf("%.2lf Kilograms = %.2lf Pounds\n", value, value / 0.453592);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void convert_temperature() {
    double value;
    int choice;

    printf("--- Temperature Converter ---\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("Choose conversion type (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter value in Celsius: ");
            scanf("%lf", &value);
            printf("%.2lf Celsius = %.2lf Fahrenheit\n", value, (value * 9.0/5.0) + 32.0);
            break;
        case 2:
            printf("Enter value in Fahrenheit: ");
            scanf("%lf", &value);
            printf("%.2lf Fahrenheit = %.2lf Celsius\n", value, (value - 32.0) * 5.0/9.0);
            break;
        case 3:
            printf("Enter value in Celsius: ");
            scanf("%lf", &value);
            printf("%.2lf Celsius = %.2lf Kelvin\n", value, value + 273.15);
            break;
        case 4:
            printf("Enter value in Kelvin: ");
            scanf("%lf", &value);
            printf("%.2lf Kelvin = %.2lf Celsius\n", value, value - 273.15);
            break;
        default:
            printf("Invalid choice!\n");
    }
}