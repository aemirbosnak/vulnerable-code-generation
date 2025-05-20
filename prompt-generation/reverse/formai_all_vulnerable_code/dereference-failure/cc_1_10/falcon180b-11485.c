//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define MAX_CHARACTERS 5000

typedef struct {
    char *text;
    int width;
    int height;
    int num_chars;
} AsciiArt;

AsciiArt *generate_ascii_art(const char *input_text) {
    AsciiArt *ascii_art = malloc(sizeof(AsciiArt));

    if (ascii_art == NULL) {
        printf("Error: Failed to allocate memory for AsciiArt structure.\n");
        exit(1);
    }

    ascii_art->text = strdup(input_text);
    ascii_art->width = 0;
    ascii_art->height = 0;
    ascii_art->num_chars = 0;

    return ascii_art;
}

void free_ascii_art(AsciiArt *ascii_art) {
    free(ascii_art->text);
    free(ascii_art);
}

void print_ascii_art(const AsciiArt *ascii_art) {
    int i, j;
    int num_spaces = (ascii_art->width - strlen(ascii_art->text)) / 2;

    for (i = 0; i < ascii_art->height; i++) {
        for (j = 0; j < num_spaces; j++) {
            printf(" ");
        }
        printf("%s\n", ascii_art->text);
    }
}

int main() {
    char input_text[MAX_CHARACTERS];
    AsciiArt *ascii_art;

    printf("Enter your text (max %d characters): ", MAX_CHARACTERS);
    fgets(input_text, MAX_CHARACTERS, stdin);

    ascii_art = generate_ascii_art(input_text);
    print_ascii_art(ascii_art);

    free_ascii_art(ascii_art);

    return 0;
}