//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    char text[50];
    char art[7][60];
    
    printf("Enter text you want to convert to ASCII art: ");
    scanf("%[^\n]", text);
    getchar();
    
    // Initialize the art array with spaces
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 60; j++) {
            art[i][j] = ' ';
        }
    }
    
    // Add characters to the art array row by row
    for (int i = 0; i < strlen(text); i++) {
        
        if (text[i] == ' ') {
            // Add a space character to the art array
            for (int j = 0; j < 7; j++) {
                art[j][i*6] = ' ';
            }
        }
        else {
            // Find the ASCII code for the character
            int code = (int)text[i];
            
            // Convert the ASCII code to binary
            char binary[9];
            for (int j = 0; j < 8; j++) {
                binary[j] = (code % 2) + '0';
                code = code / 2;
            }
            binary[8] = '\0';
            
            // Add the binary digits to the art array
            for (int j = 0; j < 7; j++) {
                art[j][i*6] = binary[j];
            }
        }
    }
    
    // Print the ASCII art
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < strlen(text)*6; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}