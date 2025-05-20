//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

// Function prototypes
int isFloat(char *str);
void convertCelsiusToFahrenheit(float celsius);
void convertFahrenheitToCelsius(float fahrenheit);

int main(int argc, char *argv[]) {
    char input[MAX];
    int choice;

    // Initialize random seed
    srand(time(NULL));

    // Prompt user for temperature input and conversion choice
    printf("Enter a temperature in Celsius or Fahrenheit: ");
    scanf("%s", input);

    printf("\nChoose a conversion option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    // Convert temperature based on user choice
    switch(choice) {
        case 1:
            if(isFloat(input)) {
                float celsius = atof(input);
                convertCelsiusToFahrenheit(celsius);
            } else {
                printf("Invalid input. Please enter a valid Celsius temperature.\n");
            }
            break;
        case 2:
            if(isFloat(input)) {
                float fahrenheit = atof(input);
                convertFahrenheitToCelsius(fahrenheit);
            } else {
                printf("Invalid input. Please enter a valid Fahrenheit temperature.\n");
            }
            break;
        default:
            printf("Invalid choice. Please enter 1 or 2.\n");
            break;
    }

    return 0;
}

// Function to check if input string is a valid float
int isFloat(char *str) {
    char *endptr;
    float f = strtof(str, &endptr);
    return (*endptr == '\0');
}

// Function to convert Celsius to Fahrenheit
void convertCelsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
}

// Function to convert Fahrenheit to Celsius
void convertFahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);
}