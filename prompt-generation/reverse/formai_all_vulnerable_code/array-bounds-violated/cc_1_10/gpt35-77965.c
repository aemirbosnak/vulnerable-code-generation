//FormAI DATASET v1.0 Category: Image compression ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

int main()
{
    // Define the original image matrix
    int original[ROWS][COLS] = {
        {3, 10, 12, 14, 15},
        {4, 8, 15, 14, 12},
        {3, 9, 13, 15, 10},
        {2, 8, 10, 12, 16},
        {1, 3, 5, 7, 9}
    };

    // Define the compressed image matrix
    int compressed[ROWS / 2][COLS / 2] = {0};

    // Compress the image
    for (int i = 0; i < ROWS; i += 2)
    {
        for (int j = 0; j < COLS; j += 2)
        {
            compressed[i / 2][j / 2] = (original[i][j] + original[i][j + 1] +
                                         original[i + 1][j] + original[i + 1][j + 1]) / 4;
        }
    }

    // Print the original image matrix
    printf("Original image:\n\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%3d ", original[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Print the compressed image matrix
    printf("Compressed image:\n\n");
    for (int i = 0; i < ROWS / 2; i++)
    {
        for (int j = 0; j < COLS / 2; j++)
        {
            printf("%3d ", compressed[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}