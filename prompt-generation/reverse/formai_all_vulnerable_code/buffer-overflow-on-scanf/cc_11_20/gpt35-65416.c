//FormAI DATASET v1.0 Category: Graph representation ; Style: random
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("\n*** C Graph Representation Example Program ***\n\n");

    int vertices, i, j, k;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    // Creating adjacency matrix
    int **adj_matrix = (int **)malloc(vertices * sizeof(int *));
    for(i=0; i<vertices; i++)
        adj_matrix[i] = (int *)malloc(vertices * sizeof(int));

    printf("\nEnter the adjacency matrix of the graph: \n");
    for(i=0; i<vertices; i++)
        for(j=0; j<vertices; j++)
            scanf("%d", &adj_matrix[i][j]);

    // Displaying adjacency matrix
    printf("\nAdjacency matrix of the graph is: \n");
    for(i=0; i<vertices; i++){
        for(j=0; j<vertices; j++)
            printf("%d ", adj_matrix[i][j]);
        printf("\n");
    }

    // Creating adjacency list
    typedef struct node{
        int data;
        struct node *next;
    }node;

    node **adj_list = (node **)malloc(vertices*sizeof(node *));
    for(i=0; i<vertices; i++)
        adj_list[i] = NULL;

    for(i=0; i<vertices; i++){
        node *last = NULL;
        for(j=0; j<vertices; j++){
            if(adj_matrix[i][j]){
                node *new_node = (node *)malloc(sizeof(node));
                new_node->data = j;
                new_node->next = NULL;
                if(adj_list[i] == NULL)
                    adj_list[i] = new_node;
                else
                    last->next = new_node;
                last = new_node;
            }
        }
    }

    // Displaying adjacency list
    printf("\nAdjacency list of the graph is: \n");
    for(i=0; i<vertices; i++){
        node *ptr = adj_list[i];
        printf("Vertex %d: ", i);
        while(ptr != NULL){
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }

    // Freeing memory
    for(i=0; i<vertices; i++){
        node *ptr, *next;
        ptr = adj_list[i];
        while(ptr != NULL){
            next = ptr->next;
            free(ptr);
            ptr = next;
        }
        free(adj_matrix[i]);
    }
    free(adj_matrix);
    free(adj_list);

    printf("\n*** Program ended successfully ***\n");

    return 0;
}