//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: invasive
#include <stdio.h>

void displayMenu() {
    printf("Welcome to the Unit Converter!\n");
    printf("Please select the conversion you want to perform:\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("4. Exit\n");
}

void lengthConversion() {
    double meters, kilometers, feet, inches;
    int choice;

    printf("\nLength Conversion\n");
    printf("Choose conversion:\n");
    printf("1. Meters to Kilometers\n");
    printf("2. Meters to Feet\n");
    printf("3. Meters to Inches\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter length in meters: ");
            scanf("%lf", &meters);
            kilometers = meters / 1000.0;
            printf("%.2lf meters is equal to %.2lf kilometers.\n", meters, kilometers);
            break;
        case 2:
            printf("Enter length in meters: ");
            scanf("%lf", &meters);
            feet = meters * 3.28084;
            printf("%.2lf meters is equal to %.2lf feet.\n", meters, feet);
            break;
        case 3:
            printf("Enter length in meters: ");
            scanf("%lf", &meters);
            inches = meters * 39.3701;
            printf("%.2lf meters is equal to %.2lf inches.\n", meters, inches);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

void weightConversion() {
    double kilograms, pounds, ounces;
    int choice;

    printf("\nWeight Conversion\n");
    printf("Choose conversion:\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Kilograms to Ounces\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter weight in kilograms: ");
            scanf("%lf", &kilograms);
            pounds = kilograms * 2.20462;
            printf("%.2lf kilograms is equal to %.2lf pounds.\n", kilograms, pounds);
            break;
        case 2:
            printf("Enter weight in kilograms: ");
            scanf("%lf", &kilograms);
            ounces = kilograms * 35.274;
            printf("%.2lf kilograms is equal to %.2lf ounces.\n", kilograms, ounces);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

void temperatureConversion() {
    double celsius, fahrenheit;
    int choice;

    printf("\nTemperature Conversion\n");
    printf("Choose conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &celsius);
            fahrenheit = (celsius * 9/5) + 32;
            printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", celsius, fahrenheit);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &fahrenheit);
            celsius = (fahrenheit - 32) * 5/9;
            printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n", fahrenheit, celsius);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                lengthConversion();
                break;
            case 2:
                weightConversion();
                break;
            case 3:
                temperatureConversion();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}