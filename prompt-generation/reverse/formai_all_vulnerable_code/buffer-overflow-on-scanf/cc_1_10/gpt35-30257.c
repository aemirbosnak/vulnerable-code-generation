//FormAI DATASET v1.0 Category: Unit converter ; Style: Ada Lovelace
/* This program converts various units of measurement using Ada Lovelace's conversion factors and style */

#include <stdio.h>

// Function to convert miles to kilometers
float miles_to_km(float miles) {
    return miles * 1.60934;
}

// Function to convert feet to meters
float feet_to_meters(float feet) {
    return feet * 0.3048;
}

// Function to convert pounds to kilograms
float lbs_to_kgs(float lbs) {
    return lbs * 0.453592;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * (5.0/9.0);
}

int main() {
    float miles, km, feet, meters, lbs, kgs, fahrenheit, celsius;
    
    printf("Welcome to Ada Lovelace's unit converter!\n\n");
    
    // Convert miles to kilometers
    printf("Enter the number of miles to convert to kilometers: ");
    scanf("%f", &miles);
    km = miles_to_km(miles);
    printf("%f miles is equal to %f kilometers\n", miles, km);
    
    // Convert feet to meters
    printf("\nEnter the number of feet to convert to meters: ");
    scanf("%f", &feet);
    meters = feet_to_meters(feet);
    printf("%f feet is equal to %f meters\n", feet, meters);
    
    // Convert pounds to kilograms
    printf("\nEnter the number of pounds to convert to kilograms: ");
    scanf("%f", &lbs);
    kgs = lbs_to_kgs(lbs);
    printf("%f pounds is equal to %f kilograms\n", lbs, kgs);
    
    // Convert Fahrenheit to Celsius
    printf("\nEnter the temperature in Fahrenheit to convert to Celsius: ");
    scanf("%f", &fahrenheit);
    celsius = fahrenheit_to_celsius(fahrenheit);
    printf("%f degrees Fahrenheit is equal to %f degrees Celsius\n", fahrenheit, celsius);
    
    printf("\nThank you for using Ada Lovelace's unit converter! Goodbye.");
    
    return 0;
}