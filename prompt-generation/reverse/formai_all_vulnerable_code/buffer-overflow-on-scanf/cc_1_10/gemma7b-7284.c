//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    char data[MAX];
    printf("Enter data: ");
    scanf("%s", data);

    int size = 0;
    for (int i = 0; data[i] != '\0'; i++)
    {
        size++;
    }

    int matrix[size][size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = 0;
        }
    }

    int x = 0;
    for (int i = 0; data[i] != '\0'; i++)
    {
        matrix[x][x] = 1;
        x++;
    }

    int i = 0;
    for (int y = 0; y < size; y++)
    {
        for (int z = 0; z < size; z++)
        {
            if (matrix[y][z] == 1)
            {
                printf("X ");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}