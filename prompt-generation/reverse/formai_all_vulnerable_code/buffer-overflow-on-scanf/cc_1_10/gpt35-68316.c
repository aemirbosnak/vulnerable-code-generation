//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LEN 10

struct node {
    char name[MAX_NAME_LEN];
    double value;
};

struct element {
    char type;
    struct node* left;
    struct node* right;
    double value;
};

int main() {
    struct node nodes[MAX_NODES];
    struct element elements[MAX_NODES];
    int num_nodes = 0;
    int num_elements = 0;
    
    // Read in nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        printf("Enter node %d name: ", i+1);
        scanf("%s", nodes[i].name);
        nodes[i].value = 0.0;
    }
    
    // Read in elements
    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);
    for (int i = 0; i < num_elements; i++) {
        struct element e;
        printf("Enter element %d type (R/L/C): ", i+1);
        scanf(" %c", &e.type);
        printf("Enter element %d left node name: ", i+1);
        char left_node_name[MAX_NAME_LEN];
        scanf("%s", left_node_name);
        for (int j = 0; j < num_nodes; j++) {
            if (strcmp(nodes[j].name, left_node_name) == 0) {
                e.left = &nodes[j];
                break;
            }
        }
        printf("Enter element %d right node name: ", i+1);
        char right_node_name[MAX_NAME_LEN];
        scanf("%s", right_node_name);
        for (int j = 0; j < num_nodes; j++) {
            if (strcmp(nodes[j].name, right_node_name) == 0) {
                e.right = &nodes[j];
                break;
            }
        }
        printf("Enter element %d value (ohms/henries/farads): ", i+1);
        scanf("%lf", &e.value);
        
        elements[i] = e;
    }
    
    // Print out circuit
    printf("Circuit:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%c %s %s %lf\n", elements[i].type, elements[i].left->name, elements[i].right->name, elements[i].value);
    }

    return 0;
}