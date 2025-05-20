//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: medieval
#include <stdio.h>

void display_welcome_message() {
    printf("=================================\n");
    printf("   Greetings, Noble Traveler!   \n");
    printf("   Welcome to the Temperature     \n");
    printf("   Converter of the Ancient Realm.\n");
    printf("=================================\n");
}

void display_instructions() {
    printf("Pray tell, enter the temperature you wish to convert:\n");
    printf("1. From Celsius to Fahrenheit\n");
    printf("2. From Fahrenheit to Celsius\n");
    printf("3. To exit the enchanted realm\n");
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

void convert_temperature() {
    int choice;
    float temperature, converted_temperature;
    
    while (1) {
        display_instructions();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &temperature);
            converted_temperature = celsius_to_fahrenheit(temperature);
            printf("The temperature in Fahrenheit is: %.2f\n\n", converted_temperature);
        } else if (choice == 2) {
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            converted_temperature = fahrenheit_to_celsius(temperature);
            printf("The temperature in Celsius is: %.2f\n\n", converted_temperature);
        } else if (choice == 3) {
            printf("Farewell, noble traveler, until our paths cross again!\n");
            break;
        } else {
            printf("Alas! Thy choice is invalid. Please try again.\n\n");
        }
    }
}

int main() {
    display_welcome_message();
    convert_temperature();
    return 0;
}