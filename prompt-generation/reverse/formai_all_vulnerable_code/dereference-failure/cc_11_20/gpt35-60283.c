//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int red;
    int green;
    int blue;
} Color;

int main() {
    int width, height;
    printf("Enter the width and height of your canvas: ");
    scanf("%d %d", &width, &height);

    Color** canvas = (Color**)malloc(sizeof(Color*) * height);
    for (int y=0; y<height; y++) {
        canvas[y] = (Color*)malloc(sizeof(Color) * width);
        for (int x=0; x<width; x++) {
            canvas[y][x].red = 255;
            canvas[y][x].green = 255;
            canvas[y][x].blue = 255;
        }
    }

    int tool = 0; // 0 = pencil, 1 = eraser
    Color color = {0, 0, 0}; // default color is black
    int x, y;
    while (1) {
        // display canvas
        for (int y=0; y<height; y++) {
            for (int x=0; x<width; x++) {
                printf("\x1b[48;2;%d;%d;%dm  \x1b[0m", canvas[y][x].red, canvas[y][x].green, canvas[y][x].blue);
            }
            printf("\n");
        }

        // display user controls
        printf("P: pencil, E: eraser, C: change color, X: exit\n");

        // read user input
        char input;
        scanf(" %c", &input);
        switch (input) {
            case 'P':
            case 'p':
                tool = 0;
                break;
            case 'E':
            case 'e':
                tool = 1;
                break;
            case 'C':
            case 'c':
                printf("Enter the color R G B values: ");
                scanf("%d %d %d", &color.red, &color.green, &color.blue);
                break;
            case 'X':
            case 'x':
                for (int y=0; y<height; y++) {
                    free(canvas[y]);
                }
                free(canvas);
                return 0;
            default:
                break;
        }

        // handle mouse input
        printf("Click on pixel coordinates: ");
        scanf("%d %d", &x, &y);
        if (tool == 0) {
            canvas[y][x] = color;
        } else {
            canvas[y][x].red = 255;
            canvas[y][x].green = 255;
            canvas[y][x].blue = 255;
        }
    }
}