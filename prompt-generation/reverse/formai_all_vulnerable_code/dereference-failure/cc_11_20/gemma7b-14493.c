//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: shape shifting
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20

int main()
{
    int **traffic_light = (int**)malloc(ROWS * sizeof(int*));
    for (int i = 0; i < ROWS; i++)
    {
        traffic_light[i] = (int*)malloc(COLS * sizeof(int));
    }

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            traffic_light[r][c] = 0;
        }
    }

    srand(time(NULL));

    while (1)
    {
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if (traffic_light[r][c] == 0)
                {
                    traffic_light[r][c] = rand() % 2;
                }
            }
        }

        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                switch (traffic_light[r][c])
                {
                    case 0:
                        printf("G ");
                        break;
                    case 1:
                        printf("Y ");
                        break;
                    case 2:
                        printf("R ");
                        break;
                }
            }
        }

        printf("\n");
        sleep(1);
    }

    return 0;
}