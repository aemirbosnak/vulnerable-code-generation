//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define WIDTH 80
#define HEIGHT 25

int main() {
    char *input = NULL;
    size_t input_size = 0;
    char *output = NULL;
    size_t output_size = 0;
    char *line;
    char *p;
    int c;
    int i, j;
    int x, y;
    int count = 0;
    int max_count = 0;
    int max_x = 0;
    int max_y = 0;

    if (getline(&input, &input_size, stdin) == -1) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    output_size = input_size + 1;
    output = malloc(output_size);
    if (output == NULL) {
        fprintf(stderr, "Error allocating memory.\n");
        return 1;
    }

    line = output;
    p = input;
    while (*p!= '\0') {
        c = tolower(*p);
        if (isalpha(c)) {
            if (count == 0) {
                max_count = 1;
                max_x = x;
                max_y = y;
            }
            count++;
        } else {
            count = 0;
        }
        if (c == '\n') {
            y++;
            x = 0;
        } else {
            x++;
            if (x >= WIDTH) {
                y++;
                x = 0;
            }
        }
        if (y >= HEIGHT) {
            fprintf(stderr, "Error: input is too long.\n");
            free(output);
            return 1;
        }
        if (count > 0) {
            if (count > max_count) {
                max_count = count;
                max_x = x;
                max_y = y;
            }
        }
        if (count == 0) {
            *line++ = c;
        }
    }
    *line = '\0';

    printf("ASCII art:\n");
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (i >= max_y && i < max_y + max_count && j >= max_x && j < max_x + max_count) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    free(output);
    free(input);
    return 0;
}