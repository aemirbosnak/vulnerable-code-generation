//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to check if input is a valid number
int is_number(const char *s) {
    for (int i = 0; s[i]!= '\0'; i++) {
        if (!isdigit(s[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert Celsius to Fahrenheit
int celsius_to_fahrenheit(int celsius) {
    int fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
int fahrenheit_to_celsius(int fahrenheit) {
    int celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

// Main function
int main() {
    int choice, celsius, fahrenheit;
    char input[20];

    // Display menu
    printf("Welcome to the Medieval Temperature Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");

    // Get user choice
    scanf("%d", &choice);

    // Validate user choice
    if (choice < 1 || choice > 3) {
        printf("Invalid choice. Exiting program.\n");
        return 1;
    }

    // Get input from user
    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%s", input);

            // Validate input
            if (!is_number(input)) {
                printf("Invalid input. Please enter a valid number.\n");
                return 1;
            }

            // Convert Celsius to Fahrenheit
            celsius = atoi(input);
            fahrenheit = celsius_to_fahrenheit(celsius);
            printf("%d degrees Celsius is equal to %d degrees Fahrenheit.\n", celsius, fahrenheit);
            break;

        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%s", input);

            // Validate input
            if (!is_number(input)) {
                printf("Invalid input. Please enter a valid number.\n");
                return 1;
            }

            // Convert Fahrenheit to Celsius
            fahrenheit = atoi(input);
            celsius = fahrenheit_to_celsius(fahrenheit);
            printf("%d degrees Fahrenheit is equal to %d degrees Celsius.\n", fahrenheit, celsius);
            break;

        case 3:
            printf("Exiting program. Fare thee well!\n");
            break;
    }

    return 0;
}