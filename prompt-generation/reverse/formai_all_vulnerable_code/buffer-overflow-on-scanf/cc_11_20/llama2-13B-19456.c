//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 5
#define MAX_CONVERTIONS 10

typedef struct {
    char name[20];
    double value;
} unit_t;

unit_t units[MAX_UNITS] = {
    {"meter", 1.0},
    {"kilogram", 1.0},
    {"second", 1.0},
    {"celsius", 1.0},
    {"gram", 1.0}
};

int main() {
    int i, j;
    char input[100];
    double value;

    // Print the unit menu
    printf("Welcome to the Ultimate Unit Converter!\n");
    printf("Select a unit to convert: ");
    for (i = 0; i < MAX_UNITS; i++) {
        printf("%d: %s\n", i + 1, units[i].name);
    }

    // Get the user's input
    scanf("%d", &i);

    // Convert the value
    switch (i) {
        case 1:
            value = units[0].value;
            break;
        case 2:
            value = units[1].value;
            break;
        case 3:
            value = units[2].value;
            break;
        case 4:
            value = units[3].value;
            break;
        case 5:
            value = units[4].value;
            break;
        default:
            printf("Invalid selection. Try again!\n");
            return 1;
    }

    // Print the conversion
    printf("Your value is: %f %s\n", value, units[i].name);

    // Ask the user if they want to convert again
    printf("Do you want to convert again? (y/n): ");
    scanf(" %c", &input[0]);

    // If the user wants to convert again, continue
    if (input[0] == 'y' || input[0] == 'Y') {
        // Clear the input
        printf("\n");
        // Get the next user input
        scanf("%d", &i);
        goto convert;
    } else {
        // If the user doesn't want to convert again, exit
        printf("Goodbye!👋\n");
        return 0;
    }

convert:
    // Convert the value again
    switch (i) {
        case 1:
            value = units[0].value * value;
            break;
        case 2:
            value = units[1].value * value;
            break;
        case 3:
            value = units[2].value * value;
            break;
        case 4:
            value = units[3].value * value;
            break;
        case 5:
            value = units[4].value * value;
            break;
        default:
            printf("Invalid selection. Try again!\n");
            return 1;
    }

    // Print the conversion
    printf("Your value is: %f %s\n", value, units[i].name);
}