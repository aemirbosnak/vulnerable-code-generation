//FormAI DATASET v1.0 Category: Graph representation ; Style: calm
#include <stdio.h>

#define MAX_VERTICES 20

int adjacent[MAX_VERTICES][MAX_VERTICES];
int n;

void init()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            adjacent[i][j] = 0;
        }
    }
}

void add_edge(int u, int v)
{
    adjacent[u][v] = 1;
    adjacent[v][u] = 1;
}

void print_graph()
{
    printf("Graph:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d: ", i);
        for(int j = 0; j < n; j++)
        {
            if(adjacent[i][j]) printf("%d ", j);
        }
        printf("\n");
    }
}

int main()
{
    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &n);

    init();

    // add some edges
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(1, 2);
    add_edge(2, 3);
    add_edge(3, 4);

    print_graph();

    return 0;
}