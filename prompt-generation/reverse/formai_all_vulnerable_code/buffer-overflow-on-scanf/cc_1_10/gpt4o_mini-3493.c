//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: shape shifting
#include <stdio.h>

void displayMenu();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
void performConversion(int choice);
void clearInputBuffer();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Please select a conversion option (1-3, or 0 to exit): ");
        scanf("%d", &choice);
        clearInputBuffer();

        if (choice >= 1 && choice <= 3) {
            performConversion(choice);
        } else if (choice != 0) {
            printf("Invalid option, please choose again.\n");
        }

    } while (choice != 0);

    printf("Thank you for using the Temperature Converter! Goodbye!\n");
    return 0;
}

void displayMenu() {
    printf("\n=== Temperature Converter ===\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Both Directions\n");
    printf("0. Exit\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

void performConversion(int choice) {
    float temperature;
    
    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        printf("%.2f Celsius is %.2f Fahrenheit\n", temperature, celsiusToFahrenheit(temperature));
    } 
    else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        printf("%.2f Fahrenheit is %.2f Celsius\n", temperature, fahrenheitToCelsius(temperature));
    } 
    else if (choice == 3) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        printf("%.2f Celsius is %.2f Fahrenheit\n", temperature, celsiusToFahrenheit(temperature));

        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        printf("%.2f Fahrenheit is %.2f Celsius\n", temperature, fahrenheitToCelsius(temperature));
    }
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}