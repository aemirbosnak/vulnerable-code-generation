//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if input is a valid number
int isNumber(char* input) {
    int i;
    for(i = 0; i < strlen(input); i++) {
        if(!isdigit(input[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert between units
double convert(double value, char* from, char* to) {
    if(strcmp(from, "m") == 0 && strcmp(to, "km") == 0) {
        return value / 1000.0;
    } else if(strcmp(from, "km") == 0 && strcmp(to, "m") == 0) {
        return value * 1000.0;
    } else if(strcmp(from, "kg") == 0 && strcmp(to, "lb") == 0) {
        return value * 2.20462;
    } else if(strcmp(from, "lb") == 0 && strcmp(to, "kg") == 0) {
        return value / 2.20462;
    } else if(strcmp(from, "l") == 0 && strcmp(to, "gal") == 0) {
        return value * 3.78541;
    } else if(strcmp(from, "gal") == 0 && strcmp(to, "l") == 0) {
        return value / 3.78541;
    } else {
        printf("Invalid conversion\n");
        exit(1);
    }
}

int main() {
    char input[100];
    char from[10];
    char to[10];
    double value;

    // Get user input
    printf("Enter a value to convert: ");
    scanf("%s", input);

    // Check if input is a valid number
    if(!isNumber(input)) {
        printf("Invalid input\n");
        exit(1);
    }

    // Get the units to convert from
    printf("Enter the units to convert from: ");
    scanf("%s", from);

    // Get the units to convert to
    printf("Enter the units to convert to: ");
    scanf("%s", to);

    // Convert the value
    value = strtod(input, NULL);
    value = convert(value, from, to);

    // Print the result
    printf("%.2f %s = %.2f %s\n", value, to, value, from);

    return 0;
}