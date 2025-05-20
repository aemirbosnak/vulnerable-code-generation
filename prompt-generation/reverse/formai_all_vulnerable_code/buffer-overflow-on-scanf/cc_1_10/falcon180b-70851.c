//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: shocked
#include <stdio.h>

// function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

int main() {
    float celsius, fahrenheit;
    int choice;

    // loop until user chooses to exit
    while(1) {
        printf("Enter your choice:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &celsius);
                printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, celsiusToFahrenheit(celsius));
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);
                printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, fahrenheitToCelsius(fahrenheit));
                break;

            case 3:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}