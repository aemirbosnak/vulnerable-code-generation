//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a character to its ASCII value
int charToASCII(char c) {
    return (int)c;
}

// Function to print the ASCII art
void printASCIIArt(char* text, int width, int height) {
    int i, j, len = strlen(text);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i * width + j < len) {
                printf("%c", charToASCII(text[i * width + j]));
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    char inputText[1000];

    // Get input from user
    printf("Enter the text to convert to ASCII art: ");
    fgets(inputText, sizeof(inputText), stdin);

    // Remove newline character from input
    inputText[strcspn(inputText, "\n")] = '\0';

    // Get width and height for ASCII art
    int width, height;
    printf("Enter the width of the ASCII art: ");
    scanf("%d", &width);
    printf("Enter the height of the ASCII art: ");
    scanf("%d", &height);

    // Convert input to uppercase
    for (int i = 0; i < strlen(inputText); i++) {
        inputText[i] = toupper(inputText[i]);
    }

    // Print ASCII art
    printf("\n");
    printASCIIArt(inputText, width, height);

    return 0;
}