//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>

void displayMenu() {
    printf("Welcome to the Ultimate Unit Converter!\n");
    printf("Please select a conversion type:\n");
    printf("1. Temperature (Celsius to Fahrenheit)\n");
    printf("2. Distance (Kilometers to Miles)\n");
    printf("3. Weight (Kilograms to Pounds)\n");
    printf("4. Exit\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float kilometersToMiles(float kilometers) {
    return kilometers * 0.621371;
}

float kilogramsToPounds(float kilograms) {
    return kilograms * 2.20462;
}

int main() {
    int choice;
    float input, result;
    
    do {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You've chosen Temperature Conversion!\n");
                printf("Enter temperature in Celsius: ");
                scanf("%f", &input);
                result = celsiusToFahrenheit(input);
                printf("%.2f Celsius is equal to %.2f Fahrenheit!\n", input, result);
                break;

            case 2:
                printf("You've chosen Distance Conversion!\n");
                printf("Enter distance in Kilometers: ");
                scanf("%f", &input);
                result = kilometersToMiles(input);
                printf("%.2f Kilometers is equal to %.2f Miles!\n", input, result);
                break;

            case 3:
                printf("You've chosen Weight Conversion!\n");
                printf("Enter weight in Kilograms: ");
                scanf("%f", &input);
                result = kilogramsToPounds(input);
                printf("%.2f Kilograms is equal to %.2f Pounds!\n", input, result);
                break;

            case 4:
                printf("Thank you for using the Ultimate Unit Converter!\n");
                printf("Goodbye and happy converting!\n");
                break;

            default:
                printf("Invalid choice! Please select a valid option (1-4).\n");
        }
        printf("\n");

    } while (choice != 4);

    return 0;
}