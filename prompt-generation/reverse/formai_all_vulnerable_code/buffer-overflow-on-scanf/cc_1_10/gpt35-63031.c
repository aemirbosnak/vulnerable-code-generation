//FormAI DATASET v1.0 Category: Color Code Converter ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to convert RGB values to HEX code
void RGBtoHEX(char r[], char g[], char b[]) {
    int red = atoi(r);
    int green = atoi(g);
    int blue = atoi(b);
    char hex[7];
    
    sprintf(hex, "#%02x%02x%02x", red, green, blue); // sprintf to format HEX code
    
    printf("HEX Code: %s\n", hex);
}

// Function to convert HEX code to RGB values
void HEXtoRGB(char hex[]) {
    int red, green, blue;
    
    // If '#' is present in the HEX code, remove it
    if(hex[0] == '#') {
        memmove(hex, hex + 1, strlen(hex)); // memmove to shift the characters to left
    }
    
    sscanf(hex, "%02x%02x%02x", &red, &green, &blue); // sscanf to read HEX code
    
    printf("RGB Values: %d, %d, %d\n", red, green, blue);
}

int main() {
    char choice, r[4], g[4], b[4], hex[7];
    
    printf("Welcome to Color Code Converter!\n\n");
    printf("Choose an option:\n");
    printf("1. Convert RGB values to HEX code.\n");
    printf("2. Convert HEX code to RGB values.\n");
    printf("Your choice: ");
    scanf("%c", &choice);
    
    switch(choice) {
        // If choice is to convert RGB values to HEX code
        case '1':
            printf("\nEnter the RGB values (0-255):\n");
            printf("- Red: ");
            scanf("%s", r);
            printf("- Green: ");
            scanf("%s", g);
            printf("- Blue: ");
            scanf("%s", b);
            
            RGBtoHEX(r, g, b);
            break;
        
        // If choice is to convert HEX code to RGB values
        case '2':
            printf("\nEnter the HEX code (without '#'): ");
            scanf("%s", hex);
            
            HEXtoRGB(hex);
            break;
        
        default:
            printf("\nInvalid choice! Please try again.\n");
            break;
    }
    
    return 0;
}