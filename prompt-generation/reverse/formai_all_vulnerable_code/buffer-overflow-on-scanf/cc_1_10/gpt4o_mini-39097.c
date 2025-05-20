//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: happy
#include <stdio.h>

void display_menu() {
    printf("\n🌟 Welcome to the Happy Unit Converter! 🌟\n");
    printf("Please choose a conversion type:\n");
    printf("1. Length (Meters to Feet)\n");
    printf("2. Weight (Kilograms to Pounds)\n");
    printf("3. Temperature (Celsius to Fahrenheit)\n");
    printf("4. Exit\n");
    printf("Happy converting! Enter your choice (1-4): ");
}

double meters_to_feet(double meters) {
    return meters * 3.28084;
}

double kilograms_to_pounds(double kilograms) {
    return kilograms * 2.20462;
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

void length_conversion() {
    double meters;
    printf("\n🌈 Enter the length in meters: ");
    scanf("%lf", &meters);
    double feet = meters_to_feet(meters);
    printf("🎉 %lf meters is equal to %lf feet!\n", meters, feet);
}

void weight_conversion() {
    double kilograms;
    printf("\n🌈 Enter the weight in kilograms: ");
    scanf("%lf", &kilograms);
    double pounds = kilograms_to_pounds(kilograms);
    printf("🎉 %lf kilograms is equal to %lf pounds!\n", kilograms, pounds);
}

void temperature_conversion() {
    double celsius;
    printf("\n🌈 Enter the temperature in Celsius: ");
    scanf("%lf", &celsius);
    double fahrenheit = celsius_to_fahrenheit(celsius);
    printf("🎉 %lf degrees Celsius is equal to %lf degrees Fahrenheit!\n", celsius, fahrenheit);
}

int main() {
    int choice = 0;

    while (choice != 4) {
        display_menu();
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
                printf("🌻 Thank you for using the Happy Unit Converter! Have a great day! 🌻\n");
                break;
            default:
                printf("🚫 Invalid choice! Please enter a number between 1 and 4.\n");
                break;
        }
    }
    
    return 0;
}