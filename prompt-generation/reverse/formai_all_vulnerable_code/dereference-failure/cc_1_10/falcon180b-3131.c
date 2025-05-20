//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define MAX_LINES 1000

typedef struct {
    char *text;
    int width;
    int height;
    int lines;
} TextArt;

void print_textart(TextArt *art) {
    int i, j, k;
    for (i = 0; i < art->height; i++) {
        for (j = 0; j < art->width; j++) {
            if (art->text[i * art->width + j]!= '\0') {
                printf("%c", art->text[i * art->width + j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generate_textart(TextArt *art) {
    int i, j, k, l;
    char *text = art->text;
    int width = art->width;
    int height = art->height;
    int lines = art->lines;

    for (i = 0; i < lines; i++) {
        int len = strlen(text);
        for (j = 0; j < len; j++) {
            if (isalpha(text[j])) {
                int x = (i % height) * width + (j % width);
                int y = i / height;
                art->text[x + y * width] = text[j];
            }
        }
        text += len;
    }
}

int main() {
    TextArt art = {0};

    printf("Enter the text to convert into ASCII art:\n");
    scanf("%s", art.text);

    printf("Enter the width of the ASCII art (default: %d):\n", MAX_WIDTH);
    scanf("%d", &art.width);

    printf("Enter the height of the ASCII art (default: %d):\n", MAX_HEIGHT);
    scanf("%d", &art.height);

    printf("Enter the number of lines in the ASCII art (default: %d):\n", MAX_LINES);
    scanf("%d", &art.lines);

    generate_textart(&art);
    print_textart(&art);

    return 0;
}