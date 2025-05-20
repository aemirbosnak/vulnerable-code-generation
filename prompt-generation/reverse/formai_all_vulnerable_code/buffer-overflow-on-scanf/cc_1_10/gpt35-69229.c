//FormAI DATASET v1.0 Category: Unit converter ; Style: decentralized
// A simple unit converter program in a decentralized style
#include <stdio.h>

// Constants for unit conversion
#define MILES_TO_KM 1.60934
#define YARDS_TO_METERS 0.9144
#define FEET_TO_METERS 0.3048
#define INCHES_TO_CM 2.54
#define POUNDS_TO_KG 0.453592
#define OUNCES_TO_GRAMS 28.3495

// Function prototypes
void convert_distance();
void convert_weight();

int main() {
    int choice;

    printf("Welcome to the unit converter program!\n");
    printf("Please choose an option:\n");
    printf("1. Convert distance\n");
    printf("2. Convert weight\n");
    scanf("%d", &choice);

    // Switch statements for unit conversion options
    switch (choice) {
        case 1:
            convert_distance();
            break;
        case 2:
            convert_weight();
            break;
        default:
            printf("Invalid choice. Please enter 1 or 2.\n");
            break;
    }

    return 0;
}

void convert_distance() {
    int choice;
    double distance;

    // Prompt user for input
    printf("Please enter the distance to convert: ");
    scanf("%lf", &distance);

    printf("Please choose an option:\n");
    printf("1. Convert miles to kilometers\n");
    printf("2. Convert yards to meters\n");
    printf("3. Convert feet to meters\n");
    printf("4. Convert inches to centimeters\n");
    scanf("%d", &choice);

    // Switch statements for distance conversion options
    switch (choice) {
        case 1:
            printf("%.2f miles is equal to %.2f kilometers.\n", distance, distance * MILES_TO_KM);
            break;
        case 2:
            printf("%.2f yards is equal to %.2f meters.\n", distance, distance * YARDS_TO_METERS);
            break;
        case 3:
            printf("%.2f feet is equal to %.2f meters.\n", distance, distance * FEET_TO_METERS);
            break;
        case 4:
            printf("%.2f inches is equal to %.2f centimeters.\n", distance, distance * INCHES_TO_CM);
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
            break;
    }
}

void convert_weight() {
    int choice;
    double weight;

    // Prompt user for input
    printf("Please enter the weight to convert: ");
    scanf("%lf", &weight);

    printf("Please choose an option:\n");
    printf("1. Convert pounds to kilograms\n");
    printf("2. Convert ounces to grams\n");
    scanf("%d", &choice);

    // Switch statements for weight conversion options
    switch (choice) {
        case 1:
            printf("%.2f pounds is equal to %.2f kilograms.\n", weight, weight * POUNDS_TO_KG);
            break;
        case 2:
            printf("%.2f ounces is equal to %.2f grams.\n", weight, weight * OUNCES_TO_GRAMS);
            break;
        default:
            printf("Invalid choice. Please enter 1 or 2.\n");
            break;
    }
}