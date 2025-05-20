//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    char *text;
    int width;
    int height;
} Art;

void generate_art(Art *art) {
    int i, j;
    int num_chars = strlen(art->text);
    int num_lines = (num_chars + MAX_WIDTH - 1) / MAX_WIDTH;

    for (i = 0; i < num_lines; i++) {
        for (j = 0; j < MAX_WIDTH; j++) {
            if (i * MAX_WIDTH + j < num_chars) {
                printf("%c", art->text[i * MAX_WIDTH + j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    Art art;

    printf("Enter the text to convert to ASCII art:\n");
    scanf("%s", art.text);

    printf("Enter the width of the ASCII art (0 for auto):\n");
    scanf("%d", &art.width);

    if (art.width == 0) {
        art.width = MAX_WIDTH;
    }

    printf("Enter the height of the ASCII art (0 for auto):\n");
    scanf("%d", &art.height);

    if (art.height == 0) {
        art.height = (strlen(art.text) + MAX_WIDTH - 1) / MAX_WIDTH;
    }

    generate_art(&art);

    return 0;
}