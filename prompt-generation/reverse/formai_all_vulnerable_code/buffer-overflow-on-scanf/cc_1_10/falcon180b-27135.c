//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int choice;
    char color[10];
    int hex;
    int r, g, b;

    // Menu
    printf("Welcome to the Color Code Converter!\n\n");
    printf("1. Convert RGB to Hex\n");
    printf("2. Convert Hex to RGB\n");
    printf("3. Exit\n");
    printf("\n");

    // Get user choice
    scanf("%d", &choice);

    // Convert RGB to Hex
    if (choice == 1) {
        printf("Enter the RGB values: ");
        scanf("%d %d %d", &r, &g, &b);

        // Convert RGB to hexadecimal
        sprintf(color, "#%02X%02X%02X", r, g, b);

        // Display the result
        printf("The hexadecimal color code is: %s\n", color);
    }

    // Convert Hex to RGB
    if (choice == 2) {
        printf("Enter the hexadecimal color code: ");
        scanf("%s", color);

        // Convert hexadecimal to RGB
        sscanf(color, "#%02X%02X%02X", &r, &g, &b);

        // Display the result
        printf("The RGB values are: %d %d %d\n", r, g, b);
    }

    // Exit
    if (choice == 3) {
        printf("Exiting program...\n");
    }

    return 0;
}