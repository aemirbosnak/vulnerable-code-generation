//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    char *text;
    int width;
    int height;
} TextArt;

void generate_art(TextArt art) {
    int i, j, k, l;
    int text_length = strlen(art.text);
    int padding = (art.width - text_length) / 2;

    for (i = 0; i < art.height; i++) {
        for (j = 0; j < art.width; j++) {
            if (i < art.height / 2 || i >= art.height / 2 + 1) {
                printf(" ");
            } else {
                k = (i - (art.height / 2)) * art.width / (art.height / 2) + j;
                if (k < text_length) {
                    printf("%c", tolower(art.text[k]));
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    char input_text[100];
    int width, height;

    printf("Enter the text to convert to ASCII art:\n");
    scanf("%s", input_text);

    printf("Enter the width of the ASCII art (max %d):\n", MAX_WIDTH);
    scanf("%d", &width);

    printf("Enter the height of the ASCII art (max %d):\n", MAX_HEIGHT);
    scanf("%d", &height);

    TextArt art = {input_text, width, height};
    generate_art(art);

    return 0;
}