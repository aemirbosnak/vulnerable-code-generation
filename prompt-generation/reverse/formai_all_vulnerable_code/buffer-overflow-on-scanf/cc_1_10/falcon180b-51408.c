//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int choice;
    float temp, converted_temp;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please select the unit of temperature you would like to convert from:\n");
    printf("1. Celsius\n2. Fahrenheit\n3. Kelvin\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1: // Convert from Celsius to Fahrenheit and Kelvin
            printf("Please enter the temperature in Celsius: ");
            scanf("%f", &temp);

            converted_temp = (temp * 9/5) + 32; // Convert Celsius to Fahrenheit
            printf("The temperature in Fahrenheit is: %.2f\n", converted_temp);

            converted_temp = temp + 273.15; // Convert Celsius to Kelvin
            printf("The temperature in Kelvin is: %.2f\n", converted_temp);

            break;

        case 2: // Convert from Fahrenheit to Celsius and Kelvin
            printf("Please enter the temperature in Fahrenheit: ");
            scanf("%f", &temp);

            converted_temp = (temp - 32) * 5/9; // Convert Fahrenheit to Celsius
            printf("The temperature in Celsius is: %.2f\n", converted_temp);

            converted_temp = (temp + 459.67) * 5/9; // Convert Fahrenheit to Kelvin
            printf("The temperature in Kelvin is: %.2f\n", converted_temp);

            break;

        case 3: // Convert from Kelvin to Celsius and Fahrenheit
            printf("Please enter the temperature in Kelvin: ");
            scanf("%f", &temp);

            converted_temp = temp - 273.15; // Convert Kelvin to Celsius
            printf("The temperature in Celsius is: %.2f\n", converted_temp);

            converted_temp = (temp - 273.15) * 9/5 - 459.67; // Convert Kelvin to Fahrenheit
            printf("The temperature in Fahrenheit is: %.2f\n", converted_temp);

            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}