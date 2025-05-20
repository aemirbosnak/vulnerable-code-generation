//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Define the maximum number of vertices of the graph
#define MAX_VERTICES 50

//Define the maximum number of colors that can be assigned
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];

/* Function to check if a given color can be assigned 
    to a vertex v */
int isSafe(int v, int c, int n)
{
    for(int i=0; i<n; i++)
        if (graph[v][i] && c == color[i])
            return 0;
    return 1;
}

/* Function to generate and print the graph */
void generateGraph(int n, int m)
{
    srand(time(NULL));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            graph[i][j] = 0;
    for(int i=0;i<m;i++)
    {
        int x,y;
        x=rand()%n;
        y=rand()%n;
        while(x==y || graph[x][y]==1)
        {
            x=rand()%n;
            y=rand()%n;
        }
        graph[x][y]=1;
        graph[y][x]=1;
    }
    printf("Graph Generated:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}

/* Function to assign colors recursively to each vertex */
int assignColors(int n, int m, int v)
{
    if (v == n)
        return 1;
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c, n)) {
            color[v] = c;
            if(assignColors(n, m, v + 1) == 1)
                return 1;
            color[v] = 0;
        }
    }
    return 0;
}

/* Driver program to test above functions */
int main()
{
    int n,m;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &m);
    generateGraph(n,m);
    printf("\nEnter the number of colors that can be assigned: ");
    scanf("%d", &m);
    if(assignColors(n,m,0) == 1) {
        printf("\nColors assigned successfully:\n");
        for(int i=0; i<n; i++)
            printf("Vertex %d: Color %d\n", i+1, color[i]);
    }
    else
        printf("\nColors cannot be assigned\n");
    return 0;
}