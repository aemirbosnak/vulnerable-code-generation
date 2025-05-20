//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Function to convert RGB to hexadecimal color code
void RGB_to_HEX(int R, int G, int B)
{
    // Converting RGB values to hexadecimal string
    char hex[7];
    sprintf(hex, "%02X%02X%02X", R, G, B);
    
    // Printing the hexadecimal color code
    printf("The hexadecimal color code for (%d, %d, %d) is #%s\n", R, G, B, hex);
}

// Function to convert hexadecimal color code to RGB
void HEX_to_RGB(char hex_code[])
{
    // Converting hexadecimal string to RGB values
    int R, G, B;
    sscanf(hex_code, "%02X%02X%02X", &R, &G, &B);
    
    // Printing the RGB values
    printf("The RGB values for #%s are (%d, %d, %d)\n", hex_code, R, G, B);
}

int main()
{
    int option;
    
    // Displaying menu
    printf("Color Code Converter\n");
    printf("1. RGB to HEX\n");
    printf("2. HEX to RGB\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &option);
    
    // Validating the input
    if (option != 1 && option != 2) {
        printf("Invalid choice!\n");
        exit(0);
    }
    
    // Taking input from the user
    int R, G, B;
    char hex_code[7];
    if (option == 1) {
        printf("Enter the RGB values (0-255): ");
        scanf("%d %d %d", &R, &G, &B);
        RGB_to_HEX(R, G, B);
    } else {
        printf("Enter the hexadecimal color code: ");
        scanf("%s", hex_code);
        HEX_to_RGB(hex_code);
    }
    
    return 0;
}