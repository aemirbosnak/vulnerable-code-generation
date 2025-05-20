//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    char *data;
    int width;
    int height;
} AsciiArt;

AsciiArt *generate_ascii_art(const char *text) {
    int width, height;
    char *data;
    AsciiArt *ascii_art = malloc(sizeof(AsciiArt));

    width = strlen(text);
    height = (int) ceil((double) width / MAX_WIDTH);

    ascii_art->width = width;
    ascii_art->height = height;

    data = malloc((height * MAX_WIDTH + 1) * sizeof(char));

    int x = 0, y = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < MAX_WIDTH && x < width; j++) {
            data[i * MAX_WIDTH + j] = text[x++];
        }
        for (int j = MAX_WIDTH - 1; j >= 0 && x < width; j--) {
            data[(i * MAX_WIDTH) + j] = text[x++];
        }
        if (x == width) break;
    }

    for (int i = 0; i < height; i++) {
        data[(i * MAX_WIDTH) + MAX_WIDTH - 1] = '\0';
    }

    ascii_art->data = data;

    return ascii_art;
}

void print_ascii_art(const AsciiArt *ascii_art) {
    for (int i = 0; i < ascii_art->height; i++) {
        printf("%s\n", ascii_art->data + i * MAX_WIDTH);
    }
}

void free_ascii_art(AsciiArt *ascii_art) {
    free(ascii_art->data);
    free(ascii_art);
}

int main() {
    const char *text = "Hello, World!";
    AsciiArt *ascii_art = generate_ascii_art(text);
    print_ascii_art(ascii_art);
    free_ascii_art(ascii_art);

    return 0;
}