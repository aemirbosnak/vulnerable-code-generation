//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 1000

int n, m, i, j, k, l, c, d, u, v, w, x, y, z, count = 0, parent[10], rank[10];

void make_set(int x)
{
    parent[x] = x;
    rank[x] = 0;
}

int find_set(int x)
{
    if(parent[x]!= x)
        parent[x] = find_set(parent[x]);
    return parent[x];
}

void union_set(int x, int y)
{
    int i = find_set(x);
    int j = find_set(y);

    if(rank[i] > rank[j])
        parent[j] = i;
    else if(rank[i] < rank[j])
        parent[i] = j;
    else
    {
        parent[j] = i;
        rank[i]++;
    }
}

void kruskals_algorithm(int graph[MAX][MAX], int edge_count)
{
    int i, j, min_cost = INT_MAX, u, v;

    for(i = 0; i < edge_count; i++)
    {
        u = graph[i][0];
        v = graph[i][1];
        w = graph[i][2];

        if(find_set(u)!= find_set(v))
        {
            if(w < min_cost)
                min_cost = w;
        }
    }

    count = 0;

    for(i = 0; i < edge_count; i++)
    {
        u = graph[i][0];
        v = graph[i][1];
        w = graph[i][2];

        if(find_set(u)!= find_set(v))
        {
            union_set(u, v);
            count++;
        }
    }

    if(count!= n - 1)
        printf("\nThe given graph does not have a minimum spanning tree.\n");
    else
        printf("\nThe minimum spanning tree has %d edges.\n", edge_count - count);
}

int main()
{
    int graph[MAX][MAX], edge_count, i, j, u, v, w;

    printf("\nEnter the number of vertices in the graph: ");
    scanf("%d", &n);

    printf("\nEnter the number of edges in the graph: ");
    scanf("%d", &m);

    printf("\nEnter the edges with their weights: ");

    for(i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        graph[i][0] = u;
        graph[i][1] = v;
        graph[i][2] = w;
    }

    edge_count = m;

    kruskals_algorithm(graph, edge_count);

    return 0;
}