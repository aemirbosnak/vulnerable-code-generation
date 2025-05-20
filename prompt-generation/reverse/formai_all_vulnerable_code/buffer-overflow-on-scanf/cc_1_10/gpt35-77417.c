//FormAI DATASET v1.0 Category: Unit converter ; Style: invasive
#include <stdio.h>

void displayMenu() {
    printf("\nConversion Menu:");
    printf("\n1. Inches to Centimeters");
    printf("\n2. Feet to Meters");
    printf("\n3. Miles to Kilometers");
    printf("\n4. Pounds to Kilograms");
    printf("\n5. Gallons to Liters");
    printf("\n6. Exit");
}

int main() {
    int choice;
    float input, output;

    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter length in inches: ");
                scanf("%f", &input);
                output = input * 2.54;
                printf("\n%.2f inches = %.2f centimeters\n", input, output);
                break;

            case 2:
                printf("\nEnter length in feet: ");
                scanf("%f", &input);
                output = input * 0.3048;
                printf("\n%.2f feet = %.2f meters\n", input, output);
                break;

            case 3:
                printf("\nEnter distance in miles: ");
                scanf("%f", &input);
                output = input * 1.60934;
                printf("\n%.2f miles = %.2f kilometers\n", input, output);
                break;

            case 4:
                printf("\nEnter weight in pounds: ");
                scanf("%f", &input);
                output = input * 0.453592;
                printf("\n%.2f pounds = %.2f kilograms\n", input, output);
                break;

            case 5:
                printf("\nEnter volume in gallons: ");
                scanf("%f", &input);
                output = input * 3.78541;
                printf("\n%.2f gallons = %.2f liters\n", input, output);
                break;

            case 6:
                printf("\nExiting program...");
                break;

            default:
                printf("\nInvalid input. Try again.");
                break;
        }

    } while(choice != 6);

    return 0;
}