//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int x, y, i, j, n, m, **a, **b, path_taken = 0, current_position = 0, target_position = MAX - 1;

    printf("Enter the number of rows and columns for the maze:");
    scanf("%d %d", &n, &m);

    a = (int *)malloc(n * m * sizeof(int));
    b = (int *)malloc(n * m * sizeof(int));

    printf("Enter the maze map:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d ", &a[i][j]);
            b[i][j] = 0;
        }
    }

    b[current_position][current_position] = 1;

    while (current_position != target_position)
    {
        int direction = rand() % 4;

        switch (direction)
        {
            case 0:
                if (a[current_position - 1][current_position] != 1)
                {
                    current_position--;
                    b[current_position][current_position] = 1;
                    path_taken++;
                }
                break;
            case 1:
                if (a[current_position][current_position + 1] != 1)
                {
                    current_position++;
                    b[current_position][current_position] = 1;
                    path_taken++;
                }
                break;
            case 2:
                if (a[current_position + 1][current_position] != 1)
                {
                    current_position++;
                    b[current_position][current_position] = 1;
                    path_taken++;
                }
                break;
            case 3:
                if (a[current_position][current_position - 1] != 1)
                {
                    current_position--;
                    b[current_position][current_position] = 1;
                    path_taken++;
                }
                break;
        }
    }

    printf("The number of paths taken is: %d\n", path_taken);

    return 0;
}