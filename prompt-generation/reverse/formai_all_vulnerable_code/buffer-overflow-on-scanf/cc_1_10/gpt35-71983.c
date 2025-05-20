//FormAI DATASET v1.0 Category: Color Code Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_LENGTH 10

// function to convert hexadecimal to decimal
int hexToDec(char hex[]) {
    int len = strlen(hex);
    int base = 1;
    int decimal = 0;
    for(int i=len-1; i>=0; i--) {
        if(hex[i]>='0'&&hex[i]<='9') {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        }
        else if(hex[i]>='A'&&hex[i]<='F') {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
    }
    return decimal;
}

// function to convert an RGB value to hexadecimal
char* rgbToHex(int r, int g, int b) {
    char* hex = malloc(sizeof(char) * 7);
    sprintf(hex, "#%02X%02X%02X", r, g, b);
    return hex;
}

// function to convert a hexadecimal value to RGB
void hexToRgb(char hex[], int* r, int* g, int* b) {
    int len = strlen(hex);
    if(len != 7) return;
    int red = hexToDec(strncpy((char*)malloc(sizeof(char) * 3), hex+1, 2));
    int green = hexToDec(strncpy((char*)malloc(sizeof(char) * 3), hex+3, 2));
    int blue = hexToDec(strncpy((char*)malloc(sizeof(char) * 3), hex+5, 2));
    *r = red;
    *g = green;
    *b = blue;
}

int main() {
    char color[MAX_COLOR_LENGTH]; // to store color input
    char choice; // to store user's choice
    int red, green, blue; // to store color values
    
    while(1) { // infinite loop until user chooses to exit
        printf("\nSelect an option:\n1. Convert RGB value to hexadecimal\n2. Convert hexadecimal value to RGB\n3. Exit\n");
        scanf(" %c", &choice);
        
        switch(choice) {
            case '1': // convert RGB to hexadecimal
                printf("\nEnter the values of red, green, and blue (between 0 and 255): ");
                scanf("%d %d %d", &red, &green, &blue);
                printf("The hexadecimal value of RGB (%d,%d,%d) is %s", red, green, blue, rgbToHex(red, green, blue));
                break;
            case '2': // convert hexadecimal to RGB
                printf("\nEnter a hexadecimal color value (in the format #RRGGBB): ");
                scanf("%s", color);
                hexToRgb(color, &red, &green, &blue);
                printf("The RGB value of %s is (%d,%d,%d)\n", color, red, green, blue);
                break;
            case '3': // exit program
                printf("\nExiting program...\n");
                exit(0);
            default: // wrong input
                printf("\nInvalid input. Please try again.\n");
        }
    }
    return 0;
}