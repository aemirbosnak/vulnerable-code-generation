//FormAI DATASET v1.0 Category: Color Code Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function to convert RGB values to hexadecimal
void RGBtoHex(int R, int G, int B)
{
    char hex[7];  // We use char to store hexadecimal value since it always be a a string of characters
    sprintf(hex, "#%02x%02x%02x", R, G, B); // Using sprintf to convert RGB integers to hexadecimal value
    printf("Hexadecimal color code is %s", hex);
}

// Function to convert hexadecimal to RGB values
void HextoRGB(char hex[])
{
    int R, G, B;
    sscanf(hex, "#%02x%02x%02x", &R, &G, &B); // Using sscanf to convert hexadecimal string to RGB integers
    printf("RGB values are %d, %d, %d", R, G, B);
}

int main()
{
    int option;
    printf("Enter 1 to convert RGB to hexadecimal code\n");
    printf("Enter 2 to convert hexadecimal code to RGB\n");
    scanf("%d", &option); // Taking input from user to perform required operation
    
    if (option == 1)
    {
        int R, G, B;
        printf("Enter the value of Red: ");
        scanf("%d", &R);
        printf("Enter the value of Green: ");
        scanf("%d", &G);
        printf("Enter the value of Blue: ");
        scanf("%d", &B);
        RGBtoHex(R, G, B); // Calling RGB to hexadecimal function
    }
    else if (option == 2)
    {
        char hex[7];
        printf("Enter hexadecimal color code (e.g., #FF0000): ");
        scanf("%s", hex);
        HextoRGB(hex); // Calling hexadecimal to RGB function
    }
    else
    {
        printf("Invalid input");
        exit(0);
    }
    
    return 0;
}