//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: excited
#include <stdio.h>

// Function to convert temperature from Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius)
{
    return (celsius * 1.8) + 32;
}

// Function to convert temperature from Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit)
{
    return (fahrenheit - 32) / 1.8;
}

// Function to convert length from centimeters to inches
float centimetersToInches(float centimeters)
{
    return centimeters / 2.54;
}

// Function to convert length from inches to centimeters
float inchesToCentimeters(float inches)
{
    return inches * 2.54;
}

// Function to convert weight from kilograms to pounds
float kilogramsToPounds(float kilograms)
{
    return kilograms * 2.2;
}

// Function to convert weight from pounds to kilograms
float poundsToKilograms(float pounds)
{
    return pounds / 2.2;
}

// Function to convert volume from liters to gallons
float litersToGallons(float liters)
{
    return liters * 0.264172;
}

// Function to convert volume from gallons to liters
float gallonsToLiters(float gallons)
{
    return gallons / 0.264172;
}

int main()
{
    float celsius, fahrenheit, centimeters, inches, kilograms, pounds, liters, gallons;

    // Get user input for Celsius temperature
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert Celsius to Fahrenheit and display result
    printf("%.2f Celsius is equivalent to %.2f Fahrenheit.\n", celsius, celsiusToFahrenheit(celsius));

    // Get user input for Fahrenheit temperature
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    // Convert Fahrenheit to Celsius and display result
    printf("%.2f Fahrenheit is equivalent to %.2f Celsius.\n", fahrenheit, fahrenheitToCelsius(fahrenheit));

    // Get user input for length in centimeters
    printf("Enter length in centimeters: ");
    scanf("%f", &centimeters);

    // Convert centimeters to inches and display result
    printf("%.2f centimeters is equivalent to %.2f inches.\n", centimeters, centimetersToInches(centimeters));

    // Get user input for length in inches
    printf("Enter length in inches: ");
    scanf("%f", &inches);

    // Convert inches to centimeters and display result
    printf("%.2f inches is equivalent to %.2f centimeters.\n", inches, inchesToCentimeters(inches));

    // Get user input for weight in kilograms
    printf("Enter weight in kilograms: ");
    scanf("%f", &kilograms);

    // Convert kilograms to pounds and display result
    printf("%.2f kilograms is equivalent to %.2f pounds.\n", kilograms, kilogramsToPounds(kilograms));

    // Get user input for weight in pounds
    printf("Enter weight in pounds: ");
    scanf("%f", &pounds);

    // Convert pounds to kilograms and display result
    printf("%.2f pounds is equivalent to %.2f kilograms.\n", pounds, poundsToKilograms(pounds));

    // Get user input for volume in liters
    printf("Enter volume in liters: ");
    scanf("%f", &liters);

    // Convert liters to gallons and display result
    printf("%.2f liters is equivalent to %.2f gallons.\n", liters, litersToGallons(liters));

    // Get user input for volume in gallons
    printf("Enter volume in gallons: ");
    scanf("%f", &gallons);

    // Convert gallons to liters and display result
    printf("%.2f gallons is equivalent to %.2f liters.\n", gallons, gallonsToLiters(gallons));

    return 0;
}