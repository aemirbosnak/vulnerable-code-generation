//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    float input;

    printf("Welcome to the Retro Unit Converter!\n");
    printf("Please select a conversion:\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Volume\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Please enter the value to convert: ");
            scanf("%f", &input);
            printf("Please select the unit to convert from:\n");
            printf("1. Meters\n");
            printf("2. Centimeters\n");
            printf("3. Millimeters\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("%.2f meters is equal to %.2f kilometers.\n", input, input/1000);
                    break;
                case 2:
                    printf("%.2f meters is equal to %.2f kilometers.\n", input*100, input);
                    break;
                case 3:
                    printf("%.2f meters is equal to %.2f kilometers.\n", input*10000, input);
                    break;
            }
            break;

        case 2:
            printf("Please enter the value to convert: ");
            scanf("%f", &input);
            printf("Please select the unit to convert from:\n");
            printf("1. Kilograms\n");
            printf("2. Grams\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("%.2f kilograms is equal to %.2f pounds.\n", input, input*2.20462);
                    break;
                case 2:
                    printf("%.2f grams is equal to %.2f pounds.\n", input*1000, input*0.00220462);
                    break;
            }
            break;

        case 3:
            printf("Please enter the value to convert: ");
            scanf("%f", &input);
            printf("Please select the unit to convert from:\n");
            printf("1. Liters\n");
            printf("2. Milliliters\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("%.2f liters is equal to %.2f gallons.\n", input, input*0.264172);
                    break;
                case 2:
                    printf("%.2f milliliters is equal to %.2f gallons.\n", input*1000, input*0.000264172);
                    break;
            }
            break;

        default:
            printf("Invalid selection.\n");
            break;
    }

    return 0;
}