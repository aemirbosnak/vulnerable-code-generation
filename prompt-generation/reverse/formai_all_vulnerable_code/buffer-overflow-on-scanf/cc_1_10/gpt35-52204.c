//FormAI DATASET v1.0 Category: Unit converter ; Style: decentralized
#include <stdio.h>
#include <string.h>

float convertUnit(float input, char inputUnit[], char outputUnit[]);

int main() {
    float input;
    char inputUnit[15], outputUnit[15];

    printf("Enter the value: ");
    scanf("%f", &input);

    printf("Enter the input unit: ");
    scanf("%s", inputUnit);

    printf("Enter the output unit: ");
    scanf("%s", outputUnit);

    printf("%.2f %s is equivalent to %.2f %s.\n", input, inputUnit, convertUnit(input, inputUnit, outputUnit), outputUnit);

    return 0;
}

float convertUnit(float input, char inputUnit[], char outputUnit[]) {
    float output;

    if(strcmp(inputUnit, "miles") == 0) {
        if(strcmp(outputUnit, "kilometers") == 0) {
            output = input * 1.60934;
        }
        else if(strcmp(outputUnit, "meters") == 0) {
            output = input * 1609.34;
        }
        else if(strcmp(outputUnit, "centimeters") == 0) {
            output = input * 160934;
        }
        else {
            output = input;
        }
    }

    else if(strcmp(inputUnit, "kilometers") == 0) {
        if(strcmp(outputUnit, "miles") == 0) {
            output = input / 1.60934;
        }
        else if(strcmp(outputUnit, "meters") == 0) {
            output = input * 1000;
        }
        else if(strcmp(outputUnit, "centimeters") == 0) {
            output = input * 100000;
        }
        else {
            output = input;
        }
    }

    else if(strcmp(inputUnit, "meters") == 0) {
        if(strcmp(outputUnit, "miles") == 0) {
            output = input / 1609.34;
        }
        else if(strcmp(outputUnit, "kilometers") == 0) {
            output = input / 1000;
        }
        else if(strcmp(outputUnit, "centimeters") == 0) {
            output = input * 100;
        }
        else {
            output = input;
        }
    }

    else if(strcmp(inputUnit, "centimeters") == 0) {
        if(strcmp(outputUnit, "miles") == 0) {
            output = input / 160934;
        }
        else if(strcmp(outputUnit, "kilometers") == 0) {
            output = input / 100000;
        }
        else if(strcmp(outputUnit, "meters") == 0) {
            output = input / 100;
        }
        else {
            output = input;
        }
    }

    else {
        output = input;
    }

    return output;
}