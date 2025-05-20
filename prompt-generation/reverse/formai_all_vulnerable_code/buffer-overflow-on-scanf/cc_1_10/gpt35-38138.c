//FormAI DATASET v1.0 Category: Color Code Converter ; Style: statistical
#include <stdio.h>
#include <string.h>

// Function to convert hex string to decimal
int hexToDec(char hex[]) {
    int len = strlen(hex);
    int base = 1;
    int dec = 0;
    
    for(int i=len-1; i>=0; i--) {
        if(hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - 48) * base;
            base *= 16;
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (hex[i] - 55) * base;
            base *= 16;
        }
    }
    return dec;
}

int main() {
    char colorHex[7];
    printf("Enter a 6-digit hex color code: ");
    scanf("%s", colorHex);
    
    // Separating R, G, B values from hex color code
    int r = hexToDec(strncpy(colorHex, &colorHex[0], 2));
    int g = hexToDec(strncpy(colorHex, &colorHex[2], 2));
    int b = hexToDec(strncpy(colorHex, &colorHex[4], 2));
    
    // Converting R, G, B values to decimal
    float rDecimal = r / 255.0;
    float gDecimal = g / 255.0;
    float bDecimal = b / 255.0;
    
    // Calculating brightness and saturation
    float cMax = rDecimal;
    if(gDecimal > cMax) cMax = gDecimal;
    if(bDecimal > cMax) cMax = bDecimal;
    
    float cMin = rDecimal;
    if(gDecimal < cMin) cMin = gDecimal;
    if(bDecimal < cMin) cMin = bDecimal;
    
    float brightness = cMax;
    
    float delta = cMax - cMin;
    float saturation;
    if(cMax == 0) saturation = 0;
    else saturation = delta / cMax;
    
    // Printing the HSL and RGB values
    printf("\nRGB Values: (%d, %d, %d)\n", r, g, b);
    printf("HSL Values: (%.2f, %.2f, %.2f)\n", brightness, saturation, cMax);
    
    return 0;
}