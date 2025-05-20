//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: cheerful
#include <stdio.h>

void display_welcome_message() {
    printf("************************************************\n");
    printf("*                                              *\n");
    printf("*          Welcome to the Temperature          *\n");
    printf("*              Conversion Program!              *\n");
    printf("*                                              *\n");
    printf("************************************************\n");
    printf("\n");
    printf("Let's convert temperatures from Celsius to Fahrenheit and vice versa!\n");
}

void display_goodbye_message() {
    printf("\n");
    printf("************************************************\n");
    printf("*                                              *\n");
    printf("*             Thank you for using our         *\n");
    printf("*              Temperature Converter!          *\n");
    printf("*                                              *\n");
    printf("************************************************\n");
    printf("Have a wonderful day!\n");
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

void perform_conversion() {
    int choice;
    float temperature, converted_temperature;

    printf("Please select the conversion you wish to perform:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice (1 or 2): ");
    
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Oops! That's not a valid choice. Please enter 1 or 2: ");
        while(getchar() != '\n'); // flush the input buffer
    }

    if (choice == 1) {
        printf("Enter the temperature in Celsius: ");
        while (scanf("%f", &temperature) != 1) {
            printf("Oops! Please enter a valid number for Celsius: ");
            while(getchar() != '\n'); // flush the input buffer
        }
        converted_temperature = celsius_to_fahrenheit(temperature);
        printf("Yay! %.2f Celsius is equal to %.2f Fahrenheit!\n", temperature, converted_temperature);
    } else {
        printf("Enter the temperature in Fahrenheit: ");
        while (scanf("%f", &temperature) != 1) {
            printf("Oops! Please enter a valid number for Fahrenheit: ");
            while(getchar() != '\n'); // flush the input buffer
        }
        converted_temperature = fahrenheit_to_celsius(temperature);
        printf("Hooray! %.2f Fahrenheit is equal to %.2f Celsius!\n", temperature, converted_temperature);
    }
}

int main() {
    display_welcome_message();
    perform_conversion();
    display_goodbye_message();
    
    return 0;
}