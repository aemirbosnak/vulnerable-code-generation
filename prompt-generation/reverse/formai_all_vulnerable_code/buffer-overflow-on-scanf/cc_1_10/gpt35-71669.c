//FormAI DATASET v1.0 Category: Temperature Converter ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

// Function to get the absolute value
double absolute(double num) {
    if(num<0) return -num;
    return num;
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius*1.8) + 32;
}

// Function to convert Celsius to Kelvin
double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit-32) / 1.8;
}

// Function to convert Fahrenheit to Kelvin
double fahrenheit_to_kelvin(double fahrenheit) {
    return (fahrenheit-32) / 1.8 + 273.15;
}

// Function to convert Kelvin to Celsius
double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

// Function to convert Kelvin to Fahrenheit
double kelvin_to_fahrenheit(double kelvin) {
    return (kelvin-273.15) * 1.8 + 32;
}

// Main function
int main() {

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\tWelcome to the Surrealist Temperature Converter");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("Today we celebrate temperature conversions in a surrealist way!\n");
	printf("So, Let's make things more interesting than they seem!\n\n");

    double temperature;
    int choice;

    // Infinite loop for the menu
    while(1) {
        printf("\n\nMENU:\n");
        printf("-----------------------------------------------------\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Celsius to Kelvin\n");
        printf("3. Convert Fahrenheit to Celsius\n");
        printf("4. Convert Fahrenheit to Kelvin\n");
        printf("5. Convert Kelvin to Celsius\n");
        printf("6. Convert Kelvin to Fahrenheit\n");
        printf("7. EXIT\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handling the choice selected
        switch(choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temperature);
                printf("\nThe temperature in Fahrenheit is: %.2lf°F", celsius_to_fahrenheit(temperature));
                break;

            case 2:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temperature);
                printf("\nThe temperature in Kelvin is: %.2lfK", celsius_to_kelvin(temperature));
                break;

            case 3:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                printf("\nThe temperature in Celsius is: %.2lf°C", fahrenheit_to_celsius(temperature));
                break;

            case 4:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                printf("\nThe temperature in Kelvin is: %.2lfK", fahrenheit_to_kelvin(temperature));
                break;

            case 5:
                printf("Enter temperature in Kelvin: ");
                scanf("%lf", &temperature);
                printf("\nThe temperature in Celsius is: %.2lf°C", kelvin_to_celsius(temperature));
                break;

            case 6:
                printf("Enter temperature in Kelvin: ");
                scanf("%lf", &temperature);
                printf("\nThe temperature in Fahrenheit is: %.2lf°F", kelvin_to_fahrenheit(temperature));
                break;

            case 7:
                printf("\n\n\nI hope you've had a surreal experience. Au revoir!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }
    return 0;
}