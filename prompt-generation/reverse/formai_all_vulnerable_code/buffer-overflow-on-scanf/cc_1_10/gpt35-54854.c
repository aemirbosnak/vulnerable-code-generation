//FormAI DATASET v1.0 Category: Temperature Converter ; Style: statistical
#include <stdio.h>

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

double fahrenheit_to_kelvin(double fahrenheit) {
    return (fahrenheit + 459.67) * 5/9;
}

double kelvin_to_fahrenheit(double kelvin) {
    return kelvin * 9/5 - 459.67;
}
int main() {
    char input_type, output_type;
    double input_temp, output_temp;
    printf("Temperature Converter\n");
    printf("Input type (C, F, K): ");
    scanf("%c", &input_type);
    printf("Enter input temperature: ");
    scanf("%lf", &input_temp);
    printf("Output type (C, F, K): ");
    scanf(" %c", &output_type);

    if (input_type == output_type) {
        output_temp = input_temp;
    } else if (input_type == 'C' && output_type == 'F') {
        output_temp = celsius_to_fahrenheit(input_temp);
    } else if (input_type == 'F' && output_type == 'C') {
        output_temp = fahrenheit_to_celsius(input_temp);
    } else if (input_type == 'C' && output_type == 'K') {
        output_temp = celsius_to_kelvin(input_temp);
    } else if (input_type == 'K' && output_type == 'C') {
        output_temp = kelvin_to_celsius(input_temp);
    } else if (input_type == 'F' && output_type == 'K') {
        output_temp = fahrenheit_to_kelvin(input_temp);
    } else if (input_type == 'K' && output_type == 'F') {
        output_temp = kelvin_to_fahrenheit(input_temp);
    } else {
        printf("Invalid temperature input or output type.\n");
        return 1;
    }

    printf("%.2lf %c = %.2lf %c\n", input_temp, input_type, output_temp, output_type);

    return 0;
}