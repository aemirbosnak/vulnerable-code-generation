//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: shape shifting
#include <stdio.h>

typedef enum {
    METERS_TO_FEET,
    FEET_TO_METERS,
    KILOGRAMS_TO_POUNDS,
    POUNDS_TO_KILOGRAMS,
    CELSIUS_TO_FAHRENHEIT,
    FAHRENHEIT_TO_CELSIUS,
    LITERS_TO_GALLONS,
    GALLONS_TO_LITERS,
    EXIT
} ConversionType;

void print_menu() {
    printf("\n----- Shape-Shifting Unit Converter -----\n");
    printf("Choose your conversion:\n");
    printf("1. Meters to Feet\n");
    printf("2. Feet to Meters\n");
    printf("3. Kilograms to Pounds\n");
    printf("4. Pounds to Kilograms\n");
    printf("5. Celsius to Fahrenheit\n");
    printf("6. Fahrenheit to Celsius\n");
    printf("7. Liters to Gallons\n");
    printf("8. Gallons to Liters\n");
    printf("9. Exit\n");
    printf("Please enter your choice (1-9): ");
}

void convert_units(int choice) {
    float input, output;

    switch (choice) {
        case 1:
            printf("Enter length in meters: ");
            scanf("%f", &input);
            output = input * 3.28084;
            printf("%.2f meters = %.2f feet\n", input, output);
            break;
        case 2:
            printf("Enter length in feet: ");
            scanf("%f", &input);
            output = input / 3.28084;
            printf("%.2f feet = %.2f meters\n", input, output);
            break;
        case 3:
            printf("Enter weight in kilograms: ");
            scanf("%f", &input);
            output = input * 2.20462;
            printf("%.2f kilograms = %.2f pounds\n", input, output);
            break;
        case 4:
            printf("Enter weight in pounds: ");
            scanf("%f", &input);
            output = input / 2.20462;
            printf("%.2f pounds = %.2f kilograms\n", input, output);
            break;
        case 5:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &input);
            output = (input * 9 / 5) + 32;
            printf("%.2f Celsius = %.2f Fahrenheit\n", input, output);
            break;
        case 6:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &input);
            output = (input - 32) * 5 / 9;
            printf("%.2f Fahrenheit = %.2f Celsius\n", input, output);
            break;
        case 7:
            printf("Enter volume in liters: ");
            scanf("%f", &input);
            output = input / 3.78541;
            printf("%.2f liters = %.2f gallons\n", input, output);
            break;
        case 8:
            printf("Enter volume in gallons: ");
            scanf("%f", &input);
            output = input * 3.78541;
            printf("%.2f gallons = %.2f liters\n", input, output);
            break;
        case 9:
            printf("Exiting the program. Thank you!\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
}

int main() {
    int choice;
    
    while (1) {
        print_menu();
        scanf("%d", &choice);
        if (choice == EXIT) {
            break;
        } else {
            convert_units(choice);
        }
    }

    return 0;
}