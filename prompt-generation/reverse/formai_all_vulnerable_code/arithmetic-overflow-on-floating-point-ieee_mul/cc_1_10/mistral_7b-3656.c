//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_LEN 100
#define MIN_TEMP_CELSIUS -50.0
#define MAX_TEMP_CELSIUS 200.0
#define MIN_TEMP_FAHRENHEIT -60.0
#define MAX_TEMP_FAHRENHEIT 540.0

typedef struct {
    char unit;
    double value;
} Temperature;

void get_user_input(Temperature *temp);
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);
void print_result(Temperature temp);

int main() {
    Temperature temp;

    get_user_input(&temp);

    if (temp.unit == 'C' || temp.unit == 'c') {
        temp.value = celsius_to_fahrenheit(temp.value);
        print_result(temp);
    } else if (temp.unit == 'F' || temp.unit == 'f') {
        temp.value = fahrenheit_to_celsius(temp.value);
        print_result(temp);
    } else {
        printf("Invalid temperature unit.\n");
        return 1;
    }

    return 0;
}

void get_user_input(Temperature *temp) {
    printf("Enter temperature value: ");
    scanf("%lf", &temp->value);
    printf("Enter temperature unit (C/c for Celsius, F/f for Fahrenheit): ");
    scanf(" %c", &temp->unit);
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

void print_result(Temperature temp) {
    printf("\nResult:\n");
    printf("Temperature value: %.2lf\n", temp.value);
    printf("Temperature unit: %c\n", temp.unit);

    if (temp.unit == 'C' || temp.unit == 'c') {
        printf("Equivalent temperature: %.2lf°F\n", celsius_to_fahrenheit(temp.value));
    } else {
        printf("Equivalent temperature: %.2lf°C\n", fahrenheit_to_celsius(temp.value));
    }
}