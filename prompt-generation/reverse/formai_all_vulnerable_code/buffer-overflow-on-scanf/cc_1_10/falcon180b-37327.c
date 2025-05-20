//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to generate a random temperature in Celsius
float generate_random_celsius() {
    return rand() % 101;
}

// Function to generate a random temperature in Fahrenheit
float generate_random_fahrenheit() {
    return rand() % 101;
}

// Function to display the temperature conversion
void display_conversion(float original_temp, float converted_temp) {
    printf("Original temperature: %.2f %s\n", original_temp, (original_temp < 0? "C" : "F"));
    printf("Converted temperature: %.2f %s\n", converted_temp, (converted_temp < 0? "C" : "F"));
}

int main() {
    srand(time(NULL));

    // Get user input for temperature type
    char temp_type;
    printf("Enter temperature type (C/F): ");
    scanf("%c", &temp_type);

    // Generate a random temperature based on user input
    float random_temp;
    if (temp_type == 'C' || temp_type == 'c') {
        random_temp = generate_random_celsius();
    } else {
        random_temp = generate_random_fahrenheit();
    }

    // Convert the temperature to the opposite unit
    float converted_temp;
    if (temp_type == 'C' || temp_type == 'c') {
        converted_temp = fahrenheit_to_celsius(random_temp);
    } else {
        converted_temp = celsius_to_fahrenheit(random_temp);
    }

    // Display the temperature conversion
    display_conversion(random_temp, converted_temp);

    return 0;
}