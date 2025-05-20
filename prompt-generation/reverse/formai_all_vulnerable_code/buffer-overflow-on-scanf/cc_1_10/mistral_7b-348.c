//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>

typedef struct Temperature {
    float celsius;
    float fahrenheit;
} Temperature;

void convertFtoC(float temperatureFahrenheit, Temperature *temperatureCelsius) {
    temperatureCelsius->celsius = (temperatureFahrenheit - 32.0) * 5.0 / 9.0;
}

void convertCtoF(float temperatureCelsius, Temperature *temperatureFahrenheit) {
    temperatureFahrenheit->fahrenheit = temperatureCelsius * 9.0 / 5.0 + 32.0;
}

int main(void) {
    Temperature temperature;
    char input[10];
    float temperatureValue;
    int choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter the temperature value in Fahrenheit or Celsius:\n");
    scanf("%s", input);

    if (strlen(input) > 2) {
        printf("Invalid input. Please enter only Fahrenheit or Celsius.\n");
        return 1;
    }

    if (strcmp(input, "F") == 0 || strcmp(input, "f") == 0) {
        printf("Please enter the temperature value in Fahrenheit: ");
        scanf("%f", &temperatureValue);

        convertFtoC(temperatureValue, &temperature);
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperatureValue, temperature.celsius);
    } else if (strcmp(input, "C") == 0 || strcmp(input, "c") == 0) {
        printf("Please enter the temperature value in Celsius: ");
        scanf("%f", &temperatureValue);

        convertCtoF(temperatureValue, &temperature);
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperatureValue, temperature.fahrenheit);
    } else {
        printf("Invalid input. Please enter F or C.\n");
        return 1;
    }

    printf("Do you want to convert another temperature?\n1. Yes\n2. No\n");
    scanf("%d", &choice);

    if (choice == 1) {
        main();
    }

    return 0;
}