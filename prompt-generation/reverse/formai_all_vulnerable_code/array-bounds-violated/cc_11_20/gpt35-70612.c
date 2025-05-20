//FormAI DATASET v1.0 Category: Graph representation ; Style: real-life
#include<stdio.h>

int main() {

    int vertices, edges, i, j, k;
    printf("Enter the number of vertices and edges: ");
    scanf("%d%d", &vertices, &edges);

    int graph[vertices][vertices][edges];

    for(i=0;i<vertices;i++) {
        for(j=0;j<vertices;j++) {
            for(k=0;k<edges;k++) {
                graph[i][j][k] = 0;
            }
        }
    }

    printf("Enter the edges in the format (vertex1 vertex2 weight): \n");
    for(i=0;i<edges;i++) {
        int v1, v2, weight;
        scanf("%d%d%d", &v1, &v2, &weight);
        graph[v1][v2][i] = weight;
        graph[v2][v1][i] = weight; //for undirected graph
    }

    printf("\nAdjacency Matrix: \n");
    for(i=0;i<vertices;i++) {
        for(j=0;j<vertices;j++) {
            int sum = 0;
            for(k=0;k<edges;k++) {
                sum += graph[i][j][k];
            }
            printf("%d ", sum);
        }
        printf("\n");
    }

    printf("\nEdge List: \n");
    for(i=0;i<edges;i++) {
        for(j=0;j<vertices;j++) {
            for(k=0;k<vertices;k++) {
                if(graph[j][k][i]!=0) {
                    printf("%d %d %d\n", j, k, graph[j][k][i]);
                }
            }
        }
    }

    printf("\nGraph visualization: \n");
    for(i=0;i<vertices;i++) {
        for(j=0;j<vertices;j++) {
            int sum = 0;
            for(k=0;k<edges;k++) {
                sum += graph[i][j][k];
            }
            if(sum!=0) {
                printf("%d --> %d (", i, j);
                for(k=0;k<edges;k++) {
                    if(graph[i][j][k]!=0) {
                        printf("%d,", graph[i][j][k]);
                    }
                }
                printf(")\n");
            }
        }
    }

    return 0;
}