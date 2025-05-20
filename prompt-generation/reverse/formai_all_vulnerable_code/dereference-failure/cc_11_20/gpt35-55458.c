//FormAI DATASET v1.0 Category: Graph representation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
 
int main()
{
    int size, i, j, value;
    printf("Enter the size of the graph: ");
    scanf("%d",&size); //get the size of the graph from user
 
    int **graph = (int **)malloc(size * sizeof(int *)); //allocate memory for 2D array
    for(i=0; i<size; i++)
        graph[i] = (int *)malloc(size * sizeof(int));
 
    for(i=0; i<size; i++) //populate the graph array with random values
    {
        for(j=0; j<size; j++)
        {
            value = rand() % 2; //0 or 1
            if(value == 1)
                graph[i][j] = rand() % MAX; //random value between 0 and 9
            else
                graph[i][j] = -1; //no edge
        }
    }
 
    printf("\nThe graph is:\n\n");
    for(i=0; i<size; i++) //print the 2D array
    {
        for(j=0; j<size; j++)
        {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
 
    printf("\n\nMatrix Representation:\n");
    printf("\n   ");
    for (i=0; i<size; i++)
        printf("%2d ", i+1);
 
    printf("\n  ");
    for (i=0; i<size; i++)
        printf("-- ");
 
    printf("\n");
    for (i=0; i<size; i++)
    {
        printf("%2d|", i+1);
        for (j=0; j<size; j++)
        {
            if (graph[i][j] == -1)
                printf("  |");
            else
                printf("%2d|", graph[i][j]);
        }
        printf("\n");
 
        for (j=0; j<size; j++)
            printf("---");
 
        printf("\n");
    }
 
    for(i=0; i<size; i++) //free the memory
        free(graph[i]);
    free(graph);
 
    return 0;
}