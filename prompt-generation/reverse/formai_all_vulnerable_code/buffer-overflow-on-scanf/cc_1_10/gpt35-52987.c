//FormAI DATASET v1.0 Category: Unit converter ; Style: retro
#include <stdio.h>

int main() {
    int choice = 0;
    float value = 0.0;

    while (1) {
        printf("Welcome to Retro Unit Converter\n");
        printf("1. Feet to meters\n");
        printf("2. Meters to feet\n");
        printf("3. Pounds to kilograms\n");
        printf("4. Kilograms to pounds\n");
        printf("5. Inches to centimeters\n");
        printf("6. Centimeters to inches\n");
        printf("7. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: { //Feet to meters
                printf("Enter length in feet: ");
                scanf("%f", &value);
                printf("%.2f feet is %.2f meters\n", value, value * 0.3048);
            } break;

            case 2: { //Meters to feet
                printf("Enter length in meters: ");
                scanf("%f", &value);
                printf("%.2f meters is %.2f feet\n", value, value * 3.2808);
            } break;

            case 3: { //Pounds to kilograms
                printf("Enter weight in pounds: ");
                scanf("%f", &value);
                printf("%.2f pounds is %.2f kilograms\n", value, value * 0.4536);
            } break;

            case 4: { //Kilograms to pounds
                printf("Enter weight in kilograms: ");
                scanf("%f", &value);
                printf("%.2f kilograms is %.2f pounds\n", value, value * 2.2046);
            } break;

            case 5: { //Inches to centimeters
                printf("Enter length in inches: ");
                scanf("%f", &value);
                printf("%.2f inches is %.2f centimeters\n", value, value * 2.54);
            } break;

            case 6: { //Centimeters to inches
                printf("Enter length in centimeters: ");
                scanf("%f", &value);
                printf("%.2f centimeters is %.2f inches\n", value, value * 0.3937);
            } break;

            case 7: { //Quit
                printf("Thank you for using Retro Unit Converter\n");
                return 0;
            } break;

            default: {
                printf("Invalid input. Please try again\n");
            }
        }
    }

    return 0;
}