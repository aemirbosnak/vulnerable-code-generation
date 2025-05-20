//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//function to convert celsius to fahrenheit
float celsius_to_fahrenheit(float celsius) {
    float fahrenheit = (celsius * 1.8) + 32;
    return fahrenheit;
}

//function to convert fahrenheit to celsius
float fahrenheit_to_celsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) / 1.8;
    return celsius;
}

int main() {
    int choice;
    float temperature;

    //menu
    printf("Temperature Converter Menu:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");

    //user choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    //temperature input
    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperature, celsius_to_fahrenheit(temperature));
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temperature, fahrenheit_to_celsius(temperature));
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}