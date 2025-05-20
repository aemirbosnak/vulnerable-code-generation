//FormAI DATASET v1.0 Category: Graph representation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int adj_matrix[MAX_VERTICES][MAX_VERTICES];
int vertex_count = 0;

int get_index(char vertex)
{
    int i;
    for(i = 0; i < vertex_count; i++){
        if(vertex == 65+i){
            return i;
        }
    }
    return -1;
}

void add_edge(char u, char v)
{
    int index1 = get_index(u);
    int index2 = get_index(v);

    adj_matrix[index1][index2] = 1;
    adj_matrix[index2][index1] = 1;
}

void display_graph()
{
    int i, j;
    for(i = 0; i < vertex_count; i++){
        printf("%c -> ", 65+i);
        for(j = 0; j < vertex_count; j++){
            if(adj_matrix[i][j] == 1){
                printf("%c ", 65+j);
            }
        }
        printf("\n");
    }
}

int main()
{
    int option;
    char vertex, u, v;

    printf("Welcome to the energetic C Graph program!\n");

    while(1){
        printf("\n");
        printf("Select an option:\n");
        printf("1. Add Vertex\n");
        printf("2. Add Edge\n");
        printf("3. Display Graph\n");
        printf("4. Quit\n");

        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Enter a new vertex (A-Z): ");
                fflush(stdin);
                scanf("%c", &vertex);
                if(get_index(vertex) == -1){
                    adj_matrix[vertex_count][vertex_count] = 0;
                    vertex_count++;
                }
                else{
                    printf("Vertex already exists!\n");
                }
                break;

            case 2:
                printf("Enter two vertices to add an edge between them (A-Z): ");
                fflush(stdin);
                scanf("%c %c", &u, &v);
                add_edge(u, v);
                break;

            case 3:
                printf("Graph Representation:\n");
                display_graph();
                break;

            case 4:
                printf("Thanks for using the energetic C Graph program!\n");
                exit(0);
                break;

            default:
                printf("Invalid option!\n");
                break;
        }
    }
    
    return 0;
}