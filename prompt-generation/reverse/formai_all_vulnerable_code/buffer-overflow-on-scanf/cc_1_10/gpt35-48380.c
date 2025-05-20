//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char original[MAX][MAX];   // original image
char watermark[MAX][MAX];  // watermark image
char final_image[MAX][MAX]; // final image with watermark

// function to print the image
void print_image(char image[MAX][MAX], int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("%c", image[i][j]);
        }
        printf("\n");
    }
}

// function to add watermark
void watermark_image(char original[MAX][MAX], char watermark[MAX][MAX], char final_image[MAX][MAX], int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(watermark[i][j] == '1')
            {
                final_image[i][j] = '1';
            }
            else
            {
                final_image[i][j] = original[i][j];
            }
        }
    }
}

int main()
{
    int size, players;
    printf("Enter size of image: ");
    scanf("%d", &size);

    //inputting original image
    for(int i=0;i<size;i++)
    {
        printf("Enter row %d of original image (0's and 1's only): ", i+1);
        scanf("%s", original[i]);
    }

    //inputting watermark image
    for(int i=0;i<size;i++)
    {
        printf("Enter row %d of watermark image (0's and 1's only): ", i+1);
        scanf("%s", watermark[i]);
    }

    // printing the original image
    printf("\nOriginal Image:\n");
    print_image(original, size);

    // printing the watermark image
    printf("\nWatermark Image:\n");
    print_image(watermark, size);

    printf("\nEnter number of players: ");
    scanf("%d", &players);

    // watermarking the image
    watermark_image(original, watermark, final_image, size);

    // printing the final image
    printf("\nFinal Image with Watermark:\n");
    print_image(final_image, size);

    return 0;
}