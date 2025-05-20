//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: protected
#include <stdio.h>

void displayMenu() {
    printf("\nUnit Converter\n");
    printf("1. Convert Miles to Kilometers\n");
    printf("2. Convert Kilograms to Pounds\n");
    printf("3. Convert Celsius to Fahrenheit\n");
    printf("4. Convert Liters to Gallons\n");
    printf("5. Convert Inches to Centimeters\n");
    printf("6. Exit\n");
    printf("Choose an option (1-6): ");
}

float milesToKilometers(float miles) {
    return miles * 1.60934;
}

float kilogramsToPounds(float kg) {
    return kg * 2.20462;
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0/5.0) + 32;
}

float litersToGallons(float liters) {
    return liters * 0.264172;
}

float inchesToCentimeters(float inches) {
    return inches * 2.54;
}

void convertUnits() {
    int choice;
    float input, result;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter miles: ");
                scanf("%f", &input);
                result = milesToKilometers(input);
                printf("%.2f miles = %.2f kilometers\n", input, result);
                break;
            case 2:
                printf("Enter kilograms: ");
                scanf("%f", &input);
                result = kilogramsToPounds(input);
                printf("%.2f kg = %.2f pounds\n", input, result);
                break;
            case 3:
                printf("Enter celsius: ");
                scanf("%f", &input);
                result = celsiusToFahrenheit(input);
                printf("%.2f °C = %.2f °F\n", input, result);
                break;
            case 4:
                printf("Enter liters: ");
                scanf("%f", &input);
                result = litersToGallons(input);
                printf("%.2f liters = %.2f gallons\n", input, result);
                break;
            case 5:
                printf("Enter inches: ");
                scanf("%f", &input);
                result = inchesToCentimeters(input);
                printf("%.2f inches = %.2f centimeters\n", input, result);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
}

int main() {
    printf("Welcome to the Unit Converter Program!\n");
    convertUnits();
    return 0;
}