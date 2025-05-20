//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to check if input is a valid number
int isNumber(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

int main() {
    char input[100];
    float temperature;
    int choice;

    printf("Welcome to the Temperature Converter!\n");
    printf("Enter the temperature you want to convert (e.g. 25 C or 77 F): ");
    scanf("%s", input);

    // Check if input is a valid number
    if (!isNumber(input)) {
        printf("Invalid input. Please enter a valid number.\n");
        return 0;
    }

    // Check if input is in Celsius or Fahrenheit
    if (toupper(input[strlen(input)-1]) == 'C') {
        temperature = atof(input);
        printf("%.2f C is equal to %.2f F.\n", temperature, celsiusToFahrenheit(temperature));
    } else if (toupper(input[strlen(input)-1]) == 'F') {
        temperature = atof(input);
        printf("%.2f F is equal to %.2f C.\n", temperature, fahrenheitToCelsius(temperature));
    } else {
        printf("Invalid input. Please enter a temperature in Celsius or Fahrenheit.\n");
        return 0;
    }

    printf("Do you want to convert another temperature? (y/n): ");
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y') {
        main();
    } else {
        printf("Thank you for using the Temperature Converter!\n");
        return 0;
    }
}