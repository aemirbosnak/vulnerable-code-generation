//FormAI DATASET v1.0 Category: Fractal Generation ; Style: grateful
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void draw_fractal(char **canvas, int x1, int y1, int x2, int y2, int depth)
{
    if(depth == 0)
    {
        (*canvas)[y1 * 81 + x1] = '*';
        return;
    }

    int mid_x = (x1+x2)/2;
    int mid_y = (y1+y2)/2;

    draw_fractal(canvas, x1, y1, mid_x, mid_y, depth-1); // top left quadrant
    draw_fractal(canvas, mid_x, y1, x2, mid_y, depth-1); // top right quadrant
    draw_fractal(canvas, x1, mid_y, mid_x, y2, depth-1); // bottom left quadrant
    draw_fractal(canvas, mid_x, mid_y, x2, y2, depth-1); // bottom right quadrant

    return;
}

int main()
{
    int depth;
    printf("Enter the depth of the desired fractal (1-5): ");
    scanf("%d", &depth);

    if(depth > 5)
    {
        printf("Fractal depth is limited to 5. Please enter a valid depth.\n");
        return 0;
    }

    char *canvas = (char*) malloc(81*81);
    memset(canvas, ' ', 81*81);

    draw_fractal(&canvas, 0, 0, 80, 80, depth);

    for(int i=0; i<81; i++)
    {
        for(int j=0; j<81; j++)
        {
            printf("%c", canvas[i*81 + j]);
        }
        printf("\n");
    }

    free(canvas);
    return 0;
}