//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Temperature {
    double fahrenheit;
    double celsius;
    double kelvin;
} Temperature;

void convertTemperature(Temperature* temp, double value, char unit) {
    switch(unit) {
        case 'F':
            temp->fahrenheit = value;
            temp->celsius = (temp->fahrenheit - 32) * 5.0/9.0;
            temp->kelvin = temp->celsius + 273.15;
            break;
        case 'C':
            temp->celsius = value;
            temp->fahrenheit = temp->celsius * 9.0/5.0 + 32;
            temp->kelvin = temp->celsius + 273.15;
            break;
        case 'K':
            temp->kelvin = value;
            temp->fahrenheit = temp->kelvin - 273.15;
            temp->celsius = temp->kelvin - 273.15;
            temp->celsius *= 1.8;
            temp->celsius += 32.0;
            break;
        default:
            printf("Invalid temperature unit. Use F, C or K.\n");
            exit(EXIT_FAILURE);
    }
}

int main() {
    Temperature temp;
    double temperature;
    char unit;

    printf("Enter temperature value and unit (F/C/K): ");
    scanf("%lf %c", &temperature, &unit);

    convertTemperature(&temp, temperature, unit);

    printf("\nFahrenheit: %.2f\n", temp.fahrenheit);
    printf("Celsius: %.2f\n", temp.celsius);
    printf("Kelvin: %.2f\n", temp.kelvin);

    return 0;
}