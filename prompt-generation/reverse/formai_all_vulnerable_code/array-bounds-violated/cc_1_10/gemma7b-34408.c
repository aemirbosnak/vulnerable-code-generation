//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

void generateQR(char *data)
{
    int i, j, k, size = strlen(data) + 1;
    int matrix[size][size];

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (k = 0; k < strlen(data); k++)
    {
        int pos = data[k] - 65;
        matrix[pos][pos] = 1;
    }

    // Draw the QR code
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (matrix[i][j] == 1)
            {
                printf("X ");
            }
            else
            {
                printf("  ");
            }
        }

        printf("\n");
    }
}

int main()
{
    char data[] = "Hello, world!";
    generateQR(data);

    return 0;
}