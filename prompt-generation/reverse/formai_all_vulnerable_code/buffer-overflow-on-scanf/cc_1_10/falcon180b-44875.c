//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: optimized
#include <stdio.h>

// Function to convert length from meters to feet
float metersToFeet(float meters) {
    float feet = meters * 3.28084;
    return feet;
}

// Function to convert weight from kilograms to pounds
float kilogramsToPounds(float kilograms) {
    float pounds = kilograms * 2.20462;
    return pounds;
}

// Function to convert volume from liters to gallons
float litersToGallons(float liters) {
    float gallons = liters * 0.264172;
    return gallons;
}

// Function to convert temperature from Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 1.8) + 32;
    return fahrenheit;
}

int main() {
    char choice;
    float input, output;

    // Menu to choose conversion type
    printf("Unit Conversion Program\n");
    printf("1. Length (meters to feet)\n");
    printf("2. Weight (kilograms to pounds)\n");
    printf("3. Volume (liters to gallons)\n");
    printf("4. Temperature (Celsius to Fahrenheit)\n");
    printf("Enter your choice: ");
    scanf("%c", &choice);

    // Convert user input to uppercase
    choice = toupper(choice);

    // Perform conversion based on user choice
    switch(choice) {
        case '1':
            printf("Enter length in meters: ");
            scanf("%f", &input);
            output = metersToFeet(input);
            printf("%.2f meters is equal to %.2f feet.\n", input, output);
            break;
        case '2':
            printf("Enter weight in kilograms: ");
            scanf("%f", &input);
            output = kilogramsToPounds(input);
            printf("%.2f kilograms is equal to %.2f pounds.\n", input, output);
            break;
        case '3':
            printf("Enter volume in liters: ");
            scanf("%f", &input);
            output = litersToGallons(input);
            printf("%.2f liters is equal to %.2f gallons.\n", input, output);
            break;
        case '4':
            printf("Enter temperature in Celsius: ");
            scanf("%f", &input);
            output = celsiusToFahrenheit(input);
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", input, output);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}