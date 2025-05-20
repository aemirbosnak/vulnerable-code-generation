//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: distributed
#include <stdio.h>

void convert_length();
void convert_weight();
void length_menu();
void weight_menu();

int main() {
    int choice;

    while (1) {
        printf("Welcome to the Unit Converter!\n");
        printf("Choose a conversion type:\n");
        printf("1. Length\n");
        printf("2. Weight\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convert_length();
                break;
            case 2:
                convert_weight();
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void convert_length() {
    int choice;
    double value, result;

    length_menu();
    scanf("%d", &choice);

    if (choice < 1 || choice > 4) {
        printf("Invalid choice! Returning to main menu.\n");
        return;
    }

    printf("Enter your value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1: // Meters to Feet
            result = value * 3.28084;
            printf("%.2f meters = %.2f feet\n", value, result);
            break;
        case 2: // Kilometers to Miles
            result = value * 0.621371;
            printf("%.2f kilometers = %.2f miles\n", value, result);
            break;
        case 3: // Feet to Meters
            result = value / 3.28084;
            printf("%.2f feet = %.2f meters\n", value, result);
            break;
        case 4: // Miles to Kilometers
            result = value / 0.621371;
            printf("%.2f miles = %.2f kilometers\n", value, result);
            break;
    }
}

void convert_weight() {
    int choice;
    double value, result;

    weight_menu();
    scanf("%d", &choice);

    if (choice < 1 || choice > 4) {
        printf("Invalid choice! Returning to main menu.\n");
        return;
    }

    printf("Enter your value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1: // Grams to Pounds
            result = value * 0.00220462;
            printf("%.2f grams = %.2f pounds\n", value, result);
            break;
        case 2: // Kilograms to Stones
            result = value * 0.157473;
            printf("%.2f kilograms = %.2f stones\n", value, result);
            break;
        case 3: // Pounds to Grams
            result = value / 0.00220462;
            printf("%.2f pounds = %.2f grams\n", value, result);
            break;
        case 4: // Stones to Kilograms
            result = value / 0.157473;
            printf("%.2f stones = %.2f kilograms\n", value, result);
            break;
    }
}

void length_menu() {
    printf("Length Conversion Menu:\n");
    printf("1. Meters to Feet\n");
    printf("2. Kilometers to Miles\n");
    printf("3. Feet to Meters\n");
    printf("4. Miles to Kilometers\n");
    printf("Enter your choice: ");
}

void weight_menu() {
    printf("Weight Conversion Menu:\n");
    printf("1. Grams to Pounds\n");
    printf("2. Kilograms to Stones\n");
    printf("3. Pounds to Grams\n");
    printf("4. Stones to Kilograms\n");
    printf("Enter your choice: ");
}