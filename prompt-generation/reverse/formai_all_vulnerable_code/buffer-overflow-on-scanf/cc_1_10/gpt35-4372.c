//FormAI DATASET v1.0 Category: Unit converter ; Style: active
#include <stdio.h>

// Converts Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

// Converts Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Converts Miles to Kilometers
float milesToKilometers(float miles) {
    return miles * 1.60934;
}

// Converts Kilometers to Miles
float kilometersToMiles(float kilometers) {
    return kilometers * 0.621371;
}

// Converts Pounds to Kilograms
float poundsToKilograms(float pounds) {
    return pounds * 0.453592;
}

// Converts Kilograms to Pounds
float kilogramsToPounds(float kilograms) {
    return kilograms * 2.20462;
}

// Main function
int main() {
    int choice;
    float value, result;
    
    // Display menu
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Kilometers to Miles\n");
    printf("5. Pounds to Kilograms\n");
    printf("6. Kilograms to Pounds\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &value);
            result = celsiusToFahrenheit(value);
            printf("%.2f Celsius = %.2f Fahrenheit", value, result);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &value);
            result = fahrenheitToCelsius(value);
            printf("%.2f Fahrenheit = %.2f Celsius", value, result);
            break;
        case 3:
            printf("Enter distance in miles: ");
            scanf("%f", &value);
            result = milesToKilometers(value);
            printf("%.2f miles = %.2f kilometers", value, result);
            break;
        case 4:
            printf("Enter distance in kilometers: ");
            scanf("%f", &value);
            result = kilometersToMiles(value);
            printf("%.2f kilometers = %.2f miles", value, result);
            break;
        case 5:
            printf("Enter weight in pounds: ");
            scanf("%f", &value);
            result = poundsToKilograms(value);
            printf("%.2f pounds = %.2f kilograms", value, result);
            break;
        case 6:
            printf("Enter weight in kilograms: ");
            scanf("%f", &value);
            result = kilogramsToPounds(value);
            printf("%.2f kilograms = %.2f pounds", value, result);
            break;
        default:
            printf("Invalid choice!");
    }
    
    return 0;
}