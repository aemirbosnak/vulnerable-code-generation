//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: curious
#include <stdio.h>

// Function prototypes
void convert_celsius_to_fahrenheit(double celsius);
void convert_fahrenheit_to_celsius(double fahrenheit);

int main() {
    double temperature, converted_temperature;
    char choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("----------------------------------------\n");

    while(1) {
        printf("Please enter your temperature in Celsius or Fahrenheit:\n");
        scanf("%lf", &temperature);

        printf("Please enter C for Celsius or F for Fahrenheit:\n");
        scanf(" %c", &choice);

        if(choice == 'C' || choice == 'c') {
            printf("You entered %.2lf degrees Celsius.\n", temperature);
            convert_celsius_to_fahrenheit(temperature);
        } else if(choice == 'F' || choice == 'f') {
            printf("You entered %.2lf degrees Fahrenheit.\n", temperature);
            convert_fahrenheit_to_celsius(temperature);
        } else {
            printf("Invalid input. Please enter C or F.\n");
        }

        printf("Would you like to convert another temperature? (Y/N): ");
        scanf(" %c", &choice);
        if(choice == 'N' || choice == 'n') {
            break;
        }
    }

    return 0;
}

void convert_celsius_to_fahrenheit(double celsius) {
    double fahrenheit;

    fahrenheit = (celsius * 9.0) / 5.0 + 32.0;

    printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", celsius, fahrenheit);
}

void convert_fahrenheit_to_celsius(double fahrenheit) {
    double celsius;

    celsius = (fahrenheit - 32.0) * 5.0 / 9.0;

    printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", fahrenheit, celsius);
}