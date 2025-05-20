//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

void display_menu() {
    printf("Welcome to the Temperature Converter!\n");
    printf("What temperature scale would you like to convert from?\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n");
}

void convert_from_celsius(double celsius) {
    double fahrenheit = (celsius * 9/5) + 32;
    double kelvin = celsius + 273.15;
    printf("Celsius: %.2f\n", celsius);
    printf("Fahrenheit: %.2f\n", fahrenheit);
    printf("Kelvin: %.2f\n", kelvin);
}

void convert_from_fahrenheit(double fahrenheit) {
    double celsius = (fahrenheit - 32) * 5/9;
    double kelvin = celsius + 273.15;
    printf("Fahrenheit: %.2f\n", fahrenheit);
    printf("Celsius: %.2f\n", celsius);
    printf("Kelvin: %.2f\n", kelvin);
}

void convert_from_kelvin(double kelvin) {
    double celsius = kelvin - 273.15;
    double fahrenheit = (celsius * 9/5) + 32;
    printf("Kelvin: %.2f\n", kelvin);
    printf("Celsius: %.2f\n", celsius);
    printf("Fahrenheit: %.2f\n", fahrenheit);
}

int main() {
    int choice;
    double temperature;

    while (1) {
        display_menu();
        printf("Please enter your choice (1-3, or 0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Thank you for using the Temperature Converter. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 3) {
            printf("Hmm, that doesn't seem like a valid choice. Let's try again!\n");
            continue;
        }

        printf("Great choice! Now, please enter the temperature to convert: ");
        scanf("%lf", &temperature);

        switch (choice) {
            case 1:
                printf("You've chosen to convert from Celsius!\n");
                convert_from_celsius(temperature);
                break;
            case 2:
                printf("You've chosen to convert from Fahrenheit!\n");
                convert_from_fahrenheit(temperature);
                break;
            case 3:
                printf("You've chosen to convert from Kelvin!\n");
                convert_from_kelvin(temperature);
                break;
            default:
                printf("It seems there was an issue with the selection. Let's reset.\n");
                break;
        }
        
        printf("\nWould you like to perform another conversion? (1 for Yes, 0 for No): ");
        int again;
        scanf("%d", &again);
        if (again == 0) {
            printf("Thanks for converting with us! Until next time!\n");
            break;
        }
    }

    return 0;
}