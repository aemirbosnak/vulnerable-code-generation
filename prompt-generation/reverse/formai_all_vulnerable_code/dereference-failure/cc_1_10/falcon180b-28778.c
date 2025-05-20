//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80

typedef struct {
    char *text;
    int width;
} TextBlock;

void generate_ascii_art(const char *input_text) {
    char *text = strdup(input_text);
    int num_lines = 1;
    int line_length = strlen(text);
    int i = 0;

    while (line_length > MAX_WIDTH) {
        line_length -= MAX_WIDTH;
        num_lines++;
    }

    TextBlock *blocks = malloc(sizeof(TextBlock) * num_lines);

    for (i = 0; i < num_lines; i++) {
        blocks[i].text = strndup(text + i * MAX_WIDTH, MAX_WIDTH);
        blocks[i].width = strlen(blocks[i].text);
    }

    printf("+");
    for (i = 0; i < num_lines; i++) {
        printf("-+-");
    }
    printf("+\n");

    for (i = 0; i < num_lines; i++) {
        printf("| %s |\n", blocks[i].text);
    }

    printf("+");
    for (i = 0; i < num_lines; i++) {
        printf("-+-");
    }
    printf("+\n");

    for (i = 0; i < num_lines; i++) {
        free(blocks[i].text);
    }
    free(blocks);
    free(text);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    generate_ascii_art(argv[1]);

    return 0;
}