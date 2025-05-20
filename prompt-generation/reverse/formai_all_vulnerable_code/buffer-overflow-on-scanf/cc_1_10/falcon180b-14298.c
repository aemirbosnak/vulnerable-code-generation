//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_NODES 100
#define MAX_EDGES 200

int adj_matrix[MAX_NODES][MAX_EDGES];
int degrees[MAX_NODES];
int color[MAX_NODES];

void init_graph(int n, int e)
{
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < e; j++)
        {
            adj_matrix[i][j] = rand() % 2;
        }
    }
}

void get_degrees(int n)
{
    for(int i = 0; i < n; i++)
    {
        degrees[i] = 0;
        for(int j = 0; j < n; j++)
        {
            if(adj_matrix[i][j] == 1)
            {
                degrees[i]++;
            }
        }
    }
}

void color_graph(int n)
{
    for(int i = 0; i < n; i++)
    {
        color[i] = rand() % 3 + 1;
    }
}

void print_graph(int n, int e)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < e; j++)
        {
            if(adj_matrix[i][j] == 1)
            {
                printf("(%d,%d) ", i, j);
            }
        }
        printf("\n");
    }
}

int main()
{
    int n, e;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    init_graph(n, e);
    get_degrees(n);
    color_graph(n);

    printf("Adjacency matrix:\n");
    print_graph(n, e);

    printf("Degree of nodes:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", degrees[i]);
    }

    printf("\n");
    return 0;
}