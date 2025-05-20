//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: high level of detail
#include <stdio.h>

void temperatureConversion() {
    float celsius, fahrenheit;
    int choice;

    printf("Temperature Conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);
        fahrenheit = (celsius * 9 / 5) + 32;
        printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
    } else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);
        celsius = (fahrenheit - 32) * 5 / 9;
        printf("%.2f Fahrenheit = %.2f Celsius\n", fahrenheit, celsius);
    } else {
        printf("Invalid choice!\n");
    }
}

void lengthConversion() {
    float meters, kilometers;
    int choice;

    printf("Length Conversion:\n");
    printf("1. Meters to Kilometers\n");
    printf("2. Kilometers to Meters\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter length in Meters: ");
        scanf("%f", &meters);
        kilometers = meters / 1000;
        printf("%.2f Meters = %.2f Kilometers\n", meters, kilometers);
    } else if (choice == 2) {
        printf("Enter length in Kilometers: ");
        scanf("%f", &kilometers);
        meters = kilometers * 1000;
        printf("%.2f Kilometers = %.2f Meters\n", kilometers, meters);
    } else {
        printf("Invalid choice!\n");
    }
}

void weightConversion() {
    float grams, kilograms;
    int choice;

    printf("Weight Conversion:\n");
    printf("1. Grams to Kilograms\n");
    printf("2. Kilograms to Grams\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter weight in Grams: ");
        scanf("%f", &grams);
        kilograms = grams / 1000;
        printf("%.2f Grams = %.2f Kilograms\n", grams, kilograms);
    } else if (choice == 2) {
        printf("Enter weight in Kilograms: ");
        scanf("%f", &kilograms);
        grams = kilograms * 1000;
        printf("%.2f Kilograms = %.2f Grams\n", kilograms, grams);
    } else {
        printf("Invalid choice!\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nUnit Conversion Program\n");
        printf("1. Temperature Conversion\n");
        printf("2. Length Conversion\n");
        printf("3. Weight Conversion\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                temperatureConversion();
                break;
            case 2:
                lengthConversion();
                break;
            case 3:
                weightConversion();
                break;
            case 4:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }
}