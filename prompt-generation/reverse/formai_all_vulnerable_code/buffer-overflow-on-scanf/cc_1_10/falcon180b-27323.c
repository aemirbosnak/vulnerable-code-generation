//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: calm
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

AsciiArt *generateAsciiArt(const char *text) {
    AsciiArt *art = malloc(sizeof(AsciiArt));
    art->data = malloc(MAX_WIDTH * MAX_HEIGHT * sizeof(char));
    art->width = 0;
    art->height = 0;

    int i, j, k;
    for (i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (c == '\n') {
            art->height++;
            art->width = 0;
        } else {
            art->data[art->width * art->height + art->height - 1] = c;
            art->width++;
        }
    }

    return art;
}

void printAsciiArt(const AsciiArt *art) {
    for (int i = 0; i < art->height; i++) {
        for (int j = 0; j < art->width; j++) {
            printf("%c", art->data[i * art->width + j]);
        }
        printf("\n");
    }
}

int main() {
    char input[1000];
    printf("Enter your text: ");
    scanf("%s", input);

    AsciiArt *art = generateAsciiArt(input);
    printAsciiArt(art);

    free(art->data);
    free(art);

    return 0;
}