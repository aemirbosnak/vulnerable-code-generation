//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 50

typedef struct {
    char *data;
    int width;
    int height;
} AsciiArt;

AsciiArt *generateAsciiArt(const char *input) {
    AsciiArt *art = malloc(sizeof(AsciiArt));
    art->data = malloc(MAX_WIDTH * MAX_HEIGHT * sizeof(char));
    art->width = 0;
    art->height = 0;

    int x = 0, y = 0;
    for (int i = 0; input[i]!= '\0'; i++) {
        if (input[i] == '\n') {
            x = 0;
            y++;
        } else {
            art->data[y * MAX_WIDTH + x] = input[i];
            x++;
        }

        if (x > art->width) {
            art->width = x;
        }

        if (y > art->height) {
            art->height = y;
        }
    }

    art->data[y * MAX_WIDTH + x] = '\0';
    return art;
}

void printAsciiArt(AsciiArt *art) {
    for (int y = 0; y < art->height; y++) {
        for (int x = 0; x < art->width; x++) {
            printf("%c", art->data[y * MAX_WIDTH + x]);
        }
        printf("\n");
    }
}

int main() {
    const char *input = "Hello, World!";
    AsciiArt *art = generateAsciiArt(input);
    printAsciiArt(art);
    free(art->data);
    free(art);

    return 0;
}