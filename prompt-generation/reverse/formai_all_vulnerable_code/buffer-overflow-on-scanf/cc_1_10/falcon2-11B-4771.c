//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include<assert.h>

#define MAX_NODES 10
#define MAX_EDGES 10
#define INF INT_MAX

//Structure for the nodes
struct node{
    int color;
    struct node *next;
};

//Function to create a new node
struct node *newNode(int color){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->color = color;
    temp->next = NULL;
    return temp;
}

//Function to print the graph
void printGraph(struct node *head){
    struct node *temp = head;
    while(temp!= NULL){
        printf("%d ", temp->color);
        temp = temp->next;
    }
    printf("\n");
}

//Function to add an edge to the graph
void addEdge(struct node *head, int a, int b){
    struct node *temp = head;
    while(temp!= NULL){
        if(temp->color == a){
            temp->next = newNode(b);
            return;
        }
        temp = temp->next;
    }
}

//Function to find the minimum color in the graph
int findMin(struct node *head){
    struct node *temp = head;
    int minColor = INF;
    while(temp!= NULL){
        if(temp->color < minColor){
            minColor = temp->color;
        }
        temp = temp->next;
    }
    return minColor;
}

//Function to color the graph using Prim's algorithm
void prims(struct node *head){
    int minColor = findMin(head);
    printf("Minimum color = %d\n", minColor);
    struct node *temp = head;
    while(temp!= NULL){
        if(temp->color == minColor){
            temp->color = -1;
            temp = temp->next;
        }
        else{
            temp = temp->next;
        }
    }
}

//Function to perform BFS
void bfs(struct node *head){
    struct node *temp = head;
    int visited[MAX_NODES] = {0};
    int colorCount[MAX_NODES] = {0};
    int i;
    for(i = 0; i < MAX_NODES; i++){
        colorCount[i] = 0;
    }
    while(temp!= NULL){
        if(visited[temp->color] == 0){
            printf("%d ", temp->color);
            visited[temp->color] = 1;
            colorCount[temp->color] = 1;
            temp = temp->next;
        }
        else{
            temp = temp->next;
        }
    }
    printf("\n");
    for(i = 0; i < MAX_NODES; i++){
        printf("%d ", colorCount[i]);
    }
    printf("\n");
}

int main(){
    struct node *head = NULL;
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    while(m--){
        scanf("%d %d", &a, &b);
        addEdge(head, a, b);
    }
    bfs(head);
    prims(head);
    return 0;
}