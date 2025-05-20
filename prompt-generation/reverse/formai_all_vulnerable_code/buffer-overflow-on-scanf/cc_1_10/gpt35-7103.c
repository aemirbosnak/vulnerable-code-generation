//FormAI DATASET v1.0 Category: Color Code Converter ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>

// Function to convert RGB to hex code
void rgbToHex(int r, int g, int b)
{
    // Check for valid input range
    if (r<0 || r>255 || g<0 || g>255 || b<0 || b>255)
    {
        printf("Invalid RGB color code!\n");
        return;
    }
    
    // Convert each color to hex
    char hexCode[7];
    sprintf(hexCode, "#%02X%02X%02X", r, g, b);
    
    // Print the hex code
    printf("The RGB color code (%d, %d, %d) is equivalent to %s in hex.\n", r, g, b, hexCode);
}

// Function to convert hex code to RGB
void hexToRgb(char hexCode[])
{
    // Check for valid input
    if (hexCode[0] != '#' || strlen(hexCode) != 7)
    {
        printf("Invalid hex color code!\n");
        return;
    }
    
    // Convert each color from hex to decimal
    int r, g, b;
    bool success = sscanf(hexCode, "#%02X%02X%02X", &r, &g, &b);
    
    // Check for successful conversion and valid range
    if (!success || r<0 || r>255 || g<0 || g>255 || b<0 || b>255)
    {
        printf("Invalid hex color code!\n");
        return;
    }
    
    // Print the RGB colors
    printf("The hex color code %s is equivalent to RGB (%d, %d, %d).\n", hexCode, r, g, b);
}

// Main function to prompt user for input and call appropriate function
int main()
{
    // Prompt user for choice
    printf("Enter 1 to convert RGB to hex or 2 to convert hex to RGB: ");
    int choice;
    scanf("%d", &choice);
    
    // Call appropriate function based on user choice
    if (choice == 1)
    {
        int r, g, b;
        printf("Enter RGB color values (0-255):\n");
        printf("Red: ");
        scanf("%d", &r);
        printf("Green: ");
        scanf("%d", &g);
        printf("Blue: ");
        scanf("%d", &b);
        rgbToHex(r, g, b);
    }
    else if (choice == 2)
    {
        char hexCode[7];
        printf("Enter hex color code (in the format #RRGGBB): ");
        scanf("%s", hexCode);
        hexToRgb(hexCode);
    }
    else
    {
        printf("Invalid choice!\n");
    }
    
    return 0;
}