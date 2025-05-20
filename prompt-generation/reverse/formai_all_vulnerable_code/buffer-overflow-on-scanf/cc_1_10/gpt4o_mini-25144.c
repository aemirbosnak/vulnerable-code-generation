//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: modular
#include <stdio.h>

// Function declarations
void displayMenu();
void convertTemperature();
void convertDistance();
void convertWeight();
float celsiusToFahrenheit(float celsius);
float kilometersToMiles(float kilometers);
float kilogramsToPounds(float kilograms);

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                convertTemperature();
                break;
            case 2:
                convertDistance();
                break;
            case 3:
                convertWeight();
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Unit Converter ---\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Kilometers to Miles\n");
    printf("3. Convert Kilograms to Pounds\n");
    printf("4. Exit\n");
}

// Function to convert temperature
void convertTemperature() {
    float celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = celsiusToFahrenheit(celsius);
    
    printf("%.2f °C is equal to %.2f °F\n", celsius, fahrenheit);
}

// Function to convert distance
void convertDistance() {
    float kilometers, miles;

    printf("Enter distance in Kilometers: ");
    scanf("%f", &kilometers);
    miles = kilometersToMiles(kilometers);
    
    printf("%.2f km is equal to %.2f miles\n", kilometers, miles);
}

// Function to convert weight
void convertWeight() {
    float kilograms, pounds;

    printf("Enter weight in Kilograms: ");
    scanf("%f", &kilograms);
    pounds = kilogramsToPounds(kilograms);
    
    printf("%.2f kg is equal to %.2f lbs\n", kilograms, pounds);
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Kilometers to Miles
float kilometersToMiles(float kilometers) {
    return kilometers * 0.621371;
}

// Function to convert Kilograms to Pounds
float kilogramsToPounds(float kilograms) {
    return kilograms * 2.20462;
}