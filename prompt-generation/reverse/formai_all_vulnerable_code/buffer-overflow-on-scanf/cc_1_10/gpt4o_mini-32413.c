//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: careful
#include <stdio.h>

void displayMenu() {
    printf("\nUnit Converter Menu:\n");
    printf("1. Length Conversion\n");
    printf("2. Volume Conversion\n");
    printf("3. Exit\n");
    printf("Please select an option (1-3): ");
}

void lengthConversion() {
    int choice;
    double value, convertedValue;
    printf("\nLength Conversion:\n");
    printf("1. Meters to Kilometers\n");
    printf("2. Kilometers to Miles\n");
    printf("3. Miles to Feet\n");
    printf("4. Feet to Meters\n");
    printf("Select a conversion (1-4): ");
    scanf("%d", &choice);
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            convertedValue = value / 1000.0;
            printf("%.2lf Meters = %.2lf Kilometers\n", value, convertedValue);
            break;
        case 2:
            convertedValue = value * 0.621371;
            printf("%.2lf Kilometers = %.2lf Miles\n", value, convertedValue);
            break;
        case 3:
            convertedValue = value * 5280.0;
            printf("%.2lf Miles = %.2lf Feet\n", value, convertedValue);
            break;
        case 4:
            convertedValue = value / 3.281;
            printf("%.2lf Feet = %.2lf Meters\n", value, convertedValue);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void volumeConversion() {
    int choice;
    double value, convertedValue;
    printf("\nVolume Conversion:\n");
    printf("1. Liters to Gallons\n");
    printf("2. Gallons to Liters\n");
    printf("Select a conversion (1-2): ");
    scanf("%d", &choice);
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            convertedValue = value * 0.264172;
            printf("%.2lf Liters = %.2lf Gallons\n", value, convertedValue);
            break;
        case 2:
            convertedValue = value / 0.264172;
            printf("%.2lf Gallons = %.2lf Liters\n", value, convertedValue);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

int main() {
    int menuChoice;

    do {
        displayMenu();
        scanf("%d", &menuChoice);
        
        switch (menuChoice) {
            case 1:
                lengthConversion();
                break;
            case 2:
                volumeConversion();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please select 1, 2, or 3.\n");
        }

    } while (menuChoice != 3);

    return 0;
}