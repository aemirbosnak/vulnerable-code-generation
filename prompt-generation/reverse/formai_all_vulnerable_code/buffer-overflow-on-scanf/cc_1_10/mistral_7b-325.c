//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

typedef struct Temperature {
    char unit;
    float value;
} Temperature;

void FahrenheitToCelsius(Temperature *temp) {
    temp->value = (temp->value - 32.0) * 5.0 / 9.0;
}

void CelsiusToFahrenheit(Temperature *temp) {
    temp->value = temp->value * 9.0 / 5.0 + 32.0;
}

void PrintTemperature(Temperature temp) {
    printf("%.2f%c\n", temp.value, temp.unit);
}

int main() {
    char command;
    Temperature temp;

    printf("Welcome to the Future Temperature Converter!\n");
    printf("We don't use old units like Celsius or Fahrenheit anymore!\n");
    printf("Instead, we use Temperature Units of the Future!\n");
    printf("1. Type 'F' to convert from Fahrenheit to Future Temperature.\n");
    printf("2. Type 'C' to convert from Celsius to Future Temperature.\n");
    printf("3. Type 'T' to convert from Future Temperature to Celsius.\n");
    printf("4. Type 'Q' to quit.\n");

    while (1) {
        scanf("%c", &command);

        switch (command) {
            case 'F':
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%f", &temp.value);
                FahrenheitToCelsius(&temp);
                temp.unit = 'F';
                break;

            case 'C':
                printf("Enter the temperature in Celsius: ");
                scanf("%f", &temp.value);
                temp.unit = 'C';
                break;

            case 'T':
                if (temp.unit != 'F') {
                    printf("Invalid operation! Temperature must be in Fahrenheit to convert to Celsius.\n");
                    continue;
                }
                CelsiusToFahrenheit(&temp);
                temp.unit = 'C';
                break;

            case 'Q':
                printf("Goodbye from the Future Temperature Converter!\n");
                return 0;

            default:
                printf("Invalid command! Please try again.\n");
                break;
        }

        PrintTemperature(temp);
    }

    return 0;
}