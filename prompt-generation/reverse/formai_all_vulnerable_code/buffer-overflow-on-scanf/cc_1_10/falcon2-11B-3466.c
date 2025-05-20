//Falcon2-11B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int AStar(int start_x, int start_y, int end_x, int end_y)
{
    int grid[10][10] = {0};
    int visited[10][10] = {0};
    int parent[10][10] = {0};
    int open_list[10][10] = {0};
    int closed_list[10][10] = {0};

    int start[10][10] = {-1};
    int end[10][10] = {0};
    int cost[10][10] = {0};
    int f[10][10] = {0};
    int g[10][10] = {0};
    int h[10][10] = {0};

    int queue[10][10] = {0};

    int i = 0;
    int j = 0;

    while (i < 10 && j < 10)
    {
        int cost_i = 0;
        int cost_j = 0;

        for (int k = 0; k < 10; k++)
        {
            cost_i += abs(grid[i][k] - start_x);
            cost_j += abs(grid[j][k] - end_x);
        }

        cost[i][j] = cost_i + cost_j;
        f[i][j] = cost_i + cost_j;
        g[i][j] = cost_i;
        h[i][j] = sqrt(cost_i * cost_i + cost_j * cost_j);

        open_list[i][j] = 1;
        parent[i][j] = -1;
        closed_list[i][j] = 0;
        visited[i][j] = 0;

        if (i == start_x && j == start_y)
        {
            start[i][j] = 1;
        }

        if (i == end_x && j == end_y)
        {
            end[i][j] = 1;
        }

        queue[i][j] = 1;

        i++;
        j++;
    }

    while (i < 10 && j < 10)
    {
        int min_f = 999999;
        int min_i = 0;
        int min_j = 0;

        for (int k = 0; k < 10; k++)
        {
            if (open_list[k][j] == 1)
            {
                if (f[k][j] < min_f)
                {
                    min_f = f[k][j];
                    min_i = k;
                    min_j = j;
                }
            }
        }

        if (min_f == 999999)
        {
            break;
        }

        int current_i = min_i;
        int current_j = min_j;

        open_list[min_i][min_j] = 0;
        closed_list[min_i][min_j] = 1;
        visited[min_i][min_j] = 1;

        for (int k = 0; k < 10; k++)
        {
            if (abs(grid[current_i][k] - grid[current_j][k]) == 1)
            {
                if (open_list[current_i][k] == 1 && parent[current_i][k] == -1)
                {
                    parent[current_i][k] = current_j;
                    queue[current_i][k] = 1;
                    cost[current_i][k] = cost[current_i][min_j] + 1;
                    f[current_i][k] = cost[current_i][k];
                    g[current_i][k] = cost[current_i][k];
                    h[current_i][k] = sqrt(cost[current_i][k] * cost[current_i][k] + 1 * 1);
                    open_list[current_i][k] = 1;
                }
            }
        }

        i++;
        j++;
    }

    return 0;
}

int main()
{
    int start_x = 0;
    int start_y = 0;
    int end_x = 0;
    int end_y = 0;

    printf("Enter start coordinates (x, y): ");
    scanf("%d %d", &start_x, &start_y);

    printf("Enter end coordinates (x, y): ");
    scanf("%d %d", &end_x, &end_y);

    AStar(start_x, start_y, end_x, end_y);

    return 0;
}