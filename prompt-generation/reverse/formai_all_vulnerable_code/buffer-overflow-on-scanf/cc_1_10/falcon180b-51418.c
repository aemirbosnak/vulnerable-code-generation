//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    char *text;
    int width;
    int height;
    int (*draw)(void *data, int x, int y);
} Art;

void art_draw_space(void *data, int x, int y) {
    Art *art = data;
    if (x < art->width && y < art->height) {
        printf(" ");
    }
}

void art_draw_letter(void *data, int x, int y) {
    Art *art = data;
    if (x < art->width && y < art->height) {
        printf("%c", toupper(art->text[y * art->width + x]));
    }
}

int main() {
    FILE *file;
    char filename[100];
    printf("Enter the name of the text file: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char text[100000];
    fseek(file, 0, SEEK_END);
    int filesize = ftell(file);
    fseek(file, 0, SEEK_SET);
    fread(text, filesize, 1, file);
    fclose(file);

    int width, height;
    printf("Enter the width of the ASCII art (1-80): ");
    scanf("%d", &width);
    printf("Enter the height of the ASCII art (1-25): ");
    scanf("%d", &height);

    Art art = {
       .text = text,
       .width = width,
       .height = height,
       .draw = art_draw_letter
    };

    art_draw_space(&art, 0, 0);
    for (int y = 0; y < art.height; y++) {
        for (int x = 0; x < art.width; x++) {
            if (art.text[y * art.width + x] == '\n') {
                art_draw_space(&art, x, y);
            } else {
                art_draw_letter(&art, x, y);
            }
        }
        printf("\n");
    }

    return 0;
}