//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    char *data;
    int width;
    int height;
} TextArt;

void generate_art(TextArt *art, const char *text) {
    int i, j;
    int letter_count = 0;
    int row_count = 0;
    int col_count = 0;
    int max_row_count = 0;

    for (i = 0; i < strlen(text); i++) {
        if (isspace(text[i])) {
            if (col_count > MAX_WIDTH) {
                row_count++;
                col_count = 0;
            }
        } else {
            art->data[row_count] = (char)text[i];
            col_count++;
        }

        if (row_count > max_row_count) {
            max_row_count = row_count;
        }
    }

    art->width = col_count;
    art->height = max_row_count;
}

void print_art(TextArt *art) {
    int i, j;

    for (i = 0; i < art->height; i++) {
        for (j = 0; j < art->width; j++) {
            printf("%c", art->data[i * art->width + j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <text> <output.txt>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    char *text = NULL;
    size_t text_size = 0;

    if (getline(&text, &text_size, input_file) == -1) {
        printf("Error: could not read input file.\n");
        fclose(input_file);
        return 1;
    }

    fclose(input_file);

    TextArt art;
    generate_art(&art, text);

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        free(text);
        return 1;
    }

    print_art(&art);

    fprintf(output_file, "%s", art.data);

    fclose(output_file);
    free(text);

    return 0;
}