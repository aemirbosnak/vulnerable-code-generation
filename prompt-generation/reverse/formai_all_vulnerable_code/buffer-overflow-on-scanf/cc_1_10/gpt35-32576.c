//FormAI DATASET v1.0 Category: Unit converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

int main() {
    // Declare Variables
    double temperature, converted_temperature;
    char unit;

    // Romeo enters
    printf("Romeo: Ah, Juliet, my love, how doth the temperature fare today?\n");

    // Juliet replies
    printf("Juliet: Good day, Romeo. The temperature is fine. But in what unit would you like me to express it?\n");

    // Romeo responds
    printf("Romeo: Pray, let us use the Fahrenheit and Celsius scales, for they are the ones that bring me closest to thy fiery love!\n");

    // Juliet obliges
    printf("Juliet: Very well then, Romeo. What is the temperature that you would like me to convert?\n");

    // Romeo speaks his heart
    printf("Romeo: Oh, sweetest Juliet, it is: ");

    // Scan for temperature
    scanf("%lf", &temperature);

    // Romeo asks for unit
    printf("Romeo: And in what unit is this temperature expressed, my love?\n");

    // Juliet replies
    printf("Juliet: It is expressed in: ");

    // Scan for unit
    scanf(" %c", &unit);

    // Check for valid unit
    if (unit == 'C' || unit == 'c') {
        converted_temperature = celsiusToFahrenheit(temperature);
        printf("Juliet: The temperature in Fahrenheit is: %lfF\n", converted_temperature);
    } 
    else if (unit == 'F' || unit == 'f') {
        converted_temperature = fahrenheitToCelsius(temperature);
        printf("Juliet: The temperature in Celsius is: %lfC\n", converted_temperature);
    } 
    else {
        // Romeo is confused
        printf("Romeo: Alas, Juliet, what unit is this? I do not recognise it!\n");
        printf("Juliet: I am sorry, my love. The unit you entered is not valid.\n");
    }

    // End with love
    printf("Romeo: Thank you, Juliet. With your help, I shall stay warm in the cold winter nights!\n");
    printf("Juliet: Farewell, Romeo. May thy heart stay warm and thy temperature stay perfect!\n");

    return 0;
}