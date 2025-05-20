//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

int parent[MAX];
int rank[MAX];

void make_set(int v)
{
    parent[v] = v;
    rank[v] = 0;
}

int find_set(int v)
{
    if (parent[v]!= v)
        parent[v] = find_set(parent[v]);
    return parent[v];
}

void union_sets(int u, int v)
{
    int pu = find_set(u);
    int pv = find_set(v);

    if (pu!= pv)
    {
        if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else
            parent[pu] = pv;
        if (rank[pu] == rank[pv])
            rank[pu]++;
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    int i, u, v, w;

    for (i = 0; i < n; i++)
        make_set(i);

    for (i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        if (find_set(u)!= find_set(v))
        {
            union_sets(u, v);
            printf("%d %d %d\n", u, v, w);
        }
    }

    return 0;
}