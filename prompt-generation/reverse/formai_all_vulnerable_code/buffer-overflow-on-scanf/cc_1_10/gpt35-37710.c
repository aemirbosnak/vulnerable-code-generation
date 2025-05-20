//FormAI DATASET v1.0 Category: Temperature Converter ; Style: mathematical
#include<stdio.h>

// Function to convert Celsius to Fahrenheit
float CelsiusToFahrenheit(float celsius){
    return (celsius * 9/5) + 32;
}

// Function to convert Celsius to Kelvin
float CelsiusToKelvin(float celsius){
    return celsius + 273.15;
}

// Function to convert Fahrenheit to Celsius
float FahrenheitToCelsius(float fahrenheit){
    return (fahrenheit - 32) * 5/9;
}

// Function to convert Fahrenheit to Kelvin
float FahrenheitToKelvin(float fahrenheit){
    return (fahrenheit + 459.67) * 5/9;
}

// Function to convert Kelvin to Celsius
float KelvinToCelsius(float kelvin){
    return kelvin - 273.15;
}

// Function to convert Kelvin to Fahrenheit
float KelvinToFahrenheit(float kelvin){
    return (kelvin * 9/5) - 459.67;
}

// Main function to get input and output temperature scale
int main(){

    float temperature, result;
    char scale, newScale;

    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    printf("Enter the temperature scale (C, F, K): ");
    scanf(" %c", &scale);

    // Convert temperature to Celsius
    if(scale == 'F'){
        temperature = FahrenheitToCelsius(temperature);
    }
    else if(scale == 'K'){
        temperature = KelvinToCelsius(temperature);
    }

    // Get output temperature scale
    printf("Enter the new temperature scale (C, F, K): ");
    scanf(" %c", &newScale);

    // Convert Celsius to new temperature scale
    if(newScale == 'F'){
        result = CelsiusToFahrenheit(temperature);
    }
    else if(newScale == 'K'){
        result = CelsiusToKelvin(temperature);
    }
    else{
        result = temperature;
    }

    printf("The temperature is %.2f %c", result, newScale);

    return 0;
}