//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: irregular
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

// Function to get user input for temperature and unit
float get_temperature_input(char *unit) {
    float temperature = 0;
    printf("Enter temperature in %s: ", unit);
    if (scanf("%f", &temperature)!= 1) {
        printf("Invalid input. Please enter a number.\n");
        exit(1);
    }
    return temperature;
}

// Function to convert temperature and display result
void convert_temperature(float temperature, char *from_unit, char *to_unit) {
    float result = 0;
    if (strcmp(from_unit, "C") == 0 && strcmp(to_unit, "F") == 0) {
        result = celsius_to_fahrenheit(temperature);
    } else if (strcmp(from_unit, "F") == 0 && strcmp(to_unit, "C") == 0) {
        result = fahrenheit_to_celsius(temperature);
    } else {
        printf("Invalid conversion. Please enter valid units.\n");
        exit(1);
    }
    printf("%.2f %s is equal to %.2f %s\n", temperature, from_unit, result, to_unit);
}

int main() {
    srand(time(NULL));
    int choice = rand() % 2; // Randomly choose Celsius or Fahrenheit as default unit

    char from_unit = (choice == 0)? 'C' : 'F';
    char to_unit = (choice == 0)? 'F' : 'C';

    float temperature = get_temperature_input(from_unit == 'C'? "Celsius" : "Fahrenheit");
    convert_temperature(temperature, from_unit == 'C'? "C" : "F", to_unit == 'C'? "C" : "F");

    return 0;
}