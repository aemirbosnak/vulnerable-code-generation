//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the character and its ASCII value
typedef struct {
    char character;
    int asciiValue;
} CharacterInfo;

// Function to compare two characters based on their ASCII values
int compareCharacters(const void *a, const void *b) {
    const CharacterInfo *char1 = (const CharacterInfo *)a;
    const CharacterInfo *char2 = (const CharacterInfo *)b;

    return char1->asciiValue - char2->asciiValue;
}

// Function to generate ASCII art from a given text
void generateASCIIArt(char *text) {
    // Create an array of characters and their ASCII values
    CharacterInfo characters[256];
    for (int i = 0; i < 256; i++) {
        characters[i].character = (char)i;
        characters[i].asciiValue = i;
    }

    // Sort the characters based on their ASCII values
    qsort(characters, 256, sizeof(CharacterInfo), compareCharacters);

    // Create an array to store the ASCII art
    char asciiArt[strlen(text) * 8 + 1];
    memset(asciiArt, ' ', strlen(text) * 8);
    asciiArt[strlen(text) * 8] = '\0';

    // Loop through each character in the text
    int index = 0;
    for (int i = 0; i < strlen(text); i++) {
        // Get the ASCII value of the character
        int asciiValue = text[i];

        // Find the index of the character in the sorted array
        int characterIndex = bsearch(&asciiValue, characters, 256, sizeof(CharacterInfo), compareCharacters);

        // Generate the ASCII art for the character
        for (int row = 0; row < 8; row++) {
            for (int column = 0; column < 8; column++) {
                int bit = (characters[characterIndex].asciiValue >> (7 - row)) & 1;
                asciiArt[index++] = bit ? '#' : ' ';
            }
            asciiArt[index++] = '\n';
        }
        asciiArt[index++] = ' ';
    }

    // Print the ASCII art
    printf("%s\n", asciiArt);
}

int main() {
    // Get the input text from the user
    char text[100];
    printf("Enter the text: ");
    scanf("%s", text);

    // Generate ASCII art from the text
    generateASCIIArt(text);

    return 0;
}