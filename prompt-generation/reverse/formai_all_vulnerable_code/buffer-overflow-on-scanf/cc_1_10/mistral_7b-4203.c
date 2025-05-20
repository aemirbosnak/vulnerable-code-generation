//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define F_MINUS_45_C  -45.0
#define F_MINUS_40_C  -40.0
#define F_ZERO_C     0.0
#define F_THREE_QUARTERS_C 37.5
#define F_FIFTY_C 50.0
#define F_SIXTY_C 60.0
#define F_SIXTY_FIVE_C 65.5
#define F_ONE_HUNDRED_C 100.0

typedef enum { CELSIUS, FAHRENHEIT } TemperatureUnit;

typedef struct {
    double value;
    TemperatureUnit unit;
} Temperature;

void print_temperature(Temperature temperature) {
    switch (temperature.unit) {
        case CELSIUS:
            printf("%.2lf°C", temperature.value);
            break;
        case FAHRENHEIT:
            printf("%.2lf°F", (temperature.value * 1.8) + 32);
            break;
    }
}

Temperature convert_celsius_to_fahrenheit(double celsius) {
    Temperature result;
    result.value = celsius;
    result.unit = FAHRENHEIT;
    return result;
}

Temperature convert_fahrenheit_to_celsius(double fahrenheit) {
    Temperature result;
    result.value = (fahrenheit - 32) * 1.8;
    result.unit = CELSIUS;
    return result;
}

void print_welcome_message() {
    printf("\n-----------------------------------------------\n");
    printf("| Welcome to the Temperature Converter!         |\n");
    printf("| This program will help you convert temperatures|");
    printf("| from Celsius to Fahrenheit and vice versa!     |\n");
    printf("-----------------------------------------------\n");
}

int main() {
    char input;
    double celsius, fahrenheit;
    Temperature temperature;

    print_welcome_message();

    do {
        printf("\nDo you want to convert from Celsius to Fahrenheit (C) or from Fahrenheit to Celsius (F)?\n");
        scanf(" %c", &input);

        if (input != 'C' && input != 'F') {
            printf("\nInvalid input. Please enter either 'C' or 'F' to continue.\n");
            continue;
        }

        if (input == 'C') {
            printf("\nEnter temperature in Celsius: ");
            scanf("%lf", &celsius);

            temperature = convert_celsius_to_fahrenheit(celsius);
            print_temperature(temperature);
            printf(" is equal to\n");

            print_temperature(convert_fahrenheit_to_celsius(temperature.value));
            printf(" degrees Celsius.\n\n");
        } else {
            printf("\nEnter temperature in Fahrenheit: ");
            scanf("%lf", &fahrenheit);

            temperature = convert_fahrenheit_to_celsius(fahrenheit);
            print_temperature(temperature);
            printf(" is equal to\n");

            print_temperature(convert_celsius_to_fahrenheit(temperature.value));
            printf(" degrees Fahrenheit.\n\n");
        }

        printf("\nDo you want to convert another temperature? (Y/N)\n");
        scanf(" %c", &input);

    } while (input != 'N');

    return 0;
}