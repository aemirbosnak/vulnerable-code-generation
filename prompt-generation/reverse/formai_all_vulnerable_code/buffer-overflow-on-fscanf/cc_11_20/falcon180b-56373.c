//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, k, l, m, n, o, current_number, bingo[5][5];
    char input[5];
    FILE *fp;
    fp = fopen("bingo_numbers.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            fscanf(fp, "%d", &bingo[i][j]);
        }
    }
    fclose(fp);
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d ", bingo[i][j]);
        }
        printf("\n");
    }
    srand(time(NULL));
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            current_number = rand() % 75 + 1;
            while (current_number == bingo[i][j])
            {
                current_number = rand() % 75 + 1;
            }
            bingo[i][j] = current_number;
        }
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d ", bingo[i][j]);
        }
        printf("\n");
    }
    printf("Enter your BINGO card numbers (5 numbers):\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%s", input);
        for (j = 0; j < 5; j++)
        {
            if (input[j] == 'X')
            {
                if (bingo[i][j] == 0)
                {
                    printf("Error: Invalid number\n");
                    exit(1);
                }
            }
        }
    }
    printf("BINGO!\n");
    return 0;
}