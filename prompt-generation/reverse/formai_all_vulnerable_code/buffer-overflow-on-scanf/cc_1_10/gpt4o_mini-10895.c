//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showMenu() {
    printf("\n------------------------\n");
    printf("Welcome to the Magical Unit Converter!\n");
    printf("------------------------\n");
    printf("1. Convert Length (Meters to Feet)\n");
    printf("2. Convert Weight (Kilograms to Pounds)\n");
    printf("3. Convert Temperature (Celsius to Fahrenheit)\n");
    printf("4. Convert Time (Hours to Minutes)\n");
    printf("5. Exit\n");
    printf("------------------------\n");
    printf("Enter your choice (1-5): ");
}

float convertMetersToFeet(float meters) {
    return meters * 3.28084;
}

float convertKilogramsToPounds(float kilograms) {
    return kilograms * 2.20462;
}

float convertCelsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float convertHoursToMinutes(float hours) {
    return hours * 60.0;
}

int main() {
    int choice;
    float inputValue, convertedValue;

    while (1) {
        showMenu();
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Thanks for using the Magical Unit Converter!\n");
            break;
        }
        
        switch (choice) {
            case 1:
                printf("Enter length in meters: ");
                scanf("%f", &inputValue);
                convertedValue = convertMetersToFeet(inputValue);
                printf("%.2f meters is equal to %.2f feet\n", inputValue, convertedValue);
                break;
            case 2:
                printf("Enter weight in kilograms: ");
                scanf("%f", &inputValue);
                convertedValue = convertKilogramsToPounds(inputValue);
                printf("%.2f kilograms is equal to %.2f pounds\n", inputValue, convertedValue);
                break;
            case 3:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &inputValue);
                convertedValue = convertCelsiusToFahrenheit(inputValue);
                printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", inputValue, convertedValue);
                break;
            case 4:
                printf("Enter time in hours: ");
                scanf("%f", &inputValue);
                convertedValue = convertHoursToMinutes(inputValue);
                printf("%.2f hours is equal to %.2f minutes\n", inputValue, convertedValue);
                break;
            default:
                printf("Invalid choice! Please select a valid option (1-5).\n");
                break;
        }
    }
    
    return 0;
}