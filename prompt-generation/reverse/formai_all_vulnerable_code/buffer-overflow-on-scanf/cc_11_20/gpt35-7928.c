//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

#define ROW 8
#define COL 8

int main()
{
    int i,j,binary_val[ROW][COL], watermark[ROW][COL], original_image[ROW][COL];
    
    printf("Enter the original image (8x8 matrix):\n");
    
    //Taking input for original image
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            scanf(" %d",&original_image[i][j]);
        }
    }
    
    printf("\nEnter the watermark (8x8 matrix):\n");
    
    //Taking input for watermark
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            scanf(" %d",&watermark[i][j]);
        }
    }
    
    //Converting original image and watermark to binary values
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            if(original_image[i][j] >= 128)
            {
                binary_val[i][j] = 1;
            }
            else
            {
                binary_val[i][j] = 0;
            }

            if(watermark[i][j] >= 128)
            {
                watermark[i][j] = 1;
            }
            else
            {
                watermark[i][j] = 0;
            }
        }
    }

    printf("\nDigital watermarking the original image:\n");
    
    //Embedding the watermark into the original image
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            if(watermark[i][j]==1 && binary_val[i][j]==0)
            {
                binary_val[i][j] = 1;
            }
            else if(watermark[i][j]==1 && binary_val[i][j]==1)
            {
                binary_val[i][j] = 0;
            }
        }
    }
    
    //Printing the watermarked image
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            printf("%d ",binary_val[i][j]);
        }
        printf("\n");
    }
    
    printf("\nExtracting the watermark from the watermarked image:\n");
    
    //Extracting the watermark from the watermarked image
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            if(binary_val[i][j]!=original_image[i][j])
            {
                printf("1 ");
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
    
    return 0;
}