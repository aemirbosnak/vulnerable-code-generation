//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: inquisitive
#include <stdio.h>

void lengthConversion() {
    float meters, kilometers, centimeters, inches;
    printf("Enter length in meters: ");
    scanf("%f", &meters);
    
    kilometers = meters / 1000.0;
    centimeters = meters * 100.0;
    inches = meters * 39.3701;

    printf("\nLength Conversion:\n");
    printf("%.2f meters = %.2f kilometers\n", meters, kilometers);
    printf("%.2f meters = %.2f centimeters\n", meters, centimeters);
    printf("%.2f meters = %.2f inches\n\n", meters, inches);
}

void temperatureConversion() {
    float celsius, fahrenheit, kelvin;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    
    fahrenheit = (celsius * 9/5) + 32;
    kelvin = celsius + 273.15;

    printf("\nTemperature Conversion:\n");
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
    printf("%.2f Celsius = %.2f Kelvin\n\n", celsius, kelvin);
}

int main() {
    int choice;

    while (1) {
        printf("Welcome to the unit converter! What would you like to convert?\n");
        printf("1. Length (meters)\n");
        printf("2. Temperature (Celsius)\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                lengthConversion();
                break;
            case 2:
                temperatureConversion();
                break;
            case 3:
                printf("Thank you for using the unit converter! Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please enter a number between 1 and 3.\n\n");
                break;
        }
    }

    return 0;
}