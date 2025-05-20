//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to validate temperature input
int is_valid_temperature(char *temperature) {
    int len = strlen(temperature);
    if (len < 3 || len > MAX_LEN) {
        printf("Invalid temperature format\n");
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isdigit(temperature[i]) && temperature[i]!= '.') {
            printf("Invalid temperature format\n");
            return 0;
        }
    }
    return 1;
}

// Function to convert temperature
void convert_temperature(char *temperature, char *from_unit, char *to_unit) {
    float temp = atof(temperature);
    if (strcmp(from_unit, "C") == 0 && strcmp(to_unit, "F") == 0) {
        printf("%.2f %s is %.2f %s\n", temp, from_unit, celsius_to_fahrenheit(temp), to_unit);
    } else if (strcmp(from_unit, "F") == 0 && strcmp(to_unit, "C") == 0) {
        printf("%.2f %s is %.2f %s\n", temp, from_unit, fahrenheit_to_celsius(temp), to_unit);
    } else {
        printf("Invalid unit conversion\n");
    }
}

int main() {
    char temperature[MAX_LEN];
    char from_unit[10];
    char to_unit[10];

    // Prompt user for input
    printf("Enter temperature (e.g. 25.5C or 77F): ");
    scanf("%s", temperature);

    // Prompt user for temperature unit
    printf("Enter temperature unit (e.g. C or F): ");
    scanf("%s", from_unit);

    // Prompt user for desired unit
    printf("Enter desired unit (e.g. C or F): ");
    scanf("%s", to_unit);

    // Validate temperature input
    if (!is_valid_temperature(temperature)) {
        return 1;
    }

    // Convert temperature
    convert_temperature(temperature, from_unit, to_unit);

    return 0;
}