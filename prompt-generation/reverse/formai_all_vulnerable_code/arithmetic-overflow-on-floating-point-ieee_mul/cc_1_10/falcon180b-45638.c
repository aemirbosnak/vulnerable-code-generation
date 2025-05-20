//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main() {
    // Declare variables
    char unit[10], outputUnit[10], inputString[100];
    double value, convertedValue;
    int choice;

    // Initialize variables
    strcpy(unit, "kg");
    strcpy(outputUnit, "lb");

    // Display welcome message
    printf("Welcome to the Unit Converter!\n");
    printf("This program is designed to convert units of measurement.\n");
    printf("Please select the unit you would like to convert from: \n");
    printf("1. Kilograms\n2. Grams\n3. Milligrams\n");
    scanf("%d", &choice);

    // Convert user input to lowercase
    for (int i = 0; i < strlen(unit); i++) {
        unit[i] = tolower(unit[i]);
    }

    // Get user input
    printf("Enter the value you would like to convert: ");
    scanf("%s", inputString);

    // Convert user input to lowercase
    for (int i = 0; i < strlen(inputString); i++) {
        inputString[i] = tolower(inputString[i]);
    }

    // Convert user input to double
    value = atof(inputString);

    // Convert kilograms to pounds
    if (choice == 1) {
        convertedValue = value * 2.20462;
        printf("%.2f kilograms is equal to %.2f pounds.\n", value, convertedValue);
    }

    // Convert grams to pounds
    else if (choice == 2) {
        convertedValue = value / 0.00220462;
        printf("%.2f grams is equal to %.2f pounds.\n", value, convertedValue);
    }

    // Convert milligrams to pounds
    else if (choice == 3) {
        convertedValue = value / 0.00000220462;
        printf("%.2f milligrams is equal to %.2f pounds.\n", value, convertedValue);
    }

    // Display goodbye message
    printf("Thank you for using the Unit Converter!\n");
    printf("Please come back soon!\n");

    return 0;
}