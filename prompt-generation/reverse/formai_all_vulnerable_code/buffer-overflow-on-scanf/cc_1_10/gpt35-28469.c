//FormAI DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>

void display_menu();
float convert_temperature(float value, char from_unit, char to_unit);
float convert_distance(float value, char from_unit, char to_unit);
float convert_weight(float value, char from_unit, char to_unit);

int main() {
    int choice;
    float value, result;
    char from_unit, to_unit;
    
    printf("Welcome to the Unit Converter!\n");
    
    do {
        display_menu();
        
        // Get user input
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice < 1 || choice > 3) {
            printf("Invalid input. Please try again.\n");
            continue;
        }
        
        printf("Enter the value to be converted: ");
        scanf("%f", &value);
        
        printf("Enter the unit to convert from: ");
        scanf(" %c", &from_unit);
        
        printf("Enter the unit to convert to: ");
        scanf(" %c", &to_unit);
        
        // Perform the appropriate conversion
        switch (choice) {
            case 1:
                result = convert_temperature(value, from_unit, to_unit);
                printf("%.2f%c = %.2f%c\n", value, from_unit, result, to_unit);
                break;
            case 2:
                result = convert_distance(value, from_unit, to_unit);
                printf("%.2f%c = %.2f%c\n", value, from_unit, result, to_unit);
                break;
            case 3:
                result = convert_weight(value, from_unit, to_unit);
                printf("%.2f%c = %.2f%c\n", value, from_unit, result, to_unit);
                break;
        }
        
        printf("\n");
        
    } while (1);
    
    return 0;
}

void display_menu() {
    printf("Please choose an option from the menu below:\n");
    printf("1. Convert temperature (C, F, K)\n");
    printf("2. Convert distance (m, ft, km)\n");
    printf("3. Convert weight (g, kg, lb)\n");
}

float convert_temperature(float value, char from_unit, char to_unit) {
    float result = 0;
    
    // Convert to Celsius first
    if (from_unit == 'F') {
        result = (value - 32) * 5 / 9;
    } else if (from_unit == 'K') {
        result = value - 273.15;
    } else { // from_unit == 'C'
        result = value;
    }
    
    // Convert to destination unit
    if (to_unit == 'F') {
        result = result * 9 / 5 + 32;
    } else if (to_unit == 'K') {
        result = result + 273.15;
    } else { // to_unit == 'C'
        // result is already in Celsius
    }
    
    return result;
}

float convert_distance(float value, char from_unit, char to_unit) {
    float result = 0;
    
    // Convert to meters first
    if (from_unit == 'ft') {
        result = value * 0.3048;
    } else if (from_unit == 'km') {
        result = value * 1000;
    } else { // from_unit == 'm'
        result = value;
    }
    
    // Convert to destination unit
    if (to_unit == 'ft') {
        result = result / 0.3048;
    } else if (to_unit == 'km') {
        result = result / 1000;
    } else { // to_unit == 'm'
        // result is already in meters
    }
    
    return result;
}

float convert_weight(float value, char from_unit, char to_unit) {
    float result = 0;
    
    // Convert to grams first
    if (from_unit == 'kg') {
        result = value * 1000;
    } else if (from_unit == 'lb') {
        result = value * 453.592;
    } else { // from_unit == 'g'
        result = value;
    }
    
    // Convert to destination unit
    if (to_unit == 'kg') {
        result = result / 1000;
    } else if (to_unit == 'lb') {
        result = result / 453.592;
    } else { // to_unit == 'g'
        // result is already in grams
    }
    
    return result;
}