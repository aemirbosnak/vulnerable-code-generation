//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\nUnit Converter\n");
    printf("1. Convert Length\n");
    printf("2. Convert Weight\n");
    printf("3. Convert Temperature\n");
    printf("4. Convert Area\n");
    printf("5. Exit\n");
    printf("Choose an option (1-5): ");
}

void convertLength() {
    double meters, feet;
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    feet = meters * 3.28084;
    printf("%.2lf meters is equal to %.2lf feet\n", meters, feet);
}

void convertWeight() {
    double kg, pounds;
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kg);
    pounds = kg * 2.20462;
    printf("%.2lf kilograms is equal to %.2lf pounds\n", kg, pounds);
}

void convertTemperature() {
    double celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = (celsius * 9 / 5) + 32;
    printf("%.2lf Celsius is equal to %.2lf Fahrenheit\n", celsius, fahrenheit);
}

void convertArea() {
    double squareMeters, acres;
    printf("Enter area in square meters: ");
    scanf("%lf", &squareMeters);
    acres = squareMeters * 0.000247105;
    printf("%.2lf square meters is equal to %.2lf acres\n", squareMeters, acres);
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convertLength();
                break;
            case 2:
                convertWeight();
                break;
            case 3:
                convertTemperature();
                break;
            case 4:
                convertArea();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}