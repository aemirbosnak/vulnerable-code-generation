//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>

void convert_length();
void convert_weight();
void convert_temperature();
void convert_volume();

void display_menu() {
    printf("\nWelcome to the Curious Unit Converter!\n");
    printf("Select a conversion type:\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Volume\n");
    printf("5. Exit\n");
    printf("Make your choice (1-5): ");
}

int main() {
    int choice;

    do {
        display_menu();
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
                convert_volume();
                break;
            case 5:
                printf("Thank you for using the Curious Unit Converter! Bye bye!\n");
                break;
            default:
                printf("Oops! That's not a valid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void convert_length() {
    double meters, feet;
    printf("\nLet's convert Length! How many meters do you want to convert? ");
    scanf("%lf", &meters);
    feet = meters * 3.28084; // 1 meter = 3.28084 feet
    printf("%.2f meters is lovely as %.2f feet!\n", meters, feet);
}

void convert_weight() {
    double kilograms, pounds;
    printf("\nTime for Weight Wonders! Please enter weight in kilograms: ");
    scanf("%lf", &kilograms);
    pounds = kilograms * 2.20462; // 1 kilogram = 2.20462 pounds
    printf("%.2f kilograms puts on a brave  %.2f pounds!\n", kilograms, pounds);
}

void convert_temperature() {
    double celsius, fahrenheit;
    printf("\nTemperature Transformation Time! What's your temperature in Celsius? ");
    scanf("%lf", &celsius);
    fahrenheit = (celsius * 9.0 / 5.0) + 32; // Convert Celsius to Fahrenheit
    printf("%.2f degrees Celsius is a steamy %.2f degrees Fahrenheit!\n", celsius, fahrenheit);
}

void convert_volume() {
    double liters, gallons;
    printf("\nVolume Ventures Ahead! Please enter volume in liters: ");
    scanf("%lf", &liters);
    gallons = liters * 0.264172; // 1 liter = 0.264172 gallons
    printf("%.2f liters will fill up your tank with %.2f gallons!\n", liters, gallons);
}