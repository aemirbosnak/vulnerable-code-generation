//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: retro
// Journey to the Retro World of Units

#include <stdio.h>
#include <stdlib.h>

// Unit conversion constants
#define INCHES_TO_CM (2.54)
#define CM_TO_INCHES (0.3937)
#define POUNDS_TO_KG (0.4536)
#define KG_TO_POUNDS (2.205)

// Menu options
enum options {
    INCH_TO_CM,
    CM_TO_INCH,
    POUND_TO_KG,
    KG_TO_POUND,
    EXIT
};

// Function declarations
void display_menu();
float inch_to_cm(float inches);
float cm_to_inch(float cm);
float pound_to_kg(float pounds);
float kg_to_pound(float kg);

int main() {
    // Welcome the user
    printf("Welcome to the Retro Unit Converter!\n");
    printf("-------------------------------------\n");

    // Display the menu
    display_menu();

    // Get the user's choice
    int choice;
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    // Loop until the user chooses to exit
    while (choice != EXIT) {
        float value, result;

        // Perform the selected conversion
        switch (choice) {
            case INCH_TO_CM:
                printf("Enter the value in inches: ");
                scanf("%f", &value);
                result = inch_to_cm(value);
                printf("%f inches is %f centimeters.\n", value, result);
                break;

            case CM_TO_INCH:
                printf("Enter the value in centimeters: ");
                scanf("%f", &value);
                result = cm_to_inch(value);
                printf("%f centimeters is %f inches.\n", value, result);
                break;

            case POUND_TO_KG:
                printf("Enter the value in pounds: ");
                scanf("%f", &value);
                result = pound_to_kg(value);
                printf("%f pounds is %f kilograms.\n", value, result);
                break;

            case KG_TO_POUND:
                printf("Enter the value in kilograms: ");
                scanf("%f", &value);
                result = kg_to_pound(value);
                printf("%f kilograms is %f pounds.\n", value, result);
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }

        // Display the menu again
        display_menu();

        // Get the user's next choice
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
    }

    // Farewell message
    printf("Thank you for using the Retro Unit Converter. See you next time!\n");

    return 0;
}

// Display the menu
void display_menu() {
    printf("\n-------------------------------------\n");
    printf("1. Inches to Centimeters\n");
    printf("2. Centimeters to Inches\n");
    printf("3. Pounds to Kilograms\n");
    printf("4. Kilograms to Pounds\n");
    printf("5. Exit\n");
}

// Convert inches to centimeters
float inch_to_cm(float inches) {
    return inches * INCHES_TO_CM;
}

// Convert centimeters to inches
float cm_to_inch(float cm) {
    return cm * CM_TO_INCHES;
}

// Convert pounds to kilograms
float pound_to_kg(float pounds) {
    return pounds * POUNDS_TO_KG;
}

// Convert kilograms to pounds
float kg_to_pound(float kg) {
    return kg * KG_TO_POUND;
}