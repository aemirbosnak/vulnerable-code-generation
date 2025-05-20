//Falcon2-11B DATASET v1.0 Category: Unit converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float inputValue, outputValue;
    char unitInput[20], unitOutput[20];
    int errorCode = 0;

    // Ask for user input
    printf("Please enter a value: ");
    scanf("%f", &inputValue);
    printf("Please enter the desired unit: ");
    scanf(" %s", unitInput);
    printf("Please enter the desired output unit: ");
    scanf(" %s", unitOutput);

    // Convert the value to the output unit
    if (strcmp(unitInput, "cm") == 0) {
        if (strcmp(unitOutput, "in") == 0) {
            outputValue = inputValue * 0.393701;
        } else if (strcmp(unitOutput, "m") == 0) {
            outputValue = inputValue * 0.01;
        } else if (strcmp(unitOutput, "ft") == 0) {
            outputValue = inputValue * 0.032808;
        } else if (strcmp(unitOutput, "km") == 0) {
            outputValue = inputValue * 0.000001;
        } else {
            errorCode = 1;
        }
    } else if (strcmp(unitInput, "in") == 0) {
        if (strcmp(unitOutput, "cm") == 0) {
            outputValue = inputValue * 2.54;
        } else if (strcmp(unitOutput, "m") == 0) {
            outputValue = inputValue * 0.0254;
        } else if (strcmp(unitOutput, "ft") == 0) {
            outputValue = inputValue * 0.083333;
        } else if (strcmp(unitOutput, "km") == 0) {
            outputValue = inputValue * 0.0254;
        } else {
            errorCode = 1;
        }
    } else if (strcmp(unitInput, "m") == 0) {
        if (strcmp(unitOutput, "cm") == 0) {
            outputValue = inputValue * 100;
        } else if (strcmp(unitOutput, "in") == 0) {
            outputValue = inputValue * 39.3701;
        } else if (strcmp(unitOutput, "ft") == 0) {
            outputValue = inputValue * 3.28084;
        } else if (strcmp(unitOutput, "km") == 0) {
            outputValue = inputValue * 0.001;
        } else {
            errorCode = 1;
        }
    } else if (strcmp(unitInput, "ft") == 0) {
        if (strcmp(unitOutput, "cm") == 0) {
            outputValue = inputValue * 30.48;
        } else if (strcmp(unitOutput, "in") == 0) {
            outputValue = inputValue * 12;
        } else if (strcmp(unitOutput, "m") == 0) {
            outputValue = inputValue * 0.3048;
        } else if (strcmp(unitOutput, "km") == 0) {
            outputValue = inputValue * 0.0003048;
        } else {
            errorCode = 1;
        }
    } else if (strcmp(unitInput, "km") == 0) {
        if (strcmp(unitOutput, "cm") == 0) {
            outputValue = inputValue * 100000;
        } else if (strcmp(unitOutput, "in") == 0) {
            outputValue = inputValue * 3280.84;
        } else if (strcmp(unitOutput, "m") == 0) {
            outputValue = inputValue * 0.001;
        } else if (strcmp(unitOutput, "ft") == 0) {
            outputValue = inputValue * 0.000621371;
        } else {
            errorCode = 1;
        }
    } else {
        errorCode = 1;
    }

    // Convert the value to the output unit
    if (errorCode == 0) {
        printf("%.2f %s is equal to %.2f %s.\n", inputValue, unitInput, outputValue, unitOutput);
    } else {
        printf("Error: Invalid input or output unit.\n");
    }

    return 0;
}