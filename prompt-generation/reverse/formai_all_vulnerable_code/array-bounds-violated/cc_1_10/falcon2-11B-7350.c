//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_maze(int m, int n)
{
    int i, j, k;
    int walls[m][n];
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            walls[i][j] = 0;
        }
    }

    // make walls
    for(k=0; k<m; k++)
    {
        for(i=0; i<m; i++)
        {
            if(i!=k)
            {
                walls[i][0] = 1;
            }
        }
        for(i=0; i<n; i++)
        {
            if(i!=0)
            {
                walls[0][i] = 1;
            }
        }
    }
    for(i=1; i<m-1; i++)
    {
        for(j=1; j<n-1; j++)
        {
            walls[i][j] = 1;
        }
    }

    // mark start and end
    walls[m/2][n/2] = 2;
    walls[m/2][n/2+1] = 2;

    // make passage
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(walls[i][j] == 1)
            {
                printf(".");
            }
            else if(walls[i][j] == 2)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    int m = rand() % 10 + 1;
    int n = rand() % 10 + 1;
    printf("Size of Maze: %d x %d\n", m, n);
    generate_maze(m, n);
    return 0;
}