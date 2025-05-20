//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: medieval
#include <stdio.h>

void display_intro() {
    printf("=========================================\n");
    printf("       Welcome to the Temperature       \n");
    printf("         Converter of the Realm!       \n");
    printf("  A program crafted by the benevolent   \n");
    printf("          wizard of C programming.      \n");
    printf("=========================================\n\n");
    printf("Be ye fellow traveler, prepare to convert the frosty realm of Celsius ");
    printf("into the warm embrace of Fahrenheit, or vice versa.\n\n");
}

void display_options() {
    printf("Choose thy realm of temperature to convert:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit the enchanted program\n");
}

float celsius_to_fahrenheit(float celsius) {
    return ((celsius * 9.0) / 5.0) + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * (5.0 / 9.0);
}

void process_choice(int choice) {
    float temperature, converted_temperature;

    switch (choice) {
        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &temperature);
            converted_temperature = celsius_to_fahrenheit(temperature);
            printf("%.2f degrees Celsius is akin to %.2f degrees Fahrenheit.\n", temperature, converted_temperature);
            break;
        case 2:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            converted_temperature = fahrenheit_to_celsius(temperature);
            printf("%.2f degrees Fahrenheit is akin to %.2f degrees Celsius.\n", temperature, converted_temperature);
            break;
        case 3:
            printf("Farewell, noble traveler! May your paths be warm and your temperatures just right!\n");
            break;
        default:
            printf("Alas! Thy choice is not recognized. Please enter a valid option.\n");
            break;
    }
}

int main() {
    int choice;

    display_intro();

    do {
        display_options();
        printf("Thou shalt make a choice (1-3): ");
        scanf("%d", &choice);
        printf("\n");

        process_choice(choice);
        printf("\n");

    } while (choice != 3);

    return 0;
}