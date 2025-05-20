//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define ASCII_ART_CHAR '@'

typedef struct {
    char *text;
    int width;
    int height;
} TextArt;

void generate_art(TextArt *art) {
    int i, j;
    int text_width = strlen(art->text);
    int text_height = (int)ceil(text_width / (double)art->width);

    for (i = 0; i < text_height; i++) {
        for (j = 0; j < art->width; j++) {
            printf("%c", ASCII_ART_CHAR);
        }
        printf("\n");
    }
}

int main() {
    char input_text[MAX_WIDTH + 1];
    int width, height;

    printf("Enter the text to convert to ASCII art:\n");
    fgets(input_text, MAX_WIDTH, stdin);
    input_text[strcspn(input_text, "\n")] = '\0';

    printf("Enter the width of the ASCII art (1-80): ");
    scanf("%d", &width);
    if (width < 1 || width > MAX_WIDTH) {
        printf("Invalid width\n");
        return 1;
    }

    printf("Enter the height of the ASCII art (1-25): ");
    scanf("%d", &height);
    if (height < 1 || height > MAX_HEIGHT) {
        printf("Invalid height\n");
        return 1;
    }

    TextArt art = {input_text, width, height};
    generate_art(&art);

    return 0;
}