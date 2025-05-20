//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    char **lines;
    int width;
    int height;
} TextArt;

void init_art(TextArt *art) {
    art->lines = calloc(MAX_HEIGHT, sizeof(char*));
    art->width = 0;
    art->height = 0;
}

void free_art(TextArt *art) {
    for (int i = 0; i < art->height; i++) {
        free(art->lines[i]);
    }
    free(art->lines);
}

void add_line(TextArt *art, const char *str) {
    int len = strlen(str);
    if (len > art->width) {
        art->width = len;
    }
    art->lines[art->height] = strdup(str);
    art->height++;
}

void print_art(const TextArt *art) {
    for (int i = 0; i < art->height; i++) {
        printf("%s\n", art->lines[i]);
    }
}

void generate_ascii_art(const char *input, TextArt *art) {
    init_art(art);

    char *line = strdup(input);
    char *word = strtok(line, " ");

    while (word!= NULL) {
        int len = strlen(word);
        int space_count = (MAX_WIDTH - len) / 2;

        char *padded_word = calloc(len + space_count + 1, sizeof(char));
        strncpy(padded_word, word, len);

        for (int i = 0; i < space_count; i++) {
            strcat(padded_word, " ");
        }

        add_line(art, padded_word);
        free(padded_word);

        word = strtok(NULL, " ");
    }

    free(line);
}

int main() {
    char input[1000];
    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);

    TextArt art;
    generate_ascii_art(input, &art);
    print_art(&art);

    free_art(&art);

    return 0;
}