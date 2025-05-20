//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* graph, int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = graph[u].next;
    graph[u].next = newNode;
}

void printGraph(Node* graph, int n) {
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i);
        Node* temp = graph[i].next;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    Node* graph = (Node*)malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
        graph[i].data = i;
        graph[i].next = NULL;
    }

    srand(time(NULL));
    for (int i = 0; i < m; i++) {
        int u = rand() % n;
        int v = rand() % n;
        while (u == v) {
            v = rand() % n;
        }
        addEdge(graph, u, v);
    }

    printf("The graph is:\n");
    printGraph(graph, n);

    return 0;
}