//FormAI DATASET v1.0 Category: Color Code Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert hexadecimal to decimal
int hexToDec(char hex[]) {
    int len = strlen(hex);
    int base = 1;
    int dec = 0;
    
    for(int i=len-1; i>=0; i--) {
        if(hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - '0') * base;
            base *= 16;
        } else if(hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (hex[i] - 'A' + 10) * base;
            base *= 16;
        } else if(hex[i] >= 'a' && hex[i] <= 'f') {
            dec += (hex[i] - 'a' + 10) * base;
            base *= 16;
        } else {
            printf("Invalid hexadecimal number.\n");
            exit(0);
        }
    }
    
    return dec;
}

// function to convert decimal to hexadecimal
char* decToHex(int dec) {
    char* hex = (char*) malloc(sizeof(char) * 8);
    int i = 0;
    
    while(dec > 0) {
        int rem = dec % 16;
        if(rem < 10) {
            hex[i] = rem + '0';
        } else {
            hex[i] = rem + 55;
        }
        i++;
        dec = dec / 16;
    }
    hex[i] = '\0';
    
    // reverse the string
    int len = strlen(hex);
    for(int j=0; j<len/2; j++) {
        char temp = hex[j];
        hex[j] = hex[len-j-1];
        hex[len-j-1] = temp;
    }
    
    return hex;
}

int main() {
    printf("Enter a color code in hexadecimal format (e.g. FF00FF for purple): ");
    char hex[7];
    scanf("%s", hex);
    
    if(strlen(hex) != 6) {
        printf("Invalid color code.\n");
        exit(0);
    }
    
    char r[3], g[3], b[3];
    strncpy(r, hex, 2);
    strncpy(g, hex+2, 2);
    strncpy(b, hex+4, 2);
    r[2] = '\0';
    g[2] = '\0';
    b[2] = '\0';
    
    int red = hexToDec(r);
    int green = hexToDec(g);
    int blue = hexToDec(b);
    
    printf("Red: %d, Green: %d, Blue: %d\n", red, green, blue);
    
    printf("Enter a decimal value for red (0-255): ");
    int newRed;
    scanf("%d", &newRed);
    if(newRed < 0 || newRed > 255) {
        printf("Invalid value.\n");
        exit(0);
    }
    
    printf("Enter a decimal value for green (0-255): ");
    int newGreen;
    scanf("%d", &newGreen);
    if(newGreen < 0 || newGreen > 255) {
        printf("Invalid value.\n");
        exit(0);
    }
    
    printf("Enter a decimal value for blue (0-255): ");
    int newBlue;
    scanf("%d", &newBlue);
    if(newBlue < 0 || newBlue > 255) {
        printf("Invalid value.\n");
        exit(0);
    }
    
    char* newRHex = decToHex(newRed);
    char* newGHex = decToHex(newGreen);
    char* newBHex = decToHex(newBlue);
    
    printf("New color code: #%s%s%s\n", newRHex, newGHex, newBHex);
    
    free(newRHex);
    free(newGHex);
    free(newBHex);
    
    return 0;
}