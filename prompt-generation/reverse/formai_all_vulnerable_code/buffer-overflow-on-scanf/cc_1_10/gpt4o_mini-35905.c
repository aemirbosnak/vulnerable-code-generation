//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: cheerful
#include <stdio.h>

void displayMenu() {
    printf("\n*** Welcome to the Cheerful Unit Converter! ***\n");
    printf("Please choose the conversion type:\n");
    printf("1. Length (Meters to Feet and vice versa)\n");
    printf("2. Weight (Kilograms to Pounds and vice versa)\n");
    printf("3. Temperature (Celsius to Fahrenheit and vice versa)\n");
    printf("4. Exit\n");
    printf("********************************************\n");
}

float metersToFeet(float meters) {
    return meters * 3.28084;
}

float feetToMeters(float feet) {
    return feet / 3.28084;
}

float kilogramsToPounds(float kilograms) {
    return kilograms * 2.20462;
}

float poundsToKilograms(float pounds) {
    return pounds / 2.20462;
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    int choice;
    float input, output;

    do {
        displayMenu();
        
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Length conversion
                printf("Enter length in meters: ");
                scanf("%f", &input);
                output = metersToFeet(input);
                printf("%.2f meters is equal to %.2f feet!\n", input, output);
                
                printf("Enter length in feet: ");
                scanf("%f", &input);
                output = feetToMeters(input);
                printf("%.2f feet is equal to %.2f meters!\n", input, output);
                break;
                
            case 2: // Weight conversion
                printf("Enter weight in kilograms: ");
                scanf("%f", &input);
                output = kilogramsToPounds(input);
                printf("%.2f kilograms is equal to %.2f pounds!\n", input, output);
                
                printf("Enter weight in pounds: ");
                scanf("%f", &input);
                output = poundsToKilograms(input);
                printf("%.2f pounds is equal to %.2f kilograms!\n", input, output);
                break;

            case 3: // Temperature conversion
                printf("Enter temperature in Celsius: ");
                scanf("%f", &input);
                output = celsiusToFahrenheit(input);
                printf("%.2f Celsius is equal to %.2f Fahrenheit!\n", input, output);
                
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &input);
                output = fahrenheitToCelsius(input);
                printf("%.2f Fahrenheit is equal to %.2f Celsius!\n", input, output);
                break;

            case 4:
                printf("Thank you for using the Cheerful Unit Converter! Have a wonderful day! 🌞\n");
                break;

            default:
                printf("Oops! Please enter a valid choice between 1 and 4.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}