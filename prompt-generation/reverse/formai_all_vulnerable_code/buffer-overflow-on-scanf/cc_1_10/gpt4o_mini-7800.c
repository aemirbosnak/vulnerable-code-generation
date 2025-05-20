//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: lively
#include <stdio.h>

void displayWelcomeMessage() {
    printf("*********************************************\n");
    printf("  Welcome to the Super Duper Temperature Converter!  \n");
    printf("*********************************************\n");
    printf("You can convert temperatures between Celsius and Fahrenheit!\n");
    printf("Let's get started!\n");
}

void convertCtoF(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
}

void convertFtoC(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);
}

int main() {
    displayWelcomeMessage();
    
    int choice;
    float temperature;

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertCtoF(temperature);
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                convertFtoC(temperature);
                break;
            case 3:
                printf("Thank you for using the Super Duper Temperature Converter! Goodbye!\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}