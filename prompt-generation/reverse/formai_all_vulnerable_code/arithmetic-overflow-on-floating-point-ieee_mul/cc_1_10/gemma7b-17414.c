//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT 100

typedef struct Conversion {
    float f_celsius;
    float f_fahrenheit;
} Conversion;

Conversion conversions[MAX_CONVERT];

void initializeConversions(void) {
    for (int i = 0; i < MAX_CONVERT; i++) {
        conversions[i].f_celsius = 0.0f;
        conversions[i].f_fahrenheit = 0.0f;
    }
}

void convertFahrenheitToCelsius(float f_fahrenheit) {
    conversions[MAX_CONVERT - 1].f_celsius = (f_fahrenheit - 32.0f) * 5.0f / 9.0f;
}

void convertCelsiusToFahrenheit(float f_celsius) {
    conversions[MAX_CONVERT - 1].f_fahrenheit = (f_celsius * 9.0f / 5.0f) + 32.0f;
}

int main() {
    initializeConversions();

    printf("Enter the conversion type (C/F): ");
    char conversion_type;
    scanf("%c", &conversion_type);

    printf("Enter the conversion value: ");
    float conversion_value;
    scanf("%f", &conversion_value);

    switch (conversion_type) {
        case 'C':
            convertCelsiusToFahrenheit(conversion_value);
            printf("The conversion result is: %.2f Fahrenheit", conversions[MAX_CONVERT - 1].f_fahrenheit);
            break;
        case 'F':
            convertFahrenheitToCelsius(conversion_value);
            printf("The conversion result is: %.2f Celsius", conversions[MAX_CONVERT - 1].f_celsius);
            break;
        default:
            printf("Invalid conversion type");
    }

    return 0;
}