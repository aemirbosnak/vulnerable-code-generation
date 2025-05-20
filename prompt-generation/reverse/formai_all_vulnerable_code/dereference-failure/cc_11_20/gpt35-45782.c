//FormAI DATASET v1.0 Category: Fractal Generation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 24
#define XMIN -2
#define XMAX 1
#define YMIN -1
#define YMAX 1

int main()
{
    int i, j, count, max_count = 0;
    double x, y, xStart, yStart, xTemp, yTemp, xOld, yOld;

    char* output[HEIGHT];

    for(i = 0; i < HEIGHT; i++)
        output[i] = (char*)malloc((WIDTH+1) * sizeof(char));

    for(i = 0; i < WIDTH; i++)
        output[HEIGHT/2][i] = '-';

    output[HEIGHT/2][WIDTH] = '\0';

    for(i = 0; i < HEIGHT; i++)
    {
        for(j = 0; j < WIDTH; j++)
        {
            xStart = XMIN + j * (XMAX - XMIN) / WIDTH;
            yStart = YMIN + i * (YMAX - YMIN) / HEIGHT;

            x = 0;
            y = 0;
            count = 0;

            do
            {
                xTemp = x * x - y * y + xStart;
                yTemp = 2 * x * y + yStart;

                x = xTemp;
                y = yTemp;

                count++;

                if(count == WIDTH)
                {
                    output[i][j] = '*';
                    break;
                }

                xOld = (x + 2) / 3;
                yOld = (y + 1) / 2;

            } while(sqrt(x * x + y * y) < 2 && count < WIDTH);

            if(count > max_count)
                max_count = count;
        }

        output[i][WIDTH] = '\0';
    }

    for(i = 0; i < HEIGHT; i++)
        printf("%s\n", output[i]);

    for(i = 0; i < HEIGHT; i++)
        free(output[i]);

    return 0;
}