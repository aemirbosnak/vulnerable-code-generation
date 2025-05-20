//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    char **rows;
    int num_rows;
    int num_cols;
} TextToAsciiArt;

void init_ascii_art(TextToAsciiArt *art) {
    art->rows = calloc(MAX_HEIGHT, sizeof(char*));
    art->num_rows = 0;
    art->num_cols = 0;
}

void free_ascii_art(TextToAsciiArt *art) {
    int i;
    for (i = 0; i < art->num_rows; i++) {
        free(art->rows[i]);
    }
    free(art->rows);
}

void add_row(TextToAsciiArt *art, const char *row) {
    art->rows[art->num_rows++] = strdup(row);
}

void print_ascii_art(const TextToAsciiArt *art) {
    int i, j;
    for (i = 0; i < art->num_rows; i++) {
        for (j = 0; j < strlen(art->rows[i]); j++) {
            printf("%c", art->rows[i][j]);
        }
        printf("\n");
    }
}

int main() {
    TextToAsciiArt art;
    init_ascii_art(&art);

    char input[MAX_WIDTH + 1];
    while (fgets(input, MAX_WIDTH, stdin)!= NULL) {
        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }
        add_row(&art, input);
        if (art.num_rows >= MAX_HEIGHT) {
            break;
        }
    }

    print_ascii_art(&art);

    free_ascii_art(&art);

    return 0;
}