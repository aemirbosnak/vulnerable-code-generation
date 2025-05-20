//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert text to ASCII art
void text_to_ascii_art(char text[], int font_size) {
    int length = strlen(text);
    char font[7][9][font_size];

    // Generate ASCII art for each character in the text
    for (int i = 0; i < length; i++) {
        char character = text[i];

        // Check if character is a letter or a number
        if ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z') || (character >= '0' && character <= '9')) {
            char filename[20];
            sprintf(filename, "fonts/%c.txt", character);

            // Open file containing font data
            FILE *fp = fopen(filename, "r");

            if (fp == NULL) {
                printf("Error: Font file for %c not found\n", character);
                return;
            }

            // Read font data from file
            char line[20];
            int row = 0;
            while (fgets(line, 20, fp) != NULL) {
                strcpy(font[character - 48][row], line);
                row++;
            }

            fclose(fp);

            // Print ASCII art for character
            for (int r = 0; r < 9; r++) {
                for (int c = 0; c < font_size; c++) {
                    printf("%c", font[character - 48][r][c]);
                }
                printf("\n");
            }
        } else {
            // Print empty line for non-letter/non-number characters
            for (int r = 0; r < 9; r++) {
                for (int i = 0; i < font_size; i++) {
                    printf(" ");
                }
                printf("\n");
            }
        }
    }
}

int main() {
    // Get user input
    char text[101];
    int font_size;
    printf("Enter text to convert to ASCII art (<100 characters): ");
    scanf("%[^\n]%*c", text);
    printf("Enter font size (1-5): ");
    scanf("%d", &font_size);

    if (font_size < 1 || font_size > 5) {
        printf("Error: Invalid font size\n");
        return 0;
    }

    // Convert text to ASCII art
    text_to_ascii_art(text, font_size);

    return 0;
}