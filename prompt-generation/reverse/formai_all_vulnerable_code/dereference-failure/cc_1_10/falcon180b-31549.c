//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80 // Maximum width of ASCII art
#define MAX_HEIGHT 24 // Maximum height of ASCII art

typedef struct {
    char *text; // Pointer to the input text
    int width; // Width of the ASCII art
    int height; // Height of the ASCII art
    char *ascii_art; // Pointer to the ASCII art
} AsciiArt;

AsciiArt *generate_ascii_art(const char *input_text) {
    AsciiArt *ascii_art = malloc(sizeof(AsciiArt));
    if (ascii_art == NULL) {
        printf("Error: Failed to allocate memory for ASCII art.\n");
        exit(1);
    }

    ascii_art->text = strdup(input_text);
    if (ascii_art->text == NULL) {
        printf("Error: Failed to duplicate input text.\n");
        free(ascii_art);
        exit(1);
    }

    int text_length = strlen(input_text);
    int num_lines = (text_length + MAX_WIDTH - 1) / MAX_WIDTH;
    ascii_art->width = MAX_WIDTH;
    ascii_art->height = num_lines;

    ascii_art->ascii_art = malloc((ascii_art->width + 1) * ascii_art->height);
    if (ascii_art->ascii_art == NULL) {
        printf("Error: Failed to allocate memory for ASCII art.\n");
        free(ascii_art->text);
        free(ascii_art);
        exit(1);
    }

    int line_index = 0;
    int char_index = 0;
    for (int i = 0; i < text_length; i++) {
        char c = tolower(input_text[i]);
        if (c == '\n') {
            line_index++;
            char_index = 0;
        } else {
            ascii_art->ascii_art[line_index * ascii_art->width + char_index++] = c;
        }
    }

    if (char_index > 0) {
        line_index++;
    }

    ascii_art->ascii_art[line_index * ascii_art->width] = '\0';

    return ascii_art;
}

void print_ascii_art(const AsciiArt *ascii_art) {
    for (int i = 0; i < ascii_art->height; i++) {
        printf("%s\n", ascii_art->ascii_art + i * ascii_art->width);
    }
}

void free_ascii_art(AsciiArt *ascii_art) {
    free(ascii_art->text);
    free(ascii_art->ascii_art);
    free(ascii_art);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_text>\n", argv[0]);
        exit(1);
    }

    AsciiArt *ascii_art = generate_ascii_art(argv[1]);
    if (ascii_art == NULL) {
        exit(1);
    }

    print_ascii_art(ascii_art);

    free_ascii_art(ascii_art);

    return 0;
}