//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define F_MIN -459.67
#define F_MAX 373.15
#define C_MIN -273.15
#define C_MAX 55.0

typedef enum { FAHRENHEIT, CELSIUS } TemperatureUnits;

typedef struct Temperature {
    double value;
    TemperatureUnits unit;
} Temperature;

void convertFtoC(Temperature *temp) {
    if (temp->unit == FAHRENHEIT) {
        temp->value = (temp->value - 32.0) * 5.0 / 9.0;
        temp->unit = CELSIUS;
    }
}

void convertCtoF(Temperature *temp) {
    if (temp->unit == CELSIUS) {
        temp->value = temp->value * 9.0 / 5.0 + 32.0;
        temp->unit = FAHRENHEIT;
    }
}

int main() {
    Temperature temp;
    char input[10];

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter temperature value and unit (F or C): ");
    scanf("%s%lf", input, &temp.value);

    temp.unit = (strcmp(input, "F") == 0) ? FAHRENHEIT : CELSIUS;

    printf("You entered: %.2f %s\n", temp.value, temp.unit == FAHRENHEIT ? "Fahrenheit" : "Celsius");

    if (temp.value < C_MIN || temp.value > C_MAX && temp.value != F_MIN && temp.value != F_MAX) {
        printf("Invalid temperature value! Temperature should be between %-.2f degrees Celsius and %-.2f degrees Celsius.\n", C_MIN, C_MAX);
        return 1;
    }

    printf("Let's convert that temperature for you!\n");
    convertFtoC(&temp);
    printf("%.2f degrees %s is equal to %.2f degrees Celsius.\n", temp.value, temp.unit == FAHRENHEIT ? "Fahrenheit" : "Celsius", temp.value);

    convertCtoF(&temp);
    printf("%.2f degrees Celsius is equal to %.2f degrees %s.\n", temp.value, temp.value, temp.unit == FAHRENHEIT ? "Fahrenheit" : "Celsius");

    return 0;
}