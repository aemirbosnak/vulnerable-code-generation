//FormAI DATASET v1.0 Category: Graph representation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

/* Function prototype declarations */

void init_graph(int adjacency_matrix[][MAX_VERTICES], int num_vertices);
void add_edge(int adjacency_matrix[][MAX_VERTICES], int num_vertices, int source, int destination);
void print_graph(int adjacency_matrix[][MAX_VERTICES], int num_vertices);

/* Main function */

int main()
{
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices, source, destination, choice;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);

    init_graph(adjacency_matrix, num_vertices);

    printf("MENU:\n");
    printf("1. Add an edge\n");
    printf("2. Print the graph\n");
    printf("3. Exit\n");

    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the source and destination vertices separated by a space: ");
                scanf("%d %d", &source, &destination);
                add_edge(adjacency_matrix, num_vertices, source, destination);
                break;

            case 2:
                print_graph(adjacency_matrix, num_vertices);
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

/* Function to initialize the graph */

void init_graph(int adjacency_matrix[][MAX_VERTICES], int num_vertices)
{
    int i, j;

    for (i = 0; i < num_vertices; i++)
    {
        for (j = 0; j < num_vertices; j++)
        {
            adjacency_matrix[i][j] = 0;
        }
    }
}

/* Function to add an edge to the graph */

void add_edge(int adjacency_matrix[][MAX_VERTICES], int num_vertices, int source, int destination)
{
    if (source >= 0 && source < num_vertices && destination >= 0 && destination < num_vertices)
    {
        adjacency_matrix[source][destination] = 1;
        adjacency_matrix[destination][source] = 1;
        printf("Edge added between vertices %d and %d\n", source, destination);
    }
    else
    {
        printf("Invalid vertices!\n");
    }
}

/* Function to print the graph */

void print_graph(int adjacency_matrix[][MAX_VERTICES], int num_vertices)
{
    int i, j;

    printf("The graph is:\n");

    for (i = 0; i < num_vertices; i++)
    {
        for (j = 0; j < num_vertices; j++)
        {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}