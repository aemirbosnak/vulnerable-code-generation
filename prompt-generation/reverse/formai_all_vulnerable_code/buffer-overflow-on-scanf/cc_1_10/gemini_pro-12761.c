//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define ASCII_SIZE 256

int main() {
    char text[100];
    int i, j, k;
    int width, height;
    float scale;
    int ascii_values[ASCII_SIZE];

    // Get the text to convert
    printf("Enter the text to convert to ASCII art: ");
    scanf("%s", text);

    // Calculate the width and height of the ASCII art
    width = strlen(text) * 8;
    height = 12;

    // Calculate the scale factor
    scale = (float)height / 12;

    // Initialize the ASCII values array
    for (i = 0; i < ASCII_SIZE; i++) {
        ascii_values[i] = 0;
    }

    // Calculate the ASCII values for each character in the text
    for (i = 0; text[i] != '\0'; i++) {
        ascii_values[(int)text[i]] += 1;
    }

    // Print the ASCII art
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int ascii_value = 0;

            // Calculate the ASCII value for the current pixel
            for (k = 0; k < ASCII_SIZE; k++) {
                if (ascii_values[k] > 0) {
                    ascii_value = k;
                    break;
                }
            }

            // Print the ASCII character
            printf("%c", (char)ascii_value);
        }

        // Move to the next line
        printf("\n");
    }

    return 0;
}