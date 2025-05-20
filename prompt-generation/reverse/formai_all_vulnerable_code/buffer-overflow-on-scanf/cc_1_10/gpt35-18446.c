//FormAI DATASET v1.0 Category: Unit converter ; Style: unmistakable
#include <stdio.h>

//function prototypes
float celsiusToFahrenheit(float celsius);
float celsiusToKelvin(float celsius);
float fahrenheitToCelsius(float fahrenheit);
float fahrenheitToKelvin(float fahrenheit);
float kelvinToCelsius(float kelvin);
float kelvinToFahrenheit(float kelvin);

int main(){

    int selection;
    float input, output;

    printf("UNIT CONVERTER\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("Enter your selection (1-6): ");
    scanf("%d", &selection);

    switch(selection){
        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &input);
            output = celsiusToFahrenheit(input);
            printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.", input, output);
            break;
        case 2:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &input);
            output = celsiusToKelvin(input);
            printf("%.2f degrees Celsius is %.2f Kelvin.", input, output);
            break;
        case 3:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &input);
            output = fahrenheitToCelsius(input);
            printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.", input, output);
            break;
        case 4:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &input);
            output = fahrenheitToKelvin(input);
            printf("%.2f degrees Fahrenheit is %.2f Kelvin.", input, output);
            break;
        case 5:
            printf("Enter the temperature in Kelvin: ");
            scanf("%f", &input);
            output = kelvinToCelsius(input);
            printf("%.2f Kelvin is %.2f degrees Celsius.", input, output);
            break;
        case 6:
            printf("Enter the temperature in Kelvin: ");
            scanf("%f", &input);
            output = kelvinToFahrenheit(input);
            printf("%.2f Kelvin is %.2f degrees Fahrenheit.", input, output);
            break;
        default:
            printf("Invalid selection, please try again.");
            break;
    }

    return 0;
}

float celsiusToFahrenheit(float celsius){
    return (celsius * 9 / 5) + 32;
}

float celsiusToKelvin(float celsius){
    return celsius + 273.15;
}

float fahrenheitToCelsius(float fahrenheit){
    return (fahrenheit - 32) * 5 / 9;
}

float fahrenheitToKelvin(float fahrenheit){
    return (fahrenheit - 32) * 5 / 9 + 273.15;
}

float kelvinToCelsius(float kelvin){
    return kelvin - 273.15;
}

float kelvinToFahrenheit(float kelvin){
    return (kelvin - 273.15) * 9 / 5 + 32;
}