//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24

typedef struct {
    int x, y, c;
} Cell;

void draw_cell(Cell cell) {
    int x = cell.x * WIDTH;
    int y = cell.y * HEIGHT;
    printf("%c", cell.c);
}

void draw_image(char *filename, int width, int height) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    Cell *cells = malloc(width * height * sizeof(Cell));
    if (cells == NULL) {
        printf("Error: Could not allocate memory for cells\n");
        exit(1);
    }

    char line[WIDTH + 1];
    int x = 0, y = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] == '\n') {
                y++;
                x = 0;
            } else if (line[i]!= '\r') {
                cells[y * width + x].c = line[i];
                cells[y * width + x].x = x;
                cells[y * width + x].y = y;
                x++;
            }
        }
    }

    fclose(fp);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            draw_cell(cells[(i * width) + j]);
        }
        printf("\n");
    }

    free(cells);
}

int main() {
    char *filename = "example.bmp";
    int width, height;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    fclose(fp);

    draw_image(filename, width, height);

    return 0;
}