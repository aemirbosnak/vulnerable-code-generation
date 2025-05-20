//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
int hex_to_decimal(char c);
void hex_to_rgb(char* hex, int* r, int* g, int* b);
void rgb_to_hex(int r, int g, int b, char* hex);

int main() {
    char mode; // conversion mode (h for hex to RGB, r for RGB to hex)
    char input[8]; // user input (hex code or RGB values)
    int r, g, b; // RGB values
    char hex[8]; // hex code
    
    printf("Welcome to the Color Code Converter!\n");
    printf("Enter 'h' to convert from hex to RGB or 'r' to convert from RGB to hex: ");
    scanf("%c", &mode);
    
    if(mode == 'h') {
        printf("Enter a 6-digit hex code: ");
        scanf("%s", input);
        hex_to_rgb(input, &r, &g, &b);
        printf("RGB values: %d %d %d\n", r, g, b);
    }
    else if(mode == 'r') {
        printf("Enter RGB values (separated by spaces): ");
        scanf("%d %d %d", &r, &g, &b);
        rgb_to_hex(r, g, b, hex);
        printf("Hex code: %s\n", hex);
    }
    else {
        printf("Invalid input\n");
        exit(1);
    }
    
    return 0;
}

// converts a hexadecimal digit to decimal
int hex_to_decimal(char c) {
    // digits 0-9
    if(c >= '0' && c <= '9') {
        return c - '0';
    }
    // letters A-F
    else if(c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    // letters a-f
    else if(c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    // invalid input
    else {
        printf("Invalid hex digit\n");
        exit(1);
    }
}

// converts a hex code to RGB values
void hex_to_rgb(char* hex, int* r, int* g, int* b) {
    int decimal1, decimal2;
    
    // convert first two digits to decimal
    decimal1 = hex_to_decimal(hex[0]) * 16 + hex_to_decimal(hex[1]);
    
    // convert next two digits to decimal
    decimal2 = hex_to_decimal(hex[2]) * 16 + hex_to_decimal(hex[3]);
    
    // convert last two digits to decimal
    *b = hex_to_decimal(hex[4]) * 16 + hex_to_decimal(hex[5]);
    
    // set RGB values
    *r = decimal1;
    *g = decimal2;
}

// converts RGB values to a hex code
void rgb_to_hex(int r, int g, int b, char* hex) {
    // convert each RGB value to two-digit hexadecimal code
    sprintf(hex, "%02X%02X%02X", r, g, b);
}