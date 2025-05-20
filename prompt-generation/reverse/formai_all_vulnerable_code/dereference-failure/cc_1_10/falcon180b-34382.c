//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 100
#define MAX_COLS 100

char text[MAX_ROWS][MAX_COLS];
int rows, cols;

void load_text(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading file: %s\n", filename);
        exit(1);
    }

    char c;
    int i, j;
    rows = cols = 0;
    while ((c = fgetc(file))!= EOF) {
        if (c == '\n') {
            rows++;
            cols = 0;
        } else if (c!= '\r') {
            if (cols >= MAX_COLS) {
                printf("Error: text too wide\n");
                exit(1);
            }
            text[rows][cols++] = c;
        }
    }
    fclose(file);
}

void generate_ascii_art(int font_size) {
    printf("Font size: %d\n", font_size);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char c = text[i][j];
            if (isalpha(c)) {
                printf("%c", c);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <text_file> <font_size>\n", argv[0]);
        return 1;
    }

    load_text(argv[1]);
    generate_ascii_art(atoi(argv[2]));

    return 0;
}