//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    float celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    return celsius;
}

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    float fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    return fahrenheit;
}

int main() {
    char user_choice;
    float temperature, conversion_value;

    printf("\n*********************************\n");
    printf("*          TEMPERATURE CONVERTER *\n");
    printf("*********************************\n\n");

    do {
        printf("\nEnter F for Fahrenheit to Celsius conversion:\n");
        printf("Enter C for Celsius to Fahrenheit conversion:\n");
        printf("Enter Q to Quit:\n");
        scanf("%c", &user_choice);

        switch(user_choice) {
            case 'F':
            case 'f':
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                conversion_value = fahrenheit_to_celsius(temperature);
                printf("\nThe temperature in Celsius is %.2f degrees.\n", conversion_value);
                break;

            case 'C':
            case 'c':
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &temperature);
                conversion_value = celsius_to_fahrenheit(temperature);
                printf("\nThe temperature in Fahrenheit is %.2f degrees.\n", conversion_value);
                break;

            case 'Q':
            case 'q':
                printf("\nQuitting the program...\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while(1); // Endless loop until user chooses to quit

    return 0;
}