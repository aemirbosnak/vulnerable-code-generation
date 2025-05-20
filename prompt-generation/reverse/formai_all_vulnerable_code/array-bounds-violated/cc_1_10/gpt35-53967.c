//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 50

int graph[max][max];
int visited[max] = {0};
int n;

void dfsTraversal(int vertex){
    visited[vertex] = 1;
    printf("%d ", vertex);

    int j;
    for(j=0; j<n; j++){
        if(graph[vertex][j]==1 && visited[j]==0){
            dfsTraversal(j);
        }
    }
}

int main(){
    printf("Enter the number of devices in the network: ");
    scanf("%d", &n);

    memset(graph, 0, sizeof(graph));
    printf("Enter the connection between devices (0 if no connection, 1 if connected):\n");
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nThe Network Topology Map is:\n\n");
    for(i=0; i<n; i++){
        printf("\tDevice%d", i+1);
    }
    printf("\n");

    for(i=0; i<n; i++){
        printf("Device%d", i+1);
        for(j=0; j<n; j++){
            printf("\t%d", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the device to start traversal from: ");
    int start;
    scanf("%d", &start);

    printf("\nDFS Traversal of the network from device %d is: ", start);
    dfsTraversal(start);

    return 0;
}