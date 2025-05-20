//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: relaxed
#include <stdio.h>
#include <string.h>

// Define the maximum size of the ASCII art
#define MAX_SIZE 400

// Define the maximum width and height of the ASCII art
#define MAX_WIDTH 20
#define MAX_HEIGHT 20

// Define the ASCII art array
char ascii_art[MAX_HEIGHT][MAX_WIDTH];

// Define a function to convert a character to its ASCII code
int char_to_ascii(char c) {
    return (int) c;
}

// Define a function to generate the ASCII art
void generate_ascii_art(char *text) {
    // Get the length of the text
    int len = strlen(text);

    // Make sure the text is not too long
    if (len > MAX_SIZE) {
        printf("Error: Text is too long\n");
        return;
    }

    // Convert each character to its ASCII code and store it in the ASCII art array
    for (int i = 0; i < len; i++) {
        int c = char_to_ascii(text[i]);

        // Calculate the ASCII art position based on the ASCII code
        int x = (c % MAX_WIDTH);
        int y = (c / MAX_WIDTH);

        // Store the character in the ASCII art array
        ascii_art[y][x] = text[i];
    }

    // Print the ASCII art
    for (int y = 0; y < MAX_HEIGHT; y++) {
        for (int x = 0; x < MAX_WIDTH; x++) {
            printf("%c", ascii_art[y][x]);
        }
        printf("\n");
    }
}

int main() {
    // Ask the user for input
    char text[MAX_SIZE];
    printf("Enter some text:\n");
    fgets(text, MAX_SIZE, stdin);

    // Generate the ASCII art
    generate_ascii_art(text);

    return 0;
}