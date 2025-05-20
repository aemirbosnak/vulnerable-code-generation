//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: energetic
#include <stdio.h>

void display_welcome_message() {
    printf("=========================================\n");
    printf("   Welcome to the Temperature Converter!   \n");
    printf("   Let's transform those temperatures!  \n");
    printf("=========================================\n");
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void display_conversion(float input, char scale) {
    if (scale == 'C') {
        float result = celsius_to_fahrenheit(input);
        printf("Converting %.2f°C to Fahrenheit... \n", input);
        printf("Result: %.2f°F\n", result);
    } else if (scale == 'F') {
        float result = fahrenheit_to_celsius(input);
        printf("Converting %.2f°F to Celsius... \n", input);
        printf("Result: %.2f°C\n", result);
    }
}

void choose_conversion() {
    char scale;
    float temperature;

    printf("\nChoose the conversion type:\n");
    printf("1. Celsius to Fahrenheit (C)\n");
    printf("2. Fahrenheit to Celsius (F)\n");
    
    printf("Please enter 'C' or 'F': ");
    scanf(" %c", &scale);

    if (scale == 'C' || scale == 'F') {
        printf("Enter the temperature you want to convert: ");
        scanf("%f", &temperature);
        display_conversion(temperature, scale);
    } else {
        printf("Oops! That's not a valid option. Please run the program again.\n");
    }
}

void display_goodbye_message() {
    printf("\n=========================================\n");
    printf("       Thank you for using the Temperature Converter!\n");
    printf("         Stay cool or warm, till next time!\n");
    printf("=========================================\n");
}

int main() {
    display_welcome_message();
    
    // Let's keep the program running until the user decides to exit
    char continue_choice = 'Y';
    while (continue_choice == 'Y' || continue_choice == 'y') {
        choose_conversion();
        printf("\nWould you like to perform another conversion? (Y/N): ");
        scanf(" %c", &continue_choice);
    }

    display_goodbye_message();
    return 0;
}