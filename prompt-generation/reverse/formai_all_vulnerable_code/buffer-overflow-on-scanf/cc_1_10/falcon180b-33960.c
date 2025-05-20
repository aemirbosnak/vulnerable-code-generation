//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// Function to get current time as string
char* get_current_time() {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    char time_str[80];
    strftime(time_str, 80, "%Y-%m-%d %H:%M:%S", t);
    return strdup(time_str);
}

// Function to get temperature from user input
float get_temperature(char* unit) {
    float temperature = 0;
    char input[80];
    printf("Enter temperature (%s): ", unit);
    fgets(input, 80, stdin);
    sscanf(input, "%f", &temperature);
    return temperature;
}

// Function to print temperature in both Celsius and Fahrenheit
void print_temperature(float temperature, char* unit) {
    float celsius = celsius_to_fahrenheit(temperature);
    float fahrenheit = fahrenheit_to_celsius(temperature);
    printf("%.2f %s = %.2f %s\n", temperature, unit, celsius, "C");
    printf("%.2f %s = %.2f %s\n", temperature, unit, fahrenheit, "F");
}

int main() {
    char unit;
    float temperature;

    // Get temperature unit from user
    printf("Enter temperature unit (C/F): ");
    scanf("%c", &unit);

    // Get temperature from user
    temperature = get_temperature(&unit);

    // Print temperature in both Celsius and Fahrenheit
    print_temperature(temperature, &unit);

    // Get current time and print it
    char* time_str = get_current_time();
    printf("Current time: %s\n", time_str);

    return 0;
}