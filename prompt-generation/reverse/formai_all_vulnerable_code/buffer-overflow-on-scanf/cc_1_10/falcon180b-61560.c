//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Recursive function to prompt user for input and convert temperature
void convertTemperature(int choice) {
    float temperature;
    char input[10];
    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperature, celsiusToFahrenheit(temperature));
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%s", input);
            temperature = atof(input);
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temperature, fahrenheitToCelsius(temperature));
            break;
        default:
            printf("Invalid choice.\n");
    }
}

int main() {
    int choice;
    do {
        printf("Enter 1 to convert Celsius to Fahrenheit.\n");
        printf("Enter 2 to convert Fahrenheit to Celsius.\n");
        printf("Enter 0 to exit.\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
            case 2:
                convertTemperature(choice);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 0);
    return 0;
}