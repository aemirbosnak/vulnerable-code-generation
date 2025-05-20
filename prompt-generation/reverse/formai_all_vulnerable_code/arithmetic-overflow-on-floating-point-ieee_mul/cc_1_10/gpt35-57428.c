//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Ken Thompson
#include <stdio.h>

void clear_screen() {
    printf("\033[H\033[J");
}

double convert_celsius_to_fahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

double convert_fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 0.5556;
}

int main() {
    double temperature_input;
    char scale_input;

    clear_screen();

    printf("Welcome to the Temperature Converter!\n\n");

    do {
        printf("Please enter a temperature value: ");
        scanf("%lf", &temperature_input);

        printf("What is the scale of the temperature you entered? (C or F) ");
        scanf(" %c", &scale_input);
        scale_input = toupper(scale_input);

        if (scale_input == 'C') {
            double fahrenheit = convert_celsius_to_fahrenheit(temperature_input);
            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temperature_input, fahrenheit);
        } else if (scale_input == 'F') {
            double celsius = convert_fahrenheit_to_celsius(temperature_input);
            printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", temperature_input, celsius);
        } else {
            printf("Invalid input.\n");
        }

        printf("\n");

        printf("Would you like to convert another temperature? (Y or N) ");
        scanf(" %c", &scale_input);
        scale_input = toupper(scale_input);

    } while (scale_input == 'Y');

    printf("\nThank you for using the Temperature Converter!\n");

    return 0;
}