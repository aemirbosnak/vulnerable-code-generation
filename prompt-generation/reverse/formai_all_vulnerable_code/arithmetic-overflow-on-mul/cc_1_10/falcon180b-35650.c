//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: complex
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

void create_text_art(char *input, int width, int height, TextArt *art) {
    int i, j, k;
    char *data = malloc(height * width * sizeof(char));

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            k = (i * width) + j;
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                data[k] = '#';
            } else {
                data[k] = input[i * width + j];
            }
        }
    }

    art->data = data;
    art->width = width;
    art->height = height;
}

void print_text_art(TextArt *art) {
    int i, j;
    for (i = 0; i < art->height; i++) {
        for (j = 0; j < art->width; j++) {
            printf("%c", art->data[i * art->width + j]);
        }
        printf("\n");
    }
}

int main() {
    char input[MAX_WIDTH * MAX_HEIGHT];
    int width, height;

    printf("Enter the text: ");
    scanf("%s", input);

    printf("Enter the width: ");
    scanf("%d", &width);

    printf("Enter the height: ");
    scanf("%d", &height);

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Invalid dimensions!\n");
        return 1;
    }

    TextArt art;
    create_text_art(input, width, height, &art);
    print_text_art(&art);

    return 0;
}