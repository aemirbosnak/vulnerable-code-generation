//FormAI DATASET v1.0 Category: Color Code Converter ; Style: innovative
#include <stdio.h>
#include <string.h>

// Function to convert hexadecimal to decimal
int hexToDecimal(char hex[]) {
    int decimal = 0, base = 1, len = strlen(hex);
    
    for(int i = len - 1; i >= 0; i--) {
        if(hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
        else if(hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 87) * base;
            base *= 16;
        }
    }
    
    return decimal;
}

// Function to convert decimal to hexadecimal
void decimalToHex(int decimal, char hex[]) {
    int rem, i = 0;
    
    while(decimal != 0) {
        rem = decimal % 16;
        
        if(rem < 10) {
            hex[i++] = rem + 48;
        }
        else {
            hex[i++] = rem + 55;
        }
        
        decimal /= 16;
    }
    
    hex[i] = '\0';
    
    // reverse the string
    int len = strlen(hex);
    for(int j = 0; j < len / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[len - j - 1];
        hex[len - j - 1] = temp;
    }
}

int main() {
    char hex[10], choice, output[10];
    int decimal;
    
    printf("Enter the color code in hexadecimal: ");
    scanf("%s", hex);
    
    printf("Do you want to convert it to (H)SV or (RGB) color code? (H/R): ");
    scanf(" %c", &choice);
    
    if(choice == 'H' || choice == 'h') {
        decimal = hexToDecimal(hex);
        int r = ((decimal & 0xFF0000) >> 16) / 255.0 * 360.0;
        int g = ((decimal & 0x00FF00) >> 8) / 255.0 * 100.0;
        int b = (decimal & 0x0000FF) / 255.0 * 100.0;
        
        sprintf(output, "%d,%d%%,%d%%", r, g, b);
        
        printf("HSV color code: %s", output);
    }
    else if(choice == 'R' || choice == 'r') {
        decimal = hexToDecimal(hex);
        int r = (decimal & 0xFF0000) >> 16;
        int g = (decimal & 0x00FF00) >> 8;
        int b = decimal & 0x0000FF;
        
        sprintf(output, "%d,%d,%d", r, g, b);
        
        printf("RGB color code: %s", output);
    }
    else {
        printf("Invalid choice.\n");
    }

    return 0;
}