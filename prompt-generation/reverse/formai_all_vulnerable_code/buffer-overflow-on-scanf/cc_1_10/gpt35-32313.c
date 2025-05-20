//FormAI DATASET v1.0 Category: Color Code Converter ; Style: genious
#include <stdio.h>

// function to convert RGB to Hexadecimal Color Code
void RGBtoHex(int r, int g, int b) {
    // variable to store the final Hexadecimal Color Code
    char hex[7];
    // converting the RGB color code into Hexadecimal color code
    sprintf(hex, "#%02x%02x%02x", r, g, b);
    printf("\nThe Hexadecimal Color Code for RGB(%d, %d, %d) is %s\n", r, g, b, hex);
}

// function to convert Hexadecimal Color Code to RGB
void HexToRGB(char hex[]) {
    // variable to store the final RGB color code
    int r, g, b;
    // converting the Hexadecimal color code into RGB color code
    sscanf(hex, "#%02x%02x%02x", &r, &g, &b);
    printf("\nThe RGB Color Code for %s is (%d, %d, %d)\n", hex, r, g, b);
}

int main() {
    // variable to store the user choice
    int choice;
    // variables to store the RGB color code
    int r, g, b;
    // variable to store the Hexadecimal color code
    char hex[7];

    // loop until the user chooses to exit
    do {
        printf("\nSelect an option:\n");
        printf("1. Convert RGB Color Code to Hexadecimal Color Code\n");
        printf("2. Convert Hexadecimal Color Code to RGB Color Code\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // get the RGB color code from the user
                printf("\nEnter the RGB Color Code (separated by spaces): ");
                scanf("%d %d %d", &r, &g, &b);
                // call the RGBtoHex function to convert the RGB color code to Hexadecimal color code
                RGBtoHex(r, g, b);
                break;
            case 2:
                // get the Hexadecimal color code from the user
                printf("\nEnter the Hexadecimal Color Code (with # symbol): ");
                scanf("%s", hex);
                // call the HexToRGB function to convert the Hexadecimal color code to RGB color code
                HexToRGB(hex);
                break;
            case 3:
                printf("\nExiting Color Code Converter!\n");
                break;
            default:
                printf("\nInvalid choice! Please enter a valid choice.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}