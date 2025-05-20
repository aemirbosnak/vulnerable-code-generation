//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to display menu
void display_menu() {
    printf("\n");
    printf("Temperature Converter Menu\n");
    printf("-------------------------\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("\n");
}

// Function to get user input
int get_user_input() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to get temperature input
float get_temperature_input(char *unit) {
    float temperature;
    printf("Enter temperature in %s: ", unit);
    scanf("%f", &temperature);
    return temperature;
}

int main() {
    srand(time(0));
    int choice;
    char unit[10];
    float temperature;

    do {
        // Display menu
        display_menu();

        // Get user choice
        choice = get_user_input();

        // Get temperature input
        switch(choice) {
            case 1:
                temperature = get_temperature_input("Celsius");
                printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperature, celsius_to_fahrenheit(temperature));
                break;
            case 2:
                temperature = get_temperature_input("Fahrenheit");
                printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temperature, fahrenheit_to_celsius(temperature));
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= 3);

    return 0;
}