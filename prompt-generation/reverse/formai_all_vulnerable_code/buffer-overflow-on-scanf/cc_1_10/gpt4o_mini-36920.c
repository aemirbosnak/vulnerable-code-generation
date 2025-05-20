//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>

void show_menu();
void convert_length();
void convert_weight();
void convert_temperature();
void clear_input_buffer();

int main() {
    int choice;

    do {
        show_menu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                convert_length();
                break;
            case 2:
                convert_weight();
                break;
            case 3:
                convert_temperature();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

void show_menu() {
    printf("\n--- Unit Converter ---\n");
    printf("1. Convert Length\n");
    printf("2. Convert Weight\n");
    printf("3. Convert Temperature\n");
    printf("4. Exit\n");
}

void convert_length() {
    double value;
    int unit_from, unit_to;
    printf("Length Conversion:\n");
    printf("Convert from:\n1. Meters\n2. Kilometers\n3. Miles\n4. Feet\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &unit_from);
    
    printf("Convert to:\n1. Meters\n2. Kilometers\n3. Miles\n4. Feet\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &unit_to);
    
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    // Conversion factors
    double meters;
    switch (unit_from) {
        case 1: meters = value; break;          // Meters
        case 2: meters = value * 1000; break;   // Kilometers
        case 3: meters = value * 1609.34; break; // Miles
        case 4: meters = value * 0.3048; break; // Feet
        default: printf("Invalid selection.\n"); return;
    }

    // Convert from meters to the target unit
    switch (unit_to) {
        case 1: printf("%.2f Meters\n", meters); break;
        case 2: printf("%.2f Kilometers\n", meters / 1000); break;
        case 3: printf("%.2f Miles\n", meters / 1609.34); break;
        case 4: printf("%.2f Feet\n", meters / 0.3048); break;
        default: printf("Invalid selection.\n");
    }
}

void convert_weight() {
    double value;
    int unit_from, unit_to;
    printf("Weight Conversion:\n");
    printf("Convert from:\n1. Grams\n2. Kilograms\n3. Pounds\n4. Ounces\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &unit_from);
    
    printf("Convert to:\n1. Grams\n2. Kilograms\n3. Pounds\n4. Ounces\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &unit_to);
    
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    // Conversion factors
    double grams;
    switch (unit_from) {
        case 1: grams = value; break;           // Grams
        case 2: grams = value * 1000; break;    // Kilograms
        case 3: grams = value * 453.592; break; // Pounds
        case 4: grams = value * 28.3495; break; // Ounces
        default: printf("Invalid selection.\n"); return;
    }

    // Convert from grams to the target unit
    switch (unit_to) {
        case 1: printf("%.2f Grams\n", grams); break;
        case 2: printf("%.2f Kilograms\n", grams / 1000); break;
        case 3: printf("%.2f Pounds\n", grams / 453.592); break;
        case 4: printf("%.2f Ounces\n", grams / 28.3495); break;
        default: printf("Invalid selection.\n");
    }
}

void convert_temperature() {
    double value;
    int unit_from, unit_to;
    printf("Temperature Conversion:\n");
    printf("Convert from:\n1. Celsius\n2. Fahrenheit\n3. Kelvin\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &unit_from);
    
    printf("Convert to:\n1. Celsius\n2. Fahrenheit\n3. Kelvin\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &unit_to);
    
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    double celsius;
    switch (unit_from) {
        case 1: celsius = value; break;                  // Celsius
        case 2: celsius = (value - 32) * 5.0 / 9.0; break; // Fahrenheit
        case 3: celsius = value - 273.15; break;          // Kelvin
        default: printf("Invalid selection.\n"); return;
    }

    // Convert from celsius to the target unit
    switch (unit_to) {
        case 1: printf("%.2f Celsius\n", celsius); break;
        case 2: printf("%.2f Fahrenheit\n", celsius * 9.0 / 5.0 + 32); break;
        case 3: printf("%.2f Kelvin\n", celsius + 273.15); break;
        default: printf("Invalid selection.\n");
    }
}

void clear_input_buffer() {
    while (getchar() != '\n'); // Clear the input buffer
}