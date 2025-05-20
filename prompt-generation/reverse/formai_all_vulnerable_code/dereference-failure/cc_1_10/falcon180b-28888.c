//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Node structure for the graph
typedef struct node{
    int data;
    struct node* next;
}node;

//Function to create a new node with the given data
node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to add an edge between two nodes
void addEdge(node* start, node* end){
    node* newNode = createNode(0);
    newNode->next = start->next;
    start->next = newNode;
}

//Function to print the graph in a readable format
void printGraph(node* start){
    printf("Graph:\n");
    while(start!= NULL){
        printf("%d -> ", start->data);
        start = start->next;
    }
    printf("NULL\n");
}

//Main function
int main(){
    node* graph = NULL;

    //Add nodes to the graph
    graph = createNode(1);
    addEdge(graph, createNode(2));
    addEdge(graph, createNode(3));
    addEdge(graph, createNode(4));

    //Print the graph
    printGraph(graph);

    return 0;
}