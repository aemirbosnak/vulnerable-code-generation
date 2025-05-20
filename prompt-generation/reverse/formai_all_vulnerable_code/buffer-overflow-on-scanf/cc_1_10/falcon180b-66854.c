//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>

// Function to convert temperature from Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// Function to convert distance from kilometers to miles
float kilometers_to_miles(float kilometers) {
    float miles = kilometers * 0.621371;
    return miles;
}

// Function to convert weight from kilograms to pounds
float kilograms_to_pounds(float kilograms) {
    float pounds = kilograms * 2.20462;
    return pounds;
}

// Function to convert volume from liters to gallons
float liters_to_gallons(float liters) {
    float gallons = liters * 0.264172;
    return gallons;
}

int main() {
    float celsius, fahrenheit, kilometers, miles, kilograms, pounds, liters, gallons;

    // Get user input for temperature conversion
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert Celsius to Fahrenheit
    fahrenheit = celsius_to_fahrenheit(celsius);
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);

    // Get user input for distance conversion
    printf("Enter distance in kilometers: ");
    scanf("%f", &kilometers);

    // Convert kilometers to miles
    miles = kilometers_to_miles(kilometers);
    printf("%.2f kilometers is equal to %.2f miles.\n", kilometers, miles);

    // Get user input for weight conversion
    printf("Enter weight in kilograms: ");
    scanf("%f", &kilograms);

    // Convert kilograms to pounds
    pounds = kilograms_to_pounds(kilograms);
    printf("%.2f kilograms is equal to %.2f pounds.\n", kilograms, pounds);

    // Get user input for volume conversion
    printf("Enter volume in liters: ");
    scanf("%f", &liters);

    // Convert liters to gallons
    gallons = liters_to_gallons(liters);
    printf("%.2f liters is equal to %.2f gallons.\n", liters, gallons);

    return 0;
}