//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Alan Turing
#include <stdio.h>

// Define the number of units to convert
#define NUM_UNITS 5

// Define the units to convert between
char *units[] = {"m", "cm", "mm", "km", "in"};

// Define the conversion factors
double factors[] = {1.0, 0.01, 0.001, 0.000001, 0.393701};

// Define the number of decimal places to display
#define DECIMALS 2

// Function to convert a value from one unit to another
double convert(double value, int from, int to) {
    return value * factors[to] / factors[from];
}

int main() {
    int choice;
    char input[100];

    // Prompt the user to select a unit
    printf("Select a unit:\n");
    for (int i = 0; i < NUM_UNITS; i++) {
        printf("%d. %s\n", i + 1, units[i]);
    }
    scanf("%d", &choice);

    // Prompt the user to enter a value
    printf("Enter a value: ");
    scanf("%s", input);

    // Convert the input value to a number
    double value = atof(input);

    // Prompt the user to select a conversion unit
    printf("Select a conversion unit:\n");
    for (int i = 0; i < NUM_UNITS; i++) {
        printf("%d. %s\n", i + 1, units[i]);
    }
    scanf("%d", &choice);

    // Convert the value and display the result
    double result = convert(value, 0, choice - 1);
    printf("%.2f %s is equal to %.2f %s.\n", value, units[0], result, units[choice]);

    return 0;
}