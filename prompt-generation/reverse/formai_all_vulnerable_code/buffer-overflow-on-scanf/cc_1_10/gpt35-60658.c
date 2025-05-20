//FormAI DATASET v1.0 Category: Unit converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void printMenu();
void convertLength();
void convertTemperature();
void convertWeight();

int main() {
    int choice;
    printf("Welcome to Unit Converter!\n");

    // infinite loop
    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                convertLength();
                break;
            case 2:
                convertTemperature();
                break;
            case 3:
                convertWeight();
                break;
            case 4:
                printf("Thank you for using Unit Converter!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void printMenu() {
    printf("\nWhat would you like to convert?\n");
    printf("1. Length\n");
    printf("2. Temperature\n");
    printf("3. Weight\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
}

void convertLength() {
    float value;
    char fromUnit[10], toUnit[10];

    printf("\nEnter the value to be converted: ");
    scanf("%f", &value);
    printf("Enter the unit of the value (e.g. cm, inch): ");
    scanf("%s", fromUnit);
    printf("Enter the desired unit to convert to (e.g. m, ft): ");
    scanf("%s", toUnit);

    // conversion logic
    float result;
    if (strcmp(fromUnit, "cm") == 0 && strcmp(toUnit, "m") == 0) {
        result = value / 100.0;
    }
    else if (strcmp(fromUnit, "m") == 0 && strcmp(toUnit, "cm") == 0) {
        result = value * 100.0;
    }
    else if (strcmp(fromUnit, "inch") == 0 && strcmp(toUnit, "cm") == 0) {
        result = value * 2.54;
    }
    else if (strcmp(fromUnit, "cm") == 0 && strcmp(toUnit, "inch") == 0) {
        result = value / 2.54;
    }
    else if (strcmp(fromUnit, "m") == 0 && strcmp(toUnit, "ft") == 0) {
        result = value * 3.281;
    }
    else if (strcmp(fromUnit, "ft") == 0 && strcmp(toUnit, "m") == 0) {
        result = value / 3.281;
    }
    else {
        printf("Invalid units. Please try again.\n");
        return;
    }

    printf("%.2f %s = %.2f %s\n", value, fromUnit, result, toUnit);
}

void convertTemperature() {
    float value;
    char fromUnit[10], toUnit[10];

    printf("\nEnter the value to be converted: ");
    scanf("%f", &value);
    printf("Enter the unit of the value (e.g. C, F, K): ");
    scanf("%s", fromUnit);
    printf("Enter the desired unit to convert to (e.g. C, F, K): ");
    scanf("%s", toUnit);

    // conversion logic
    float result;
    if (strcmp(fromUnit, "C") == 0 && strcmp(toUnit, "F") == 0) {
        result = (value * 9.0/5.0) + 32;
    }
    else if (strcmp(fromUnit, "F") == 0 && strcmp(toUnit, "C") == 0) {
        result = (value - 32) * 5.0/9.0;
    }
    else if (strcmp(fromUnit, "C") == 0 && strcmp(toUnit, "K") == 0) {
        result = value + 273.15;
    }
    else if (strcmp(fromUnit, "K") == 0 && strcmp(toUnit, "C") == 0) {
        result = value - 273.15;
    }
    else if (strcmp(fromUnit, "F") == 0 && strcmp(toUnit, "K") == 0) {
        result = (value + 459.67) * 5.0/9.0;
    }
    else if (strcmp(fromUnit, "K") == 0 && strcmp(toUnit, "F") == 0) {
        result = (value * 9.0/5.0) - 459.67;
    }
    else {
        printf("Invalid units. Please try again.\n");
        return;
    }

    printf("%.2f %s = %.2f %s\n", value, fromUnit, result, toUnit);
}

void convertWeight() {
    float value;
    char fromUnit[10], toUnit[10];

    printf("\nEnter the value to be converted: ");
    scanf("%f", &value);
    printf("Enter the unit of the value (e.g. g, kg, lb, oz): ");
    scanf("%s", fromUnit);
    printf("Enter the desired unit to convert to (e.g. g, kg, lb, oz): ");
    scanf("%s", toUnit);

    // conversion logic
    float result;
    if (strcmp(fromUnit, "g") == 0 && strcmp(toUnit, "kg") == 0) {
        result = value / 1000.0;
    }
    else if (strcmp(fromUnit, "kg") == 0 && strcmp(toUnit, "g") == 0) {
        result = value * 1000.0;
    }
    else if (strcmp(fromUnit, "lb") == 0 && strcmp(toUnit, "kg") == 0) {
        result = value * 0.453592;
    }
    else if (strcmp(fromUnit, "kg") == 0 && strcmp(toUnit, "lb") == 0) {
        result = value * 2.20462;
    }
    else if (strcmp(fromUnit, "oz") == 0 && strcmp(toUnit, "g") == 0) {
        result = value * 28.3495;
    }
    else if (strcmp(fromUnit, "g") == 0 && strcmp(toUnit, "oz") == 0) {
        result = value / 28.3495;
    }
    else {
        printf("Invalid units. Please try again.\n");
        return;
    }

    printf("%.2f %s = %.2f %s\n", value, fromUnit, result, toUnit);
}