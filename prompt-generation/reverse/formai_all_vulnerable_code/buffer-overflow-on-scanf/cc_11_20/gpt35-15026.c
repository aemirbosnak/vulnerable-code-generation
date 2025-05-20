//FormAI DATASET v1.0 Category: Digital signal processing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 64 
#define MAX_BLOCK_COUNT 512 

int main()
{
    int i, j;
    int block_count;
    int data[MAX_BLOCK_COUNT][BLOCK_SIZE];

    printf("Enter the number of blocks: ");
    scanf("%d", &block_count);

    if(block_count > MAX_BLOCK_COUNT)
    {
        printf("Error: Maximum block count exceeded!\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < block_count; i++)
    {
        printf("Enter data for block %d:\n", i);
        
        for(j = 0; j < BLOCK_SIZE; j++)
            scanf("%d", &data[i][j]);
    }

    // Digital signal processing paranoid code starts here...

    for(i = 0; i < block_count; i++)
    {
        for(j = 0; j < BLOCK_SIZE; j++)
        {
            if(data[i][j] < -32767 || data[i][j] > 32767)
            {
                printf("Warning: Data out of range in block %d, sample %d\n", i, j);
            
                if(data[i][j] < -32767)
                    data[i][j] = -32767;
                else if(data[i][j] > 32767)
                    data[i][j] = 32767;
            }
        }
    }

    for(i = 0; i < block_count; i++)
    {
        for(j = 0; j < BLOCK_SIZE; j++)
        {
            if(data[i][j] >= 0 && data[i][j] <= 2000)
            {
                data[i][j] *= 2;
            }
            else if(data[i][j] > 2000 && data[i][j] <= 8000)
            {
                data[i][j] += 500;
            }
            else if(data[i][j] > 8000 && data[i][j] <= 32767)
            {
                data[i][j] -= 1000;
            }
            else
            {
                printf("Warning: Data out of range in block %d, sample %d\n", i, j);
            }
        }
    }

    printf("Data after digital signal processing:\n");

    for(i = 0; i < block_count; i++)
    {
        printf("Block %d:\n", i);
        
        for(j = 0; j < BLOCK_SIZE; j++)
            printf("%d ", data[i][j]);
        
        printf("\n");
    }

    return 0;
}