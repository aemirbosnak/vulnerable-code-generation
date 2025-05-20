//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE 4096
#define MAX_ASCII_ART 10000

typedef struct {
    char *text;
    int width;
} AsciiArtLine;

void generate_ascii_art(const char *text, int width, AsciiArtLine *lines, int *num_lines) {
    int i, j;
    int line_width = 0;
    int num_chars = strlen(text);
    AsciiArtLine *cur_line = lines;

    for (i = 0; i < num_chars; i++) {
        if (isspace(text[i])) {
            if (line_width > 0) {
                cur_line->width = line_width;
                cur_line->text = malloc(line_width + 1);
                memcpy(cur_line->text, text + (*num_lines - 1) * width + (i - line_width), line_width);
                cur_line->text[line_width] = '\0';
                cur_line++;
                *num_lines += 1;
                line_width = 0;
            }
        } else {
            line_width++;
        }
    }

    if (line_width > 0) {
        cur_line->width = line_width;
        cur_line->text = malloc(line_width + 1);
        memcpy(cur_line->text, text + (*num_lines - 1) * width + (i - line_width), line_width);
        cur_line->text[line_width] = '\0';
        cur_line++;
        *num_lines += 1;
    }
}

void print_ascii_art(AsciiArtLine *lines, int num_lines) {
    int i;

    for (i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i].text);
    }
}

int main() {
    char text[MAX_LINE];
    AsciiArtLine lines[MAX_ASCII_ART];
    int num_lines = 0;

    printf("Enter some text: ");
    fgets(text, MAX_LINE, stdin);

    generate_ascii_art(text, 80, lines, &num_lines);

    printf("\nASCII art:\n");
    print_ascii_art(lines, num_lines);

    return 0;
}