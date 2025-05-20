//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void draw_ascii_art(char *text, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c", text[i * cols + j]);
        }
        printf("\n");
    }
}

int main() {
    char text[MAX_ROWS][MAX_COLS];
    int rows, cols;
    FILE *file;
    char ch;

    printf("Enter the name of the text file: ");
    scanf("%s", &text);

    file = fopen(text, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    rows = 0;
    cols = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isspace(ch)) {
            rows++;
            cols = 0;
        } else {
            text[rows][cols++] = ch;
        }
    }
    text[rows][cols] = '\0';
    fclose(file);

    draw_ascii_art(text, rows, cols);

    return 0;
}