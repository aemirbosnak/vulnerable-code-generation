//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#define MAX_INPUT_LENGTH 50

void celsius_to_fahrenheit(double celsius) {
    double fahrenheit;
    fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
}

void fahrenheit_to_celsius(double fahrenheit) {
    double celsius;
    celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);
}

int main() {
    char unit1, unit2;
    double temperature, conversion_factor;
    char input_string[MAX_INPUT_LENGTH];

    printf("Enter temperature value: ");
    fgets(input_string, sizeof(input_string), stdin);
    sscanf(input_string, "%lf", &temperature);

    printf("Enter unit of the given temperature (C or F): ");
    scanf("%c", &unit1);

    printf("Enter unit you want to convert to (C or F): ");
    scanf("%c", &unit2);

    if (unit1 == 'C' && unit2 == 'F') {
        conversion_factor = 1.0;
        celsius_to_fahrenheit(temperature);
    } else if (unit1 == 'C' && unit2 == 'C') {
        conversion_factor = 1.0;
        // No need to convert, just print the temperature value
        printf("%.2f degrees Celsius\n", temperature);
    } else if (unit1 == 'F' && unit2 == 'C') {
        conversion_factor = 5.0 / 9.0;
        fahrenheit_to_celsius(temperature);
    } else if (unit1 == 'F' && unit2 == 'F') {
        conversion_factor = 1.0;
        // No need to convert, just print the temperature value
        printf("%.2f degrees Fahrenheit\n", temperature);
    } else {
        printf("Invalid unit selection.\n");
        exit(EXIT_FAILURE);
    }

    if (unit1 != unit2) {
        double converted_temperature = temperature * conversion_factor;
        printf("%.2f %c temperature is equal to %.2f %c temperature.\n", temperature, unit1, converted_temperature, unit2);
    }

    return EXIT_SUCCESS;
}