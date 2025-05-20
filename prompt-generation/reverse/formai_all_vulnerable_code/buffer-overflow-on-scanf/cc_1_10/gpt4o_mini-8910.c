//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: medieval
#include <stdio.h>

void medievalGreeting() {
    printf("         _|_|_|  _|      _|  _|_|_|_|  _|_|_|  _|_|_|_|  \n");
    printf("         _|      _|      _|      _|      _|      _|      \n");
    printf("         _|_|    _|      _|      _|      _|      _|_|    \n");
    printf("         _|      _|      _|      _|      _|      _|      \n");
    printf("         _|_|_|    _|  _|    _|_|_|_|  _|_|_|  _|_|_|_|  \n");
    printf("\n");
    printf("Welcome, noble traveler, to the medieval Temperature Converter!\n");
    printf("Behold, the power of converting temperatures from Celsius to Fahrenheit and back!\n");
    printf("\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

void displayMenu() {
    printf("\nChoose thy conversion:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Quit the converter\n");
}

int main() {
    medievalGreeting();
    
    int choice;
    float temperature, convertedTemperature;
    
    while (1) {
        displayMenu();
        printf("Pray tell, enter thy choice (1-3): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("Lo! %.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperature, convertedTemperature);
                break;

            case 2:
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("Hark! %.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperature, convertedTemperature);
                break;

            case 3:
                printf("Farewell, noble traveler! Thy presence shall be missed.\n");
                return 0;

            default:
                printf("Alas! Thou hast chosen an invalid option. Please try again.\n");
        }
    }

    return 0;
}