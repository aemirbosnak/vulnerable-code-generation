//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int graph[MAX][MAX] = {{0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                              {1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                              {1, 1, 0, 1, 1, 0, 0, 0, 0, 0},
                              {0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
                              {0, 0, 1, 0, 0, 1, 1, 0, 0, 0},
                              {0, 0, 0, 1, 1, 0, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                              {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}};

    int x, y, start_x, start_y, end_x, end_y;
    scanf("Enter the starting point (x, y): ", &start_x, &start_y);
    scanf("Enter the ending point (x, y): ", &end_x, &end_y);

    // Find the path using breadth-first search
    int queue[MAX] = {0};
    int visited[MAX][MAX] = {{0, 0}};
    visited[start_x][start_y] = 1;
    queue[0] = start_x;
    queue[1] = start_y;

    int i, j, flag = 0;
    for (i = 0; i < MAX && flag == 0; i++)
    {
        for (j = 0; j < MAX && flag == 0; j++)
        {
            if (visited[queue[i]][queue[j]] == 1)
            {
                continue;
            }
            if (graph[queue[i]][queue[j]] == 1 && visited[queue[i]][queue[j]] == 0)
            {
                visited[queue[i]][queue[j]] = 1;
                queue[i * MAX + j] = graph[queue[i]][queue[j]] + queue[i] + queue[j];
                if (queue[i * MAX + j] == end_x && queue[i * MAX + j] == end_y)
                {
                    flag = 1;
                }
            }
        }
    }

    // Print the path
    if (flag == 1)
    {
        printf("The path is: ");
        int k = queue[0] * MAX + queue[1];
        while (queue[k] != start_x || queue[k] != start_y)
        {
            printf("(%d, %d) ", queue[k], queue[k + 1]);
            k = queue[k] * MAX + queue[k + 1];
        }
        printf("(%d, %d)\n", start_x, start_y);
    }
    else
    {
        printf("No path found.\n");
    }

    return 0;
}