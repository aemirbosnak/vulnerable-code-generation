//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
void convertTemperature();
void convertDistance();
void convertWeight();
void clearBuffer();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        };

    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n=== Universal Unit Converter ===\n");
    printf("1. Temperature Converter\n");
    printf("2. Distance Converter\n");
    printf("3. Weight Converter\n");
    printf("4. Exit\n");
}

void convertTemperature() {
    double celsius, fahrenheit;
    char direction;

    printf("Temperature Conversion: (C)elsius to (F)ahrenheit or (F)ahrenheit to (C)elsius? Enter C or F: ");
    clearBuffer();
    scanf("%c", &direction);

    if (direction == 'C' || direction == 'c') {
        printf("Enter temperature in Celsius: ");
        scanf("%lf", &celsius);
        fahrenheit = (celsius * 9/5) + 32;
        printf("%.2f Celsius is %.2f Fahrenheit\n", celsius, fahrenheit);
    } else if (direction == 'F' || direction == 'f') {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%lf", &fahrenheit);
        celsius = (fahrenheit - 32) * 5/9;
        printf("%.2f Fahrenheit is %.2f Celsius\n", fahrenheit, celsius);
    } else {
        printf("Invalid selection. Please choose C or F.\n");
    }
}

void convertDistance() {
    double kilometers, miles;
    char direction;

    printf("Distance Conversion: (K)ilometers to (M)iles or (M)iles to (K)ilometers? Enter K or M: ");
    clearBuffer();
    scanf("%c", &direction);

    if (direction == 'K' || direction == 'k') {
        printf("Enter distance in Kilometers: ");
        scanf("%lf", &kilometers);
        miles = kilometers * 0.621371;
        printf("%.2f Kilometers is %.2f Miles\n", kilometers, miles);
    } else if (direction == 'M' || direction == 'm') {
        printf("Enter distance in Miles: ");
        scanf("%lf", &miles);
        kilometers = miles / 0.621371;
        printf("%.2f Miles is %.2f Kilometers\n", miles, kilometers);
    } else {
        printf("Invalid selection. Please choose K or M.\n");
    }
}

void convertWeight() {
    double kilograms, pounds;
    char direction;

    printf("Weight Conversion: (K)ilograms to (P)ounds or (P)ounds to (K)ilograms? Enter K or P: ");
    clearBuffer();
    scanf("%c", &direction);

    if (direction == 'K' || direction == 'k') {
        printf("Enter weight in Kilograms: ");
        scanf("%lf", &kilograms);
        pounds = kilograms * 2.20462;
        printf("%.2f Kilograms is %.2f Pounds\n", kilograms, pounds);
    } else if (direction == 'P' || direction == 'p') {
        printf("Enter weight in Pounds: ");
        scanf("%lf", &pounds);
        kilograms = pounds / 2.20462;
        printf("%.2f Pounds is %.2f Kilograms\n", pounds, kilograms);
    } else {
        printf("Invalid selection. Please choose K or P.\n");
    }
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}