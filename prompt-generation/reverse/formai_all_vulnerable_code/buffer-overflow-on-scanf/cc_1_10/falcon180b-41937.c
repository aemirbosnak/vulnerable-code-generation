//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24

typedef struct {
    char *data;
    int width;
    int height;
} TextArt;

void print_art(TextArt *art) {
    int i, j;
    for (i = 0; i < art->height; i++) {
        for (j = 0; j < art->width; j++) {
            printf("%c", art->data[i * art->width + j]);
        }
        printf("\n");
    }
}

int main() {
    char input_text[1000];
    printf("Enter your text: ");
    scanf("%s", input_text);

    int art_width = WIDTH;
    int art_height = HEIGHT;
    TextArt *art = malloc(sizeof(TextArt));
    art->data = malloc(art_width * art_height);
    art->width = art_width;
    art->height = art_height;

    int x = 0;
    int y = 0;
    int i = 0;
    while (input_text[i]) {
        if (input_text[i] == '\n') {
            x = 0;
            y++;
        } else {
            art->data[y * art_width + x++] = input_text[i];
        }
        i++;
    }

    print_art(art);

    free(art->data);
    free(art);

    return 0;
}