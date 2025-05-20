//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_NODES 10

//Structure to represent a node in the graph
typedef struct node{
    int id;
    int weight;
    int parent;
}Node;

//Function to find the parent of a given node
int findParent(Node* parent, int i){
    if(parent[i].parent!= -1){
        return findParent(parent, parent[i].parent);
    }
    return i;
}

//Function to merge two nodes in the graph
void merge(Node* parent, int i, int j){
    int p1 = findParent(parent, i);
    int p2 = findParent(parent, j);

    if(p1!= p2){
        if(parent[p1].weight > parent[p2].weight){
            parent[p1].parent = p2;
        }
        else{
            parent[p2].parent = p1;
        }
    }
}

//Function to initialize the graph and set the weights
void initGraph(Node* parent, int n){
    for(int i=0; i<n; i++){
        parent[i].id = i;
        parent[i].weight = rand() % 100;
        parent[i].parent = -1;
    }
}

//Function to perform Kruskal's algorithm
void kruskalsAlgorithm(Node* parent, int n, int m){
    int count = 0;
    int e = 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(parent[i].id!= parent[j].id && parent[i].weight + parent[j].weight < parent[i].weight){
                merge(parent, i, j);
                count++;
            }
        }
    }

    printf("Minimum Spanning Tree found with %d edges\n", count);
}

//Main function to run the program
int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    Node* parent = (Node*)malloc(n*sizeof(Node));
    initGraph(parent, n);

    int u, v, w;
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &u, &v, &w);
        parent[u].weight = w;
    }

    kruskalsAlgorithm(parent, n, m);

    return 0;
}