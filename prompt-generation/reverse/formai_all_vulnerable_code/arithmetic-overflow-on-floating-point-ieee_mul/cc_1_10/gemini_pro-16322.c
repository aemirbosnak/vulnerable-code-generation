//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: happy
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

int main(void) {
    // Flag to determine if the user wants to continue converting temperatures
    int continue_converting = 1;

    // Loop until the user chooses to stop converting temperatures
    while (continue_converting) {
        // Prompt the user to enter a temperature and the conversion type
        printf("Enter the temperature you want to convert (in Celsius or Fahrenheit): ");
        float temperature;
        scanf("%f", &temperature);

        printf("Enter the conversion type (C for Celsius to Fahrenheit, F for Fahrenheit to Celsius): ");
        char conversion_type;
        scanf(" %c", &conversion_type);

        // Convert the temperature based on the user's input
        float converted_temperature;
        switch (conversion_type) {
            case 'C':
                converted_temperature = celsius_to_fahrenheit(temperature);
                printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", temperature, converted_temperature);
                break;
            case 'F':
                converted_temperature = fahrenheit_to_celsius(temperature);
                printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", temperature, converted_temperature);
                break;
            default:
                printf("Invalid conversion type. Please enter C or F.\n");
                break;
        }

        // Prompt the user to continue or stop converting temperatures
        printf("Do you want to continue converting temperatures? (1/0): ");
        scanf("%d", &continue_converting);
    }

    // End the program with a happy message
    printf("Thanks for using the temperature converter! Have a wonderful day!\n");

    return 0;
}