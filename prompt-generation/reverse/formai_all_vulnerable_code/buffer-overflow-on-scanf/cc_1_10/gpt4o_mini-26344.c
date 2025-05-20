//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: shocked
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0/5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0/9.0;
}

void display_menu() {
    printf("********* TEMPERATURE CONVERTER *********\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("***************************************\n");
    printf("Please select an option (1-3): ");
}

int main() {
    int choice;
    float temperature, converted_temp;

    // Welcome message
    printf("Welcome to the Temperature Converter!\n\n");
    printf("Get ready to be shocked by the transformation of temperatures!\n\n");

    do {
        display_menu();
        // Reads user input and checks for valid choice
        if (scanf("%d", &choice) != 1) {
            printf("Oops! That's not a valid choice. Please enter a number between 1 and 3.\n");
            // Clear the input buffer if invalid input occurs
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
        case 1:
            // Celsius to Fahrenheit
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            converted_temp = celsius_to_fahrenheit(temperature);
            printf("Whoaaa! %0.2f Celsius shocks you at %0.2f Fahrenheit!\n", temperature, converted_temp);
            break;

        case 2:
            // Fahrenheit to Celsius
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            converted_temp = fahrenheit_to_celsius(temperature);
            printf("Surprise! %0.2f Fahrenheit chills you at %0.2f Celsius!\n", temperature, converted_temp);
            break;

        case 3:
            // Exit condition
            printf("Thank you for using the Temperature Converter! Stay warm or cool!\n");
            break;

        default:
            printf("Whoa! That's out of bounds! Please enter a valid option (1-3).\n");
            break;
        }

    } while (choice != 3);

    return 0;
}