//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_TEMP 1000 // Maximum temperature allowed

// Function to read temperature from sensor
float read_temperature() {
    float temp = 0.0;
    // Add code to read temperature from sensor
    return temp;
}

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    float fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    return fahrenheit;
}

// Function to print temperature in Celsius and Fahrenheit
void print_temperature(float celsius, float fahrenheit) {
    printf("Temperature: %.2f°C / %.2f°F\n", celsius, fahrenheit);
}

// Function to play sound alert when temperature exceeds limit
void play_alert_sound() {
    // Add code to play sound alert
}

int main() {
    float temperature = 0.0;
    float celsius = 0.0;
    float fahrenheit = 0.0;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        // Read temperature from sensor
        temperature = read_temperature();

        // Convert Celsius to Fahrenheit
        celsius = temperature;
        fahrenheit = celsius_to_fahrenheit(celsius);

        // Check if temperature exceeds limit
        if (celsius > MAX_TEMP) {
            printf("Temperature exceeded limit: %.2f°C / %.2f°F\n", celsius, fahrenheit);
            play_alert_sound();
        }

        // Print temperature in Celsius and Fahrenheit
        print_temperature(celsius, fahrenheit);

        // Ask user if they want to continue monitoring temperature
        printf("Do you want to continue monitoring temperature? (y/n): ");
        scanf(" %c", &choice);
    }

    return 0;
}