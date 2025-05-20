//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 50

struct Node{
    int node_id;
    int degree;
    int *adj_list;
};

void create_graph(struct Node graph[MAX_NODES]){
    int i,j,k,n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        graph[i].node_id = i;
        graph[i].degree = 0;
        graph[i].adj_list = (int *)malloc(n*sizeof(int));
        for(j=0;j<n;j++){
            graph[i].adj_list[j] = 0;
        }
    }

    printf("Enter the edges: ");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&k);
            if(k==1){
                graph[i].degree++;
                graph[i].adj_list[graph[j].node_id] = 1;
                graph[j].degree++;
                graph[j].adj_list[graph[i].node_id] = 1;
            }
        }
    }
}

void print_graph(struct Node graph[MAX_NODES]){
    int i,j,k;
    printf("\nThe graph is:\n");
    for(i=0;i<graph[0].degree;i++){
        printf("%d ",graph[0].node_id);
    }
    printf("\n");

    for(i=1;i<graph[0].degree;i++){
        printf("%d ",i);
        for(j=0;j<graph[0].degree;j++){
            if(graph[i].adj_list[j]==1){
                printf("%d ",j);
            }
        }
        printf("\n");
    }
}

int main(){
    struct Node graph[MAX_NODES];
    create_graph(graph);
    print_graph(graph);
    return 0;
}