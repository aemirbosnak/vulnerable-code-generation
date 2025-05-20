//FormAI DATASET v1.0 Category: Unit converter ; Style: happy
#include <stdio.h>

int main() {
    printf("Welcome to the Happy Unit Converter!\n\n");

    int choice1, choice2;
    float value;
    printf("What unit would you like to convert from?\n");
    printf("1. Meter\n2. Kilometer\n3. Centimeter\n4. Millimeter\n5. Feet\n6. Inches\n");
    scanf("%d", &choice1);
    printf("What unit would you like to convert to?\n");
    printf("1. Meter\n2. Kilometer\n3. Centimeter\n4. Millimeter\n5. Feet\n6. Inches\n");
    scanf("%d", &choice2);
    printf("Enter the value you would like to convert: ");
    scanf("%f", &value);

    float convertedValue;
    if (choice1 == choice2) {
        printf("You have chosen the same units. The value remains the same.\n");
        convertedValue = value;
    } else if (choice1 == 1) {
        if (choice2 == 2) {
            convertedValue = value / 1000;
        } else if (choice2 == 3) {
            convertedValue = value * 100;
        } else if (choice2 == 4) {
            convertedValue = value * 1000;
        } else if (choice2 == 5) {
            convertedValue = value * 3.281;
        } else {
            convertedValue = value * 39.37;
        }
    } else if (choice1 == 2) {
        if (choice2 == 1) {
            convertedValue = value * 1000;
        } else if (choice2 == 3) {
            convertedValue = value * 100000;
        } else if (choice2 == 4) {
            convertedValue = value * 1000000;
        } else if (choice2 == 5) {
            convertedValue = value * 3281;
        } else {
            convertedValue = value * 39370;
        }
    } else if (choice1 == 3) {
        if (choice2 == 1) {
            convertedValue = value / 100;
        } else if (choice2 == 2) {
            convertedValue = value / 100000;
        } else if (choice2 == 4) {
            convertedValue = value * 10;
        } else if (choice2 == 5) {
            convertedValue = value / 30.48;
        } else {
            convertedValue = value / 2.54;
        }
    } else if (choice1 == 4) {
        if (choice2 == 1) {
            convertedValue = value / 1000;
        } else if (choice2 == 2) {
            convertedValue = value / 1000000;
        } else if (choice2 == 3) {
            convertedValue = value / 10;
        } else if (choice2 == 5) {
            convertedValue = value / 304.8;
        } else {
            convertedValue = value / 25.4;
        }
    } else if (choice1 == 5) {
        if (choice2 == 1) {
            convertedValue = value / 3.281;
        } else if (choice2 == 2) {
            convertedValue = value / 3281;
        } else if (choice2 == 3) {
            convertedValue = value * 30.48;
        } else if (choice2 == 4) {
            convertedValue = value * 304.8;
        } else {
            convertedValue = value * 12;
        }
    } else {
        if (choice2 == 1) {
            convertedValue = value / 39.37;
        } else if (choice2 == 2) {
            convertedValue = value / 39370;
        } else if (choice2 == 3) {
            convertedValue = value * 2.54;
        } else if (choice2 == 4) {
            convertedValue = value * 25.4;
        } else {
            convertedValue = value / 12;
        }
    }

    printf("The converted value is: %.2f", convertedValue);
    printf("\n\nThanks for using the Happy Unit Converter!\n");
    return 0;
}