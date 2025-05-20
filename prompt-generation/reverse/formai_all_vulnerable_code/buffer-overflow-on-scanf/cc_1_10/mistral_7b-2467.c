//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 8
#define HEIGHT 8

char canvas[HEIGHT][WIDTH];

void print_canvas() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

void set_pixel(int x, int y, char value) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        canvas[y][x] = value;
    }
}

int main() {
    char filename[50];

    // Initialize canvas with default values
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = ' ';
        }
    }

    int x, y;
    char value;

    while (1) {
        print_canvas();
        printf("\nEnter x, y and character (space to save and quit): ");
        scanf("%d%d%c", &x, &y, &value);

        set_pixel(x, y, value);

        if (value == ' ') {
            printf("Enter filename: ");
            scanf("%s", filename);
            FILE *fp = fopen(filename, "w");
            for (int i = 0; i < HEIGHT; i++) {
                for (int j = 0; j < WIDTH; j++) {
                    fprintf(fp, "%c", canvas[i][j]);
                }
                fprintf(fp, "\n");
            }
            fclose(fp);
            printf("Image saved as %s\n", filename);
            break;
        }
    }

    return 0;
}