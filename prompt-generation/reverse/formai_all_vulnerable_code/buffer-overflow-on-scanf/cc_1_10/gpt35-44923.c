//FormAI DATASET v1.0 Category: Color Code Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hex character to decimal value
int hexToDecimal(char hex[]){
    int len = strlen(hex);
    int base = 1;
    int decimal = 0;
    for(int i=len-1; i>=0; i--){
        if(hex[i]>='0' && hex[i]<='9'){
            decimal += (hex[i] - 48) * base;
            base *= 16;
        }
        else if(hex[i]>='A' && hex[i]<='F'){
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
    }
    return decimal;
}

int main(){
    char hex[8];
    printf("Enter a color code in hexadecimal format (#RRGGBB): ");
    scanf("%s", hex);

    // Convert hex color code to decimal RGB values
    int red = hexToDecimal(strncpy((char[3]){}, hex+1, 2));
    int green = hexToDecimal(strncpy((char[3]){}, hex+3, 2));
    int blue = hexToDecimal(strncpy((char[3]){}, hex+5, 2));

    printf("\nDecimal RGB values:\n");
    printf("Red: %d\n", red);
    printf("Green: %d\n", green);
    printf("Blue: %d\n", blue);

    // Convert decimal RGB values to CMYK values
    float cyan = 1 - (red/255.0);
    float magenta = 1 - (green/255.0);
    float yellow = 1 - (blue/255.0);
    float k = 1;
    if(cyan < k) k = cyan;
    if(magenta < k) k = magenta;
    if(yellow < k) k = yellow;
    if(k == 1){
        cyan = 0;
        magenta = 0;
        yellow = 0;
    }
    else{
        cyan = (cyan - k) / (1 - k);
        magenta = (magenta - k) / (1 - k);
        yellow = (yellow - k) / (1 - k);
    }

    printf("\nCMYK values:\n");
    printf("Cyan: %.2f\n", cyan);
    printf("Magenta: %.2f\n", magenta);
    printf("Yellow: %.2f\n", yellow);
    printf("Black: %.2f\n", k);

    return 0;
}