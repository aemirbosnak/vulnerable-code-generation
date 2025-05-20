//FormAI DATASET v1.0 Category: Temperature Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <math.h>

typedef struct TemperatureInputData {
    char *inputValue;
    char *inputUnit;
    char *outputUnit;
} TemperatureInputData;

// function to perform temperature unit conversion
void convertTemperature(TemperatureInputData *tempInputData) {
    double inputValue = strtod(tempInputData->inputValue, NULL);
    char *inputUnit = tempInputData->inputUnit;
    char *outputUnit = tempInputData->outputUnit;
    double result;

    if (strcmp(inputUnit, "C") == 0) {
        if (strcmp(outputUnit, "F") == 0) {
            result = (inputValue * 9 / 5) + 32;
            printf("%.2lf C ==> %.2lf F\n", inputValue, result);
        } else if (strcmp(outputUnit, "K") == 0) {
            result = inputValue + 273.15;
            printf("%.2lf C ==> %.2lf K\n", inputValue, result);
        } else {
            printf("Invalid output unit, please enter valid unit (F or K).\n");
        }
    } else if (strcmp(inputUnit, "F") == 0) {
        if (strcmp(outputUnit, "C") == 0) {
            result = (inputValue - 32) * 5 / 9;
            printf("%.2lf F ==> %.2lf C\n", inputValue, result);
        } else if (strcmp(outputUnit, "K") == 0) {
            result = (inputValue + 459.67) * 5 / 9;
            printf("%.2lf F ==> %.2lf K\n", inputValue, result);
        } else {
            printf("Invalid output unit, please enter valid unit (C or K).\n");
        }
    } else if (strcmp(inputUnit, "K") == 0) {
        if (strcmp(outputUnit, "C") == 0) {
            result = inputValue - 273.15;
            printf("%.2lf K ==> %.2lf C\n", inputValue, result);
        } else if (strcmp(outputUnit, "F") == 0) {
            result = inputValue * 9 / 5 - 459.67;
            printf("%.2lf K ==> %.2lf F\n", inputValue, result);
        } else {
            printf("Invalid output unit, please enter valid unit (C or F).\n");
        }
    } else {
        printf("Invalid input unit, please enter valid unit (C, F or K).\n");
    }
}

// function to validate temperature input data
bool validateTemperatureInput(TemperatureInputData *tempInputData) {
    char *inputValue = tempInputData->inputValue;
    char *inputUnit = tempInputData->inputUnit;

    if (inputValue == NULL || strlen(inputValue) == 0) {
        printf("Input value cannot be empty.\n");
        return false;
    }

    for (int i = 0; i < strlen(inputValue); i++) {
        if (!isdigit(inputValue[i]) && inputValue[i] != '.') {
            printf("Invalid input value, please enter valid number.\n");
            return false;
        }
    }

    if (inputUnit == NULL || strlen(inputUnit) == 0) {
        printf("Input unit cannot be empty.\n");
        return false;
    }

    if (strcmp(inputUnit, "C") != 0 && strcmp(inputUnit, "F") != 0 && strcmp(inputUnit, "K") != 0) {
        printf("Invalid input unit, please enter valid unit (C, F or K).\n");
        return false;
    }

    return true;
}

// function to read input temperature data
TemperatureInputData *readTemperatureInput() {
    TemperatureInputData *tempInputData = (TemperatureInputData*)malloc(sizeof(TemperatureInputData));
    char *inputValue = (char*)malloc(sizeof(char) * 10);
    char *inputUnit = (char*)malloc(sizeof(char) * 5);
    char *outputUnit = (char*)malloc(sizeof(char) * 5);

    printf("Enter input temperature (eg: 32 C): ");
    scanf("%s %s", inputValue, inputUnit);

    printf("Enter output temperature unit (eg: F or K): ");
    scanf("%s", outputUnit);

    tempInputData->inputValue = inputValue;
    tempInputData->inputUnit = inputUnit;
    tempInputData->outputUnit = outputUnit;

    return tempInputData;
}

int main() {
    TemperatureInputData *tempInputData;

    while (true) {
        tempInputData = readTemperatureInput();

        if (validateTemperatureInput(tempInputData)) {
            convertTemperature(tempInputData);
            break;
        }
    }

    return 0;
}