//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX 118

int main()
{
    system("clear");

    // Print the header
    printf("Periodic Table of Elements\n");
    printf("----------------------\n");

    // Create the table
    int table[MAX][MAX] = {{0}};

    // Print the group numbers
    printf("Group Numbers:\n");
    for(int r = 1; r <= MAX; r++)
    {
        for(int c = 1; c <= MAX; c++)
        {
            if(table[r][c] != 0)
            {
                printf("%d ", table[r][c]);
            }
        }
        printf("\n");
    }

    // Print the element names
    printf("Element Names:\n");
    for(int r = 1; r <= MAX; r++)
    {
        for(int c = 1; c <= MAX; c++)
        {
            if(table[r][c] != 0)
            {
                printf("%s ", table[r][c]);
            }
        }
        printf("\n");
    }

    // Print the atomic numbers
    printf("Atomic Numbers:\n");
    for(int r = 1; r <= MAX; r++)
    {
        for(int c = 1; c <= MAX; c++)
        {
            if(table[r][c] != 0)
            {
                printf("%d ", table[r][c]);
            }
        }
        printf("\n");
    }

    return 0;
}