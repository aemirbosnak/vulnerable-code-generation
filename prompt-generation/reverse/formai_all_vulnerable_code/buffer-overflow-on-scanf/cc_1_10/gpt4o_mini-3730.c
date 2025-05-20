//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMenu() {
    printf("Unit Converter\n");
    printf("1. Convert Length\n");
    printf("2. Convert Weight\n");
    printf("3. Convert Temperature\n");
    printf("4. Exit\n");
    printf("Select an option (1-4): ");
}

void convertLength() {
    double meters, feet;
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    feet = meters * 3.28084;
    printf("%.2f meters is equivalent to %.2f feet\n", meters, feet);
}

void convertWeight() {
    double kilograms, pounds;
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kilograms);
    pounds = kilograms * 2.20462;
    printf("%.2f kilograms is equivalent to %.2f pounds\n", kilograms, pounds);
}

void convertTemperature() {
    double celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = (celsius * 9/5) + 32;
    printf("%.2f degrees Celsius is equivalent to %.2f degrees Fahrenheit\n", celsius, fahrenheit);
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 4.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer(); // Clear any leftover input

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
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
        printf("\n"); // Add a newline for better readability
    }

    return 0;
}