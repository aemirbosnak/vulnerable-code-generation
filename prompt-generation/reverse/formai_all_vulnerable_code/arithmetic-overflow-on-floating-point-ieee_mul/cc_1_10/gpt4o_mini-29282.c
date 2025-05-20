//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: grateful
#include <stdio.h>

void displayWelcomeMessage() {
    printf("*******************************************************\n");
    printf("                Temperature Converter                  \n");
    printf("                  -- A Grateful Conversion --           \n");
    printf("*******************************************************\n");
    printf("Welcome to the Temperature Converter!                 \n");
    printf("We are grateful for your presence here today!         \n");
    printf("You can convert temperatures from Celsius to Fahrenheit\n");
    printf("And from Fahrenheit to Celsius. Let's get started!    \n");
    printf("*******************************************************\n");
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

void displayConversionMenu() {
    printf("Choose the type of conversion you wish to perform:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit the program\n");
    printf("Please enter your choice (1-3): ");
}

void performConversion(int choice) {
    double inputTemperature, convertedTemperature;

    switch (choice) {
        case 1:
            printf("You have chosen Celsius to Fahrenheit.\n");
            printf("Please enter the temperature in Celsius: ");
            scanf("%lf", &inputTemperature);
            convertedTemperature = celsiusToFahrenheit(inputTemperature);
            printf("Thank you for providing the Celsius temperature!\n");
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", inputTemperature, convertedTemperature);
            break;
        case 2:
            printf("You have chosen Fahrenheit to Celsius.\n");
            printf("Please enter the temperature in Fahrenheit: ");
            scanf("%lf", &inputTemperature);
            convertedTemperature = fahrenheitToCelsius(inputTemperature);
            printf("Thank you for providing the Fahrenheit temperature!\n");
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", inputTemperature, convertedTemperature);
            break;
        case 3:
            printf("We are grateful for your time!\n");
            printf("Thank you for using the Temperature Converter! Goodbye!\n");
            break;
        default:
            printf("Invalid choice! Please select a valid option.\n");
    }
}

int main() {
    int choice;

    displayWelcomeMessage();

    while (1) {
        displayConversionMenu();
        scanf("%d", &choice);

        if (choice == 3) {
            performConversion(choice);
            break; // Exit the program
        }
        
        performConversion(choice);
        printf("\nWould you like to perform another conversion? (1 for Yes, 0 for No): ");
        int again;
        scanf("%d", &again);
        if (again != 1) {
            printf("We truly appreciate your time! Goodbye!\n");
            break;
        }
        printf("\n");
    }
    return 0;
}