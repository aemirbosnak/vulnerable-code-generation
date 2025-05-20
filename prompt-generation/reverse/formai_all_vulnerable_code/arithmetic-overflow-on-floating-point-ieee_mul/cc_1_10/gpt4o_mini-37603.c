//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: energetic
#include <stdio.h>

void displayMenu() {
    printf("\n*** Welcome to the Energetic Unit Converter! ***\n");
    printf("1. Temperature Converter\n");
    printf("2. Length Converter\n");
    printf("3. Mass Converter\n");
    printf("4. Exit\n");
    printf("Please select an option (1-4): ");
}

void temperatureConverter() {
    double celsius, fahrenheit;
    printf("\n--- Temperature Converter ---\n");
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    printf("%.2lf Celsius is equal to %.2lf Fahrenheit\n", celsius, fahrenheit);
}

void lengthConverter() {
    double meters, kilometers;
    printf("\n--- Length Converter ---\n");
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    kilometers = meters / 1000.0;
    printf("%.2lf meters is equal to %.2lf kilometers\n", meters, kilometers);
}

void massConverter() {
    double grams, kilograms;
    printf("\n--- Mass Converter ---\n");
    printf("Enter mass in grams: ");
    scanf("%lf", &grams);
    kilograms = grams / 1000.0;
    printf("%.2lf grams is equal to %.2lf kilograms\n", grams, kilograms);
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                temperatureConverter();
                break;
            case 2:
                lengthConverter();
                break;
            case 3:
                massConverter();
                break;
            case 4:
                printf("Exiting the Energetic Unit Converter. Thank you!\n");
                return 0;
            default:
                printf("Invalid choice! Please select a valid option (1-4).\n");
        }
        
        // Option to perform another conversion
        char continueChoice;
        printf("\nDo you want to convert another unit? (y/n): ");
        scanf(" %c", &continueChoice);
        
        if (continueChoice != 'y' && continueChoice != 'Y') {
            printf("Thank you for using the Energetic Unit Converter! Goodbye!\n");
            break;
        }
    }
    return 0;
}