//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define MAX_CHARS 1000

typedef struct {
    char *text;
    int width;
    int height;
    int chars;
} TextArt;

void generate_art(TextArt *art) {
    int i, j, k, l;
    int spaces = (art->width - strlen(art->text)) / 2;
    int lines = art->height - 2;

    for (i = 0; i < lines; i++) {
        for (j = 0; j < spaces; j++) {
            printf(" ");
        }

        for (k = 0; k < strlen(art->text); k++) {
            printf("%c", art->text[k]);

            if (k % 2 == 0 && k < strlen(art->text) - 1) {
                printf("_");
            }
        }

        printf("\n");
    }

    for (l = 0; l < spaces; l++) {
        printf(" ");
    }

    printf("+");

    for (l = 0; l < strlen(art->text) - 1; l++) {
        printf("-");
    }

    printf("+\n");
}

int main() {
    char input[MAX_CHARS];
    TextArt art;

    printf("Enter some text: ");
    fgets(input, MAX_CHARS, stdin);

    art.text = strdup(input);
    art.width = MAX_WIDTH;
    art.height = MAX_HEIGHT;
    art.chars = strlen(art.text);

    generate_art(&art);

    free(art.text);

    return 0;
}