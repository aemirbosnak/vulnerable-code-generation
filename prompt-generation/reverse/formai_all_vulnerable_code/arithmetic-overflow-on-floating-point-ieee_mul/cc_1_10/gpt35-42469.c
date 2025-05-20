//FormAI DATASET v1.0 Category: Unit converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

float convertTemperature(float input, char inputUnit, char outputUnit);
float convertWeight(float input, char inputUnit, char outputUnit);
float convertLength(float input, char inputUnit, char outputUnit);
char askForCategory(void);
char askForUnit(char category);
float askForValue(void);

int main() {
	char category, inputUnit, outputUnit;
	float input, output;

    printf("Welcome to the Unit Converter!\n\n");

    while (1) {
        category = askForCategory();

        if (category == 'Q') {
            printf("Thank you for using the Unit Converter. Goodbye!\n");
            break;
        }

        inputUnit = askForUnit(category);
        outputUnit = askForUnit(category);

        input = askForValue();

        switch(category) {
            case 'T':
                output = convertTemperature(input, inputUnit, outputUnit);
                printf("%.2f %c = %.2f %c\n\n", input, inputUnit, output, outputUnit);
                break;
            case 'W':
                output = convertWeight(input, inputUnit, outputUnit);
                printf("%.2f %c = %.2f %c\n\n", input, inputUnit, output, outputUnit);
                break;
            case 'L':
                output = convertLength(input, inputUnit, outputUnit);
                printf("%.2f %c = %.2f %c\n\n", input, inputUnit, output, outputUnit);
                break;
            default:
                printf("Invalid category. Please try again.\n\n");
        }
    }

    return 0;
}

float convertTemperature(float input, char inputUnit, char outputUnit) {
    float output;

    if (inputUnit == 'C') {
        switch(outputUnit) {
            case 'F':
                output = (input * 1.8) + 32;
                break;
            case 'K':
                output = input + 273.15;
                break;
            default:
                output = input;
        }
    }
    else if (inputUnit == 'F') {
        switch(outputUnit) {
            case 'C':
                output = (input - 32) / 1.8;
                break;
            case 'K':
                output = ((input - 32) / 1.8) + 273.15;
                break;
            default:
                output = input;
        }
    }
    else if (inputUnit == 'K') {
        switch(outputUnit) {
            case 'C':
                output = input - 273.15;
                break;
            case 'F':
                output = ((input - 273.15) * 1.8) + 32;
                break;
            default:
                output = input;
        }
    }
    else {
        output = input;
    }

    return output;
}

float convertWeight(float input, char inputUnit, char outputUnit) {
    float output;

    if (inputUnit == 'G') {
        switch(outputUnit) {
            case 'K':
                output = input / 1000;
                break;
            case 'L':
                output = input / 453.592;
                break;
            default:
                output = input;
        }
    }
    else if (inputUnit == 'K') {
        switch(outputUnit) {
            case 'G':
                output = input * 1000;
                break;
            case 'L':
                output = input * 2.20462;
                break;
            default:
                output = input;
        }
    }
    else if (inputUnit == 'L') {
        switch(outputUnit) {
            case 'G':
                output = input * 453.592;
                break;
            case 'K':
                output = input / 2.20462;
                break;
            default:
                output = input;
        }
    }
    else {
        output = input;
    }

    return output;
}

float convertLength(float input, char inputUnit, char outputUnit) {
    float output;

    if (inputUnit == 'C') {
        switch(outputUnit) {
            case 'I':
                output = input / 2.54;
                break;
            case 'M':
                output = input / 100;
                break;
            default:
                output = input;
        }
    }
    else if (inputUnit == 'I') {
        switch(outputUnit) {
            case 'C':
                output = input * 2.54;
                break;
            case 'M':
                output = input / 39.3701;
                break;
            default:
                output = input;
        }
    }
    else if (inputUnit == 'M') {
        switch(outputUnit) {
            case 'C':
                output = input * 100;
                break;
            case 'I':
                output = input * 39.3701;
                break;
            default:
                output = input;
        }
    }
    else {
        output = input;
    }

    return output;
}

char askForCategory() {
    char category;

    printf("What category would you like to convert in?\n");
    printf("T) Temperature\n");
    printf("W) Weight\n");
    printf("L) Length\n");
    printf("Q) Quit\n");
    printf("Please enter the category letter: ");

    scanf(" %c", &category);

    return category;
}

char askForUnit(char category) {
    char unit;

    if (category == 'T') {
        printf("What temperature unit would you like to convert to?\n");
        printf("C) Celsius\n");
        printf("F) Fahrenheit\n");
        printf("K) Kelvin\n");
        printf("Please enter the unit letter: ");
    }
    else if (category == 'W') {
        printf("What weight unit would you like to convert to?\n");
        printf("G) grams\n");
        printf("K) kilograms\n");
        printf("L) pounds\n");
        printf("Please enter the unit letter: ");
    }
    else if (category == 'L') {
        printf("What length unit would you like to convert to?\n");
        printf("C) centimeters\n");
        printf("I) inches\n");
        printf("M) meters\n");
        printf("Please enter the unit letter: ");
    }

    scanf(" %c", &unit);

    return unit;
}

float askForValue() {
    float value;

    printf("Please enter the value to convert: ");
    scanf("%f", &value);

    return value;
}