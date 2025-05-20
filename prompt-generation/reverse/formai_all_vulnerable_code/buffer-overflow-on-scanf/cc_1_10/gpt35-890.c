//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

//Struct for storing data of links
struct link {
    int source;
    int dest;
    int weight;
};
//Struct for storing adjacency matrix
struct node {
    int dist;
    int pos;
    struct link* link_arr;
};

//Function to add edge to the link array
void addEdge(struct link* link_arr, int source, int dest, int weight, int* ptr) {
    link_arr[*ptr].source = source;
    link_arr[*ptr].dest = dest;
    link_arr[*ptr].weight = weight;
    (*ptr)++;
}

//Function to implement Dijkstra's algorithm
//to find shortest path between two nodes
void dijkstra(struct node** adj_mat, int start, int end, int num_nodes) {
    int visited[num_nodes];
    for(int i=0; i<num_nodes; i++) {
        visited[i] = 0;
        adj_mat[i]->pos = i;
        adj_mat[i]->dist = -1;
    }
    adj_mat[start]->dist = 0;
    while(1) {
        int min = -1;
        for(int i=0; i<num_nodes; i++) {
            if(visited[i] == 0) {
                if(adj_mat[i]->dist != -1 && (min == -1 || adj_mat[i]->dist < adj_mat[min]->dist)) {
                    min = i;
                }
            }
        }
        if(min == -1) {
            break;
        }
        visited[min] = 1;
        for(int i=0; i<num_nodes; i++) {
            if(adj_mat[min][i].dist != -1) {
                int dist = adj_mat[min]->dist + adj_mat[min][i].dist;
                if(adj_mat[i]->dist == -1 || adj_mat[i]->dist > dist) {
                    adj_mat[i]->dist = dist;
                }
            }
        }
    }
    printf("Shortest Distance between node %d and %d: %d\n", start, end, adj_mat[end]->dist);
}

int main() {
    printf("Enter the number of nodes: ");
    int num_nodes;
    scanf("%d", &num_nodes);
    struct node** adj_mat = (struct node**)malloc(num_nodes*sizeof(struct node*));
    for(int i=0; i<num_nodes; i++) {
        adj_mat[i] = (struct node*)malloc(num_nodes*sizeof(struct node));
        for(int j=0; j<num_nodes; j++) {
            adj_mat[i][j].dist = -1;
            adj_mat[i][j].pos = i;
            struct link* link_arr = (struct link*)malloc(max*sizeof(struct link));
            adj_mat[i][j].link_arr = link_arr;
        }
    }
    printf("Enter the number of links: ");
    int num_links;
    scanf("%d", &num_links);
    for(int i=0; i<num_links; i++) {
        int source, dest, weight;
        printf("Enter Source, Destination and Weight for link %d: ", i+1);
        scanf("%d %d %d", &source, &dest, &weight);
        addEdge(adj_mat[source]->link_arr, source, dest, weight, &adj_mat[source]->pos);
        adj_mat[source][dest].dist = weight;
        adj_mat[dest][source].dist = weight;
    }
    printf("Enter the starting node: ");
    int start;
    scanf("%d", &start);
    printf("Enter the ending node: ");
    int end;
    scanf("%d", &end);
    dijkstra(adj_mat, start, end, num_nodes);
    return 0;
}