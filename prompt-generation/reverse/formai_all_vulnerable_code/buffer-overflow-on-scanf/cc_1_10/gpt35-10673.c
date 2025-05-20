//FormAI DATASET v1.0 Category: Color Code Converter ; Style: modular
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given character is a valid hexadecimal digit
bool isHexDigit(char c){
    if(c >= '0' && c <= '9')
        return true;
    if(c >= 'a' && c <= 'f')
        return true;
    if(c >= 'A' && c <= 'F')
        return true;
    return false;
}

// Function to convert a single hexadecimal digit to its decimal value
int hexDigitToDecimal(char c){
    if(c >= '0' && c <= '9')
        return c - '0';
    if(c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    if(c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    return -1;
}

// Function to convert a hexadecimal color code to its corresponding RGB values
void convertColor(char* color, int* r, int* g, int* b){
    // Each color code has 6 digits, so ignore any extra characters
    if(strlen(color) != 6){
        printf("Invalid color code: %s\n", color);
        return;
    }

    // Extract the red, green, and blue values from the color code
    int red = hexDigitToDecimal(color[0]) * 16 + hexDigitToDecimal(color[1]);
    int green = hexDigitToDecimal(color[2]) * 16 + hexDigitToDecimal(color[3]);
    int blue = hexDigitToDecimal(color[4]) * 16 + hexDigitToDecimal(color[5]);

    // Update the RGB values passed as arguments
    *r = red;
    *g = green;
    *b = blue;
}

int main(){
    char color[7];
    int r, g, b;

    // Loop until the user enters a valid color code or inputs 'exit'
    while(true){
        printf("Enter a hexadecimal color code (or 'exit' to quit): ");
        scanf("%s", color);

        // Check if the user wants to quit the program
        if(strcmp(color, "exit") == 0){
            printf("Goodbye!\n");
            break;
        }

        // Validate the user input and convert the color code to RGB values
        convertColor(color, &r, &g, &b);
        if(r == -1 || g == -1 || b == -1){
            printf("Invalid color code: %s\n", color);
        }else{
            printf("RGB values: %d,%d,%d\n", r, g, b);
        }
    }

    return 0;
}