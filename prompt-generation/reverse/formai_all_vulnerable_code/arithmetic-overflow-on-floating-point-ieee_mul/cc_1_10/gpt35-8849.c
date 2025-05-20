//FormAI DATASET v1.0 Category: Unit converter ; Style: systematic
#include <stdio.h>

// function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius){
    float fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

// function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit){
    float celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

// function to convert Miles to Kilometers
float milesToKilometers(float miles){
    float kilometers = miles * 1.60934;
    return kilometers;
}

// function to convert Kilometers to Miles
float kilometersToMiles(float kilometers){
    float miles = kilometers * 0.621371;
    return miles;
}

int main(){
    int choice;
    float value;
    printf("Welcome to the Unit Converter!\n");
    printf("Please choose an option below:\n");
    printf("1. Celsius to Fahrenheit Conversion\n");
    printf("2. Fahrenheit to Celsius Conversion\n");
    printf("3. Miles to Kilometers Conversion\n");
    printf("4. Kilometers to Miles Conversion\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &value);
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", value, celsiusToFahrenheit(value));
            break;
        case 2:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &value);
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", value, fahrenheitToCelsius(value));
            break;
        case 3:
            printf("Enter the distance in Miles: ");
            scanf("%f", &value);
            printf("%.2f Miles is equal to %.2f Kilometers.\n", value, milesToKilometers(value));
            break;
        case 4:
            printf("Enter the distance in Kilometers: ");
            scanf("%f", &value);
            printf("%.2f Kilometers is equal to %.2f Miles.\n", value, kilometersToMiles(value));
            break;
        default:
            printf("Invalid option selected. Please try again.\n");
            break;
    }
    return 0;
}