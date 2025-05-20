//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 80
#define MAX_TEXT_LENGTH 1000

char *text;
int text_length;
int line_length;
int num_lines;

void generate_art(char *text, int text_length, int line_length) {
    int i, j, k;
    for (i = 0; i < text_length; i++) {
        if (text[i] == '\n') {
            num_lines++;
        }
    }
    if (num_lines == 0) {
        num_lines = 1;
    }
    fprintf(stdout, "Number of lines: %d\n", num_lines);
    for (i = 0; i < text_length; i++) {
        if (text[i] == '\n') {
            for (j = 0; j < line_length; j++) {
                fprintf(stdout, " ");
            }
            fprintf(stdout, "\n");
        } else {
            for (j = 0; j < strlen(text+i); j++) {
                fprintf(stdout, "%c", text[i+j]);
            }
            for (k = strlen(text+i); k < line_length; k++) {
                fprintf(stdout, " ");
            }
        }
    }
}

int main() {
    srand(time(NULL));
    text = malloc(MAX_TEXT_LENGTH * sizeof(char));
    if (text == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for text.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "Enter text to convert to ASCII art:\n");
    fgets(text, MAX_TEXT_LENGTH, stdin);
    text_length = strlen(text);
    if (text_length == 0) {
        fprintf(stdout, "Error: Empty text entered.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "Enter line length (default: %d): ", MAX_LINE_LENGTH);
    scanf("%d", &line_length);
    if (line_length <= 0) {
        line_length = MAX_LINE_LENGTH;
    }
    generate_art(text, text_length, line_length);
    free(text);
    return 0;
}