//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to get user input for temperature unit
char get_unit() {
    char unit;
    
    do {
        printf("Enter temperature unit (C/F): ");
        scanf("%c", &unit);
    } while (unit!= 'C' && unit!= 'F');
    
    return unit;
}

// Function to get user input for temperature
double get_temperature(char unit) {
    double temperature = 0.0;
    
    do {
        printf("Enter temperature: ");
        scanf("%lf", &temperature);
    } while (unit == 'C' && temperature < -273.15 ||
             unit == 'F' && temperature < -459.67);
    
    return temperature;
}

// Function to convert temperature and print result
void convert_temperature(double temperature, char from_unit, char to_unit) {
    double converted_temperature;
    
    if (from_unit == to_unit) {
        printf("Temperature is already in %c.\n", to_unit);
        return;
    }
    
    if (from_unit == 'C') {
        converted_temperature = celsius_to_fahrenheit(temperature);
    } else {
        converted_temperature = fahrenheit_to_celsius(temperature);
    }
    
    printf("%.2lf %c = %.2lf %c\n", temperature, from_unit, converted_temperature, to_unit);
}

int main() {
    char from_unit, to_unit;
    double temperature;
    
    // Get user input for temperature unit
    from_unit = get_unit();
    
    // Get user input for temperature
    temperature = get_temperature(from_unit);
    
    // Convert temperature and print result
    printf("Convert from %c to:\n", from_unit);
    printf("C");
    convert_temperature(temperature, from_unit, 'C');
    printf("F");
    convert_temperature(temperature, from_unit, 'F');
    
    return 0;
}