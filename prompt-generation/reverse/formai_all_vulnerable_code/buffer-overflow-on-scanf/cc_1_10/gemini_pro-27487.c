//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TEMPERATURE_STRING_LENGTH 32
#define MAX_CONVERSION_PRECISION 10
#define CONVERSION_PRECISION_INCREMENT 0.00001

// Function to convert a temperature string to a double
double temperature_string_to_double(const char *temperature_string) {
    double temperature = atof(temperature_string);
    return temperature;
}

// Function to convert a double to a temperature string
char *double_to_temperature_string(double temperature, int precision) {
    char *temperature_string = malloc(MAX_TEMPERATURE_STRING_LENGTH);
    if (temperature_string == NULL) {
        return NULL;
    }
    snprintf(temperature_string, MAX_TEMPERATURE_STRING_LENGTH, "%.*f", precision, temperature);
    return temperature_string;
}

// Function to convert a temperature from one unit to another
double temperature_convert(double temperature, char *from_unit, char *to_unit) {
    double converted_temperature;
    if (strcmp(from_unit, "C") == 0) {
        if (strcmp(to_unit, "F") == 0) {
            converted_temperature = (temperature * 1.8) + 32;
        } else if (strcmp(to_unit, "K") == 0) {
            converted_temperature = temperature + 273.15;
        } else {
            converted_temperature = temperature;
        }
    } else if (strcmp(from_unit, "F") == 0) {
        if (strcmp(to_unit, "C") == 0) {
            converted_temperature = (temperature - 32) * 0.5555555555555556;
        } else if (strcmp(to_unit, "K") == 0) {
            converted_temperature = (temperature + 459.67) * 0.5555555555555556;
        } else {
            converted_temperature = temperature;
        }
    } else if (strcmp(from_unit, "K") == 0) {
        if (strcmp(to_unit, "C") == 0) {
            converted_temperature = temperature - 273.15;
        } else if (strcmp(to_unit, "F") == 0) {
            converted_temperature = (temperature * 1.8) - 459.67;
        } else {
            converted_temperature = temperature;
        }
    } else {
        converted_temperature = temperature;
    }
    return converted_temperature;
}

// Function to print the temperature conversion results
void temperature_convert_print(double temperature, char *from_unit, char *to_unit, int precision) {
    char *temperature_string = double_to_temperature_string(temperature, precision);
    if (temperature_string == NULL) {
        printf("Error: Out of memory.\n");
    } else {
        printf("%s %s = %s %s\n", temperature_string, from_unit, temperature_string, to_unit);
        free(temperature_string);
    }
}

// Function to get the temperature conversion precision from the user
int temperature_convert_get_precision() {
    int precision;
    printf("Enter the desired conversion precision (up to %d decimal places): ", MAX_CONVERSION_PRECISION);
    scanf("%d", &precision);
    if (precision < 0 || precision > MAX_CONVERSION_PRECISION) {
        precision = MAX_CONVERSION_PRECISION;
    }
    return precision;
}

// Main function
int main() {
    double temperature;
    char from_unit[4];
    char to_unit[4];
    int precision;

    // Get the temperature to convert
    printf("Enter the temperature to convert: ");
    scanf("%lf", &temperature);

    // Get the from unit
    printf("Enter the from unit (C, F, or K): ");
    scanf("%s", from_unit);

    // Get the to unit
    printf("Enter the to unit (C, F, or K): ");
    scanf("%s", to_unit);

    // Get the conversion precision
    precision = temperature_convert_get_precision();

    // Convert the temperature
    double converted_temperature = temperature_convert(temperature, from_unit, to_unit);

    // Print the conversion results
    temperature_convert_print(converted_temperature, from_unit, to_unit, precision);

    return 0;
}