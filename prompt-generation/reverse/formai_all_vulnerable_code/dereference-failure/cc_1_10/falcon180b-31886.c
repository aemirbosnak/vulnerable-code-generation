//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    char *text;
    int width;
    int height;
} TextArt;

void draw_art(const TextArt *art) {
    int i, j;
    for (i = 0; i < art->height; i++) {
        for (j = 0; j < art->width; j++) {
            printf("%c", art->text[i * art->width + j]);
        }
        printf("\n");
    }
}

void generate_art(const char *input_text, int width, int height, TextArt *art) {
    int i, j;
    int input_len = strlen(input_text);
    int art_len = width * height;
    int max_len = input_len > art_len? art_len : input_len;
    art->text = malloc(sizeof(char) * (max_len + 1));
    art->width = width;
    art->height = height;

    for (i = 0; i < max_len; i++) {
        art->text[i] = tolower(input_text[i % input_len]);
    }
    art->text[max_len] = '\0';
}

int main() {
    char input_text[1000];
    int width, height;

    printf("Enter the text to convert to ASCII art: ");
    scanf("%s", input_text);

    printf("Enter the width of the ASCII art (between 1 and %d): ", MAX_WIDTH);
    scanf("%d", &width);

    printf("Enter the height of the ASCII art (between 1 and %d): ", MAX_HEIGHT);
    scanf("%d", &height);

    TextArt art;
    generate_art(input_text, width, height, &art);

    draw_art(&art);

    return 0;
}