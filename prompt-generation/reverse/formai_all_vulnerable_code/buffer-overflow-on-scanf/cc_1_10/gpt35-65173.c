//FormAI DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include <stdio.h>

float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float meters_to_feet(float meters);
float feet_to_meters(float feet);
float kilograms_to_pounds(float kilograms);
float pounds_to_kilograms(float pounds);

int main() {
    float temp_celsius, temp_fahrenheit, distance_feet, distance_meters, weight_kilos, weight_pounds;
    
    // Convert temperature from Celsius to Fahrenheit
    printf("Enter temperature in Celsius: ");
    scanf("%f", &temp_celsius);
    temp_fahrenheit = celsius_to_fahrenheit(temp_celsius);
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temp_celsius, temp_fahrenheit);
    
    // Convert temperature from Fahrenheit to Celsius
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &temp_fahrenheit);
    temp_celsius = fahrenheit_to_celsius(temp_fahrenheit);
    printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temp_fahrenheit, temp_celsius);
    
    // Convert distance from meters to feet
    printf("Enter distance in meters: ");
    scanf("%f", &distance_meters);
    distance_feet = meters_to_feet(distance_meters);
    printf("%.2f meters is equal to %.2f feet.\n", distance_meters, distance_feet);
    
    // Convert distance from feet to meters
    printf("Enter distance in feet: ");
    scanf("%f", &distance_feet);
    distance_meters = feet_to_meters(distance_feet);
    printf("%.2f feet is equal to %.2f meters.\n", distance_feet, distance_meters);
    
    // Convert weight from kilograms to pounds
    printf("Enter weight in kilograms: ");
    scanf("%f", &weight_kilos);
    weight_pounds = kilograms_to_pounds(weight_kilos);
    printf("%.2f kilograms is equal to %.2f pounds.\n", weight_kilos, weight_pounds);
    
    // Convert weight from pounds to kilograms
    printf("Enter weight in pounds: ");
    scanf("%f", &weight_pounds);
    weight_kilos = pounds_to_kilograms(weight_pounds);
    printf("%.2f pounds is equal to %.2f kilograms.\n", weight_pounds, weight_kilos);
    
    return 0;
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float meters_to_feet(float meters) {
    return meters * 3.28;
}

float feet_to_meters(float feet) {
    return feet / 3.28;
}

float kilograms_to_pounds(float kilograms) {
    return kilograms * 2.205;
}

float pounds_to_kilograms(float pounds) {
    return pounds / 2.205;
}