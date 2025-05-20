//FormAI DATASET v1.0 Category: Graph representation ; Style: Dennis Ritchie
#include <stdio.h>

#define max_vertices 100

int vertices, edges;
int graph[max_vertices][max_vertices];

void print_graph(){
    int i,j;
    for(i = 0; i < vertices; i++){
        printf("%d: ", i+1);
        for(j = 0; j < vertices; j++){
            if(graph[i][j] == 1){
                printf("%d ", j+1);
            }
        }
        printf("\n");
    }
}

void add_edge(int u, int v){
    graph[u-1][v-1] = 1;
    graph[v-1][u-1] = 1;
}

void remove_edge(int u, int v){
    graph[u-1][v-1] = 0;
    graph[v-1][u-1] = 0;
}

int main(){
    int i, u, v, choice;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    for(i = 0; i < edges; i++){
        printf("Enter edge %d: ", i+1);
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    print_graph();

    do{
        printf("\nMenu:\n");
        printf("1. Add edge\n");
        printf("2. Remove edge\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the edge to be added: ");
                scanf("%d %d", &u, &v);
                add_edge(u, v);
                printf("Updated graph: \n");
                print_graph();
                break;
            case 2:
                printf("Enter the edge to be removed: ");
                scanf("%d %d", &u, &v);
                remove_edge(u, v);
                printf("Updated graph: \n");
                print_graph();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(1);

    return 0;
}