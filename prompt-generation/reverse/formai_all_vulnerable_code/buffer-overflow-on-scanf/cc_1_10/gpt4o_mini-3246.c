//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: immersive
#include <stdio.h>

// Function declarations
void display_menu();
void length_conversion();
void weight_conversion();
void temperature_conversion();
void volume_conversion();
void clear_buffer();

int main() {
    int choice;

    do {
        display_menu();
        printf("Enter your choice (1-5), or 0 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                length_conversion();
                break;
            case 2:
                weight_conversion();
                break;
            case 3:
                temperature_conversion();
                break;
            case 4:
                volume_conversion();
                break;
            case 5:
                printf("Thank you for using the Unit Converter. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}

void display_menu() {
    printf("\n==== Unit Converter ====\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("4. Volume Conversion\n");
    printf("5. Exit\n");
    printf("========================\n");
}

void length_conversion() {
    float meters, feet, inches;
    printf("Length Conversion:\n");
    printf("Enter length in meters: ");
    scanf("%f", &meters);

    feet = meters * 3.28084;
    inches = feet * 12;

    printf("%.2f meters is equal to %.2f feet.\n", meters, feet);
    printf("%.2f feet is equal to %.2f inches.\n", feet, inches);
}

void weight_conversion() {
    float kilograms, pounds, ounces;
    printf("\nWeight Conversion:\n");
    printf("Enter weight in kilograms: ");
    scanf("%f", &kilograms);

    pounds = kilograms * 2.20462;
    ounces = pounds * 16;

    printf("%.2f kilograms is equal to %.2f pounds.\n", kilograms, pounds);
    printf("%.2f pounds is equal to %.2f ounces.\n", pounds, ounces);
}

void temperature_conversion() {
    float celsius, fahrenheit;
    printf("\nTemperature Conversion:\n");
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9/5) + 32;

    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);
}

void volume_conversion() {
    float liters, gallons, cubic_meters;
    printf("\nVolume Conversion:\n");
    printf("Enter volume in liters: ");
    scanf("%f", &liters);

    gallons = liters * 0.264172;
    cubic_meters = liters / 1000;

    printf("%.2f liters is equal to %.2f gallons.\n", liters, gallons);
    printf("%.2f liters is equal to %.2f cubic meters.\n", liters, cubic_meters);
}

void clear_buffer() {
    while (getchar() != '\n');
}