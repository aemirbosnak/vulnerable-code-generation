//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
    char *text;
    int width;
    int height;
    int font_size;
    int line_spacing;
} TextArt;

void generate_text_art(TextArt *art) {
    int i, j, k;
    int char_width, char_height;
    int x, y;

    char_width = art->font_size * 6;
    char_height = art->font_size * 8;

    for (i = 0; i < art->height; i++) {
        for (j = 0; j < art->width; j++) {
            if (art->text[i * art->width + j] == '\n') {
                x = 0;
                y += char_height;
            } else {
                x = j * char_width;
                y = i * char_height;
            }

            for (k = 0; k < char_height; k++) {
                if ((art->text[i * art->width + j] & (1 << k))!= 0) {
                    printf("  ");
                } else {
                    printf("██");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    TextArt art;

    printf("Enter the text to convert to ASCII art:\n");
    scanf("%s", art.text);

    printf("Enter the font size (6-24):\n");
    scanf("%d", &art.font_size);

    art.width = strlen(art.text) / art.font_size;
    art.height = strlen(art.text) / art.width;

    printf("Enter the line spacing (1-3):\n");
    scanf("%d", &art.line_spacing);

    generate_text_art(&art);

    return 0;
}