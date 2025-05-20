//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: introspective
#include <stdio.h>

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    // Calculate temperature difference from freezing point of water
    float temperature_difference = fahrenheit - 32.0;
    
    // Multiply temperature difference by 5 and divide by 9 to get Celsius value
    float celsius = temperature_difference * 5.0 / 9.0;
    
    return celsius;
}

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    // Multiply Celsius value by 9 and divide by 5 to get temperature difference from freezing point of water
    float temperature_difference = celsius * 9.0 / 5.0;
    
    // Add 32.0 to get Fahrenheit value
    float fahrenheit = temperature_difference + 32.0;
    
    return fahrenheit;
}

int main() {
    // Declare variables for temperature input and conversion
    float fahrenheit, celsius;

    // Ask user for temperature input in Fahrenheit
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    // Convert Fahrenheit to Celsius using function
    celsius = fahrenheit_to_celsius(fahrenheit);

    // Print temperature conversion result
    printf("Temperature in Celsius: %.2f\n", celsius);

    // Ask user for temperature input in Celsius
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert Celsius to Fahrenheit using function
    fahrenheit = celsius_to_fahrenheit(celsius);

    // Print temperature conversion result
    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);

    return 0;
}