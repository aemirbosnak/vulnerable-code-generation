//FormAI DATASET v1.0 Category: Unit converter ; Style: irregular
#include <stdio.h>
#include <string.h>

int main() {
    printf("\n**** Welcome to the Custom Unit Converter ****\n\n");

    char menuOption[10];
    char fromUnit[10];
    char toUnit[10];
    double inputValue;
    double outputValue = 0;
    int repeat = 1;

    while (repeat) {
        printf("Select option from the menu below:\n");
        printf("1. Temperature\n");
        printf("2. Length\n");
        printf("3. Weight\n");
        printf("4. Time\n");

        printf("\nEnter choice: ");
        scanf("%s", menuOption);

        switch (menuOption[0]) {
            case '1':
                printf("\nYou have selected Temperature Conversion\n");
                printf("Enter value: ");
                scanf("%lf", &inputValue);
                printf("From unit (F/C): ");
                scanf("%s", fromUnit);
                printf("To unit (F/C): ");
                scanf("%s", toUnit);

                if (strcmp(fromUnit, "F") == 0 && strcmp(toUnit, "C") == 0) {
                    outputValue = (inputValue - 32) * 5/9;
                } else if (strcmp(fromUnit, "C") == 0 && strcmp(toUnit, "F") == 0) {
                    outputValue = (inputValue * 9/5) + 32;
                } else {
                    printf("\nInvalid Unit Conversion!\n");
                    break;
                }

                printf("Conversion Result: %.2lf %s = %.2lf %s\n", inputValue, fromUnit, outputValue, toUnit);
                break;

            case '2':
                printf("\nYou have selected Length Conversion\n");
                printf("Enter value: ");
                scanf("%lf", &inputValue);
                printf("From unit (m/cm/ft/in): ");
                scanf("%s", fromUnit);
                printf("To unit (m/cm/ft/in): ");
                scanf("%s", toUnit);

                if (strcmp(fromUnit, "m") == 0 && strcmp(toUnit, "cm") == 0) {
                    outputValue = inputValue * 100;
                } else if (strcmp(fromUnit, "cm") == 0 && strcmp(toUnit, "m") == 0) {
                    outputValue = inputValue / 100;
                } else if (strcmp(fromUnit, "m") == 0 && strcmp(toUnit, "ft") == 0) {
                    outputValue = inputValue * 3.281;
                } else if (strcmp(fromUnit, "ft") == 0 && strcmp(toUnit, "m") == 0) {
                    outputValue = inputValue / 3.281;
                } else if (strcmp(fromUnit, "cm") == 0 && strcmp(toUnit, "in") == 0) {
                    outputValue = inputValue / 2.54;
                } else if (strcmp(fromUnit, "in") == 0 && strcmp(toUnit, "cm") == 0) {
                    outputValue = inputValue * 2.54;
                } else {
                    printf("\nInvalid Unit Conversion!\n");
                    break;
                }

                printf("Conversion Result: %.2lf %s = %.2lf %s\n", inputValue, fromUnit, outputValue, toUnit);
                break;

            case '3':
                printf("\nYou have selected Weight Conversion\n");
                printf("Enter value: ");
                scanf("%lf", &inputValue);
                printf("From unit (kg/g/lb): ");
                scanf("%s", fromUnit);
                printf("To unit (kg/g/lb): ");
                scanf("%s", toUnit);

                if (strcmp(fromUnit, "kg") == 0 && strcmp(toUnit, "g") == 0) {
                    outputValue = inputValue * 1000;
                } else if (strcmp(fromUnit, "g") == 0 && strcmp(toUnit, "kg") == 0) {
                    outputValue = inputValue / 1000;
                } else if (strcmp(fromUnit, "kg") == 0 && strcmp(toUnit, "lb") == 0) {
                    outputValue = inputValue * 2.20462;
                } else if (strcmp(fromUnit, "lb") == 0 && strcmp(toUnit, "kg") == 0) {
                    outputValue = inputValue / 2.20462;
                } else {
                    printf("\nInvalid Unit Conversion!\n");
                    break;
                }

                printf("Conversion Result: %.2lf %s = %.2lf %s\n", inputValue, fromUnit, outputValue, toUnit);
                break;

            case '4':
                printf("\nYou have selected Time Conversion\n");
                printf("Enter value: ");
                scanf("%lf", &inputValue);
                printf("From unit (s/min/hr): ");
                scanf("%s", fromUnit);
                printf("To unit (s/min/hr): ");
                scanf("%s", toUnit);

                if (strcmp(fromUnit, "s") == 0 && strcmp(toUnit, "min") == 0) {
                    outputValue = inputValue / 60;
                } else if (strcmp(fromUnit, "min") == 0 && strcmp(toUnit, "s") == 0) {
                    outputValue = inputValue * 60;
                } else if (strcmp(fromUnit, "min") == 0 && strcmp(toUnit, "hr") == 0) {
                    outputValue = inputValue / 60;
                } else if (strcmp(fromUnit, "hr") == 0 && strcmp(toUnit, "min") == 0) {
                    outputValue = inputValue * 60;
                } else {
                    printf("\nInvalid Unit Conversion!\n");
                    break;
                }

                printf("Conversion Result: %.2lf %s = %.2lf %s\n", inputValue, fromUnit, outputValue, toUnit);
                break;

            default:
                printf("\nInvalid input! Please enter a number between 1 to 4.\n");
                break;
        }

        char userContinue[10];
        printf("Do you want to convert again? (Yes/No): ");
        scanf("%s", userContinue);

        if (strcmp(userContinue, "Yes") == 0 || strcmp(userContinue, "yes") == 0) {
            repeat = 1;
        } else if (strcmp(userContinue, "No") == 0 || strcmp(userContinue, "no") == 0) {
            repeat = 0;
            printf("\n**** Thank you for using Custom Unit Converter! ****\n\n");
        } else {
            repeat = 0;
            printf("\nInvalid input! Exiting custom Unit Converter...\n");
        }
    }

    return 0;
}