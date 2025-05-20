//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: synchronous
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX 1000
#define INF INT_MAX

int n, m;
int graph[MAX][MAX];
int parent[MAX];
int visited[MAX];
int min_cost[MAX];

void init()
{
    memset(graph, 0, sizeof(graph));
    memset(parent, -1, sizeof(parent));
    memset(visited, 0, sizeof(visited));
    memset(min_cost, 0, sizeof(min_cost));
}

void greedy_mst()
{
    int i, j, u, v, min_dist;
    int count = 0;

    for(i=0; i<n; i++)
    {
        min_dist = INF;
        for(j=0; j<n; j++)
        {
            if(graph[i][j]!= 0 && visited[j] == 0 && min_dist > graph[i][j])
            {
                min_dist = graph[i][j];
                u = i;
                v = j;
            }
        }

        if(min_dist!= INF)
        {
            count++;
            parent[v] = u;
            visited[v] = 1;
        }
    }

    printf("Minimum spanning tree created with %d edges\n", count);
}

void print_mst()
{
    int i, j;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(parent[j] == i)
            {
                printf("%d - %d\n", i, j);
            }
        }
    }
}

int main()
{
    int i, j, w;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    init();

    printf("Enter the edges with their weights:\n");

    for(i=0; i<m; i++)
    {
        scanf("%d %d %d", &i, &j, &w);
        graph[i][j] = w;
        graph[j][i] = w;
    }

    greedy_mst();
    print_mst();

    return 0;
}