//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    char *data;
    int width;
    int height;
} TextArt;

void create_art(char *text, TextArt *art) {
    int len = strlen(text);
    art->width = len;
    art->height = 1;
    art->data = malloc(art->width * art->height * sizeof(char));
    strncpy(art->data, text, art->width * art->height - 1);
}

void print_art(TextArt art) {
    int i, j;
    for (i = 0; i < art.height; i++) {
        for (j = 0; j < art.width; j++) {
            printf("%c", art.data[i * art.width + j]);
        }
        printf("\n");
    }
}

void free_art(TextArt *art) {
    free(art->data);
    art->data = NULL;
}

int main() {
    char input[MAX_WIDTH * MAX_HEIGHT];
    TextArt art;

    printf("Enter some text to convert to ASCII art:\n");
    fgets(input, MAX_WIDTH * MAX_HEIGHT, stdin);

    create_art(input, &art);
    print_art(art);

    free_art(&art);

    return 0;
}