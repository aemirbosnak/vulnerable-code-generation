//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

void display_menu() {
    printf("------------------------------------------------\n");
    printf("           The Temperature Converter            \n");
    printf("------------------------------------------------\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("------------------------------------------------\n");
    printf("Enter your choice (1-3): ");
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void temperature_conversion() {
    int choice;
    double temperature, converted_temp;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        if (choice == 3) {
            printf("The game is afoot! Until next time...\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter the temperature in Celsius: ");
                scanf("%lf", &temperature);
                converted_temp = celsius_to_fahrenheit(temperature);
                printf("Ah, the temperature %lf°C is quite the mystery; it converts to %.2lf°F.\n", temperature, converted_temp);
                break;

            case 2:
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                converted_temp = fahrenheit_to_celsius(temperature);
                printf("Incredible! The temperature %lf°F reveals itself as %.2lf°C.\n", temperature, converted_temp);
                break;

            default:
                printf("Elementary, my dear user! Please choose between 1 to 3.\n");
                break;
        }

        printf("\nWould you like to perform another conversion? (y/n): ");
        char continue_choice;
        while ((continue_choice = getchar()) != '\n' && continue_choice != EOF);
        continue_choice = getchar();
        
        if (continue_choice != 'y' && continue_choice != 'Y') {
            printf("The game is afoot! Until next time...\n");
            break;
        }
    }
}

int main() {
    printf("Greetings, I am Sherlock Holmes, and welcome to my Temperature Conversion chamber.\n");
    temperature_conversion();
    return 0;
}