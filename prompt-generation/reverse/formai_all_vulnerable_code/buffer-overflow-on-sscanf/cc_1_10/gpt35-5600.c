//FormAI DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100
#define NUM_UNITS 4

// Struct to hold unit data
typedef struct Unit {
    char name[20];
    double conversionFactor;
} Unit;

// Initialize units
Unit units[NUM_UNITS] = {
    {"Inches", 1.0},
    {"Feet", 12.0},
    {"Meters", 39.3701},
    {"Kilometers", 39370.1}
};

// Function to display menu options
void displayMenu() {
    printf("\n\nMenu\n");
    printf("----\n");
    for(int i = 0; i < NUM_UNITS; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }
    printf("0. Exit\n");
}

// Function to convert units
double convertUnits(double value, int fromIndex, int toIndex) {
    return value * (units[fromIndex].conversionFactor / units[toIndex].conversionFactor);
}

int main() {
    char input[MAX_INPUT_SIZE], *ptr;
    int fromIndex = -1, toIndex = -1;
    double value, convertedValue;

    // These variables are used to check for integer conversion errors
    long longValue;
    unsigned int uintValue;

    while(1) {
        displayMenu();
        printf("\nEnter a value and the unit you want to convert from (0 to exit): ");
        fgets(input, MAX_INPUT_SIZE, stdin);

        // Check if input is integer (value) followed by string (unit)
        value = strtod(input, &ptr);
        if(ptr == input) {
            printf("Invalid input. Please enter a number followed by a unit.\n");
            continue;
        }
        if(sscanf(ptr, "%llu", &longValue) == 1) {
            printf("Invalid input. Please enter a unit after the number.\n");
            continue;
        }

        // Check if input unit is valid
        if(sscanf(ptr, "%s", input) == 1) {
            for(int i = 0; i < NUM_UNITS; i++) {
                if(strcasecmp(units[i].name, input) == 0) {
                    fromIndex = i;
                    break;
                }
            }
            if(fromIndex == -1) {
                printf("Invalid unit '%s'. Please enter a valid unit.\n", input);
                continue;
            }
        } else {
            printf("Invalid input. Please enter a valid unit after the number.\n");
            continue;
        }

        // Get unit to convert to
        printf("Enter the unit you want to convert to: ");
        if(fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
            printf("Error reading input. Please try again.\n");
            continue;
        }
        if(sscanf(input, "%s", input) == 1) {
            for(int i = 0; i < NUM_UNITS; i++) {
                if(strcasecmp(units[i].name, input) == 0) {
                    toIndex = i;
                    break;
                }
            }
            if(toIndex == -1) {
                printf("Invalid unit '%s'. Please enter a valid unit.\n", input);
                continue;
            }
        } else {
            printf("Invalid input. Please enter a valid unit.\n");
            continue;
        }

        // Convert units and print result
        convertedValue = convertUnits(value, fromIndex, toIndex);
        printf("%.2f %s = %.2f %s\n", value, units[fromIndex].name, convertedValue, units[toIndex].name);
    }

    return 0;
}