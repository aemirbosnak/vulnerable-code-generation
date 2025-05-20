//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[100];
    char unitFrom[10];
    char unitTo[10];
    double value;
    int choice;
    int validInput = 0;

    printf("Welcome to the Surrealist Unit Converter!\n");
    printf("Please enter a value, the unit you want to convert from, and the unit you want to convert to.\n");
    printf("For example: 10 meters to feet\n");
    scanf("%s %s %s", input, unitFrom, unitTo);

    if (strcmp(unitFrom, "meters") == 0) {
        if (strcmp(unitTo, "feet") == 0) {
            value = atof(input) * 3.28084;
            printf("%s meters is equal to %.2f feet.\n", input, value);
        } else if (strcmp(unitTo, "inches") == 0) {
            value = atof(input) * 39.3701;
            printf("%s meters is equal to %.2f inches.\n", input, value);
        } else {
            printf("Invalid unit conversion.\n");
        }
    } else if (strcmp(unitFrom, "feet") == 0) {
        if (strcmp(unitTo, "meters") == 0) {
            value = atof(input) / 3.28084;
            printf("%s feet is equal to %.2f meters.\n", input, value);
        } else if (strcmp(unitTo, "inches") == 0) {
            value = atof(input) * 12;
            printf("%s feet is equal to %.2f inches.\n", input, value);
        } else {
            printf("Invalid unit conversion.\n");
        }
    } else if (strcmp(unitFrom, "inches") == 0) {
        if (strcmp(unitTo, "meters") == 0) {
            value = atof(input) / 39.3701;
            printf("%s inches is equal to %.2f meters.\n", input, value);
        } else if (strcmp(unitTo, "feet") == 0) {
            value = atof(input) / 12;
            printf("%s inches is equal to %.2f feet.\n", input, value);
        } else {
            printf("Invalid unit conversion.\n");
        }
    } else {
        printf("Invalid unit conversion.\n");
    }

    return 0;
}