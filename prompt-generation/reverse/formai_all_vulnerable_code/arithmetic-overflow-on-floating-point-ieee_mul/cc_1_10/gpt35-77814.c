//FormAI DATASET v1.0 Category: Temperature Converter ; Style: brave
#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    // Taking input in Celsius
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert Celsius to Fahrenheit
    fahrenheit = (celsius * 9/5) + 32;

    // Display result
    printf("\n%f degree Celsius is equal to %f degree Fahrenheit.\n", celsius, fahrenheit);
    
    // Added feature to convert Fahrenheit to Celsius
    printf("\nEnter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    // Convert Fahrenheit to Celsius
    celsius = (fahrenheit - 32) * 5/9;

    // Display result
    printf("\n%f degree Fahrenheit is equal to %f degree Celsius.\n", fahrenheit, celsius);

    // Adding some brave loops to make it better
    printf("\nLet's convert temperatures in a range!\n");

    float increment;
    printf("Enter the increment: ");
    scanf("%f", &increment);

    float limit;
    printf("Enter the limit: ");
    scanf("%f", &limit);

    printf("\nCelsius\t\tFahrenheit");
    printf("\n-------\t\t----------");

    celsius = 0;
    while (celsius <= limit) {
        fahrenheit = (celsius * 9/5) + 32;
        printf("\n%f\t%f", celsius, fahrenheit);
        celsius += increment;
    }

    printf("\n\nFahrenheit\t\tCelsius");
    printf("\n----------\t\t-------");

    fahrenheit = 0;
    while (fahrenheit <= limit) {
        celsius = (fahrenheit - 32) * 5/9;
        printf("\n%f\t%f", fahrenheit, celsius);
        fahrenheit += increment;
    }

    return 0;
}