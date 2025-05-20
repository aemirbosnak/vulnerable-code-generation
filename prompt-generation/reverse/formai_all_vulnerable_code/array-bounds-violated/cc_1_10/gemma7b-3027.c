//Gemma-7B DATASET v1.0 Category: QR code reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beep(int duration)
{
    printf("%c", 255 - duration);
    sleep(duration);
    printf("%c", 255);
}

int main()
{
    char data[1024] = "Hello, world!";
    int i = 0;
    int size = 0;

    for (i = 0; data[i] != '\0'; i++)
    {
        size++;
    }

    int matrix[size][size];

    for (i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (i = 0; data[i] != '\0'; i++)
    {
        int row = data[i] / 7;
        int col = data[i] % 7;
        matrix[row][col] = 1;
    }

    beep(200);

    for (i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] == 1)
            {
                beep(200);
            }
        }
    }

    return 0;
}