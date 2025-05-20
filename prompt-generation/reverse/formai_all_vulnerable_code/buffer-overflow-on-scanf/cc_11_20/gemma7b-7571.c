//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, choice, unit_from, unit_to;

    printf("Welcome to the Unit Converter!\n");
    printf("Please select an option:\n");
    printf("1. Metric to Imperial\n");
    printf("2. Imperial to Metric\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the number of units you want to convert:");
            scanf("%d", &num);
            unit_from = 1;
            unit_to = 2;
            break;
        case 2:
            printf("Enter the number of units you want to convert:");
            scanf("%d", &num);
            unit_from = 2;
            unit_to = 1;
            break;
        default:
            printf("Invalid option.\n");
            return 1;
    }

    switch (unit_from) {
        case 1:
            switch (unit_to) {
                case 2:
                    printf("%d liters is equal to %d gallons.\n", num, num * 1.05669);
                    break;
                case 3:
                    printf("%d liters is equal to %d cubic meters.\n", num, num * 1000);
                    break;
            }
            break;
        case 2:
            switch (unit_to) {
                case 1:
                    printf("%d gallons is equal to %d liters.\n", num, num * 3.78541);
                    break;
                case 3:
                    printf("%d gallons is equal to %d cubic meters.\n", num, num * 3.78541 * 1000);
                    break;
            }
            break;
        case 3:
            switch (unit_to) {
                case 1:
                    printf("%d cubic meters is equal to %d liters.\n", num, num * 1000);
                    break;
                case 2:
                    printf("%d cubic meters is equal to %d gallons.\n", num, num * 1000 * 3.78541);
                    break;
            }
            break;
    }

    return 0;
}