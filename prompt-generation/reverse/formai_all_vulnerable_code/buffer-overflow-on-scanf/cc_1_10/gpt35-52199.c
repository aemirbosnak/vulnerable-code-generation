//FormAI DATASET v1.0 Category: Graph representation ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100

int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void initialise()
{
    int i,j;
    for(i = 0; i < MAX_VERTICES; i++)
    {
        for(j = 0; j < MAX_VERTICES; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int a, int b)
{
    adjMatrix[a][b] = 1;
    adjMatrix[b][a] = 1;
}

void printGraph(int n)
{
    int i,j;
    printf("\nThe Adjacency Matrix of the graph is:\n\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void dfs(int v, int n)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for(i = 0; i < n; i++)
    {
        if(adjMatrix[v][i] == 1 && visited[i] == 0)
        {
            dfs(i, n);
        }
    }
}

int main()
{
    int n, i, option, a, b;
    printf("Enter the number of vertices in the graph:\n");
    scanf("%d", &n);

    initialise();

    do {
        printf("\nChoose an option:\n");
        printf("1. Add Edge\n");
        printf("2. Print Graph\n");
        printf("3. Depth First Search\n");
        printf("0. Exit\n");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\nEnter the vertices to add edge between:\n");
                scanf("%d %d", &a, &b);
                addEdge(a, b);
                break;

            case 2:
                printGraph(n);
                break;

            case 3:
                printf("\nEnter the vertex for depth first search:\n");
                scanf("%d", &a);
                printf("\nThe depth first search starting from vertex %d is:\n\n", a);
                for(i=0; i<n; i++)
                {
                    visited[i] = 0;
                }
                dfs(a, n);
                printf("\n");

                break;

            case 0: break;

            default: printf("\nInvalid input. Please try again.\n");
        }

    } while(option != 0);

    return 0;
}