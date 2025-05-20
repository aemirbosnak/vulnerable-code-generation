//FormAI DATASET v1.0 Category: Color Code Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert hexadecimal to decimal
int hexToDec(char hex[]) {
    int decimal = 0, length = strlen(hex), base = 1;
    
    // iterating through the string from right to left
    for(int i=length-1; i>=0; i--) {
        if(hex[i] >= '0' && hex[i] <= '9')
            decimal += (hex[i] - 48) * base;
        else if(hex[i] >= 'A' && hex[i] <= 'F')
            decimal += (hex[i] - 55) * base;
        else if(hex[i] >= 'a' && hex[i] <= 'f')
            decimal += (hex[i] - 87) * base;
        base *= 16;  // incrementing base value
    }
    return decimal;
}

// function to convert RGB values to color code
void rgbToColorCode(int r, int g, int b) {
    printf("Color Code: #%02X%02X%02X\n", r, g, b);
}

// function to convert color code to RGB values
void colorCodeToRGB(char code[]) {
    char temp[3], r[3], g[3], b[3];
    strncpy(temp, code+1, 2);
    temp[2] = '\0';
    sprintf(r, "%d", hexToDec(temp));
    strncpy(temp, code+3, 2);
    temp[2] = '\0';
    sprintf(g, "%d", hexToDec(temp));
    strncpy(temp, code+5, 2);
    temp[2] = '\0';
    sprintf(b, "%d", hexToDec(temp));
    printf("RGB Values: %d %d %d\n", atoi(r), atoi(g), atoi(b));
}

int main() {
    int r, g, b;
    char code[7];
    
    printf("Enter RGB values (0-255): ");
    scanf("%d %d %d", &r, &g, &b);
    rgbToColorCode(r, g, b);
    
    printf("Enter Color code (in hex): ");
    scanf("%s", code);
    colorCodeToRGB(code);
    
    return 0;
}