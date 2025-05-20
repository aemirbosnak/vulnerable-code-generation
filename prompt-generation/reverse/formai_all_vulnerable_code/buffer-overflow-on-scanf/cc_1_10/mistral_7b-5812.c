//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define F_TO_C(x) ((x) - 32.0 * 5.0 / 9.0)
#define C_TO_F(x) ((x) * 9.0 / 5.0 + 32.0)

typedef enum { FAHRENHEIT, CELSIUS } TemperatureUnit;

struct Temperature {
    double value;
    TemperatureUnit unit;
};

void print_temperature(struct Temperature temp) {
    switch (temp.unit) {
        case FAHRENHEIT:
            printf("%.2f°F", temp.value);
            break;
        case CELSIUS:
            printf("%.2f°C", temp.value);
            break;
        default:
            printf("Invalid temperature unit.");
            break;
    }
}

struct Temperature convert_temperature(struct Temperature input, TemperatureUnit output) {
    struct Temperature result;

    switch (input.unit) {
        case FAHRENHEIT:
            result.value = C_TO_F(input.value);
            result.unit = output;
            break;
        case CELSIUS:
            result.value = F_TO_C(input.value);
            result.unit = output;
            break;
        default:
            result = input;
            break;
    }

    return result;
}

int main() {
    double fahrenheit, celsius;
    struct Temperature temp_f, temp_c, temp_conversion;

    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit);

    temp_f.value = fahrenheit;
    temp_f.unit = FAHRENHEIT;

    printf("Enter temperature in Celsius (leave blank if not converting): ");
    scanf("%lf", &celsius);

    if (celsius != 0.0) {
        temp_c.value = celsius;
        temp_c.unit = CELSIUS;
    }

    if (temp_c.unit == FAHRENHEIT) {
        temp_conversion = convert_temperature(temp_c, FAHRENHEIT);
        temp_f = convert_temperature(temp_conversion, FAHRENHEIT);
    }

    temp_conversion = convert_temperature(temp_f, CELSIUS);
    temp_c = convert_temperature(temp_conversion, CELSIUS);

    printf("\nTemperature in Celsius: ");
    print_temperature(temp_c);
    printf("\n");

    printf("Temperature in Fahrenheit: ");
    print_temperature(temp_f);
    printf("\n");

    return EXIT_SUCCESS;
}