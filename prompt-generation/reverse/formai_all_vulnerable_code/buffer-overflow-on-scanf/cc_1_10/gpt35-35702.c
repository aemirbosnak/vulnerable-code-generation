//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: active
#include <stdio.h>

int main() {
    char text[1000];
    int width, height;

    printf("Enter the text to be converted to ASCII art: ");
    fgets(text, 1000, stdin);

    printf("Enter the width of the ASCII art: ");
    scanf("%d", &width);

    // Calculate the aspect ratio of the ASCII art
    float aspectRatio = 1.0 * width / 8.0;

    // Calculate the height of the ASCII art based on the aspect ratio and length of text
    int textLength = strlen(text);
    int charCount = 0;
    for (int i = 0; i < textLength; i++) {
        if (text[i] != '\n') {
            charCount++;
        }
    }
    float heightFloat = charCount / aspectRatio;
    height = (int) ceil(heightFloat);

    // Declare the ASCII art array
    char art[height][width];

    // Populate the ASCII art array with spaces
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            art[i][j] = ' ';
        }
    }

    // Populate the ASCII art array with the text
    int row = 0;
    int col = 0;
    for (int i = 0; i < textLength; i++) {
        if (text[i] != '\n') {
            art[row][col] = text[i];
            col++;
            if (col >= width) {
                col = 0;
                row++;
            }
        }
    }

    // Print the ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }

    return 0;
}