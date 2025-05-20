//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
    char *text;
    int width;
    int height;
} TextArt;

void generate_art(TextArt *art) {
    int i, j, k;
    int line_count = 0;
    int char_count = 0;
    int max_line_length = 0;
    int line_length = 0;
    int center = (art->width - strlen(art->text)) / 2;

    for (i = 0; i < art->height; i++) {
        line_length = 0;
        for (j = 0; j < art->width; j++) {
            if (i < strlen(art->text)) {
                if (art->text[i] == '\n') {
                    line_count++;
                    line_length = 0;
                } else if (j >= center - line_count && j < center + line_count) {
                    printf("%c", art->text[i]);
                    line_length++;
                } else {
                    printf(" ");
                    line_length++;
                }
            } else {
                printf(" ");
                line_length++;
            }
        }
        printf("\n");
        if (line_length > max_line_length) {
            max_line_length = line_length;
        }
        line_count++;
    }

    for (i = 0; i < art->height; i++) {
        for (j = 0; j < max_line_length; j++) {
            printf("-");
        }
        printf("\n");
    }
}

int main() {
    TextArt art;

    printf("Enter text: ");
    scanf("%s", art.text);

    printf("Enter width: ");
    scanf("%d", &art.width);

    printf("Enter height: ");
    scanf("%d", &art.height);

    generate_art(&art);

    return 0;
}