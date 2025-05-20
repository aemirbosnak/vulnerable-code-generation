//FormAI DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>

int main() {
    int choice, unit;
    float input, output;
    char con_choice = 'Y';
    printf("Welcome to the G-RATE unit converter!\n");

    while (con_choice == 'Y') {
        printf("\nPlease select the type of unit you'd like to convert:\n");
        printf("1. Length\n2. Temperature\n3. Weight\n4. Speed\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Length conversion
                printf("\nPlease select the unit you'd like to convert:\n");
                printf("1. Inches to Centimeters\n2. Feet to Meters\n3. Miles to Kilometers\n");
                scanf("%d", &unit);

                switch (unit) {
                    case 1:
                        printf("\nPlease input the length in inches: ");
                        scanf("%f", &input);
                        output = input * 2.54;
                        printf("\n%.2f inches is equal to %.2f centimeters.\n", input, output);
                        break;
                    case 2:
                        printf("\nPlease input the length in feet: ");
                        scanf("%f", &input);
                        output = input * 0.3048;
                        printf("\n%.2f feet is equal to %.2f meters.\n", input, output);
                        break;
                    case 3:
                        printf("\nPlease input the length in miles: ");
                        scanf("%f", &input);
                        output = input * 1.60934;
                        printf("\n%.2f miles is equal to %.2f kilometers.\n", input, output);
                        break;
                    default:
                        printf("Invalid choice.\n");
                }
                break;
            case 2:  // Temperature conversion
                printf("\nPlease select the unit you'd like to convert:\n");
                printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");
                scanf("%d", &unit);

                switch (unit) {
                    case 1:
                        printf("\nPlease input the temperature in Celsius: ");
                        scanf("%f", &input);
                        output = (input * 9 / 5) + 32;
                        printf("\n%.2f Celsius is equal to %.2f Fahrenheit.\n", input, output);
                        break;
                    case 2:
                        printf("\nPlease input the temperature in Fahrenheit: ");
                        scanf("%f", &input);
                        output = (input - 32) * 5 / 9;
                        printf("\n%.2f Fahrenheit is equal to %.2f Celsius.\n", input, output);
                        break;
                    default:
                        printf("Invalid choice.\n");
                }
                break;
            case 3:  // Weight conversion
                printf("\nPlease select the unit you'd like to convert:\n");
                printf("1. Pounds to Kilograms\n2. Kilograms to Pounds\n");
                scanf("%d", &unit);

                switch (unit) {
                    case 1:
                        printf("\nPlease input the weight in pounds: ");
                        scanf("%f", &input);
                        output = input * 0.453592;
                        printf("\n%.2f pounds is equal to %.2f kilograms.\n", input, output);
                        break;
                    case 2:
                        printf("\nPlease input the weight in kilograms: ");
                        scanf("%f", &input);
                        output = input * 2.20462;
                        printf("\n%.2f kilograms is equal to %.2f pounds.\n", input, output);
                        break;
                    default:
                        printf("Invalid choice.\n");
                }
                break;
            case 4:  // Speed conversion
                printf("\nPlease select the unit you'd like to convert:\n");
                printf("1. Miles per Hour to Kilometers per Hour\n2. Kilometers per Hour to Miles per Hour\n");
                scanf("%d", &unit);

                switch (unit) {
                    case 1:
                        printf("\nPlease input the speed in miles per hour: ");
                        scanf("%f", &input);
                        output = input * 1.60934;
                        printf("\n%.2f miles per hour is equal to %.2f kilometers per hour.\n", input, output);
                        break;
                    case 2:
                        printf("\nPlease input the speed in kilometers per hour: ");
                        scanf("%f", &input);
                        output = input * 0.621371;
                        printf("\n%.2f kilometers per hour is equal to %.2f miles per hour.\n", input, output);
                        break;
                    default:
                        printf("Invalid choice.\n");
                }
                break;
            default:
                printf("Invalid choice.\n");
        }

        // ask user if they'd like to continue the conversation
        printf("\nWould you like to convert another unit? (Y/N): ");
        scanf("%s", &con_choice);
        if (con_choice != 'Y' || con_choice != 'y') {
            printf("\nThank you for using G-RATE unit converter!\n");
            break;
        }
    }

    return 0;
}