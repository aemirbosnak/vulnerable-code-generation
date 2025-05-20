//FormAI DATASET v1.0 Category: Temperature Converter ; Style: secure
#include <stdio.h>
#include <stdbool.h>

/* Function that converts Celsius to Fahrenheit */
double celsiusToFahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

/* Function that converts Celsius to Kelvin */
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

/* Function that validates user input */
bool validateInput(double temp) {
    if (temp < -273.15) {
        printf("Temperature cannot be below absolute zero (-273.15 Celsius)\n");
        return false;
    }
    return true;
}

int main() {
    double celsius;
    char choice;
    
    do {
        printf("Select an option:\n");
        printf("(1) Convert Celsius to Fahrenheit\n");
        printf("(2) Convert Celsius to Kelvin\n");
        scanf(" %c", &choice);
        
        printf("Enter a temperature in Celsius: ");
        scanf("%lf", &celsius);
        
        if (validateInput(celsius)) {
            switch (choice) {
                case '1':
                    printf("%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, celsiusToFahrenheit(celsius));
                    break;
                case '2':
                    printf("%.2f Celsius is equal to %.2f Kelvin\n", celsius, celsiusToKelvin(celsius));
                    break;
                default:
                    printf("Invalid choice. Please select either 1 or 2.\n");
                    break;
            }
        }
        
        printf("Do you want to convert another temperature? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}