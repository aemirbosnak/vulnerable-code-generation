//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Function to check if a string is a valid number
int isNumber(char* str) {
    for(int i=0; i<strlen(str); i++) {
        if(!isdigit(str[i])) {
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
    char input[50];
    float temperature, convertedTemperature;
    int choice;

    // Menu loop
    do {
        printf("Temperature Converter\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter temperature in Celsius: ");
            scanf("%s", input);
            if(isNumber(input)) {
                temperature = atof(input);
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("%.2f Celsius is %.2f Fahrenheit\n", temperature, convertedTemperature);
            } else {
                printf("Invalid input\n");
            }
        } else if(choice == 2) {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%s", input);
            if(isNumber(input)) {
                temperature = atof(input);
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("%.2f Fahrenheit is %.2f Celsius\n", temperature, convertedTemperature);
            } else {
                printf("Invalid input\n");
            }
        } else if(choice == 3) {
            printf("Exiting program...\n");
        } else {
            printf("Invalid choice\n");
        }

    } while(choice!= 3);

    return 0;
}