//FormAI DATASET v1.0 Category: Color Code Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    printf("Welcome to the Color Code Converter!\n");

    // Prompt user for input
    printf("Please enter the color code you would like to convert: ");

    // Read in user input
    char colorCode[8];
    fgets(colorCode, sizeof(colorCode), stdin);

    // Remove newline character
    if (colorCode[strlen(colorCode) - 1] == '\n') {
        colorCode[strlen(colorCode) - 1] = '\0';
    }

    // Check if color code is valid
    if (strlen(colorCode) != 7 || colorCode[0] != '#' || strspn(colorCode + 1, "0123456789ABCDEFabcdef") != 6) {
        printf("Invalid color code! Please enter a valid color code.\n");
        return 1;
    }

    // Convert color code to RGB values
    int r = (int)strtol(colorCode + 1, NULL, 16);
    int g = (int)strtol(colorCode + 3, NULL, 16);
    int b = (int)strtol(colorCode + 5, NULL, 16);

    // Print out RGB values
    printf("The RGB values for %s are (%d, %d, %d).\n", colorCode, r, g, b);

    // Prompt user to continue
    printf("Would you like to convert another color code? Enter Y for yes, or N for no: ");

    // Read in user input
    char input[2];
    fgets(input, sizeof(input), stdin);

    // Remove newline character
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    // Convert input to uppercase
    if (input[0] >= 97 && input[0] <= 122) {
        input[0] -= 32;
    }

    // Check user input
    if (strcmp(input, "Y") == 0) {
        main();
    } else if (strcmp(input, "N") == 0) {
        printf("Thank you for using the Color Code Converter!\n");
    } else {
        printf("Invalid input! Please enter either Y or N.\n");
        return 1;
    }

    return 0;
}