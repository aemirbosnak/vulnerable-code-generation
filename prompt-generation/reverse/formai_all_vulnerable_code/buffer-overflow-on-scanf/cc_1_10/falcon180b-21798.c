//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    char *text;
    int width;
    int height;
} AsciiArt;

void print_ascii_art(AsciiArt *ascii_art) {
    int i, j;
    for (i = 0; i < ascii_art->height; i++) {
        for (j = 0; j < ascii_art->width; j++) {
            printf("%c", ascii_art->text[i * ascii_art->width + j]);
        }
        printf("\n");
    }
}

AsciiArt *generate_ascii_art(char *text, int width, int height) {
    AsciiArt *ascii_art = malloc(sizeof(AsciiArt));
    ascii_art->text = text;
    ascii_art->width = width;
    ascii_art->height = height;
    return ascii_art;
}

int main() {
    char input_text[1000];
    printf("Enter the text to convert to ASCII art: ");
    scanf("%s", input_text);

    int width, height;
    printf("Enter the width of the ASCII art: ");
    scanf("%d", &width);
    printf("Enter the height of the ASCII art: ");
    scanf("%d", &height);

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Invalid width or height.\n");
        return 1;
    }

    AsciiArt *ascii_art = generate_ascii_art(input_text, width, height);
    print_ascii_art(ascii_art);

    free(ascii_art->text);
    free(ascii_art);

    return 0;
}