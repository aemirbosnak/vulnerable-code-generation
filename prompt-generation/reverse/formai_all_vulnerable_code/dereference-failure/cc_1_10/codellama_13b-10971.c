//Code Llama-13B DATASET v1.0 Category: Text to ASCII art generator ; Style: Ken Thompson
/*
 * Text to ASCII art generator in the style of Ken Thompson
 *
 * Usage: ./ascii_art <text>
 *
 * Output: ASCII art representation of the text
 */

#include <stdio.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

void print_ascii_art(char *text) {
    int len = strlen(text);
    int width = 0;
    int height = 1;

    // Determine the width and height of the text
    for (int i = 0; i < len; i++) {
        if (text[i] == '\n') {
            height++;
            width = 0;
        } else {
            width++;
        }
    }

    // Ensure that the text fits within the maximum dimensions
    if (width > MAX_WIDTH) {
        width = MAX_WIDTH;
    }
    if (height > MAX_HEIGHT) {
        height = MAX_HEIGHT;
    }

    // Print the text with ASCII art characters
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = i * width + j;
            if (index < len) {
                char c = text[index];
                if (c == ' ') {
                    printf(" ");
                } else if (c >= 'a' && c <= 'z') {
                    printf("%c", c + 10);
                } else if (c >= 'A' && c <= 'Z') {
                    printf("%c", c + 32);
                } else {
                    printf(" ");
                }
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    print_ascii_art(argv[1]);

    return 0;
}