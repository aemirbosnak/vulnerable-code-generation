//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define CHAR_SET_SIZE 95

typedef struct {
    char *text;
    int width;
    int height;
    char **char_set;
} ascii_art;

void generate_ascii_art(ascii_art *art) {
    int i, j, k, l;
    int text_len = strlen(art->text);
    int max_chars = art->width * art->height;
    char *ascii_text = malloc(max_chars + 1);

    for (i = 0; i < art->height; i++) {
        for (j = 0; j < art->width; j++) {
            int index = (i * art->width + j) % max_chars;
            ascii_text[index] = art->char_set[rand() % CHAR_SET_SIZE][0];
        }
        ascii_text[i * art->width + art->width - 1] = '\n';
    }

    printf("%s\n", ascii_text);
    free(ascii_text);
}

int main() {
    ascii_art art;
    art.text = "Hello, World! ";
    art.width = MAX_WIDTH;
    art.height = MAX_HEIGHT;

    art.char_set = malloc(CHAR_SET_SIZE * sizeof(char *));
    art.char_set[0] = strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    art.char_set[1] = strdup("abcdefghijklmnopqrstuvwxyz");
    art.char_set[2] = strdup("0123456789");
    art.char_set[3] = strdup("!@#$%^&*()_+");

    generate_ascii_art(&art);

    return 0;
}