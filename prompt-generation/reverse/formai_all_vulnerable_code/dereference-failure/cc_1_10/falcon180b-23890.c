//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10
#define MAX_DATA_SIZE 100

typedef struct {
    char data[MAX_DATA_SIZE];
    int size;
} Data;

typedef struct node {
    Data data;
    int id;
    struct node* next;
} Node;

Node* createNode(int id) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    newNode->id = id;
    newNode->next = NULL;
    return newNode;
}

void addData(Node* node, char* data, int size) {
    if (node->data.size + size > MAX_DATA_SIZE) {
        printf("Error: Data size exceeds maximum limit.\n");
        exit(1);
    }
    strncat(node->data.data, data, size);
    node->data.size += size;
}

void printData(Data data) {
    printf("Data: %s\n", data.data);
    printf("Size: %d\n", data.size);
}

int main() {
    int numNodes, i;
    char input[MAX_DATA_SIZE];

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    Node* nodes = malloc(numNodes * sizeof(Node));
    if (nodes == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    for (i = 0; i < numNodes; i++) {
        printf("Enter the ID of node %d: ", i+1);
        scanf("%d", &nodes[i].id);
        printf("Enter the data for node %d: ", i+1);
        scanf("%s", input);
        addData(&nodes[i], input, strlen(input));
    }

    printf("Data in the nodes:\n");
    for (i = 0; i < numNodes; i++) {
        printData(nodes[i].data);
    }

    return 0;
}