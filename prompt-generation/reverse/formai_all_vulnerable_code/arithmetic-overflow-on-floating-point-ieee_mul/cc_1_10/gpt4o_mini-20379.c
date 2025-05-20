//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: Dennis Ritchie
#include <stdio.h>

// Function prototypes for unit conversion
void convert_length();
void convert_weight();
void convert_temperature();
void convert_area();
void convert_volume();
void display_menu();

// Constants for conversion factors
const float METERS_TO_FEET = 3.28084;
const float KILOGRAMS_TO_POUNDS = 2.20462;
const float CELSIUS_TO_FAHRENHEIT_MULTIPLIER = 9.0 / 5.0;
const float CELSIUS_TO_FAHRENHEIT_OFFSET = 32.0;
const float SQUARE_METERS_TO_SQUARE_FEET = 10.7639;
const float LITERS_TO_GALLONS = 0.264172;

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice (1-5, or 0 to exit): ");
        scanf("%d", &choice);

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
                convert_area();
                break;
            case 5:
                convert_volume();
                break;
            case 0:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}

void display_menu() {
    printf("Unit Converter Menu:\n");
    printf("1. Length Conversion (meters to feet)\n");
    printf("2. Weight Conversion (kilograms to pounds)\n");
    printf("3. Temperature Conversion (Celsius to Fahrenheit)\n");
    printf("4. Area Conversion (square meters to square feet)\n");
    printf("5. Volume Conversion (liters to gallons)\n");
    printf("0. Exit\n");
}

void convert_length() {
    float meters, feet;
    printf("Enter length in meters: ");
    scanf("%f", &meters);
    feet = meters * METERS_TO_FEET;
    printf("%.2f meters is equal to %.2f feet.\n", meters, feet);
}

void convert_weight() {
    float kilograms, pounds;
    printf("Enter weight in kilograms: ");
    scanf("%f", &kilograms);
    pounds = kilograms * KILOGRAMS_TO_POUNDS;
    printf("%.2f kilograms is equal to %.2f pounds.\n", kilograms, pounds);
}

void convert_temperature() {
    float celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * CELSIUS_TO_FAHRENHEIT_MULTIPLIER) + CELSIUS_TO_FAHRENHEIT_OFFSET;
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);
}

void convert_area() {
    float square_meters, square_feet;
    printf("Enter area in square meters: ");
    scanf("%f", &square_meters);
    square_feet = square_meters * SQUARE_METERS_TO_SQUARE_FEET;
    printf("%.2f square meters is equal to %.2f square feet.\n", square_meters, square_feet);
}

void convert_volume() {
    float liters, gallons;
    printf("Enter volume in liters: ");
    scanf("%f", &liters);
    gallons = liters * LITERS_TO_GALLONS;
    printf("%.2f liters is equal to %.2f gallons.\n", liters, gallons);
}