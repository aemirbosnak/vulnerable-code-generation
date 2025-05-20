//FormAI DATASET v1.0 Category: Unit converter ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// function to clear input buffer
void clearInputBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// function to convert temperature units
float temperatureConversion(float temp, char fromType, char toType) {
    float result;
    if (fromType == 'C') {
        if (toType == 'F') {
            result = (temp * 1.8) + 32;
        } else if (toType == 'K') {
            result = temp + 273.15;
        } else {
            printf("Invalid unit selected!\n");
            return 0;
        }
    } else if (fromType == 'F') {
        if (toType == 'C') {
            result = (temp - 32) / 1.8;
        } else if (toType == 'K') {
            result = ((temp - 32) / 1.8) + 273.15;
        } else {
            printf("Invalid unit selected!\n");
            return 0;
        }
    } else if (fromType == 'K') {
        if (toType == 'C') {
            result = temp - 273.15;
        } else if (toType == 'F') {
            result = ((temp - 273.15) * 1.8) + 32;
        } else {
            printf("Invalid unit selected!\n");
            return 0;
        }
    } else {
        printf("Invalid unit selected!\n");
        return 0;
    }
    return result;
}

int main() {
    float conversionResult, inputValue;
    char inputUnitType, outputUnitType, choice;
    int exitProgram = 0;
    
    while (!exitProgram) {
        printf("Enter the value to convert:\n");
        scanf("%f", &inputValue);
        clearInputBuffer();
        
        printf("Enter the type of unit (C, F, K):\n");
        scanf("%c", &inputUnitType);
        inputUnitType = toupper(inputUnitType);
        clearInputBuffer();
        
        printf("Enter the unit to convert to (C, F, K):\n");
        scanf("%c", &outputUnitType);
        outputUnitType = toupper(outputUnitType);
        clearInputBuffer();
        
        conversionResult = temperatureConversion(inputValue, inputUnitType, outputUnitType);
        if (conversionResult != 0) {
            printf("%.2f %c is equal to %.2f %c\n", inputValue, inputUnitType, conversionResult, outputUnitType);
        }
        
        printf("Would you like to convert another value? (Y/N)\n");
        scanf("%c", &choice);
        choice = toupper(choice);
        clearInputBuffer();
        
        if (choice == 'N') {
            exitProgram = 1;
        }
    }
    
    printf("Thank you for using our unit converter!\n");
    
    return 0;
}