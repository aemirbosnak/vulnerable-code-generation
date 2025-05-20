//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 20

typedef struct {
    char *text;
    int width;
    int height;
} AsciiArt;

AsciiArt *generate_ascii_art(const char *input_text) {
    int text_length = strlen(input_text);
    int width = (text_length + MAX_WIDTH - 1) / MAX_WIDTH;
    int height = (width + MAX_HEIGHT - 1) / MAX_HEIGHT;

    AsciiArt *ascii_art = malloc(sizeof(AsciiArt));
    ascii_art->text = strdup(input_text);
    ascii_art->width = width;
    ascii_art->height = height;

    return ascii_art;
}

void print_ascii_art(AsciiArt *ascii_art) {
    int i, j;
    for (i = 0; i < ascii_art->height; i++) {
        for (j = 0; j < ascii_art->width; j++) {
            printf("%c", ascii_art->text[i * MAX_WIDTH + j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [input_text]\n", argv[0]);
        return 1;
    }

    char *input_text = argv[1];
    AsciiArt *ascii_art = generate_ascii_art(input_text);
    print_ascii_art(ascii_art);

    free(ascii_art->text);
    free(ascii_art);

    return 0;
}