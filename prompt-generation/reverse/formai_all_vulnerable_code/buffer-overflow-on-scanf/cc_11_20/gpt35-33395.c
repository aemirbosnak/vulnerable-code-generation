//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

#define ROWS 4
#define COLS 4

int main()
{
    int input_image[ROWS][COLS];
    int watermark[ROWS][COLS];

    printf("Enter the elements of the input_image:\n");

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            scanf("%d", &input_image[i][j]);
        }
    }

    printf("Enter the elements of the watermark:\n");

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            scanf("%d", &watermark[i][j]);
        }
    }

    printf("Input_image:\n");

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%d ", input_image[i][j]);
        }
        printf("\n");
    }

    printf("Watermark:\n");

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%d ", watermark[i][j]);
        }
        printf("\n");
    }

    // Applying the watermark
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(watermark[i][j] == 1)
            {
                input_image[i][j] += 1;
            }
        }
    }

    printf("Digital Watermarked Image:\n");

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%d ", input_image[i][j]);
        }
        printf("\n");
    }

    return 0;
}