//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

#define inf 999999
#define n 10

int dist[n][n];
int parent[n][n];
int start, end;

void initial(int dist[n][n], int start, int end)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==start && j==end)
                dist[i][j] = 0;
            else
                dist[i][j] = inf;
        }
    }
}

void print_matrix(int dist[n][n])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

void a_star(int dist[n][n], int parent[n][n], int start, int end)
{
    int u, v, min_dist = inf;
    int open_list[n*n], closed_list[n*n];
    int open_count = 0, closed_count = 0;
    int start_index = start*n + end;
    int end_index = end*n + start;

    open_list[0] = start_index;
    closed_list[closed_count++] = end_index;

    while(open_count < closed_count)
    {
        min_dist = inf;
        for(int i=0; i<open_count; i++)
        {
            u = open_list[i]/n;
            v = open_list[i]%n;

            for(int k=0; k<n; k++)
            {
                if(dist[u][k]!= inf && dist[u][k] + dist[k][v] < min_dist)
                {
                    min_dist = dist[u][k] + dist[k][v];
                    parent[u][v] = k;
                }
            }
        }

        for(int i=0; i<open_count; i++)
        {
            if(dist[open_list[i]/n][open_list[i]%n] == min_dist)
            {
                open_list[i] = -1;
                open_count--;
                break;
            }
        }
    }

    printf("The shortest path is: ");
    int path[n];
    int temp = end_index;
    for(int i=0; i<n; i++)
    {
        path[i] = temp%n;
        temp /= n;
    }

    for(int i=n-1; i>=0; i--)
        printf("%d ", path[i]);
}

int main()
{
    int start, end;

    printf("Enter the start and end points: ");
    scanf("%d %d", &start, &end);

    initial(dist, start, end);

    a_star(dist, parent, start, end);

    return 0;
}