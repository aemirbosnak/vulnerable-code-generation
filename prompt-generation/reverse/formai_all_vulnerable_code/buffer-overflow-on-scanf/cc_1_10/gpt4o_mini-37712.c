//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>

void convert_length(float value, int from_unit, int to_unit);
void convert_weight(float value, int from_unit, int to_unit);
void convert_temperature(float value, int from_unit, int to_unit);
void display_length_menu();
void display_weight_menu();
void display_temperature_menu();

int main() {
    int choice, from_unit, to_unit;
    float value;

    do {
        printf("\n=== Unit Converter ===\n");
        printf("1. Length\n");
        printf("2. Weight\n");
        printf("3. Temperature\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            break;
        }

        printf("Enter the value to convert: ");
        scanf("%f", &value);
        
        switch (choice) {
            case 1:
                display_length_menu();
                printf("Enter from unit (1-4): ");
                scanf("%d", &from_unit);
                printf("Enter to unit (1-4): ");
                scanf("%d", &to_unit);
                convert_length(value, from_unit, to_unit);
                break;

            case 2:
                display_weight_menu();
                printf("Enter from unit (1-4): ");
                scanf("%d", &from_unit);
                printf("Enter to unit (1-4): ");
                scanf("%d", &to_unit);
                convert_weight(value, from_unit, to_unit);
                break;

            case 3:
                display_temperature_menu();
                printf("Enter from unit (1-3): ");
                scanf("%d", &from_unit);
                printf("Enter to unit (1-3): ");
                scanf("%d", &to_unit);
                convert_temperature(value, from_unit, to_unit);
                break;

            default:
                printf("Invalid option, please try again.\n");
        }
    } while (1);

    printf("Thank you for using the unit converter!\n");
    return 0;
}

void display_length_menu() {
    printf("\n--- Length Units ---\n");
    printf("1. Meters\n");
    printf("2. Kilometers\n");
    printf("3. Feet\n");
    printf("4. Miles\n");
}

void display_weight_menu() {
    printf("\n--- Weight Units ---\n");
    printf("1. Grams\n");
    printf("2. Kilograms\n");
    printf("3. Pounds\n");
    printf("4. Ounces\n");
}

void display_temperature_menu() {
    printf("\n--- Temperature Units ---\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n");
}

void convert_length(float value, int from_unit, int to_unit) {
    float converted_value;

    // Length conversion factors
    if(from_unit == 1) value = value; // Meters
    else if(from_unit == 2) value *= 1000; // Kilometers to Meters
    else if(from_unit == 3) value *= 0.3048; // Feet to Meters
    else if(from_unit == 4) value *= 1609.34; // Miles to Meters

    if(to_unit == 1) converted_value = value; // Meters
    else if(to_unit == 2) converted_value = value / 1000; // Meters to Kilometers
    else if(to_unit == 3) converted_value = value / 0.3048; // Meters to Feet
    else if(to_unit == 4) converted_value = value / 1609.34; // Meters to Miles

    printf("Converted Length: %.2f\n", converted_value);
}

void convert_weight(float value, int from_unit, int to_unit) {
    float converted_value;

    // Weight conversion factors
    if(from_unit == 1) value = value; // Grams
    else if(from_unit == 2) value *= 1000; // Kilograms to Grams
    else if(from_unit == 3) value *= 453.592; // Pounds to Grams
    else if(from_unit == 4) value *= 28.3495; // Ounces to Grams

    if(to_unit == 1) converted_value = value; // Grams
    else if(to_unit == 2) converted_value = value / 1000; // Grams to Kilograms
    else if(to_unit == 3) converted_value = value / 453.592; // Grams to Pounds
    else if(to_unit == 4) converted_value = value / 28.3495; // Grams to Ounces

    printf("Converted Weight: %.2f\n", converted_value);
}

void convert_temperature(float value, int from_unit, int to_unit) {
    float converted_value;

    // Temperature conversion
    if (from_unit == 1) { // Celsius to Other
        if (to_unit == 1) converted_value = value; // Celsius to Celsius
        else if (to_unit == 2) converted_value = (value * 9/5) + 32; // Celsius to Fahrenheit
        else if (to_unit == 3) converted_value = value + 273.15; // Celsius to Kelvin
    }
    else if (from_unit == 2) { // Fahrenheit to Other
        if (to_unit == 1) converted_value = (value - 32) * 5/9; // Fahrenheit to Celsius
        else if (to_unit == 2) converted_value = value; // Fahrenheit to Fahrenheit
        else if (to_unit == 3) converted_value = (value - 32) * 5/9 + 273.15; // Fahrenheit to Kelvin
    }
    else if (from_unit == 3) { // Kelvin to Other
        if (to_unit == 1) converted_value = value - 273.15; // Kelvin to Celsius
        else if (to_unit == 2) converted_value = (value - 273.15) * 9/5 + 32; // Kelvin to Fahrenheit
        else if (to_unit == 3) converted_value = value; // Kelvin to Kelvin
    }

    printf("Converted Temperature: %.2f\n", converted_value);
}