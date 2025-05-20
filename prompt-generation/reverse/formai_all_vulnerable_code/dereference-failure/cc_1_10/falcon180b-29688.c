//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    char *data;
    int width;
    int height;
} AsciiArt;

AsciiArt *generate_ascii_art(const char *text) {
    int text_width = strlen(text);
    int text_height = 1;
    if (text_width > MAX_WIDTH) {
        text_height = text_width / MAX_WIDTH + ((text_width % MAX_WIDTH)? 1 : 0);
        text_width = MAX_WIDTH;
    }

    AsciiArt *art = malloc(sizeof(AsciiArt));
    art->data = malloc(text_width * text_height + 1);
    if (!art->data) {
        free(art);
        return NULL;
    }

    art->width = text_width;
    art->height = text_height;

    int x = 0;
    int y = 0;
    for (int i = 0; i < text_height; i++) {
        for (int j = 0; j < text_width; j++) {
            art->data[y * text_width + x] = text[i * text_width + j];
            x++;
        }
        x = 0;
        y++;
    }

    art->data[y * text_width] = '\0';

    return art;
}

void print_ascii_art(const AsciiArt *art) {
    for (int i = 0; i < art->height; i++) {
        printf("%s\n", art->data + i * art->width);
    }
}

void free_ascii_art(AsciiArt *art) {
    free(art->data);
    free(art);
}

int main() {
    char input[1000];
    printf("Enter your text:\n");
    if (fgets(input, 1000, stdin) == NULL) {
        printf("Error: Input too long.\n");
        return 1;
    }

    AsciiArt *art = generate_ascii_art(input);
    if (!art) {
        printf("Error: Failed to generate ASCII art.\n");
        return 1;
    }

    printf("ASCII art:\n");
    print_ascii_art(art);

    free_ascii_art(art);

    return 0;
}