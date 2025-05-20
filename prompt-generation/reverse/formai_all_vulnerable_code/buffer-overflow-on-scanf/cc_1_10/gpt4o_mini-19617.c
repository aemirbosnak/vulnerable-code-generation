//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>

void displayMenu();
void convertLength();
void convertTemperature();
void convertWeight();
void lengthToMeters();
void temperatureToCelsius();
void weightToKilograms();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Choose a conversion option (1-4) or 0 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convertLength();
                break;
            case 2:
                convertTemperature();
                break;
            case 3:
                convertWeight();
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n==== Unit Converter ====\n");
    printf("1. Length Conversion\n");
    printf("2. Temperature Conversion\n");
    printf("3. Weight Conversion\n");
    printf("0. Exit\n");
}

void convertLength() {
    int choice;
    float value, result;

    printf("\nLength Conversion:\n");
    printf("1. Meters to Kilometers\n");
    printf("2. Kilometers to Meters\n");
    printf("3. Feet to Meters\n");
    printf("4. Meters to Feet\n");
    printf("Enter conversion option (1-4): ");
    scanf("%d", &choice);

    printf("Enter value to convert: ");
    scanf("%f", &value);

    switch (choice) {
        case 1:
            result = value / 1000;
            printf("%.2f Meters = %.2f Kilometers\n", value, result);
            break;
        case 2:
            result = value * 1000;
            printf("%.2f Kilometers = %.2f Meters\n", value, result);
            break;
        case 3:
            result = value * 0.3048;
            printf("%.2f Feet = %.2f Meters\n", value, result);
            break;
        case 4:
            result = value / 0.3048;
            printf("%.2f Meters = %.2f Feet\n", value, result);
            break;
        default:
            printf("Invalid length conversion option.\n");
            break;
    }
}

void convertTemperature() {
    int choice;
    float value, result;

    printf("\nTemperature Conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter conversion option (1-2): ");
    scanf("%d", &choice);

    printf("Enter temperature to convert: ");
    scanf("%f", &value);

    switch (choice) {
        case 1:
            result = (value * 9/5) + 32;
            printf("%.2f Celsius = %.2f Fahrenheit\n", value, result);
            break;
        case 2:
            result = (value - 32) * 5/9;
            printf("%.2f Fahrenheit = %.2f Celsius\n", value, result);
            break;
        default:
            printf("Invalid temperature conversion option.\n");
            break;
    }
}

void convertWeight() {
    int choice;
    float value, result;

    printf("\nWeight Conversion:\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("Enter conversion option (1-2): ");
    scanf("%d", &choice);

    printf("Enter weight to convert: ");
    scanf("%f", &value);

    switch (choice) {
        case 1:
            result = value * 2.20462;
            printf("%.2f Kilograms = %.2f Pounds\n", value, result);
            break;
        case 2:
            result = value / 2.20462;
            printf("%.2f Pounds = %.2f Kilograms\n", value, result);
            break;
        default:
            printf("Invalid weight conversion option.\n");
            break;
    }
}