//FormAI DATASET v1.0 Category: Unit converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int choice = 0, valid = 0;
    double inputValue = 0, outputValue = 0;
    char inputUnit[10] = "", outputUnit[10] = "", input[100], *ptr = NULL;

    while (!valid) {
        printf("Please enter your input value and unit: ");
        fgets(input, 100, stdin);
        if (sscanf(input, "%lf %s", &inputValue, inputUnit) == 2) {
            valid = 1;
        }
        else {
            printf("Invalid input, please enter a number followed by a valid unit of measurement.\n");
        }
    }

    valid = 0;
    while (!valid) {
        printf("Please choose your output unit:\n");
        printf("1. Meters\n");
        printf("2. Kilometers\n");
        printf("3. Feet\n");
        printf("4. Yards\n");
        printf("5. Miles\n");
        printf("Enter a number from 1-5: ");
        fgets(input, 100, stdin);
        if (sscanf(input, "%d", &choice) == 1 && choice >= 1 && choice <= 5) {
            valid = 1;
        }
        else {
            printf("Invalid choice, please enter a number from 1-5.\n");
        }
    }

    switch (choice) {
        case 1:
            strcpy(outputUnit, "meters");
            outputValue = inputValue;
            break;
        case 2:
            strcpy(outputUnit, "kilometers");
            outputValue = inputValue * 0.001;
            break;
        case 3:
            strcpy(outputUnit, "feet");
            outputValue = inputValue * 3.28084;
            break;
        case 4:
            strcpy(outputUnit, "yards");
            outputValue = inputValue * 1.09361;
            break;
        case 5:
            strcpy(outputUnit, "miles");
            outputValue = inputValue * 0.000621371;
            break;
    }

    printf("%g %s is equal to %g %s.\n", inputValue, inputUnit, outputValue, outputUnit);

    return 0;
}