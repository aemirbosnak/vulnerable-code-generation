//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0/5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0/9.0;
}

// Function to validate user input
int isValidInput(char *input) {
    int i = 0;
    while (input[i]!= '\0') {
        if (!isdigit(input[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {
    char input[100];
    float celsius, fahrenheit;
    int choice;
    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter the temperature you want to convert (in Celsius or Fahrenheit): ");
    scanf("%s", input);
    if (isValidInput(input)) {
        celsius = atof(input);
        printf("You entered %.2f degrees Celsius.\n", celsius);
        printf("1. Convert to Fahrenheit\n");
        printf("2. Convert to Celsius\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, celsiusToFahrenheit(celsius));
                break;
            case 2:
                printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", celsiusToFahrenheit(celsius), fahrenheitToCelsius(celsius));
                break;
            case 3:
                printf("Thank you for using the Temperature Converter!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } else {
        printf("Invalid input. Please enter a valid temperature.\n");
    }
    return 0;
}