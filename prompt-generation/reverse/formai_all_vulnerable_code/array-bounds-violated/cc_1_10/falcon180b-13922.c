//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define INF INT_MAX
#define V 4
#define E 6

int adj[V][V];
int dist[V];
int parent[V];

void init()
{
    int i, j;
    for(i=0; i<V; i++)
    {
        for(j=0; j<V; j++)
        {
            if(i==j)
            {
                adj[i][j] = 0;
            }
            else
            {
                adj[i][j] = INF;
            }
        }
    }
}

void a_star(int start, int end)
{
    int i, u, v;
    int min_dist = INF, min_index;
    int spt_set[V];
    int spt_set_size = 0;

    spt_set[spt_set_size++] = start;
    dist[start] = 0;

    while(spt_set_size > 0)
    {
        min_dist = INF;
        for(i=0; i<spt_set_size; i++)
        {
            u = spt_set[i];

            for(v=0; v<V; v++)
            {
                if(adj[u][v] < dist[u] + dist[v])
                {
                    dist[v] = dist[u] + adj[u][v];
                    parent[v] = u;
                }
            }
        }

        for(i=0; i<spt_set_size; i++)
        {
            if(dist[spt_set[i]] == min_dist)
            {
                min_index = i;
                break;
            }
        }

        spt_set_size--;
        for(i=min_index; i<spt_set_size; i++)
        {
            spt_set[i] = spt_set[i+1];
        }
    }

    printf("\nPath from %d to %d:\n", start, end);
    if(dist[end] == INF)
    {
        printf("No path found.\n");
    }
    else
    {
        int v = end;
        while(v!= -1)
        {
            printf("%d ", v);
            v = parent[v];
        }
        printf("\n");
    }
}

int main()
{
    int i, j;
    init();

    for(i=0; i<V; i++)
    {
        for(j=0; j<V; j++)
        {
            if(i!=j)
            {
                printf("%d ", adj[i][j]);
            }
            else
            {
                printf("%d ", 0);
            }
        }
        printf("\n");
    }

    a_star(0, 3);

    return 0;
}