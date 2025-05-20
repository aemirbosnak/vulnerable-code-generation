//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate ASCII art
void generateArt(char* message, char* fontPath) {
    FILE* fontFile = fopen(fontPath, "r"); // Open font file

    // Check whether font file exists or not
    if (fontFile == NULL){
        printf("Error: Font file cannot be opened\n");
        exit(1);
    }

    // Read font header
    int charHeight, charWidth, maxCharNumber;
    fscanf(fontFile, "height=%d width=%d max=%d", &charHeight, &charWidth, &maxCharNumber);

    // Allocate memory for characters
    char** characters = (char**)malloc(sizeof(char*) * maxCharNumber);
    for (int i = 0; i < maxCharNumber; ++i){
        characters[i] = (char*)malloc(sizeof(char) * (charWidth * charHeight + 1));
    }

    // Read character data from font file
    for (int i = 0; i < maxCharNumber; ++i){
        fgetc(fontFile); // Discard number
        fgets(characters[i], charWidth * charHeight + 1, fontFile);
    }

    fclose(fontFile);

    printf("\n"); // Add line break before art

    // Print ASCII art of message
    for (int row = 0; row < charHeight; ++row){
        for (int i = 0; i < strlen(message); ++i){
            int charCode = message[i];
            if (charCode < 0 || charCode >= maxCharNumber){
                charCode = maxCharNumber - 1;
            }
            printf("%.*s", charWidth, characters[charCode] + row * charWidth);
        }
        printf("\n");
    }

    printf("\n"); // Add line break after art

    // Free memory for characters
    for (int i = 0; i < maxCharNumber; ++i){
        free(characters[i]);
    }
    free(characters);
}

// Main function
int main(){
    char* message = "ASCII art generator";
    char* fontPath = "font.txt";

    generateArt(message, fontPath);
    return 0;
}