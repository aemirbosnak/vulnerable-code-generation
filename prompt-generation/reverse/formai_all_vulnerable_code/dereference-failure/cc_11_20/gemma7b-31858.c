//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 768

int main()
{
    // Initialize the RNG
    srand(time(NULL));

    // Create the weather map
    int **weather_map = (int **)malloc(MAX_HEIGHT * sizeof(int *));
    for (int h = 0; h < MAX_HEIGHT; h++)
    {
        weather_map[h] = (int *)malloc(MAX_WIDTH * sizeof(int));
    }

    // Initialize the weather map with random values
    for (int h = 0; h < MAX_HEIGHT; h++)
    {
        for (int w = 0; w < MAX_WIDTH; w++)
        {
            weather_map[h][w] = rand() % 4;
        }
    }

    // Print the weather map
    for (int h = 0; h < MAX_HEIGHT; h++)
    {
        for (int w = 0; w < MAX_WIDTH; w++)
        {
            switch (weather_map[h][w])
            {
                case 0:
                    printf("O ");
                    break;
                case 1:
                    printf("C ");
                    break;
                case 2:
                    printf("R ");
                    break;
                case 3:
                    printf("S ");
                    break;
            }
        }
        printf("\n");
    }

    // Free the memory allocated for the weather map
    for (int h = 0; h < MAX_HEIGHT; h++)
    {
        free(weather_map[h]);
    }
    free(weather_map);

    return 0;
}