//FormAI DATASET v1.0 Category: Color Code Converter ; Style: romantic
#include <stdio.h>

// Function to convert an integer value to its corresponding hexadecimal digit
char toHexDigit(int value)
{
    if (value >= 0 && value <= 9)
    {
        return (char)(value + '0');
    }
    else if (value >= 10 && value <= 15)
    {
        return (char)(value - 10 + 'A');
    }
    
    return '\0';
}

// Function to convert an RGB color code to its equivalent hexadecimal value
void rgbToHex(int r, int g, int b)
{
    int hexR = r / 16;
    int hexG = g / 16;
    int hexB = b / 16;
    
    int remR = r % 16;
    int remG = g % 16;
    int remB = b % 16;
    
    char hexCode[7];
    hexCode[0] = '#';
    hexCode[1] = toHexDigit(hexR);
    hexCode[2] = toHexDigit(remR);
    hexCode[3] = toHexDigit(hexG);
    hexCode[4] = toHexDigit(remG);
    hexCode[5] = toHexDigit(hexB);
    hexCode[6] = toHexDigit(remB);
    
    printf("Equivalent hexadecimal code: %s\n", hexCode);
}

// Function to convert a hexadecimal color code to its equivalent RGB value
void hexToRgb(char* hexCode)
{
    int r, g, b;
    
    sscanf(hexCode, "#%2x%2x%2x", &r, &g, &b);
    
    printf("Equivalent RGB code: %d, %d, %d\n", r, g, b);
}

// Main function
int main()
{
    int choice, r, g, b;
    char hexCode[7];
    
    printf("C Color Code Converter Program\n");
    printf("------------------------------\n");
    printf("1. RGB to Hexadecimal\n");
    printf("2. Hexadecimal to RGB\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice)
    {
        case 1:
            printf("Enter the values of R, G, B (separated by spaces): ");
            scanf("%d %d %d", &r, &g, &b);
            rgbToHex(r, g, b);
            break;
            
        case 2:
            printf("Enter the hexadecimal code (format: #RRGGBB): ");
            scanf("%s", hexCode);
            hexToRgb(hexCode);
            break;
            
        default:
            printf("Invalid choice.\n");
            break;
    }
    
    return 0;
}