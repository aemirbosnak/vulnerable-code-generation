//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MIN_TEMP -270 // Minimum valid temperature in degrees Celsius
#define MAX_TEMP 1000 // Maximum valid temperature in degrees Celsius
#define MIN_F_TEMP -459.67 // Minimum valid temperature in degrees Fahrenheit
#define MAX_F_TEMP 1250 // Maximum valid temperature in degrees Fahrenheit

float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_fahrenheit(float celsius);

int main() {
    char temp_type;
    float temperature;

    printf("Enter 'F' for Fahrenheit or 'C' for Celsius: ");
    scanf("%c", &temp_type);

    if (temp_type != 'F' && temp_type != 'C') {
        printf("Invalid temperature type.\n");
        return 1;
    }

    printf("Enter temperature value: ");
    scanf("%f", &temperature);

    if (temp_type == 'F') {
        temperature = fahrenheit_to_celsius(temperature);
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperature, temperature);
    } else {
        temperature = celsius_to_fahrenheit(temperature);
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperature, temperature);
    }

    return 0;
}

float fahrenheit_to_celsius(float fahrenheit) {
    if (fahrenheit < MIN_F_TEMP || fahrenheit > MAX_F_TEMP) {
        printf("Invalid temperature value in Fahrenheit.\n");
        exit(1);
    }

    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float celsius_to_fahrenheit(float celsius) {
    if (celsius < MIN_TEMP || celsius > MAX_TEMP) {
        printf("Invalid temperature value in Celsius.\n");
        exit(1);
    }

    return (celsius * 9.0 / 5.0) + 32.0;
}