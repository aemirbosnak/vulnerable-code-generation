//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: relaxed
#include <stdio.h>
#include <math.h>

void main() {

    int choice, unit_from, unit_to;
    float value;

    printf("Welcome to the Unit Converter!\n");
    printf("Please select an option:\n");
    printf("1. Metric to Imperial\n");
    printf("2. Imperial to Metric\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the value you want to convert:");
            scanf("%f", &value);
            unit_from = 1;
            unit_to = 2;
            break;
        case 2:
            printf("Enter the value you want to convert:");
            scanf("%f", &value);
            unit_from = 2;
            unit_to = 1;
            break;
        default:
            printf("Invalid input. Please try again.\n");
            return;
    }

    switch (unit_from) {
        case 1:
            switch (unit_to) {
                case 2:
                    value = value * 2.2046;
                    printf("The converted value is: %.2f pounds.\n", value);
                    break;
                case 3:
                    value = value * 1000;
                    printf("The converted value is: %.2f cubic meters.\n", value);
                    break;
                default:
                    printf("Invalid conversion.\n");
                    return;
            }
            break;
        case 2:
            switch (unit_to) {
                case 1:
                    value = value * 0.45359;
                    printf("The converted value is: %.2f kilograms.\n", value);
                    break;
                case 3:
                    value = value * 1609;
                    printf("The converted value is: %.2f cubic meters.\n", value);
                    break;
                default:
                    printf("Invalid conversion.\n");
                    return;
            }
            break;
        case 3:
            switch (unit_to) {
                case 1:
                    value = value * 1000;
                    printf("The converted value is: %.2f kilograms.\n", value);
                    break;
                case 2:
                    value = value * 0.001;
                    printf("The converted value is: %.2f pounds.\n", value);
                    break;
                default:
                    printf("Invalid conversion.\n");
                    return;
            }
            break;
        default:
            printf("Invalid input. Please try again.\n");
            return;
    }

    return;
}