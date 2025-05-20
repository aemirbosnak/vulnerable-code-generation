//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 80

void print_art(char *text) {
    int len = strlen(text);
    int height = (len + WIDTH - 1) / WIDTH;
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (i * WIDTH + j < len) {
                printf("%c", text[i * WIDTH + j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: unable to open input file.\n");
        return 1;
    }

    char *text = NULL;
    size_t capacity = 0;
    ssize_t read;

    while ((read = getline(&text, &capacity, input_file))!= -1) {
        if (text[read - 1] == '\n') {
            text[read - 1] = '\0';
        }
    }

    fclose(input_file);

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: unable to open output file.\n");
        free(text);
        return 1;
    }

    print_art(text);

    fprintf(output_file, "%s", text);

    fclose(output_file);
    free(text);

    return 0;
}