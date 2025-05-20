//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 40
#define HEIGHT 10

void generate_ascii_art(char *text) {
    char ascii_art[WIDTH][HEIGHT];
    int text_length = strlen(text);
    int i, j, k;

    // Initialize ascii_art with spaces
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            ascii_art[i][j] = ' ';
        }
    }

    // Convert text to ASCII art
    for (i = 0; i < text_length; i++) {
        for (j = i; j < text_length + i; j++) {
            k = text[j] - ' ';
            if (k < 0 || k > 25) {
                continue;
            }
            ascii_art[i / 2][j % WIDTH] = " .:!*oe%$#@"[k];
        }
    }

    // Print ascii_art
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char text[100];

    printf("Enter a text: ");
    fgets(text, sizeof(text), stdin);
    text[strlen(text) - 1] = '\0'; // Remove newline character

    generate_ascii_art(text);

    return 0;
}