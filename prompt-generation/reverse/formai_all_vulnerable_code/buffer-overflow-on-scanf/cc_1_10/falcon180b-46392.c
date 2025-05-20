//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONVERSIONS 10

// Define a struct to hold the conversion information
typedef struct {
    char from_unit[10];
    char to_unit[10];
    double conversion_factor;
} Conversion;

// Define an array of conversions
Conversion conversions[MAX_CONVERSIONS] = {
    {"m", "km", 0.001},
    {"km", "m", 1000},
    {"kg", "lb", 2.20462},
    {"lb", "kg", 0.453592},
    {"l", "gal", 0.264172},
    {"gal", "l", 3.78541},
    {"C", "F", 1.8},
    {"F", "C", 0.555555},
    {"mi", "km", 0.001},
    {"km", "mi", 0.621371}
};

// Function to perform the conversion
void convert(char *input, char *output) {
    int i;
    double value, result;

    // Find the conversion in the array
    for(i = 0; i < MAX_CONVERSIONS; i++) {
        if(strcmp(conversions[i].from_unit, input) == 0) {
            break;
        }
    }

    // If the conversion was not found, display an error message and exit
    if(i == MAX_CONVERSIONS) {
        printf("Error: Invalid conversion\n");
        exit(1);
    }

    // Convert the value
    value = atof(input);
    result = value * conversions[i].conversion_factor;

    // Print the result
    printf("%s %s = %f %s\n", input, conversions[i].to_unit, result, conversions[i].to_unit);
}

int main() {
    char input[10], output[10];

    // Get the input and output units from the user
    printf("Enter the input unit: ");
    scanf("%s", input);

    printf("Enter the output unit: ");
    scanf("%s", output);

    // Convert the units
    convert(input, output);

    return 0;
}